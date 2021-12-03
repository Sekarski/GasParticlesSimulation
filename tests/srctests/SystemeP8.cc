#include "SystemeP8.h"
#include <cmath>
using namespace std;
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









//Constructeur par défaut. Appel le constructeur par defaut de "enceinte"
Systeme::Systeme(){}

//Constructeur faisant appel au constructeur explicite de "enceinte"
Systeme::Systeme(unsigned int const& a, unsigned int const& b, unsigned int const& c):enceinte(a,b,c){}

//Redéfinition de la methode dessine() de "déssinable"
void Systeme::dessine() const
{	
	for(unsigned int i=0; i<collection.size(); ++i)
	{
		collection[i]->dessine();		//appel a la fonction dessine de chaque particule
	}
}

//Ajoute une particule au systeme. Concrétement ajoute un pointeur vers une particule au tableau "collection"
void Systeme::ajouter_particule(Particule* p)
{
	if(p !=nullptr)
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
}
