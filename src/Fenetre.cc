/*Copyright 2014 Christine Nguyen and Samuel Sekarski*/

#include "../include/Fenetre.h"
using namespace std;

BEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_CLOSE(Fenetre::OnExit)		// lorsque qu'un evénement de fermeture est lancé, la méthode OnExit va être appelé
END_EVENT_TABLE()

// ======================================================================
Fenetre::Fenetre( wxString const& titre 
				,int init[], bool mod		//pour transmettre les choix d'initialisation de la fenetre de Menu a Vue_OpenGL
                , wxSize   const& taille
                , wxPoint  const& position
                , long            style
                )
: wxFrame(0, wxID_ANY, titre, position, taille, style)	//Fenetre hérite de wxFrame, donc il faut faire appelle a son constructeur de celui-ci
, fogl(new Vue_OpenGL(this, mod))		//alloue dynamiquement une Vue_OpenGL
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
  fogl->InitOpenGL(init);		//on passe les info d'initialisation a la méthode qui initialise la Vue_openGL
}

void Fenetre::OnExit(wxCloseEvent& event) //on gère nous même la fermeture de la fenêtre pour éviter d'avoir un segmentation fault
{ 
	if(fogl->getTimer()->IsRunning())	//si le timer tourne, sinon il n'y a aucun problème de fermeture
	{
		fogl->getTimer()->Stop();	// Si on n'arrête pas le timer, il y a un segmentation fault
	}
	fogl->Destroy();	//équivalent du delete qu'il ne faut pas faire
	Destroy();
}
