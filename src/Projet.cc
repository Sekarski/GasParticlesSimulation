/*Copyright 2014 Christine Nguyen and Samuel Sekarski*/

#include "wx/wxprec.h"		//trucs pour utiliser wxwidgets
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "../bonus/FenetreCTRL.h"	//pour la fenetre de menu (ou de control)
using namespace std;

//notre application:
class Projet : public wxApp
{
private:
	FenetreCTRL* fenetreCTRL;	//fenetre de menu. Par pointeurs comme tout dans wxwidgets

public:
	bool OnInit();		//initialise de l'aplication
};

// Initialisation de l'application
bool Projet::OnInit()
{
	//On alloue la fenêtre dynamiquement.
	fenetreCTRL=new FenetreCTRL(wxT("Menu Général"),wxSize(640, 640));		//wxT("...") convertir une chainte literal en wxString utilisée par wxwidgets
	SetTopWindow(fenetreCTRL);		//choisit cette fenetre comme la principale
	return (fenetreCTRL != 0);		// renvoie "true" si l'ouverture de la fenetre c'est bien passée
}

/* ===================================================================
   Equivalent de main()
   =================================================================== */
IMPLEMENT_APP(Projet)	//lance la boucle infine du Projet
