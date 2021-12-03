#ifndef PRJ_GLENCEINTE_H
#define PRJ_GLENCEINTE_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "Enceinte.h"

class GlEnceinte: public Enceinte
{
public:
	GlEnceinte();
	GlEnceinte(double const& h, double const& l, double const& p);
	virtual ~GlEnceinte();
	virtual void dessine() const override;

};

#endif //PRJ_GLENCEINTE_H
