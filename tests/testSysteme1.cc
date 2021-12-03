#include "srctests/SystemeP8.h"
#include "../include/TXTGaz.h"	// contient les classes TXTHelium, TXTNeon, TXTArgon

int main()
{
	Systeme systeme;	//systeme par défaut
	systeme.ajouter_particule(new TXTHelium(1.0,1.0,1.0,0.0,0.0,0.0,4.002602));	//ajoute une particule d'hélium
	systeme.ajouter_particule(new TXTNeon(1.0,18.5,1.0,0.0,0.2,0.0,20.1797));	//ajoute une particule de Neon
	systeme.ajouter_particule(new TXTArgon(1.0,1.0,3.1,0.0,0.0,-0.5,39.948));	//ajoute une particule d'Argon
	systeme.ajouter_particule(new TXTKrypton(1.0,2.0,3.0,1.0,2.0,3.0,83.798));//etc...
	systeme.ajouter_particule(new TXTXenon(12.0,15.0,3.5,-3.0,0.2,3.2,131.293));
	systeme.ajouter_particule(new TXTRadon(5.5,8.0,2.9,4.4,7.24,0.0,222));
	systeme.dessine();	//affiche le systeme

return 0;
}
