#include "../include/GlGaz.h"

/*#######################################################################
 *                        classe GlHelium
 *#######################################################################*/

void GlHelium::dessine() const
{
		// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(0.0, 1.0, 0.0, 1.0); // Choisir la couleur (vert ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 1.4/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

//Constructeur par défaut qui appèle le constructeur par défaut de Particule (qui a été redéfini)
GlHelium::GlHelium(): sphere(gluNewQuadric()){}	//comme on a un constructeur explicite en dessous, il faut le mettre si on veux l'utiliser
GlHelium::~GlHelium(){gluDeleteQuadric(sphere);}
//les 3 coordonées de la position, puis les 3 composantes de la vitesse, et pour finir la masse
GlHelium::GlHelium(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}

GlHelium::GlHelium(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()){}

void GlHelium::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}

/*#######################################################################
 *                       classe GlNeon
 *#######################################################################*/

void GlNeon::dessine() const
{
		// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(0.0, 0.0, 1.0, 1.0); // Choisir la couleur (bleu ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 1.54/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

GlNeon::GlNeon():sphere(gluNewQuadric()){}
GlNeon::~GlNeon(){gluDeleteQuadric(sphere);}
GlNeon::GlNeon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}
GlNeon::GlNeon(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()){}

void GlNeon::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}
/*#######################################################################
 *                        classe GlArgon
 *#######################################################################*/

//définition méthode virtuelle
void GlArgon::dessine() const
{
	// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(1.0, 0.0, 0.0, 1.0); // Choisir la couleur (rouge ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 1.88/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

GlArgon::GlArgon():sphere(gluNewQuadric()){}
GlArgon::~GlArgon(){gluDeleteQuadric(sphere);}
GlArgon::GlArgon(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()) {}
GlArgon::GlArgon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}

void GlArgon::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}

/*#######################################################################
 *                        classe GlKrypton
 *#######################################################################*/

//définition méthode virtuelle
void GlKrypton::dessine() const
{
	// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(1.0, 1.0, 0.0, 1.0); // Choisir la couleur (jaune ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 2.02/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

GlKrypton::GlKrypton():sphere(gluNewQuadric()){}
GlKrypton::~GlKrypton(){gluDeleteQuadric(sphere);}
GlKrypton::GlKrypton(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()) {}
GlKrypton::GlKrypton(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}

void GlKrypton::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}

/*#######################################################################
 *                        classe GlXenon
 *#######################################################################*/
 
//définition méthode virtuelle
void GlXenon::dessine() const
{
	// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(1.0, 0.0, 1.0, 1.0); // Choisir la couleur (violet ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 2.16/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

GlXenon::GlXenon():sphere(gluNewQuadric()){}
GlXenon::~GlXenon(){gluDeleteQuadric(sphere);}
GlXenon::GlXenon(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()) {}
GlXenon::GlXenon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}

void GlXenon::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}

/*#######################################################################
 *                        classe GlRadon
 *#######################################################################*/

//définition méthode virtuelle
void GlRadon::dessine() const
{
	// dessin de la première sphère
  glPushMatrix();                // Sauvegarder l'endroit où l'on se trouve
  glTranslated(position.getX(), position.getY(), position.getZ());  /* Se positionner à l'endroit où l'on veut
				  * dessiner                                */
  glColor4d(0.0, 1.0, 1.0, 1.0); // Choisir la couleur (bleu cliel ici)
  gluQuadricDrawStyle(sphere, GLU_LINE);
  gluSphere(sphere, 2.20/4.0, 15, 15);// Dessiner une sphère
  glPopMatrix(); 
  
  if(taille > 0){Tracable::trace();}
}

GlRadon::GlRadon():sphere(gluNewQuadric()){}
GlRadon::~GlRadon(){gluDeleteQuadric(sphere);}
GlRadon::GlRadon(Vecteur const& p, Vecteur const& v, unsigned int const& t, double const& m):Particule(p,v,m), Tracable(t), sphere(gluNewQuadric()) {}
GlRadon::GlRadon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t, double const& m)
:Particule(a,b,c,va,vb,vc,m), Tracable(t), sphere(gluNewQuadric()) {}

void GlRadon::evolue(double const& dt)
{
	if(taille > 0){ajouter(position);}
	Particule::evolue(dt);
}
