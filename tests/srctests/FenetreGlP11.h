#ifndef PRJ_FENETREGLP11_H
#define PRJ_FENETREGLP11_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "VueOpenglP11.h"

// fenetre(s) principale(s)
class FenetreGL: public wxFrame
{
public:
  FenetreGL( wxString const& titre 
		, wxSize   const& taille   = wxDefaultSize
         , wxPoint  const& position = wxDefaultPosition
         , long            style    = wxDEFAULT_FRAME_STYLE
         );

  virtual ~FenetreGL() {}

protected:
  void OnExit(wxCloseEvent& event);

  Vue_OpenGL* fogl;

DECLARE_EVENT_TABLE()
};

#endif //PRJ_FENETREGLP11_H
