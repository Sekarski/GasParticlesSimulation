#include "glSTAT.h"
using namespace std;

glSTAT::glSTAT(
wxWindow* parent,
wxSize const& taille,
wxPoint const& position)
: wxGLCanvas(parent, wxID_ANY, position, taille, 
             wxSUNKEN_BORDER|wxFULL_REPAINT_ON_RESIZE , wxT(""))
, pos(0)
,director("project director"), christine("christine nguyen"), programer("lead programmers"), samuel("samuel sekarski"), thanks("special thanks")
,blabla("a b"), projet("p r o j e c t"), leadgraph("lead graphic programmer"), assistant("julien rechenmann"), hatter("j c chappelier")
,story("adapted from a script by"), supervisor("projet supervisor"), tbc("to be continued"), leadsys("lead system programmer")
,sys("system programmers"), graphists("graphic programmers")
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(glSTAT::dessine));
}


void glSTAT::InitOpenGl() 
{
	// Initialisation OpenGL

	SetCurrent();

	// active la gestion de la profondeur
	glEnable(GL_DEPTH_TEST);    

	// fixe la perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(130.0, 4./3., 1.0, 1000.0);

	// fixe la couleur du fond à noir
	glClearColor(0.0, 0.0, 0.0, 1.0);	// on voulais mettre un fond étoilé :(
	
	timer = new wxTimer(this);
	timer->Start(50);
	Connect(wxID_ANY, wxEVT_TIMER, wxTimerEventHandler(glSTAT::OnTimer));
}

void glSTAT::dessine(wxPaintEvent&)
{
	SetCurrent();

	// commence par effacer l'ancienne image
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* part du système de coordonnées de base 
	* (dessin à l'origine : matrice identité) */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// place la caméra
	gluLookAt(-25,   1.5, -30,
			2.5, 1.5, 0,
			1.0, 0.0, 0.0);
	glTranslated(-10,-45,0);
	glTranslated(pos,0,0);	//la position augement a chaque tour du timer

	glTranslated(0,46.5,0);	
	glScaled(4,4,4);
	glTranslated(0,0,-10);
	glRotated(40, 0.0,1.0,0.0);
	projet.dessineC();
	glRotated(-40,0.0,1.0,0.0);
	glTranslated(0,0,10);
	glScaled(1/4.0,1/4.0,1/4.0);
	glTranslated(-32,0,0);
	
	glScaled(2,2,2);		//on a fait ça un peut rapidement désolé
	director.dessineC();		//en gros on scale pour avoir la bonne taille, on dessine le texte et on descale
	glScaled(0.5,0.5,0.5);
	christine.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);		//puis on fait des translate quand on veux mettre plus d'espace
	programer.dessineC();
	glScaled(0.5,0.5,0.5);		// on vous laisse regarder le résultat ;)
	christine.dessineC();		
	samuel.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	leadgraph.dessineC();
	glScaled(0.5,0.5,0.5);
	samuel.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	graphists.dessineC();
	glScaled(0.5,0.5,0.5);
	christine.dessineC();
	samuel.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	leadsys.dessineC();
	glScaled(0.5,0.5,0.5);
	christine.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	sys.dessineC();
	glScaled(0.5,0.5,0.5);
	christine.dessineC();
	samuel.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	supervisor.dessineC();
	glScaled(0.5,0.5,0.5);
	assistant.dessineC();
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	story.dessineC();
	glScaled(0.5,0.5,0.5);
	hatter.dessineC();
	Text("aka the mad hatter").dessineC();	//on dit ça parce qu'on vous aime bien, et en plus au premier semestre, vous parliez d'Alice... (en ICC) => Alice au pays de merveiles... Chappelier fou... vous voyez ^^
	
	glScaled(2,2,2);
	glTranslated(-8,0,0);
	thanks.dessineC();
	glScaled(0.5,0.5,0.5);

	Text("christine nguyen for being awesome").dessineC();
	Text("mr assistant for answering our questions").dessineC();
	Text("coca cola for giving me the energy to work all trough the night").dessineC();

	glScaled(2,2,2);
	glTranslated(-8,0,0);
	tbc.dessineC();
	
	/*glTranslated(0,-46.5,0);
	glScaled(0.5,0.5,0.5);
	glTranslated(-20,0,0);
	Text("original star wars opening crawl").dessine();
	Text("it is a period of civil war \
	rebel spaceships striking \
	from a hidden base have won \
	their first victory against \
	the evil galactic empire").dessine();

	Text("during the battle rebel \
	spies managed to steal secret \
	plans to the empire s \
	ultimate weapon the death \
	star an armored space \
	station with enough power \
	to destroy an entire planet").dessine();

	Text("pursued by the empire s \
	sinister agents princess \
	leia races home aboard her \
	starship custodian of the \
	stolen plans that can save her \
	people and restore \
	freedom to the galaxy").dessine();*/
		

	// Finalement, on envoie le dessin à l'écran
	glFlush();
	SwapBuffers();
}

void glSTAT::OnTimer(wxTimerEvent& event)
{
  crawl(0.33); 	// event.GetInterval() a utiliser plus tard

  // demande l'affichage
  Refresh(false);
}

void glSTAT::crawl(double x)	//augement la position du text, faisant l'effet défillement quand on l'apelle toutes les X secondes
{
	pos += x;
	Refresh(false);
}

wxTimer* glSTAT::getTimer()	//pour pouvoir modifier le timer et éviter un seg fault
{
	return timer;
}
