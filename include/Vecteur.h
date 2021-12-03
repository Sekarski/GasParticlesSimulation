#ifndef PRJ_VECTEUR_H		//trucs a mettre dans les .h
#define PRJ_VECTEUR_H		// pour éviter des redondances

#include <iostream>		//Pur l'affichage

class Vecteur
{
protected:
	double x;		//on a choisi que ces 3 double serait les composantes...
	double y;		//... du vecteur de R3 dans un repère cartésien.
	double z;
	
public:
/*_______________________Constructeurs_____________________*/
	Vecteur();		//initialise le vecteur null
	Vecteur(double const& a, double const& b, double const& c);
	
/*________________________Méthodes_________________________*/
	void setVecteur(double const& a, double const& b, double const& c);
	double getX() const;
	double getY() const;
	double getZ() const;
	void getVecteur(double& a, double& b, double& c) const;	//une autre façon de faire un get
	std::ostream& affiche(std::ostream& sortie = std::cout) const;		//la valeur par défaut "cout" permet d'utilier .affiche() comme avant (P1). (mais utilisons "<<" de préférence maintenant)
	bool compare(Vecteur const& v) const;						//renvoie "true" s'il y a égalité
	Vecteur oppose() const;								//calcule l'opposé du vecteur, ie: -1*vecteur
	double prod_scal(Vecteur const& autre) const;		//
	double norme_carre() const;							//calcule le carré de la norme (optimisation: évite le sqrt() )
	double norme() const;
	Vecteur sym(Vecteur const& normal) const;			//Construit le vecteur (libre) symétrique par rapport a un plan. Prend le vecteur normal au plan en paramètre
	
/*____________________Opérateur Internes____________________*/
	const Vecteur operator-() const;
	const Vecteur& operator+=(Vecteur const& v2);		//opérateurs d'auto afféctation: modifie le vecteur, aucune copie
	const Vecteur& operator-=(Vecteur const& v2);
	const Vecteur& operator*=(double const& k);			//multiplication scalaire
	const Vecteur& operator^=(Vecteur const& v2);		//produit vectoriel
};

/*____________________Opérateur Externes___________________*/
	std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);			//format d'affichage: (x ,y ,z)
	bool operator==(Vecteur const& v1, Vecteur const& v2);			//test l'égalité via l'opérateur "=="
	bool operator!=(Vecteur const& v1, Vecteur const& v2);			//test l'inégalité ... par "!="
	const Vecteur operator+(Vecteur v1, Vecteur const& v2);
	const Vecteur operator-(Vecteur v1, Vecteur const& v2);			//opérateur standard (pour les vecteur): ne modifie aucun vecteur, mais crée un nouveau vecteur
	const Vecteur operator*(Vecteur v, double const& k);
	const Vecteur operator*(double const& k, Vecteur v);			//commutativité de la multiplication scalaire
	const double operator*(Vecteur const& v1, Vecteur const& v2);
	const Vecteur operator^(Vecteur v1, Vecteur const& v2);			//produit vectoriel. /!\ il faut mettre les () a chaque fois qu'on cet opérateur /!\ par exemple: v=(v1^v2) au lieu de v=v1^v2 a cause de la priorité des opérations

#endif // PRJ_VECTEUR_H
