#include <iostream>
#include "../include/Systeme.h"
#include "../include/TXTGaz.h"		//contient les classes TXTHelium, TXTNeon, TXTArgon
#include "../include/TXTEnceinte.h"
using namespace std;

#define K_HE 1000*8.314472/4.002602		//on pensait au début faire des attribut constant static des sous classe GlGaz
#define K_NE 1000*8.314472/20.1797
#define K_AR 1000*8.314472/39.948
#define K_KR 1000*8.314472/83.798
#define K_XE 1000*8.314472/131.293
#define K_RA 1000*8.314472/222

int main()
{

Systeme systeme(new TXTEnceinte);	//systeme avec une enceinte par défaut de 20x20x20

cout << "Ajout de particules" << endl;

//ajout particule d'hélium
int hel;
do{
cout << "Combien de particules particules d'hélium voulez-vous ajouter?" << endl;
cin >> hel;
} while (hel<0);
for(unsigned int i=0; i<hel; ++i)
{
	systeme.ajouter_particule(new TXTHelium(systeme.tirer_position(), systeme.tirer_vitesse(K_HE)));	//ajoute une particule d'hélium
}


//ajout particule de Neon
int neo;
do{
cout << "Combien de particules particules de neon voulez-vous ajouter?" << endl;
cin >> neo;
} while (neo<0);
for(unsigned int i=0; i<neo; ++i)
{
	systeme.ajouter_particule(new TXTNeon(systeme.tirer_position(), systeme.tirer_vitesse(K_NE)));	//ajoute une particule de Neon
}


//ajout particule d'argon
int arg;
do{
cout << "Combien de particules particules d'argon voulez-vous ajouter?" << endl;
cin >> arg;
} while (arg<0);
for(unsigned int i=0; i<arg; ++i)
{
	systeme.ajouter_particule(new TXTArgon(systeme.tirer_position(), systeme.tirer_vitesse(K_AR)));	//ajoute une particule d'Argon
}


//ajout particule Krypton
int kry;
do{
cout << "Combien de particules particules de krypton voulez-vous ajouter?" << endl;
cin >> kry;
} while (kry<0);
for(unsigned int i=0; i<kry; ++i)
{
	systeme.ajouter_particule(new TXTKrypton(systeme.tirer_position(), systeme.tirer_vitesse(K_KR)));	//ajoute une particule de Krypton
}


//ajout particule de Xenon
int xen;
do{
cout << "Combien de particules particules de xenon voulez-vous ajouter?" << endl;
cin >> xen;
} while (xen<0);
for(unsigned int i=0; i<xen; ++i)
{
	systeme.ajouter_particule(new TXTXenon(systeme.tirer_position(), systeme.tirer_vitesse(K_XE)));	//ajoute une particule de Xenon
}


//ajout particule de Radon
int rad;
do{
cout << "Combien de particules particules de radon voulez-vous ajouter?" << endl;
cin >> rad;
} while (rad<0);
for(unsigned int i=0; i<rad; ++i)
{
	systeme.ajouter_particule(new TXTRadon(systeme.tirer_position(), systeme.tirer_vitesse(K_RA)));	//ajoute une particule de Radon
}

    
	cout << "le systeme est constitué des " << systeme.collection_size() << " particules suivantes :" << endl;
	systeme.dessine();
	cout << "Lancement de la simulation" << endl;
	int j(4);
	for(unsigned int i=0; j<10; ++i)		//boucle infinie !! attention il faut fermer le terminal pour quitter le process
	{
		cout << "=========---------" << endl;
		systeme.evolue(1, cout);
		systeme.dessine();
	}
	cout << "etc..." << endl;
}
