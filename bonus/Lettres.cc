/* Copyright 2014 Samuel Sekarski and Christine Nguyen */

#include "Lettres.h"

void Aa::dessine() const
{
	glColor3ub(c.R(),c.G(),c.B());	//dessine dans la couleur de la lettre
	
	//dessin de la lettre
	glBegin(GL_LINE_STRIP);	//on dessine que le contour des lettres
	glVertex2d(0,0);		//on dessine une lettre de 3 unité de large et 5 unité de hauteur
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(2,2);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glVertex2d(4,2);
	glVertex2d(3,2);
	glVertex2d(3,1);
	glEnd();
}

//Même principe pour toutes les lettres
void Bb::dessine() const
{
	glColor3ub(c.R(),c.G(),c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,2);
	glVertex2d(4,3);
	glVertex2d(3,3);
	glVertex2d(2.5,2);
	glVertex2d(2,3);
	glVertex2d(1,3);
	glVertex2d(0,2);
	glVertex2d(0,0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2d(1,1);
	glVertex2d(2,1);
	glVertex2d(1.5,2);
	glVertex2d(1,1);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glVertex2d(3.5,2);
	glVertex2d(3,1);
	glEnd();
}


void Cc::dessine() const
{
	glColor3ub(c.R(),c.G(),c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,1);
	glVertex2d(1,1);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
}

void Dd::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,2);
	glVertex2d(4,3);
	glVertex2d(1,3);
	glVertex2d(0,2);
	glVertex2d(0,0);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2d(1,1);
	glVertex2d(4,1);
	glVertex2d(4,1.8);
	glVertex2d(3,2.3);
	glVertex2d(2,2.3);
	glVertex2d(1,1.8);
	glVertex2d(1,1);
	glEnd();

}


void Ee::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,1);
	glVertex2d(3,1);
	glVertex2d(3,2);
	glVertex2d(2,2);
	glVertex2d(2,1);
	glVertex2d(1,1);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
}

void Ff::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,1);
	glVertex2d(3,1);
	glVertex2d(3,2);
	glVertex2d(2,2);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
}

void Gg::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,1);
	glVertex2d(1,1);
	glVertex2d(1,2);
	glVertex2d(2,2);
	glVertex2d(2,1.6);
	glVertex2d(3,1.6);
	glVertex2d(3,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
}

void Hh::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,1);
	glVertex2d(3,1);
	glVertex2d(3,2);
	glVertex2d(5,2);
	glVertex2d(5,3);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(2,2);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
}

void Ii::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(1,0);
	glVertex2d(1,1);
	glVertex2d(4,1);
	glVertex2d(4,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,2);
	glVertex2d(1,2);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
}

void Jj::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(1,0);
	glVertex2d(1,1);
	glVertex2d(4,1);
	glVertex2d(4,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,2);
	glVertex2d(0,2);
	glVertex2d(0,0);
	glEnd();
}

void Kk::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,1);
	glVertex2d(3,1);
	glVertex2d(5,2);
	glVertex2d(5,3);
	glVertex2d(3,2);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
}

void Ll::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,1);
	glVertex2d(1,1);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
}

void Mm::dessine() const
{
		
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,1);
	glVertex2d(3.5,1.5);
	glVertex2d(5,2);
	glVertex2d(5,3);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(3.5,2);
	glVertex2d(2,1.5);
	glVertex2d(3.5,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
}

void Nn::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,1);
	glVertex2d(2,2);
	glVertex2d(5,2);
	glVertex2d(5,3);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(3,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
}

void Oo::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(1,1);
	glVertex2d(4,1);
	glVertex2d(4,2);
	glVertex2d(1,2);
	glVertex2d(1,1);
	glEnd();
}

void Pp::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(2,3);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(4,1);
	glVertex2d(4,2);
	glVertex2d(3,2);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glEnd();
}

void Qq::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,3);
	glVertex2d(5,3);
	glVertex2d(5,0);
	glVertex2d(2,0);
	glVertex2d(2,2);
	glVertex2d(0,2);
	glVertex2d(0,3);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(4,1);
	glVertex2d(4,2);
	glVertex2d(3,2);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glEnd();
}

void Rr::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(2,3);
	glVertex2d(2,2);
	glVertex2d(0,3);
	glVertex2d(0,2);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(4,1);
	glVertex2d(4,2);
	glVertex2d(3,2);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glEnd();
}

void Ss::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(0,3);
	glVertex2d(3,3);
	glVertex2d(3,1);
	glVertex2d(4,1);
	glVertex2d(4,3);
	glVertex2d(5,3);
	glVertex2d(5,0);
	glVertex2d(2,0);
	glVertex2d(2,2);
	glVertex2d(1,2);
	glVertex2d(1,0);
	glVertex2d(0,0);
	glEnd();
}

void Tt::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(4,2);
	glVertex2d(0,2);
	glVertex2d(0,1);
	glVertex2d(4,1);
	glVertex2d(4,0);
	glVertex2d(5,0);
	glEnd();
}

void Uu::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(0,0);
	glVertex2d(0,3);
	glVertex2d(5,3);
	glVertex2d(5,2);
	glVertex2d(1,2);
	glVertex2d(1,1);
	glVertex2d(5,1);
	glVertex2d(5,0);
	glEnd();
}

void Vv::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(0,1);
	glVertex2d(0,2);
	glVertex2d(5,3);
	glVertex2d(5,2);
	glVertex2d(1,1.5);
	glVertex2d(5,1);
	glVertex2d(5,0);
	glEnd();
}

void Ww::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(0,0);
	glVertex2d(0,1);
	glVertex2d(1,1.5);
	glVertex2d(0,2);
	glVertex2d(0,3);
	glVertex2d(5,3);
	glVertex2d(5,2);
	glVertex2d(1.5,2);
	glVertex2d(2.5,1.5);
	glVertex2d(1.5,1);
	glVertex2d(5,1);
	glVertex2d(5,0);
	glEnd();
}

void Xx::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(0,0);
	glVertex2d(1,0);
	glVertex2d(2.5,1);
	glVertex2d(4,0);
	glVertex2d(5,0);
	glVertex2d(3,1.5);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(2.5,2);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(2,1.5);
	glVertex2d(0,0);
	glEnd();
}

void Yy::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(3.5,0);
	glVertex2d(2,1);
	glVertex2d(0,1);
	glVertex2d(0,2);
	glVertex2d(2,2);
	glVertex2d(3.5,3);
	glVertex2d(5,3);
	glVertex2d(3,1.5);
	glVertex2d(5,0);
	glEnd();
}

void Zz::dessine() const
{
	glColor3ub(c.R(), c.G(), c.B());
	glBegin(GL_LINE_STRIP);
	glVertex2d(5,0);
	glVertex2d(5,3);
	glVertex2d(4,3);
	glVertex2d(1,1);
	glVertex2d(1,3);
	glVertex2d(0,3);
	glVertex2d(0,0);
	glVertex2d(1,0);
	glVertex2d(4,2);
	glVertex2d(4,0);
	glVertex2d(5,0);
	glEnd();
}
