#ifndef PRJ_FENETRE_H
#define PRJ_FENETRE_H

#include "wx/wxprec.h"		//includes de wxWidgets
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "VueOpengl.h"		//pour le dessin du système

// fenetre dans laquelle les dessins opengl vont se faire
class Fenetre: public wxFrame
{
public:
	Fenetre( wxString const& titre 
		,int init[], bool mod = true		// paramètre détermiant le nombres de particules a être instancier, et le modèle de collision a utiliser
         , wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );

	virtual ~Fenetre() {}

protected:
	void OnExit(wxCloseEvent& event);	//Pour gerer nous même la fermeture de la fenetre et éviter un seg fault

	Vue_OpenGL* fogl;		//contexte opengl, ou vont se faire les dessins

DECLARE_EVENT_TABLE()		//on déclare qu'il y aura une table associant des événements a certaines fonction de gestion (Handlers)
};

#endif //PRJ_FENETRE_H
