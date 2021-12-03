#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "srctests/FenetreGlP11.h"
using namespace std;



// ----------------------------------------------------------------------
// Nouvelle application
class GUI : public wxApp
{

public:
	bool OnInit();

};



/* ===================================================================
   Implementation de l'application principale
   =================================================================== */

// ======================================================================
bool GUI::OnInit()
{
  // Crée la fenêtre principale
  FenetreGL* f = new FenetreGL(wxT("Simulation temps reel"),
                           wxSize(800, 600));
  SetTopWindow(f);
  return (f != 0);
}


/* ===================================================================
   Equivalent de main()
   =================================================================== */
IMPLEMENT_APP(GUI)
