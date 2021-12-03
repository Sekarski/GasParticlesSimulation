#include "ParticuleP5.h"
using namespace std;

/*______________________Constructeurs___________________________*/
//Constructeur par défaut qui initialise tout à 0
Particule::Particule(): position(0,0,0), vitesse(0,0,0), masse(4.002602) {}
/*remarque: comme le constructeur par défaut des vecteur initialise le vecteur nul, 
on pourrait ommettre position(0,0,0),vitesse(0,0,0).
* Sinon il ne devrait pas être possible d'instancier une particule avec un masse nul,
* nous avons choisi que la particule par défaut serait une particule immobile d'hélium situé a l'origine*/

//Constructeur qui initialise tout
Particule::Particule(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
: position(a, b, c), vitesse(va, vb, vc), masse(m) {}

//Constructeur qui initialise a partir de 2 vecteurs et un double
Particule::Particule(Vecteur const& p, Vecteur const& v, double const& m)
:position(p), vitesse(v), masse(m){}

/*__________________________Méthodes_____________________________*/
//Accesseurs
Vecteur Particule::getPosition() const {return position;}
Vecteur Particule::getVitesse() const {return vitesse;}
double Particule::getMasse() const {return masse;}

//Setters
void Particule::setVitesse(Vecteur const& v)
{
	vitesse =  v;
}

//Energie cinétique
double Particule::Ecin() const {return 0.5*masse*vitesse*vitesse;}

//Quantité de mouvement
Vecteur Particule::quantite_mvt() const {return masse*vitesse;}          // Je peux écrire ça comme ça? (mult scalaire...) <--oui

ostream& Particule::afficheParticule(ostream& sortie) const
{
	sortie << "pos : " << position << " ; v : " << vitesse << " ; m : " << masse;
	return sortie;
}

void Particule::mirroir(Vecteur const& n, Vecteur const& p)	//prend l' "image par mirroir" de la particule, par le plan défini par un vecteur normal, et un vecteur position. On pourrait envisager une classe "Plan"
{
	vitesse = vitesse.sym(n);				//le vecteur libre symétrique par rapport a ce plan
	position = p + (position-p).sym(n);		//l'image de la position par symétrie a ce plan
}

void Particule::evolue(double const& dt)	//déplace la particule selon un MRUA pour un pas de temps dt
{
	position += vitesse * dt;
}

bool Particule::rencontreC(Particule const& autre, double const& epsilon)	//pavage cubique
{
	int ax(position.getX()/epsilon);		//prendre la valeure entière d'un double.
	int bx(autre.position.getX()/epsilon);	//je sais pas s'il y a une meilleure façon de faire
	int ay(position.getY()/epsilon);
	int by(autre.position.getY()/epsilon);	//pas besoin de getPosition() parce qu'on est dans la classe particule
	int az(position.getZ()/epsilon);
	int bz(autre.position.getZ()/epsilon);
	
	if(ax == bx and ay == by and az == bz)
	{return true;}
	else
	{return false;}
}

bool Particule::rencontreS(Particule const& autre, double const& epsilon)	//pavage sphérique
{
	if((position - autre.position).norme_carre() < epsilon*epsilon)		//la version "non carrée" est équivalente mathématiquement, mais niveau optimisation, cette version est meilleur: n'utilise pas 2 fois "norme_carre" et surtout ne calcule pas de "sqrt" ce qui est laborieux pour la machine
	{return true;}
	else
	{return false;}
}

/*______________________Opérateurs Externes_______________________*/
ostream& operator<<(ostream& sortie, Particule const& p)
{
	return p.afficheParticule(sortie);
}
