#ifndef PRJ_TRACABLE_H
#define PRJ_TRACABLE_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

#include "Vecteur.h"
#include <deque>

class Tracable
{
protected:
	std::deque<Vecteur> positions;
	unsigned int taille;
	
	
public:
	Tracable(unsigned int const& t =0);
	void ajouter(Vecteur v);
	virtual ~Tracable();
	virtual void trace() const;
};

#endif
