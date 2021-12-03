/*Copyright 2014 Samuel Sekarski and Christine Nguyen */

#include "../include/TXTGaz.h"
#include <iostream>		//pour dessine()
using namespace std;

/*----------------------------------------------------------------------
 *                        classe TXTHelium
 *----------------------------------------------------------------------*/

void TXTHelium::dessine() const
{
	cout << "particule TXTHelium : " << *this << endl;
	/* équivalent a:
	 * cout << "particule TXTArgon : ";
	 * afficheParticule();
	 * */
}

//Constructeur par défaut qui appèle le constructeur par défaut de Particule (qui a été redéfini)
TXTHelium::TXTHelium(){}	//comme on a un constructeur explicite en dessous, il faut le mettre si on veux l'utiliser

//les 3 coordonées de la position, puis les 3 composantes de la vitesse, et pour finir la masse
TXTHelium::TXTHelium(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTHelium::TXTHelium(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}



/*----------------------------------------------------------------------
 *                       classe TXTNeon
 *----------------------------------------------------------------------*/

void TXTNeon::dessine() const
{
	cout << "particule TXTNeon : " << *this << endl;
}

TXTNeon::TXTNeon(double const& m): Particule(0,0,0,0,0,0,m){}	//particule de néon par défaut
//(on met une valeur par défaut plutot qu'une initialisation avec la masse par défaut, au cas ou on aurait différents isotopes de gaz

TXTNeon::TXTNeon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTNeon::TXTNeon(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}


/*----------------------------------------------------------------------
 *                        classe TXTArgon
 *----------------------------------------------------------------------*/

//définition méthode virtuelle
void TXTArgon::dessine() const
{
	cout << "particule TXTArgon : " << *this << endl;
}

TXTArgon::TXTArgon(double const& m): Particule(0,0,0,0,0,0,m){}

TXTArgon::TXTArgon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTArgon::TXTArgon(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}

/*----------------------------------------------------------------------
 *                       classe TXTKrypton
 *----------------------------------------------------------------------*/

void TXTKrypton::dessine() const
{
	cout << "particule TXTKrypton : " << *this << endl;
}

TXTKrypton::TXTKrypton(double const& m): Particule(0,0,0,0,0,0,m){}

TXTKrypton::TXTKrypton(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTKrypton::TXTKrypton(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}


/*----------------------------------------------------------------------
 *                       classe TXTXenon
 *----------------------------------------------------------------------*/

void TXTXenon::dessine() const
{
	cout << "particule TXTXenon : " << *this << endl;
}

TXTXenon::TXTXenon(double const& m): Particule(0,0,0,0,0,0,m){}

TXTXenon::TXTXenon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTXenon::TXTXenon(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}

/*----------------------------------------------------------------------
 *                       classe TXTRadon
 *----------------------------------------------------------------------*/

void TXTRadon::dessine() const
{
	cout << "particule TXTRadon : " << *this << endl;
}

TXTRadon::TXTRadon(double const& m): Particule(0,0,0,0,0,0,m){}

TXTRadon::TXTRadon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m)
:Particule(a,b,c,va,vb,vc,m) {}

TXTRadon::TXTRadon(Vecteur const& p, Vecteur const& v, double const& m):Particule(p,v,m){}
