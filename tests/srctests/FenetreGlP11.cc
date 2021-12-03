#include "FenetreGlP11.h"
using namespace std;

BEGIN_EVENT_TABLE(FenetreGL, wxFrame)
    EVT_CLOSE(FenetreGL::OnExit)
END_EVENT_TABLE()

// ======================================================================
FenetreGL::FenetreGL( wxString const& titre 
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


void FenetreGL::OnExit(wxCloseEvent& event) //on gère nous même la fermeture de la fenêtre pour éviter d'avoir un segmentation fault
{ 
	if(fogl->getTimer()->IsRunning())
	{
		fogl->getTimer()->Stop();	// Si on n'arrête pas le timer, il y a un segmentation fault
	}
	fogl->Destroy();
	Destroy();
}
