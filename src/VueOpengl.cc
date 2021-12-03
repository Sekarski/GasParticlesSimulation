/*Copyright 2014 Christine Nguyen and Samuel Sekarski*/

#include "../include/VueOpengl.h"
#include <vector>
using namespace std;

//les constantes spécifiques des gazes nobles
#define K_HE 1000*8.314472/4.002602		//on pensait au début faire des attribut constant static des sous classe GlGaz
#define K_NE 1000*8.314472/20.1797
#define K_AR 1000*8.314472/39.948
#define K_KR 1000*8.314472/83.798
#define K_XE 1000*8.314472/131.293
#define K_RA 1000*8.314472/222

int Vue_OpenGL::attributelist[3] = {WX_GL_DEPTH_SIZE, 16, 0};		//on nous a dit de mettre ça pour fixer le problème de profondeur

int Vue_OpenGL::TIMER_ID(12);	//le numéro d'identité du Timer

BEGIN_EVENT_TABLE(Vue_OpenGL, wxGLCanvas)				//association evénements-méthodes qui les gèrent
    EVT_PAINT(          Vue_OpenGL::dessine       )		//demande de dessin
    EVT_SIZE(           Vue_OpenGL::OnSize        )		//Redmiension
    EVT_KEY_DOWN(       Vue_OpenGL::OnKeyDown     )		//Lors d'appuie sur des touches
    EVT_ENTER_WINDOW(   Vue_OpenGL::OnEnterWindow )
    EVT_TIMER(TIMER_ID, Vue_OpenGL::OnTimer       )		//lors de tout les tour de chronomètre
END_EVENT_TABLE()

// ======================================================================
Vue_OpenGL::Vue_OpenGL( wxWindow*      parent
						, bool mod		//true pour choisi le nouveau modèle de choc, false pour l'ancien
                      , wxSize  const& taille
                      , wxPoint const& position
                      )
: wxGLCanvas(parent, wxID_ANY, position, taille, 
             wxSUNKEN_BORDER|wxFULL_REPAINT_ON_RESIZE , wxT(""),
             Vue_OpenGL::attributelist)
, theta(35.0), phi(20.0), r(0.0)		//rotation et zoom initial du Système
, timer(new wxTimer(this, TIMER_ID))	//Allocution du Timer
, sys(new GlEnceinte(200,200,200))	//Instanciation du Système avec une encinte de 200x200x200 (pour pouvoir la modifier)
, dt(0.01)	//le pas de temps, malheureusement il ne correspond pas a celui du Timer
, modele(mod)	//on stock en attribut quel modèle utiliser
{
	fc = new FenetreOPT(this, wxT("Controles de simulation"), wxSize(500, 400));	//fênetre avec les options/contrôles de la simulation
}

void Vue_OpenGL::InitSysteme(int init[])	//initialisation du Système, c'est a dire ajout de toutes les particules demandé par l'utilisateur (stocké dans un tableau)
{
	for(int i=0; i< init[0] ; ++i)	//Helium
	{
		sys.ajouter_particule(new GlHelium(sys.tirer_position(), sys.tirer_vitesse(K_HE)));	//position aléatoire, vitesse aléatoire (pour une certain constante spécifique)
	}
	for(unsigned int i=0; i< init[1]; ++i)	//Neon
	{
		sys.ajouter_particule(new GlNeon(sys.tirer_position(), sys.tirer_vitesse(K_NE)));
	}
	for(unsigned int i=0; i< init[2]; ++i)	//Argon
	{
		sys.ajouter_particule(new GlArgon(sys.tirer_position(), sys.tirer_vitesse(K_AR)));
	}
	for(unsigned int i=0; i< init[3]; ++i)	//Krypton
	{
		sys.ajouter_particule(new GlKrypton(sys.tirer_position(), sys.tirer_vitesse(K_KR)));
	}
	for(unsigned int i=0; i< init[4]; ++i)	//Xenon
	{
		sys.ajouter_particule(new GlXenon(sys.tirer_position(), sys.tirer_vitesse(K_XE)));
	}
	for(unsigned int i=0; i< init[5]; ++i)	//Radon
	{
		sys.ajouter_particule(new GlRadon(sys.tirer_position(), sys.tirer_vitesse(K_RA)));
	}
		
		//Particues Tracée
/*sys.ajouter_particule(new GlHelium(sys.tirer_position(),sys.tirer_vitesse(K_HE),100));
		sys.ajouter_particule(new GlNeon(sys.tirer_position(),sys.tirer_vitesse(K_NE),100));
		sys.ajouter_particule(new GlArgon(sys.tirer_position(),sys.tirer_vitesse(K_AR),100));
		sys.ajouter_particule(new GlKrypton(sys.tirer_position(),sys.tirer_vitesse(K_KR),100));
		sys.ajouter_particule(new GlXenon(sys.tirer_position(),sys.tirer_vitesse(K_XE),100));
		sys.ajouter_particule(new GlRadon(sys.tirer_position(),sys.tirer_vitesse(K_RA),100));*/
		
	for(int i=0; i< init[6] ; ++i)	//Helium
	{
		sys.ajouter_particule(new GlHelium(sys.tirer_position(), sys.tirer_vitesse(K_HE), init[12]));	//position aléatoire, vitesse aléatoire (pour une certain constante spécifique)
	}
	for(unsigned int i=0; i< init[7]; ++i)	//Neon
	{
		sys.ajouter_particule(new GlNeon(sys.tirer_position(), sys.tirer_vitesse(K_NE), init[12]));
	}
	for(unsigned int i=0; i< init[8]; ++i)	//Argon
	{
		sys.ajouter_particule(new GlArgon(sys.tirer_position(), sys.tirer_vitesse(K_AR), init[12]));
	}
	for(unsigned int i=0; i< init[9]; ++i)	//Krypton
	{
		sys.ajouter_particule(new GlKrypton(sys.tirer_position(), sys.tirer_vitesse(K_KR), init[12]));
	}
	for(unsigned int i=0; i< init[10]; ++i)	//Xenon
	{
		sys.ajouter_particule(new GlXenon(sys.tirer_position(), sys.tirer_vitesse(K_XE), init[12]));
	}
	for(unsigned int i=0; i< init[11]; ++i)	//Radon
	{
		sys.ajouter_particule(new GlRadon(sys.tirer_position(), sys.tirer_vitesse(K_RA), init[12]));
	}
}

// ======================================================================
void Vue_OpenGL::dessine(wxPaintEvent&)	//dessine le système a chaque fois qu'on demande un rafraichissement
{
  if (!GetContext()) return;
	
	r = fc->getZOOM();			//MAJ (mise a jour) de la coordonée sphérique r en fonction de du slider dans la fenetre d'option
	phi = fc->getRPHI();		//MAJ de phi
	theta = fc->getRTHETA();	//MAJ de thetha
	sys.getEnceinte()->setProfondeur(fc->getEX());		//MAJ de dimension de l'enceinte en fonction des slider dans la fenetre d'option
	sys.getEnceinte()->setHauteur(fc->getEZ());
	sys.getEnceinte()->setLargeur(fc->getEY());

	SetCurrent();

	// commence par effacer l'ancienne image
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* part du système de coordonnées de base 
	* (dessin à l'origine : matrice identité) */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if(fc->getActionCam())		//si on veut placer la camera sur une particule (choisi dans la fenetre d'option)
	{
	// on place la caméra a la position d'une particule, puis on met la visée parallèle a la vitesse de la particule
	gluLookAt(sys.getParticule()->getPosition().getX(), sys.getParticule()->getPosition().getY(), sys.getParticule()->getPosition().getZ(),
				(sys.getParticule()->getVitesse() + sys.getParticule()->getPosition()).getX(),(sys.getParticule()->getVitesse() + sys.getParticule()->getPosition()).getY(), (sys.getParticule()->getVitesse() + sys.getParticule()->getPosition()).getZ(),
				0.0,0.0,1.0);
	}
	else
	{							//sinon on dessine normalement
	// place la caméra
	gluLookAt(150,   150, 150,
			sys.getEnceinte()->getProfondeur()/2.0,sys.getEnceinte()->getLargeur()/2.0,sys.getEnceinte()->getHauteur()/2.0,	//on regard le centre de l'enceinte
			0.0, 0.0, 1.0);
	}
	glTranslated(r,r,r);	// pour le zoom
	glPushMatrix();		//on emplie la matrice de dessin
	//On aimerais que les transformation (rotation) de fasse autour du centre du système et non pas de l'origine:
	glTranslated(sys.getEnceinte()->getProfondeur()/2.0,sys.getEnceinte()->getLargeur()/2.0,sys.getEnceinte()->getHauteur()/2.0);	//pour centrer sur le centre de l'enceinte
	glRotated(theta, 0.0, 1.0, 0.0); 	//rotation d'angle theta
	glRotated(phi,   0.0, 0.0, 1.0); 	//rotation d'angle phi
	glTranslated(-sys.getEnceinte()->getProfondeur()/2.0,-sys.getEnceinte()->getLargeur()/2.0,-sys.getEnceinte()->getProfondeur()/2.0);
	//on reviens a l'origine pour dessiner le système

	sys.dessine();	//dessin du Système
	glPopMatrix();		//on reviens a l'état précédent de la matrice de dessin ( sans toutes les transformation)

	// Finalement, on envoie le dessin à l'écran
	glFlush();
	SwapBuffers();
}

// ======================================================================
void Vue_OpenGL::OnSize(wxSizeEvent& event)	//lors de resize
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
void Vue_OpenGL::OnKeyDown( wxKeyEvent& event )	//lors d'appuie sur des touches
{
  switch( event.GetKeyCode() ) {
  case WXK_LEFT: 
    RotatePhi( 2.0);
    fc->setRPHI(fc->getRPHI() + 2);	//si on appuye sur les touches, les slider dans la fenetre d'option doivent changer aussi
    Refresh(false);
    break;

  case WXK_RIGHT: 
    RotatePhi( -2.0);
    fc->setRPHI(fc->getRPHI() - 2);
    Refresh(false);
    break;

  case WXK_UP: 
    RotateTheta( 2.0);
    fc->setRTHETA(fc->getRTHETA() + 2);
    Refresh(false);
    break;

  case WXK_DOWN: 
    RotateTheta(-2.0);
    fc->setRTHETA(fc->getRTHETA() -2);
    Refresh(false);
    break;

  case WXK_HOME:
    r     =  0.0;   // On revient à un point fixé
    theta = 35.0;
    phi   = 20.0;
    fc->setZOOM(r);	//les slider dans la fenetre d'option aussi
    fc->setRPHI(phi);
    fc->setRTHETA(theta);
    Refresh(false);
    break;

  case WXK_PAGEUP:
    deplace(-1.0);    // On se rapproche
    fc->setZOOM(fc->getZOOM() -1);
    Refresh(false);
    break;

  case WXK_PAGEDOWN:
    deplace(1.0);     // On s'éloigne
    fc->setZOOM(fc->getZOOM() +1);
    Refresh(false);
    break;

  // Pause sur la touche "espace"
  case ' ':
    if (timer->IsRunning()) {
      timer->Stop();	//arrete le timer s'il tourne déjà
    } else {
      timer->Start();	//sinon le relance s'il a été arrêté
    }
    break;
  }
  
  event.Skip();
}

// ======================================================================
void Vue_OpenGL::RotateTheta(GLdouble deg)
{
  theta += deg;
  while (theta < -180.0) { theta += 360.0; }		//on veut que thetha soi compris entre -180 et 180°
  while (theta >  180.0) { theta -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::RotatePhi(GLdouble deg)
{
  phi += deg;
  while (phi <   0.0) { phi += 360.0; }		//on veut que phi soit comprit entre 0 et 360°
  while (phi > 360.0) { phi -= 360.0; }
}

// ======================================================================
void Vue_OpenGL::deplace(GLdouble dr)
{
  r += dr;
  if (r < -100.0) r = -100.0;		//on veut empècher de trop zomer/dézoomer
  else if (r > 100.0) r = 100.0;
}

// ===================================================================

// ======================================================================
void Vue_OpenGL::InitOpenGL(int init[]) 
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

	InitSysteme(init);	//initialise les particules du système avant de lancer la simulation
	
  // lance le Timer
  timer->Start(20);	//20 ms
}

// ======================================================================
void Vue_OpenGL::OnTimer(wxTimerEvent& event)
{
	
	dt = fc->getDT();	//problème si on ferme la fenetre d'options avant la fenetreGL :S => on a bloqué la fermeture de fc
	if(modele)	//fait évoluer le système en fonction du modèle choisi
	{
		sys.evolue(event.GetInterval()/20*dt); 	// le pas de temps n'est pas le vrais :( le problème c'est dès que le pas de temps deviens trop grand ya un segmentation fault qui aparait
	}
	else
	{
		sys.evolue_vieux(event.GetInterval()/20*dt, 1);	//ancienne version d'évolue, avec un epsilon = 1
	}
  // demande l'affichage
  Refresh(false);
}

double Vue_OpenGL::getTemps() const	//retourne le pas de temps
{
	return dt;
}

wxTimer* Vue_OpenGL::getTimer()		//retourne un pointeur sur un Timer, pour qu'on puisse le lancer/arrêter dans la classe parente
{									//... utile pour la gestion manuel de la fermeture des fenetres
	return timer;
}
