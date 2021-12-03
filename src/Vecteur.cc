 /* copyright 2014 Samuel Sekarski and Christine Nguyen */
 
 /*Chères correcteurs, on vous souhaite bonne chance, et pour vous soutenir
  * dans vos corrections, on a mis quelques petites ASCII arts parci parlà.
  * Aussi on s'excuse d'avance pour les fautes d'orthogrphes :S */
 
 /*#############################################################################################
 * #############################################################################################
 * ########      ####  ##  ####      ####      ####      ##########  ##  ####      ######  #####
 * ########  ########  ##  ####  ########  ########  ##  ##########  ##  ####  ##  ######  #####
 * ########  ########      ####    ######    ######      ##########  ##  ####      ######  #####
 * ########  ########  ##  ####  ########  ########  #  ###########  ##  ####  #################
 * ########      ####  ##  ####      ####      ####  ##  ##########      ####  ##########  #####
 * #############################################################################################
 * ############################################################################################# */

 
#include "../include/Vecteur.h"	//comme on a séparé nos fichier en sous dossier
#include <cmath>		// pour la racine carrée	
using namespace std;	//apparament on a le droit de le mettre dans le .cc, il faut juste pas le mettre dans le .h
  
/*_______________________Constructeurs_____________________*/

//Constructeur par défaut qui crée le vecteur nul
Vecteur::Vecteur(): x(0), y(0), z(0) {}

//Constructeur pour initialiser explicitement
Vecteur::Vecteur(double const& a, double const& b, double const& c): x(a), y(b), z(c) {}

/*__________________________méthodes_______________________*/

//afficher le vecteur en entier
ostream& Vecteur::affiche(ostream& sortie) const 				//dans le prototype il y a la valeur par défaut "cout" ...
{																//... ce qui permet d'utiliser .affiche() comme avant. Même si "<<" est maintenant une meilleure solution
	sortie << "(" << x << " " << y << " " << z << ")";			//format de sortie: (x y z)
	return sortie;												//le renvoie du flot est utile pour la surcharge de l'opérateur "<<"
}

//modifier vecteur
void Vecteur::setVecteur(double const& a, double const& b, double const& c) 
{
	x = a;
	y = b;
	z = c;
}

//prendre le vecteur
void Vecteur::getVecteur(double& a, double& b, double& c) const 
{
	a = x;
	b = y;
	c = z;
}

//getteres standards
double Vecteur::getX() const{return x;}
double Vecteur::getY() const{return y;}
double Vecteur::getZ() const{return z;}

//comparer avec un autre vecteur
bool Vecteur::compare(Vecteur const& v2) const 
{
	return x == v2.x and y == v2.y and z == v2.z;				//retourne "true" si les vecteur sont les mêmes	
}	

//retourne le vecteur opposé, ie: -1*Vecteur
Vecteur Vecteur::oppose() const
{
	return Vecteur(-x, -y, -z);
}

//calcule le produit scalaire
double Vecteur::prod_scal(Vecteur const& autre) const
{
	return x*autre.x + y*autre.y + z*autre.z;	//on est dans la même classe donc autre.x est possible
}

//calcule la norme au carré du vecteur
/* cette methode est plus rapide que de faire
 * norm()*norm() (cf. ci-dessous) car il n'y a pas
 * a calculer la racine carrée sqrt(). */
double Vecteur::norme_carre() const
{
	return x*x + y*y + z*z;	//alternativement on aurait pu faire return prod_scal(*this);
}

//calcule la norme du vecteur (nécessite <cmath>)
double Vecteur::norme() const
{
	return sqrt(norme_carre());
}

//symétrie par rapport a un plan
Vecteur Vecteur::sym(Vecteur const& normal) const
{
	return *this - (2*(((*this)* normal)/normal.norme_carre())*normal);	//cf. Formulaire CRM
}																		//on a utiliser nos opérateurs surchargé

/*_____________________Opérateurs internes____________________*/

//addition vectorielle (auto afféctation)
const Vecteur& Vecteur::operator+=(Vecteur const& v2)
{																//modifie le 1er vecteur...
	x += v2.x;													//...en lui donnant les valeurs...
	y += v2.y;													//...de la somme des 2 vecteurs.
	z += v2.z;
	return *this;												//renvoie aussi la somme, ce qui permet d'utiliser (v1+=v2) comme une expression...
}																//...par exemple pour ecrire des trucs comme v = (v1+=v2)

//soustraction vectorielle (auto afféctation)
const Vecteur& Vecteur::operator-=(Vecteur const& v2)
{
	x -= v2.x;							//même principe que lôpérateur +=
	y -= v2.y;
	z -= v2.z;
	return *this;
}

//opposé
const Vecteur Vecteur::operator-() const
{
	return oppose();
}

//multiplication scalaire (auto afféctation)
const Vecteur& Vecteur::operator*=(double const& k)
{
	x *= k;
	y *= k;
	z *= k;
	return *this;
}

//produit vectorielle (auto affécatation)
const Vecteur& Vecteur::operator^=(Vecteur const& v2)
{
	double a = y*v2.z - z*v2.y;							//ici il faut passer par des variables intermédiaire, car...
	double b = -(x*v2.z - z*v2.x);						//...on a modifié x a la ligne précédente, du coup le calcule est faux 
	z = x*v2.y - y*v2.x;
	y = b;
	x = a;	
	return *this;
}

/*_____________________Opérateurs externes______________________*/

// permet d'afficher des vecteurs avec "<<"
ostream& operator<<(ostream& sortie, Vecteur const& v)			//le type de retour permet l'utilisation de "<<" plusieur fois a la suite
{
	return v.affiche(sortie);									//format de sortie: (x y z)
}

//permet de comparer directement 2 vecteurs avec == sans passer par .compare()
bool operator==(Vecteur const& v1, Vecteur const& v2)
{
	return v1.compare(v2);
}

//décide de la différence ou non de 2 vecteurs
bool operator!=(Vecteur const& v1, Vecteur const& v2)
{
	return !(v1 == v2);											//l'inverse de "=="
}

//addition vectorielle
const Vecteur operator+(Vecteur v1, Vecteur const& v2)			//optimisation c++2011: le 1er param passé par valeur, le 2eme par référence constante
{
	return v1 += v2;											//retourne un nouveau vecteur, ne modifie pas le 1er
}

//soustraction vectorielle
const Vecteur operator-(Vecteur v1, Vecteur const& v2)			//idem
{
	return v1 -= v2;											//toujours la même chose
}

//multiplication scalaire k*v
const Vecteur operator*(Vecteur v, double const& k)
{
	return v *= k;
}

//multiplication scalaire v*k
const Vecteur operator*(double const& k, Vecteur v)				//commutativité de la multiplication scalaire
{
	return v *= k;
}

//produit scalaire
const double operator*(Vecteur const& v1, Vecteur const& v2)
{
	return v1.prod_scal(v2);
}

//produit vectorielle
const Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
	return v1 ^= v2;
}
/*Pour utiliser cet opérateur il faut mettre des (), ie: (v1^v2),
 * apparament c'est du a la priorité des opération */
