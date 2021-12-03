#include <iostream>
#include "srctests/ParticuleP5.h"
#include "../include/Vecteur.h"
using namespace std;

int main()
{
	Vecteur pos1(1.0,1.0,1.0);
	Vecteur pos2(1.0,18.5,1.0);
	Vecteur vit2(0.0,0.2,0.0);
	Vecteur vit1;
	Particule p0;										//Constructeur par défaut
	Particule p1(pos1,vit1,4.002602);					//Constructeur avec 2 vecteur déjà défini
	Particule p2(pos2,vit2,20.1797);
	Particule p3(1.0,1.0,3.1,0.0,0.0,-0.5,39.9548);		//constructeur général: appelle le constructeur de Vecteur
	Particule p4 = p1;									//constructeur de copie par défaut
	
	cout << "Particule 0 : " << p0 << endl;				//test la surcharge d'affichage
	cout << "particule 1 : " << p1 << endl;			
	cout << "particule 2 : " << p2 << endl;
	cout << "particule 3 : " << p3 << endl;
	cout << "particule 4 : " << p4 << endl;
	
	cout << "Energie cinétique de la particule 2" << p2.Ecin() << endl;				//Energie cinétique
	cout << "Quantité de mouvement de la particule 2" << p2.quantite_mvt() << endl;	//vecteur quandtité de mvt
	
	return 0;
}
