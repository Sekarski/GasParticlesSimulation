#include "VueOpenglP14.h"
using namespace std;

int Vue_OpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE, 16, 0};		//on nous a dit de mettre ça pour fixer le problème de profondeur

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
, theta(35.0), phi(20.0), r(0.0)
, timer(new wxTimer(this, TIMER_ID))
, sys(new GlEnceinte(100,100,100))
, dt(0.01)
{}


void Vue_OpenGL::InitSysteme14()
{
	//sans trace
	for(unsigned int i=0; i< 166 ; ++i)
	{
		sys.ajouter_particule(new GlHelium(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/4.002602)));
	}
	for(unsigned int i=0; i< 166; ++i)
	{
		sys.ajouter_particule(new GlNeon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/20.1797)));
	}
	for(unsigned int i=0; i< 166; ++i)
	{
		sys.ajouter_particule(new GlArgon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/39.948)));
	}
	for(unsigned int i=0; i< 166; ++i)
	{
		sys.ajouter_particule(new GlKrypton(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/83.798)));
	}
	for(unsigned int i=0; i< 166; ++i)
	{
		sys.ajouter_particule(new GlXenon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/131.293)));
	}
	for(unsigned int i=0; i< 166; ++i)
	{
		sys.ajouter_particule(new GlRadon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/222)));
	}
	
	//avec trace
	for(unsigned int i=0; i< 1 ; ++i)
	{
		sys.ajouter_particule(new GlHelium(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/4.002602), 20));
	}
	for(unsigned int i=0; i< 1; ++i)
	{
		sys.ajouter_particule(new GlNeon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/20.1797), 30));
	}
	for(unsigned int i=0; i< 1; ++i)
	{
		sys.ajouter_particule(new GlArgon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/39.948), 40));
	}
	for(unsigned int i=0; i< 1; ++i)
	{
		sys.ajouter_particule(new GlKrypton(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/83.798), 50));
	}
	for(unsigned int i=0; i< 1; ++i)
	{
		sys.ajouter_particule(new GlXenon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/131.293), 60));
	}
	for(unsigned int i=0; i< 1; ++i)
	{
		sys.ajouter_particule(new GlRadon(sys.tirer_position(), sys.tirer_vitesse(1000*8.314472/222), 70));
	}
	
}


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
	gluLookAt(135,   135, 135,
			10, 10, 10,
			0.0, 0.0, 1.0);
	glTranslated(r,r,r);
	glPushMatrix();
	glTranslated(sys.getEnceinte()->getProfondeur()/2.0,sys.getEnceinte()->getLargeur()/2.0,sys.getEnceinte()->getHauteur()/2.0);	//pour centrer sur le centre de l'enceinte
	glRotated(theta, 0.0, 1.0, 0.0); 
	glRotated(phi,   0.0, 0.0, 1.0); 
	glTranslated(-sys.getEnceinte()->getProfondeur()/2.0,-sys.getEnceinte()->getLargeur()/2.0,-sys.getEnceinte()->getProfondeur()/2.0);


	sys.dessine();
	glPopMatrix();

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
    r     =  0.0;   // On revient à un point fixé
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
  if (r < -100.0) r = -100.0;
  else if (r > 100.0) r = 100.0;
}

// ===================================================================

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

	InitSysteme14();

  // lance le Timer
  timer->Start(20);	//20 ms ?
}

// ======================================================================
void Vue_OpenGL::OnTimer(wxTimerEvent& event)
{
  sys.evolue(event.GetInterval()/20*dt); 	// le pas de temps n'est pas le vrais :( le problème c'est dès que le pas de temps deviens trop grand ya un segmentation fault qui aparait

  // demande l'affichage
  Refresh(false);
}

wxTimer* Vue_OpenGL::getTimer() {return timer;}
