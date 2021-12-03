#include <iostream>
#include "../include/Systeme.h"
#include "../include/TXTGaz.h"		//contient les classes TXTHelium, TXTNeon, TXTArgon
#include "../include/TXTEnceinte.h"
using namespace std;

int main()
{
	Systeme systeme(new TXTEnceinte);	//systeme avec une enceinte par défaut de 20x20x20
	systeme.ajouter_particule(new TXTHelium(1.0,1.0,1.0,0.0,0.0,0.0,4.002602));	//ajoute une particule d'hélium
	systeme.ajouter_particule(new TXTNeon(1.0,18.5,1.0,0.0,0.2,0.0,20.1797));	//ajoute une particule de Neon
	systeme.ajouter_particule(new TXTArgon(1.0,1.0,3.1,0.0,0.0,-0.5,39.948));	//ajoute une particule d'Argon
	cout << "le systeme est constitué des " << systeme.collection_size() << " particules suivantes :" << endl;
	systeme.dessine();
	cout << "Lancement de la simulation" << endl;
	for(unsigned int i=0; i<10; ++i)		//a remplacer par une boucle infinie plus tard
	{
		cout << "=========---------" << endl;
		systeme.evolue_vieux(1, 1, cout);
		systeme.dessine();
	}
	cout << "etc..." << endl;
	return 0;
}
