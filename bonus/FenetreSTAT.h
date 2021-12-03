#ifndef GUI_FENETRESTAT_H
#define GUI_FENETRESTAT_H

#include "wx/wxprec.h"		//includes de wxWidgets
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "glSTAT.h"	//pour le dessine des crédits

//fenetre pour les crédits
class FenetreSTAT: public wxFrame
{
public:
	FenetreSTAT(wxString const& titre , wxSize const& taille = wxDefaultSize, wxPoint const& position = wxDefaultPosition, long style = wxDEFAULT_FRAME_STYLE);
	virtual ~FenetreSTAT() {}
	

protected:
	glSTAT* credits;	//contexte openGL
	void OnExit(wxCloseEvent& event);	//on gère manuellement de nouveau la fermeture de la fenetre, pour éviter un segmentaiton fault
	DECLARE_EVENT_TABLE()	//on déclarer un table d'evenement
};

#endif //GUI_FENETRESTAT_H
