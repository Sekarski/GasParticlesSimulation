/*Copyright 2014 Samuel Sekarski and Christine Nguyen */

#include "../include/TXTEnceinte.h"

TXTEnceinte::TXTEnceinte(){}		//enceinte 20x20x20
TXTEnceinte::TXTEnceinte(double const& p, double const& l, double const& h):Enceinte(p,l,h){}
TXTEnceinte::~TXTEnceinte(){}
void TXTEnceinte::dessine() const {}
/*pour cette méthode, elle ne fait pour le moment rien, mais on était 
 * obligé de la redéfinir pour pouvoir instancier cette classe,
 * on pense peut etre lui faire afficher quelquechose sur le terminal quand même
 * si on a le temps*/
