#ifndef PRJ_PARTICULE_H		//pour éviter de complier plusieurs fois cette classe...
#define PRJ_PARTICULE_H		//...si par erreur on l'aurait inclu plusieurs fois dans le projet

#include <iostream>			// pour l'affichage
#include "Vecteur.h"
#include "Dessinable.h"

class Particule : public Dessinable		//une Particule est déssinable
{
protected:
    Vecteur position;
	Vecteur vitesse;
	double masse;		//on part du principe qu'une particule ne peut pas gagner de masse (aucune fusion) ni en perdre (aucune fission), si un jour on voudrait modeliser la fission nucleaire par exmple faudra changer ça...
public:
/*______________________Constructeurs___________________________*/
Particule();//constructeur par défaut, initialisant une particule d'hélium immobile a l'origine
Particule(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m); //constructeur pour tout initialiser
Particule(Vecteur const& p, Vecteur const& v, double const& m);	//initialise la position et la vitesse avec un vecteur (constructeur de copie)

/*__________________________Méthodes_____________________________*/
//Accesseurs
Vecteur getPosition() const;
Vecteur getVitesse() const;
double getMasse() const;
void setVitesse(Vecteur const& v);	//setter pour la vitesse, aucun pour la position, qui sera MAJ dans evolue

//Afficher
std::ostream& afficheParticule(std::ostream& sortie = std::cout) const;

//Energie cinétique
double Ecin() const;

//Quantité de mouvement
Vecteur quantite_mvt() const;

virtual void evolue(double const& dt);		//déplacement MRUA d'une unité de temps (dt)
void mirroir(Vecteur const& n, Vecteur const& p);	//symétrie d'une particule (position et vitesse) par rapport a un plan (p,n)
bool rencontreS(Particule const& autre, double const& epsilon);	//détermine si 2 particule se rencontre, découpage de l'espace en cubes, de dimension epsilon
bool rencontreC(Particule const& autre, double const& epsilon);	//détermine si 2 particule se rencontre, pavage sphérique, unité d'espace epsilon
};


/*______________________Opérateurs Externes_______________________*/
std::ostream& operator<<(std::ostream& sortie, Particule const& p);


#endif //PRJ_PARTICULE_H
