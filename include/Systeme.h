#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H
#include <iostream>
#include <vector>			//pour la collection de particules
#include <list>				//pour la liste de particule par cases, on a choisi d'utiliser list plutot que vector, car de tout façon on ne fait jamais d'accès direct au element, et de plus on peut suprimier un particule n'importe ou a d'intérieure.
#include "Dessinable.h"		//le systeme EST déssinable (héritage)
#include "Particule.h"		//le systeme A des particules (attribut)
#include "Enceinte.h"		//le systeme A une enceinte (attribut)
#include "GenerateurAleatoire.h"	//Pour les trucs aléatoires
#include "Vecteur.h"	//pour les tirage aleatoire de vecteurs


//pour simplifier quelques typdefs
typedef std::list<Particule*> lvl1;
typedef std::vector<lvl1> lvl2;
typedef std::vector<lvl2> lvl3;
typedef std::vector<lvl3> lvl4;


class Systeme: public Dessinable
{
private:
//______________________Attributs_________________________
	std::vector<Particule*> collection;		//collection hétérogène, on veut donc une résolution dynamique => pointeurs
	Enceinte* enceinte;						//pour une résolutoin dynamique
	lvl4 cases;							//échantillonage de l'espace en "cases"
	GenerateurAleatoire tirage;			//Pour les trucs aléatoire
	double temp;						//température du Système
	
//_________________Methodes Privées_______________________	
	Systeme(Systeme const& sys) = delete;			//on veut éviter de faire des copies de tout le systeme
	void operator=(Systeme const& sys) = delete;	//idem, on ne veut pas copier un systeme dans un autre
	
	void gerer_choc();														//gère les chocs entres les particules
	void gerer_choc(std::ostream& sortie);									//idem mais surchargé pour l'affichage	
	void gerer_rebond(unsigned int const& index);							//gère les rebonds contre les parois
	void gerer_rebond(unsigned int const& index, std::ostream& sortie);		//idem mais surchargé pour l'affichage
	void gerer_choc_vieux(double const& epsilon);							//1er modèle de gestion des chocs
	void gerer_choc_vieux(double const& epsilon, std::ostream& sortie);		//idem mais surchargé pour l'affichage
	void remplir_cases();								//ajoute des pointeurs sur les particules dans la cases qu'elle appartient
	void choc(Particule& p1, Particule& p2);			//met a jour la particule quand il y a un choc
	void choc_truque(Particule& p1, Particule& p2);		//idem, mais avec l'aléatoire "controlé"
	bool EstDedans(Particule const& p, Enceinte const& e) const;
	
public:
	Systeme(Enceinte* const& e, double const& t = 298);
	Systeme(Enceinte* const& e, unsigned int const& g, double const& t);	//Pour débugger on passe la graine du générateuraléatoire en paramètre
	void dessine() const;					//redéfinition de la methode dessine: fait appel au methodes "dessine" de chaque particule
	void ajouter_particule(Particule* p);	//ajoute une particule au systeme via un pointeur
	void supprimer_particule();				//désalloue tout les pointeurs de "collection"
	~Systeme();								//destructeur faisant appel a la méthode supprimer_particule()
	void evolue_vieux(double const& dt, double const& epsilon);							//evolue avec le modèle 1 de collision
	void evolue_vieux(double const& dt, double const& epsilon, std::ostream& sortie);	//idem mais avec affichage
	void evolue(double const& dt);								//fait évoluer tout le Systeme (modèle 2
	void evolue(double const& dt, std::ostream& sortie);		//idem mais avec affichage
	unsigned int collection_size() const;		//plus facil que de faire un accesseur pour la collection de pointeur
	GenerateurAleatoire* getTir();				//si on ne fait pas un pointeur pour se getters on n'aura pas l'effet voulu
	Enceinte* getEnceinte() const;				//on a fait une valeur de retour pointeur, car l'attribut est un pointeur
	double getTemp() const;						//accesseur pour la température
	Vecteur tirer_vitesse(double const& k);				//tire une vitesse aléatoire selon la méthode gaussienne
	Vecteur tirer_position();							//tire une position aléatoire entre les paroi de l'enceinte
	Particule* getParticule();		//en fait c'est juste pour accèder a une particule pour lui "attacher la caméra"

};
#endif
