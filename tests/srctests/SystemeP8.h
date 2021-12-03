#ifndef PRJ_SYSTEMEP9_H
#define PRJ_SYSTEMEP9_H
#include <iostream>
#include <vector>			//pour la collection de particules
#include "../../include/Dessinable.h"		//le systeme EST déssinable (héritage)
#include "../../include/Particule.h"		//le systeme A des particules (attribut)
#include "EnceinteP6.h"		//le systeme A une enceinte (attribut)
#include "../../include/Vecteur.h"	//pour les tirage aleatoire de vecteurs

class Systeme: public Dessinable
{
private:
//______________________Attributs_________________________
	std::vector<Particule*> collection;		//collection hétérogène, on veut donc une résolution dynamique => pointeurs
	Enceinte enceinte;

//_________________Methodes Privées_______________________	
	Systeme(Systeme const& sys) = delete;			//on veut éviter de faire des copies de tout le systeme
	void operator=(Systeme const& sys) = delete;	//idem, on ne veut pas copier un systeme dans un autre
	
public:
	Systeme();								//constructeur par défaut, initialisant la collection a vide, et une enceinte par défaut
	Systeme(unsigned int const& x, unsigned int const& y, unsigned int const& z);	//initialise la collection a vide, mais crée une enceinte de dimension xyz
	void dessine() const;					//redéfinition de la methode dessine: fait appel au methodes "dessine" de chaque particule
	void ajouter_particule(Particule* p);	//ajoute une particule au systeme via un pointeur
	void supprimer_particule();				//désalloue tout les pointeurs de "collection" et vide le tableau
	~Systeme();								//destructeur faisant appel a la méthode supprimer_particule()

};

#endif	//PRJ_SYSTEMEP9_H
