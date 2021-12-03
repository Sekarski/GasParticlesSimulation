#ifndef GUI_MOTS_H
#define GUI_MOTS_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h"
#include <vector>
#include "Lettres.h"
#include <string>


class Mot
{
public:
	Mot(std::string m):txt_word(m){linkword();}		//constructeur qui prend une string, et appelle la fonction qui rempli le tableau avec l'équivalence des lettre graphique
	virtual ~Mot();
	virtual void dessine() const;		//dessine le mot
	unsigned int length() const {return word.size();}	//renvoie la longeur d'un mot, ce qui est utile pour justifié un text, le centrer, etc...
	
private:
	std::string txt_word;		//un mot sous une forme string
	std::vector<Lettre*> word;	//un mot est une collection de lettres
	void linkword();		//méthode pour lier la string a sa représentation graphique (tableau de Lettre)
	
};

#endif //GUI_MOTS_H
