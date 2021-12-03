#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "../include/Dessinable.h"
#include <vector>
using namespace std;

class Machin: public Dessinable
{
public:
  virtual void evolue(double dt) =0;
  virtual ~Machin(){}
};

//-----------------H2O-------------------
class H2O: public Machin
{
public:
	H2O():sphere(gluNewQuadric()){}
	virtual ~H2O() { gluDeleteQuadric(sphere); }
	virtual void evolue(double dt) override{}
	virtual void dessine() const override
	{
		// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(-1.0, 0.0, 0.5);  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(0.0, 0.0, 1.0, 1.0); // Choisir la couleur (bleu ici)
  gluSphere(sphere, 1.0, 30, 30);// Dessiner une sphère
  glPopMatrix();                 // Revenir à l'ancienne position

  // dessin de la seconde sphère
  glPushMatrix();
  glTranslated(0.0, 0.0, 0.0); 
  glColor4d(0.0, 1.0, 1.0, 1.0); // choisi la couleur (turquoise ici)
  gluSphere(sphere, 1.5, 50, 50);
  glPopMatrix();

  // dessin de la troisième sphère
  glPushMatrix();
  glTranslated(1.0, 0.0, 0.5);
  glColor4d(0.0, 0.8, 0.0, 1.0);  //vert
  gluSphere(sphere, 1.0, 50, 50);
  glPopMatrix();
	}
  
private:
	GLUquadric* sphere;
};

//------------Moucheron----------------
class Moucheron: public Machin
{
public:
	Moucheron():sphere(gluNewQuadric()), position(0.0){}
	virtual ~Moucheron() { gluDeleteQuadric(sphere); }
	virtual void evolue(double dt) override
	{
		// mise à jour de la position à partir du pas de temps (via une
  // vitesse, arbitraire ici)
  position += dt / 15.0;
  while (position > 360.0) position -= 360.0;
	}
	virtual void dessine() const override
	{
		// Dessin de la petite sphère qui tourne
  glPushMatrix();
  glRotated(position, 0.0, 0.0, 1.0); /* on la fait tourner de "position" 
                                       * autour de Oz...                   */
  glTranslated(2.0, 0.0, 0.0);        /* ...sur un cercle de rayon 2.0     */
  glColor4d(1.0, 0.0, 0.0, 0.6); // couleur rouge, transparente à 40%
  gluSphere(sphere, 0.1, 30, 30);
  glPopMatrix();
	}
  
private:
	GLUquadric* sphere;
	  // le paramètre dépendant du temps
  double position;
};

//--------------------Blob--------------
class Blob: public Dessinable
{
public:
	Blob()
	{
		collection.push_back(new H2O);
		collection.push_back(new Moucheron);
	}
	virtual ~Blob() 
	{
		for(unsigned int i=0; i<collection.size(); ++i)
		{
			delete collection[i];
		} 
		collection.empty();
	}
	void evolue(double dt)
	{
		for(unsigned int i=0; i<collection.size(); ++i)
		{
			collection[i]->evolue(dt);
		}
	}
	virtual void dessine() const
	{
		for(unsigned int i=0;i<collection.size(); ++i)
		{
			collection[i]->dessine();
		}
	}
	
private:
	vector<Machin*> collection;
};

// ----------------------------------------------------------------------
// Nouvelle application
class GUI : public wxApp
{
public:
  bool OnInit();
};

// ----------------------------------------------------------------------
// sous-fenetre de dessin OpenGL
class Vue_OpenGL : public wxGLCanvas
{
public:
  Vue_OpenGL( wxWindow*      parent
            , wxSize  const& taille   = wxDefaultSize     
            , wxPoint const& position = wxDefaultPosition
            );


  void InitOpenGL();

protected:
  void dessine(wxPaintEvent& evenement);
  void OnSize(wxSizeEvent& evenement);
  void OnKeyDown(wxKeyEvent& evenement);
  void OnEnterWindow(wxMouseEvent& evenement) { SetFocus(); }
  void OnTimer(wxTimerEvent& event);

  void RotateTheta(GLdouble deg);
  void RotatePhi(GLdouble deg);
  void deplace(double dr);
  
private:
static int attributelist[3];
  double theta;
  double phi;
  double r;
  Blob blob;

  // le "Timer"
  wxTimer* timer;
  static int TIMER_ID;



DECLARE_EVENT_TABLE()
};

// ----------------------------------------------------------------------
// fenetre(s) principale(s)
class Fenetre: public wxFrame
{
public:
  Fenetre( wxString const& titre 
         , wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );

  virtual ~Fenetre() {}

protected:
  void OnExit(wxCommandEvent& event) { Close(true); }

  Vue_OpenGL* fogl;

DECLARE_EVENT_TABLE()
};

/* ===================================================================
   Implementation de Vue_OpenGL
   =================================================================== */
int Vue_OpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE, 16, 0};

int Vue_OpenGL::TIMER_ID(12);

BEGIN_EVENT_TABLE(Vue_OpenGL, wxGLCanvas)
    EVT_PAINT(          Vue_OpenGL::dessine       )
    EVT_SIZE(           Vue_OpenGL::OnSize        )
    EVT_KEY_DOWN(       Vue_OpenGL::OnKeyDown     )
    EVT_ENTER_WINDOW(   Vue_OpenGL::OnEnterWindow )
    EVT_TIMER(TIMER_ID, Vue_OpenGL::OnTimer       )
END_EVENT_TABLE()

// ======================================================================
Vue_OpenGL::Vue_OpenGL( wxWindow*      parent
                      , wxSize  const& taille
                      , wxPoint const& position
                      )
: wxGLCanvas(parent, wxID_ANY, position, taille, 
             wxSUNKEN_BORDER|wxFULL_REPAINT_ON_RESIZE , wxT(""),
             Vue_OpenGL::attributelist)

, theta(35.0), phi(20.0), r(5.0)
, timer(new wxTimer(this, TIMER_ID))

{}

// ======================================================================
void Vue_OpenGL::dessine(wxPaintEvent&)
{
  if (!GetContext()) return;

  SetCurrent();

  // commence par effacer l'ancienne image
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* part du système de coordonnées de base 
   * (dessin à l'origine : matrice identité) */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // place la caméra
  gluLookAt(r,   0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 1.0);
  glRotated(theta, 0.0, 1.0, 0.0); 
  glRotated(phi,   0.0, 0.0, 1.0);

  
	blob.dessine();
  

  // Finalement, on envoie le dessin à l'écran
  glFlush();
  SwapBuffers();
}

// ======================================================================
void Vue_OpenGL::OnSize(wxSizeEvent& event)
{
  // Nécessaire pour mettre à jour le contexte sur certaines plateformes
  wxGLCanvas::OnSize(event);

  if (GetContext()) {
    // set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
    int w, h;
    GetClientSize(&w, &h);
    SetCurrent();
    glViewport(0, 0, (GLint) w, (GLint) h);
  } 
}

// ======================================================================
void Vue_OpenGL::OnKeyDown( wxKeyEvent& event )
{
  switch( event.GetKeyCode() ) {
  case WXK_LEFT: 
    RotatePhi( 2.0);
    Refresh(false);
    break;

  case WXK_RIGHT: 
    RotatePhi( -2.0);
    Refresh(false);
    break;

  case WXK_UP: 
    RotateTheta( 2.0);
    Refresh(false);
    break;

  case WXK_DOWN: 
    RotateTheta(-2.0);
    Refresh(false);
    break;

  case WXK_HOME:
    r     =  5.0;   // On revient à un point fixé
    theta = 35.0;
    phi   = 20.0;
    Refresh(false);
    break;

  case WXK_PAGEUP:
    deplace(-1.0);    // On se rapproche
    Refresh(false);
    break;

  case WXK_PAGEDOWN:
    deplace(1.0);     // On s'éloigne
    Refresh(false);
    break;

  // Pause sur la touche "espace"
  case ' ':
    if (timer->IsRunning()) {
      timer->Stop();
    } else {
      timer->Start();
    }
    break;
  }
  
  event.Skip();
}

// ======================================================================
void Vue_OpenGL::RotateTheta(GLdouble deg)
{
  theta += deg;
  while (theta < -180.0) { theta += 360.0; }
  while (theta >  180.0) { theta -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::RotatePhi(GLdouble deg)
{
  phi += deg;
  while (phi <   0.0) { phi += 360.0; }
  while (phi > 360.0) { phi -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::deplace(GLdouble dr)
{
  r += dr;
  if (r < 1.0) r = 1.0;
  else if (r > 1000.0) r = 1000.0;
}

// ======================================================================
void Vue_OpenGL::InitOpenGL() 
{
  // Initialisation OpenGL

  SetCurrent();

  // active la gestion de la profondeur
  glEnable(GL_DEPTH_TEST);    

  // active la transparence
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // fixe la perspective
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, 4./3., 1.0, 1000.0);

  // fixe la couleur du fond à noir
  glClearColor(0.0, 0.0, 0.0, 1.0);

  // lance le Timer
  timer->Start(20);
}

// ======================================================================
void Vue_OpenGL::OnTimer(wxTimerEvent& event)
{
  blob.evolue(event.GetInterval());

  // demande l'affichage
  Refresh(false);
}

/* ===================================================================
   Implementation de Fenetre
   =================================================================== */

BEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_MENU( wxID_EXIT, Fenetre::OnExit )
END_EVENT_TABLE()

// ======================================================================
Fenetre::Fenetre( wxString const& titre 
                , wxSize   const& taille
                , wxPoint  const& position
                , long            style
                )
: wxFrame(0, wxID_ANY, titre, position, taille, style)
, fogl(new Vue_OpenGL(this))
{
  // Barre de menu
  wxMenu* winMenu = new wxMenu;
  winMenu->Append(wxID_EXIT, wxT("&Close"));

  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(winMenu, wxT("&Window"));

  SetMenuBar(menuBar);

  // Affiche (montre) la fenetre
  Show(true);

  // Initialise OpenGL
  fogl->InitOpenGL();
}

/* ===================================================================
   Implementation de l'application principale
   =================================================================== */

// ======================================================================
bool GUI::OnInit()
{
  // Crée la fenêtre principale
  Fenetre* f = new Fenetre(wxT("Simulation temps reel"),
                           wxSize(800, 600));
  SetTopWindow(f);
  return (f != 0);
}

/* ===================================================================
   Equivalent de main()
   =================================================================== */
IMPLEMENT_APP(GUI)
