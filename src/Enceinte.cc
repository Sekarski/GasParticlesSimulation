/*Copyright 2014 Samuel Sekarski and Christine Nguyen */

#include "../include/Enceinte.h"
using namespace std;

/*______________________Constructeurs___________________________*/
//Constructeur par défaut: cube de 20 de côté
Enceinte::Enceinte(): hauteur(20), largeur(20), profondeur(20) {}

//Initialiser l'enceinte
Enceinte::Enceinte(double const& p, double const& l, double const& h): hauteur(h), largeur(l), profondeur(p) {}

Enceinte::~Enceinte() {}

double Enceinte::getHauteur() const{ return hauteur;}
double Enceinte::getProfondeur() const{ return profondeur;}
double Enceinte::getLargeur() const{ return largeur;}
void Enceinte::setHauteur(double const& h){hauteur = h;}
void Enceinte::setProfondeur(double const& p){profondeur = p;}
void Enceinte::setLargeur(double const& l){largeur = l;} 

/*________________________Méthodes_______________________________*/
double Enceinte::volume() const{return hauteur*largeur*profondeur;}
