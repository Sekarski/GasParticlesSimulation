#ifndef PRJ_ENCEINTE_H		//pour éviter de complier plusieurs fois cette classe...
#define PRJ_ENCEINTE_H		//...si par erreur on l'aurait inclu plusieurs fois dans le projet

#include "Dessinable.h"

class Enceinte: public Dessinable	//une enceint est dessinable
{
protected:
double hauteur;
double largeur;
double profondeur;

public:
/*_______________________Constructeurs________________________*/
Enceinte(); 		//Constructeur par défaut
Enceinte(double const& h, double const& l, double const& p); //initialiser
virtual ~Enceinte();			//en virtual car héritage
double getHauteur() const;		
double getLargeur() const;
double getProfondeur() const;
void setHauteur(double const& h);		//Les paroi sont mobiles
void setLargeur(double const& l);
void setProfondeur(double const& p);

/*__________________________Méthodes__________________________*/
double volume() const;		//peut etre utile pour collecter des informations
};

#endif // PRJ_ENCEINTE_H
