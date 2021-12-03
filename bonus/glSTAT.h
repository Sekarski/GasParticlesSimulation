#ifndef GUI_GLSTAT_H
#define GUI_GLSTAT_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Text.h"
#include <string>

class glSTAT: public wxGLCanvas
{
public:
	glSTAT(wxWindow* parent, wxSize const& taille = wxDefaultSize, wxPoint const& position = wxDefaultPosition);
	void InitOpenGl();
	wxTimer* getTimer();

private:

	void dessine(wxPaintEvent& evenement);
	Text director;
	Text christine;
	Text programer;
	Text samuel;
	Text thanks;
	Text blabla;
	Text projet;
	Text leadsys;
	Text sys;
	Text leadgraph;
	Text graphists;
	Text assistant;
	Text hatter;
	Text story;
	Text supervisor;
	Text tbc;
	double pos;
	void OnTimer(wxTimerEvent& event);
	void crawl(double x);
	
	wxTimer* timer;

};

#endif //GUI_GLSTAT_H
