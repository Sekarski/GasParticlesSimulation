#include "../include/GlEnceinte.h"

GlEnceinte::GlEnceinte(){}
GlEnceinte::GlEnceinte(double const& h, double const& l, double const& p): Enceinte(h,l,p) {}
GlEnceinte::~GlEnceinte(){}

void GlEnceinte::dessine() const
{
	//dessin des arêtes
	glBegin(GL_LINES);	
	glColor4ub(255,255,255,255);
	
	glVertex3d(0,0,0);
	glVertex3d(profondeur,0,0);
	
	glVertex3d(0,largeur,0);
	glVertex3d(profondeur,largeur,0);
	
	glVertex3d(0,largeur,hauteur);
	glVertex3d(profondeur,largeur,hauteur);
	
	glVertex3d(0,0,hauteur);
	glVertex3d(profondeur,0,hauteur);
	
	glVertex3d(0,0,0);
	glVertex3d(0,largeur,0);
	
	glVertex3d(profondeur,0,0);
	glVertex3d(profondeur,largeur,0);
	
	glVertex3d(profondeur,0,hauteur);
	glVertex3d(profondeur,largeur,hauteur);
	
	glVertex3d(0,0,hauteur);
	glVertex3d(0,largeur,hauteur);
	
	glVertex3d(0,0,0);
	glVertex3d(0,0,hauteur);
	
	glVertex3d(0,largeur,0);
	glVertex3d(0,largeur,hauteur);
	
	glVertex3d(profondeur,largeur,0);
	glVertex3d(profondeur,largeur,hauteur);
	
	glVertex3d(profondeur,0,0);
	glVertex3d(profondeur,0,hauteur);
	
	glEnd();
	
	//dessin des faces
	glBegin(GL_QUADS);
	glColor4ub(255,255,255,30);
	
	glVertex3d(0,0,0);
	glVertex3d(profondeur,0,0);
	glVertex3d(profondeur,largeur,0);
	glVertex3d(0,largeur,0);
	
	glVertex3d(0,largeur,hauteur);
	glVertex3d(profondeur,largeur,hauteur);
	glVertex3d(profondeur,0,hauteur);
	glVertex3d(0,0,hauteur);
	
	glVertex3d(0,largeur,0);
	glVertex3d(0,largeur,hauteur);
	glVertex3d(profondeur,largeur,hauteur);
	glVertex3d(profondeur,largeur,0);
	
	glVertex3d(0,0,0);
	glVertex3d(0,0,hauteur);
	glVertex3d(profondeur,0,hauteur);
	glVertex3d(profondeur,0,0);
	
	glVertex3d(profondeur,0,0);
	glVertex3d(profondeur,largeur,0);
	glVertex3d(profondeur,largeur,hauteur);
	glVertex3d(profondeur,0,hauteur);
	
	glVertex3d(0,0,0);
	glVertex3d(0,largeur,0);
	glVertex3d(0,largeur,hauteur);
	glVertex3d(0,0,hauteur);
	
	glEnd();
}
