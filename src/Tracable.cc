#include "../include/Tracable.h"

//définition méthode virtuelle
void Tracable::trace() const
{
	glBegin(GL_LINE_STRIP);
	for(size_t i=0; i<positions.size(); ++i)
	{
	  glVertex3f(positions[i].getX(), positions[i].getY(), positions[i].getZ());
	}
	glEnd();
}

Tracable::Tracable(unsigned int const& t):taille(t) {}
Tracable::~Tracable(){}


void Tracable::ajouter(Vecteur v)
{
	if(positions.size() < taille)
	{
		positions.push_back(v);
	}
	else
	{
		positions.pop_front();
		positions.push_back(v);
	}
}
