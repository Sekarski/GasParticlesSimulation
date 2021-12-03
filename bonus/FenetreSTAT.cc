/*Copyright 2014 Christine Nguyen and Samuel Sekarski*/

#include "FenetreSTAT.h"
using namespace std;


BEGIN_EVENT_TABLE(FenetreSTAT, wxFrame)
    EVT_CLOSE(FenetreSTAT::OnExit)		//lors d'un evenement de fermeture le handler OnExit est appelé (pour la fermeture manelle de la fenetre)
END_EVENT_TABLE()

FenetreSTAT::FenetreSTAT(
wxString const& titre,
wxSize const& taille,
wxPoint const& position,
long style)
:wxFrame(0, wxID_ANY, titre, position, taille, style), credits(new glSTAT(this))
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
	credits->InitOpenGl();
}


void FenetreSTAT::OnExit(wxCloseEvent& event) //on gère nous même la fermeture de la fenêtre pour éviter d'avoir un segmentation fault
{ 
	if(credits->getTimer()->IsRunning())	//on regarde si le timeer tourne toujours
	{
		credits->getTimer()->Stop();	// Si on n'arrête pas le timer, il y a un segmentation fault
	}
	credits->Destroy();	//on détruit la le context opengl (équivalent de delete)
	Destroy();			//puis on détuit la fenetre elle-même
}
