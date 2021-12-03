#ifndef GUI_TEXT_H
#define GUI_TEXT_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h"
#include <vector>
#include <string>
#include <iostream>
#include "Mots.h"

class Text
{
public:
	Text(std::string t):txt_phrase(t){linkphrase();}	//constructeur qui prend une string et la transforme en tableau de mot
	virtual ~Text();
	void dessine() const;		//méthode de dessin "justifié"
	void dessineC() const;		//méthode de dessin "centré"
	
private:
	std::string txt_phrase;		//la string on veut dessiner
	std::vector<Mot*> phrase;	//le tableau de mot avec méthode dessine graphique
	void linkphrase();			//fait le lien entre les 2 attributs ci-dessus
};


#endif //GUI_TEXT_H
