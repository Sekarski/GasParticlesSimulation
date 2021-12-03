/*Copyright 2013 Christine Nguyen and Samuel Sekarski */

/*
Quelle mélodie suis-je ?
   _ 
  / \                                               
  |  | ___##____________________________________________________________________________________________________/@\__
  | /     ##                             |                          |   /@\                |     _        /@\  |\@/  | 
  |/   ______________|____/@\°_______|\__|__________/@\°______/@\___|__|\@/____/@\_________|____/ \______|\@/__|_____| 
 /|                  |   |\@/        |   |     |   |\@/      |\@/   |  |      |\@/    /@\  |   |\_/      |     |     | 
/ |_   _______3______|___|___________|___|_____|___|_________|______|__|______|______|\@/__|___|_________|_____|_____| 
| / \         4      |   |           |   |     |   |         |      |  |      |      |     |   |         |_____|     | 
| |  | ___________/@\|___|________/@\|___|_____|___|_________|______|__|______|______|_____|___|_____________________| 
\___/             \@/    |        \@/    |  /@\|   |         |/     |         |      |     |   |                     | 
  |    __________________________________|__\@/_____________________|________________|_____|_________________________| 
  | 
\_/
   _ 
  / \          /@\                             /@\        
  |  | ___##__|\@/____/@\_____________________|\@/___________________________________________________________________
  | /     ##  |      |\@/    /@\   |          |        ______   |          /@\      ______   |     |                 | 
  |/   _______|______|______|\@/___|____/@\___|_______|______|__|_________|\@/_____|______|__|_____|_________________| 
 /|           |      |      |      |   |\@/   |       |      |  |         |        |      |  |     |                 | 
/ |_   _______|______|______|______|___|______|_______|______|__|__/@\°___|_____/@\|______|__|_____|_________________|  
| / \                |      |      |   |              |   /@\|  | |\@/    |     \@/       |  |  / \|                 | 
| |  | _____________________|______|___|___________/@\|___\@/___|_|_______|/___________/@\|__|__\_/ °________________| 
\___/                              |   |           \@/          | |                    \@/   |                       | 
  |    ____________________________|____________________________|_|__________________________|_______________________| 
  |                                                               | 
\_/

j'ai commencé.
*/ 

#include "../include/Systeme.h"
#include <cmath>
using namespace std;


//Constructeur
Systeme::Systeme(Enceinte* const& e, double const& t): enceinte(e), cases(e->getProfondeur(), lvl3(e->getLargeur(), lvl2(e->getHauteur(), lvl1()))), temp(t) {}
/*comme ça on peut donné au systeme une "glenceinte" qui est une sous classe d'enceinte avec un fonction dessine graphique.
 * a noter que e et enceinte pointent maintenant tous les 2 sur la même enceinte, ce qui implique quelque précaution si on passe
 * l'adresse d'une enceinte qui existe déjà: si on fait un delete sur un des 2, l'autre ne pourra plus accéder a l'enceinte non plus !
 * aussi on ne vérifie pas que le pointeur est non nul :(
 * Il faut donc allouer dynamiquement directement dans le constructeur: Systeme( New enceinte).
 * c'est donc a l'utilisateur de systeme de faire attention :(
 * Une copie profonde pourrait être justifié ici ?*/
 
//Constructeur pour débugger
Systeme::Systeme(Enceinte* const& e, unsigned int const& g, double const& t): enceinte(e), tirage(g), cases(e->getProfondeur(), lvl3(e->getLargeur(), lvl2(e->getHauteur(), lvl1()))), temp(t){}

//Accesseurs
double Systeme::getTemp() const {return temp;}
Enceinte* Systeme::getEnceinte() const {return enceinte;}
GenerateurAleatoire* Systeme::getTir() {return &tirage;}

//Redéfinition de la methode dessine() de "déssinable"
void Systeme::dessine() const
{	
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->dessine();		//appel a la fonction dessine de chaque particule
	}
	enceinte->dessine();
}

unsigned int Systeme::collection_size() const	//plus facile que de faire un getteur pour collection
{
	return collection.size();
}


//Ajoute une particule au systeme. Concrétement ajoute un pointeur vers une particule au tableau "collection"
void Systeme::ajouter_particule(Particule* p)
{
	if(p !=nullptr)	//on vérifie que le pointeur pointe bien vers quelquechose
	{
		collection.push_back(p);
	}
	
}

//supprime toutes les particules du systeme
void Systeme::supprimer_particule()				//note: si on décide de mettre des unique_prt, cette methode sera plus simple
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		delete collection[i];		//désaloue la mêmoire de chaque pointeur (ie le truc pointé)...
		collection[i] = nullptr;	//...le pointeur point maintenant vers nullptr...
	}
}

/*destructeur faisant appel a la méthode ci-dessus,
 * au cas ou on aurait oublié de faire appel explicitement
 * a la methode ci-dessus, pour bien libérer la mémoire.
 * ou si on a la flemme d'écrire une ligne de code :D
 */
Systeme::~Systeme()
{
	supprimer_particule();
	delete enceinte;	//suprime l'enceinte allouée dynamiquement
	enceinte = nullptr;
}

//Evolue Modèle 2
void Systeme::evolue(double const& dt)
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->evolue(dt);		//déplacement de la particule pour un pas de temps dt
		gerer_rebond(i);				//fait "rebondir" les particules contre les paroi si nécessaire
	}
	remplir_cases();		//rempli les cases de l'espace
	gerer_choc();			//détermine s'il y a des choc entre particule a faire, et si c'est le cas les fait. puis vide les cases
}

//idem mais pour l'affichage dans le terminal
void Systeme::evolue(double const& dt, ostream& sortie)
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->evolue(dt);
		gerer_rebond(i, sortie);
	}
	remplir_cases();
	gerer_choc(sortie);
}

//Evolue modèle 1
void Systeme::evolue_vieux(double const& dt, double const& epsilon)
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->evolue(dt);		//déplace la particule d'un MRUA
		gerer_rebond(i);				//si la particule a dépassé les parois de l'enceinte, on mais une symétrie pour la remetre dedans
	}
	gerer_choc_vieux(epsilon);		//détermine si 2 particules sont epsilon proches, et le cas écheant fait le choc
}

//idem pour pour le terminal
void Systeme::evolue_vieux(double const& dt, double const& epsilon, ostream& sortie)
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->evolue(dt);
		gerer_rebond(i, sortie);
	}
	gerer_choc_vieux(epsilon, sortie);
}


//fait rebondir les particules contre les parois de l'enceinte
void Systeme::gerer_rebond(unsigned int const& i)		//on passe l'index de la collection en indice
{
	//Note to Self: Pas très élégent ce qui suit, faut que je cherche a simplifier
	
	/* en gros, si une particule est allé trop loin, c'est qu'elle aurait du rebondir contre 
	 * une parois, donc on prend la symétrie de la particule par rapport a la paroi.
	 * Il y a un problème quand le pas de temps est trop grand pour une enceinte trop petit:
	 * Si la particule a euh le temps d'aller en dehors de l'enceinte de plusieur longeur
	 * d'enceinte, alors il y aura grand maximum 2 symétrie avec l'implémentation actuelle
	 * du coup, il se peut que la particule soit toujours en dehors de l'enceinte après
	 * avoir gérer les rebonds :( ce qui n'est pas voulu, et produit un segmentation fault
	 * dès que la particule quitte l'espace échantilloné... Pour remédier a cela il faudrait 
	 * faire des boucles, genre do...while(la particule not a l'intérieur de l'enceinte).
	 * Si on a le temps on corrigera ceci, en attendant dans le projet final on a mis les bornes
	 * du pas de temps de tel sorte que le pas de temps ne soit jamais trop grand pour une
	 * enceinte trop petite.*/
	 //c'est fait ! :D
	 do{
	if(collection[i]->getPosition().getX() > enceinte->getProfondeur())
		{
			collection[i]->mirroir(Vecteur(1.0,0.0,0.0),Vecteur(enceinte->getProfondeur(), 0.0,0.0));
		}		// on pensait peut etre faire une classe plan
		
		if(collection[i]->getPosition().getX() < 0.0)
		{
			collection[i]->mirroir(Vecteur(1.0,0.0,0.0),Vecteur(0.0,0.0,0.0));
		}
		
		if(collection[i]->getPosition().getY() > enceinte->getLargeur())
		{
			collection[i]->mirroir(Vecteur(0.0,1.0,0.0),Vecteur(0.0, enceinte->getLargeur(),0.0));
		}
		
		if(collection[i]->getPosition().getY() < 0.0)
		{
			collection[i]->mirroir(Vecteur(0.0,1.0,0.0),Vecteur(0.0,0.0,0.0));
		}
		
		if(collection[i]->getPosition().getZ() > enceinte->getHauteur())
		{
			collection[i]->mirroir(Vecteur(0.0,0.0,1.0),Vecteur(0.0, 0.0, enceinte->getHauteur()));
		}
		
		if(collection[i]->getPosition().getZ() < 0.0)
		{
			collection[i]->mirroir(Vecteur(0.0,0.0,1.0),Vecteur(0.0,0.0,0.0));
		}	
	}while(not EstDedans(*collection[i], *enceinte));	//répéter tant que la particule n'est pas "revenu" dans l'enceinte
}

bool Systeme::EstDedans(Particule const& p, Enceinte const& e) const	// test si la une particule est a l'intérieure d'un enceinte
{
	return p.getPosition().getX() < e.getProfondeur()	// dès que un est faux, renvoie false
		and p.getPosition().getX() > 0.0
		and p.getPosition().getY() < e.getLargeur()
		and p.getPosition().getY() > 0.0
		and p.getPosition().getZ() < e.getHauteur()
		and p.getPosition().getZ() > 0.0;
}


//idem mais avec affichage sur le terminal ( ou dans un ficher, ou n'importe quel flot de sortie)
void Systeme::gerer_rebond(unsigned int const& i, ostream& sortie)
{
	//Note to Self: Pas très élégent ce qui suit, faudra que je cherche a simplifier
	do{
	if(collection[i]->getPosition().getX() > enceinte->getProfondeur())
		{
			sortie << "La particule " << i+1 << " rebondit sur la face 2" << endl;
			collection[i]->mirroir(Vecteur(1.0,0.0,0.0),Vecteur(enceinte->getProfondeur(), 0.0,0.0));
		}
		
		if(collection[i]->getPosition().getX() < 0.0)
		{
			sortie << "La particule " << i+1 << " rebondit sur la face 1" << endl;
			collection[i]->mirroir(Vecteur(1.0,0.0,0.0),Vecteur(0.0,0.0,0.0));
		}
		
		if(collection[i]->getPosition().getY() > enceinte->getLargeur())
		{
			sortie << "La particule " << i+1 << " rebondit sur la face 4" << endl;
			collection[i]->mirroir(Vecteur(0.0,1.0,0.0),Vecteur(0.0, enceinte->getLargeur(),0.0));
		}
		
		if(collection[i]->getPosition().getY() < 0.0)
		{
			sortie << "La particule " << i+1 << " rebondit sur la face 3" << endl;
			collection[i]->mirroir(Vecteur(0.0,1.0,0.0),Vecteur(0.0,0.0,0.0));
		}
		
		if(collection[i]->getPosition().getZ() > enceinte->getHauteur())
		{
			sortie << "La particule " << i+1 << " rebondit sur la face 6" << endl;
			collection[i]->mirroir(Vecteur(0.0,0.0,1.0),Vecteur(0.0, 0.0, enceinte->getHauteur()));
		}
		
		if(collection[i]->getPosition().getZ() < 0.0)
		{
			sortie << "La particule " << i+1 <<  " rebondit sur la face 5" << endl;
			collection[i]->mirroir(Vecteur(0.0,0.0,1.0),Vecteur(0.0,0.0,0.0));
		}	
	}while( not EstDedans(*collection[i], *enceinte));
}


//1er modèle de choc
void Systeme::gerer_choc_vieux(double const& epsilon)	//pour un pas d'espace epsilon
{
	for(unsigned int i=0; i<collection.size(); ++i)	//Pour chaque particule on regarde si les autre sont en situation de choc
	{
		for(unsigned int j=i+1; j<collection.size(); ++j)	//il n'est pas nécessaire de tester les case déjà test d'ou je j=i+1
		{
			if(collection[i]->rencontreC(*collection[j],epsilon))	//rencontreC pour le pavage cubique, rencontreS pour le pavage sphérique
			{
				choc((*collection[i]), (*collection[j]));	//a remplacer par "choc_truque" pour débugger
			}
		}
	}
}

//idem mais textuellement
void Systeme::gerer_choc_vieux(double const& epsilon, ostream& sortie)
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		for(unsigned int j=i+1; j<collection.size(); ++j)
		{
			if(collection[i]->rencontreC(*collection[j],epsilon))
			{
				sortie << "particule " << i+1 << " rencontre " << j+1 << endl << endl;
				sortie << "Avant le choc" << endl;
				sortie << "	" << *collection[i] << endl;
				sortie << "	" << *collection[j] << endl;
				choc((*collection[i]), (*collection[j]));	//a remplacer par "choc_truque" pour débugger
				sortie << endl << "Après le choc" << endl;
				sortie << "	" << *collection[i] << endl;
				sortie << "	" << *collection[j] << endl << endl;
			}
		}
	}
}


//Met a jour deux particules en état de choc
void Systeme::choc(Particule& p1, Particule& p2)	//Faudrait essayer de mettre ces 2 méthodes dans particule plutot... nan ?
{	//cf. moodle pour les calcules. J'ai fait plein de variables intermédiaire pour améliorer la compréhension.
	Vecteur vg((p1.getMasse()/(p1.getMasse()+p2.getMasse()))*p1.getVitesse() + (p2.getMasse()/(p1.getMasse()+p2.getMasse()))*p2.getVitesse());
	double L = (p1.getVitesse()-vg).norme();
	double z = tirage.uniforme(-L,L);
	double r = sqrt(L*L-z*z);
	double phi = tirage.uniforme(0, 2*M_PI);
	Vecteur v0(r*cos(phi), r*sin(phi), z);
	Vecteur v1p(vg-v0);		//dans la consigned c'est - ici et + après, mais pour que ça marche comme dans l'exemple faut faire le contraire...ya une faute quelquepart
	Vecteur v2p(vg+p1.getMasse()/p2.getMasse()*v0);
	p1.setVitesse(v1p);
	p2.setVitesse(v2p);
}

//choc truqué pour débugger
void Systeme::choc_truque(Particule& p1, Particule& p2)		//choc truqué (non aléatoire) pour débugger
{
	Vecteur vg((p1.getMasse()/(p1.getMasse()+p2.getMasse()))*p1.getVitesse() + (p2.getMasse()/(p1.getMasse()+p2.getMasse()))*p2.getVitesse());
	double L((p1.getVitesse()-vg).norme());
	Vecteur v0(0.5*L, 0.86603*L, 0);
	Vecteur v1p(vg-v0);		//+ ou - ici ?
	Vecteur v2p(vg+(p1.getMasse()/p2.getMasse())*v0);		//+ ou - ici ?
	p1.setVitesse(v1p);
	p2.setVitesse(v2p);
}

Vecteur Systeme::tirer_position()		//renvoie une position aléatoire entre les paroi de l'enceinte
{
	return Vecteur
	(
	tirage.uniforme(0.0, enceinte->getProfondeur()),
	tirage.uniforme(0.0, enceinte->getLargeur()),
	tirage.uniforme(0.0, enceinte->getHauteur())
	);
}

Vecteur Systeme::tirer_vitesse(double const& k)		//renvoie une vitesse aléatoire (de façon gausienne) en fonction de la constant spécifique
{
	return Vecteur
	(
	tirage.gaussienne(0.0, sqrt(k*temp)),
	tirage.gaussienne(0.0, sqrt(k*temp)),
	tirage.gaussienne(0.0, sqrt(k*temp))
	);
}

void Systeme::remplir_cases()		//rempli la liste de particule qu'a chaque cases
{
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		cases
		[collection[i]->getPosition().getX()]
		[collection[i]->getPosition().getY()]
		[collection[i]->getPosition().getZ()]
		.push_back(collection[i]);
	}
}

//Gestion des chocs entre particules
void Systeme::gerer_choc()
{
	list<Particule*>::iterator par;		//iterateur pour parcourir la liste
	for(unsigned int i=0; i<collection.size(); ++i)	//évite de devoir accéder a toutes les cases vides (~10^6 cases pour 10^3 particule), on regarde seulement celle dans lesquels il y a une particule
	{
		int x(collection[i]->getPosition().getX());		//pour plus de lisibilité on fait ces 3 variables intermédiaires
		int y(collection[i]->getPosition().getY());
		int z(collection[i]->getPosition().getZ());	
		for(par = cases[x][y][z].begin(); par != cases[x][y][z].end();  ++par)	//on boucle sur les elements de la liste
		{
			if(collection[i] != *par)					//une particule ne peut pas se choquer avec elle même
			{
				choc_truque((*collection[i]), *(*par));	//on fait le choque
			}
			else if(par != cases[x][y][z].end())	//si on retrouve la particule et qu'elle n'est pas en dernière position on l'efface
			{
				par = cases[x][y][z].erase(par);	//on enlève la particule de sorte a ce que si il y avait plusieurs particules dans cette case, lorsque qu'on reviens a cette case on ne refait pas le même choque
				--par;	// pour bien avoir le comportement voulu lorsqu'on arrive a la fin de la boucle
			}
			else
			{		//si la particule en xyzpar est celle qu'on test et que c'est la dernière on l'efface
				cases[x][y][z].erase(par);	//si la particule qu'on test est la dernière dans une case, on la suprime et on stop la boucle. (ou s'il y a qu'une particule dans une case, on la suprime de la case)
			}
		}
		/* on utilise une liste doublement chainée parce que 
		 * de toute façon on accède de manière séquentiel au contenu
		 * des cases, du coup, osef de l'accès direct (qui est en O(n))
		 * et de plus comme ça on peut facilement enlever n'importe quel
		 * element a n'importe quel position*/
		 /* En fait je me rend compte maintenant que comme dans chaque case les particules sont stoquée
		  * de manière croissante (des indices de la collection) (cf. remplir cases), et qu'on parcours 
		  * la collection en ordre croissant, c'est toujours le 1er element de chaque case qui est la 
		  * particule testée du coup, on aurait pu utiliser une double ended qeue (deque) et faire un 
		  * pop_front() au début du parcours de la case.*/
	}
}


//pareil mais pour le terminal
void Systeme::gerer_choc(ostream& sortie)
{
	list<Particule*>::iterator par;
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		int x(collection[i]->getPosition().getX());		//pour plus de lisibilité on fait ces 3 variables intermédiaires
		int y(collection[i]->getPosition().getY());
		int z(collection[i]->getPosition().getZ());	
		for(par = cases[x][y][z].begin(); par != cases[x][y][z].end();  ++par)
		{
			
			if(collection[i] != *par)
			{
				sortie << "particule " << i+1 << " rencontre une autre " << endl << endl;
				sortie << "Avant le choc" << endl;
				sortie << "	" << *collection[i] << endl;
				sortie << "	" << **par << endl;
				choc_truque((*collection[i]), *(*par));
				sortie << endl << "Après le choc" << endl;
				sortie << "	" << *collection[i] << endl;
				sortie << "	" << **par << endl << endl;
			}
			else if(par != cases[x][y][z].end())
			{
				par = cases[x][y][z].erase(par);
				--par;
			}
			else
			{
				cases[x][y][z].erase(par);
			}
		}
	}
}


//renvoie une particule, en l'ocurence la 1ere, pour qu'on puisse lui attacher la caméra
Particule* Systeme::getParticule()	//faudra p'etre faire différament
{
	if(not collection.empty()){return collection[0];}
}

