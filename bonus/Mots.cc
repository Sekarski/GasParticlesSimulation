/* Copyright 2014 Christine Nguyen and Samuel Sekarski */

#include "Mots.h"
using namespace std;

Mot::~Mot()
{
	for(unsigned int i=0; i<word.size(); ++i)
	{
		delete word[i];		//on alloue dynamiquement les lettres, donc il faut faire un delete
		word[i] = nullptr;
	}
}

void Mot::linkword()	//lie la string a sa représentation graphique (concrètement initialise le tableau de Lettre)
{
	for(unsigned int i=0; i<txt_word.length(); ++i)
	{
		switch (txt_word[i])			//A noter qu'on par du principe qu'il n'y a pas d'espace dans le mots (les espace était géré dans une autre classe), et toute ponctuation est simplement ignorée
		{
			case 'a':						//Malheureusement on n'a pas eu le temps de prendre en compte les majuscles, ni la ponctuation
				word.push_back(new Aa);		//on alloue une nouvelle lettre dans le tableau a la place correspondante du string
				break;
			case 'b':					
				word.push_back(new Bb);		//idem pour toutes les autres lettre
				break;
			case 'c':
				word.push_back(new Cc);
				break;
			case 'd':
				word.push_back(new Dd);
				break;
			case 'e':
				word.push_back(new Ee);
				break;
			case 'f':
				word.push_back(new Ff);
				break;
			case 'g':
				word.push_back(new Gg);
				break;
			case 'h':
				word.push_back(new Hh);
				break;
			case 'i':
				word.push_back(new Ii);
				break;
			case 'j':
				word.push_back(new Jj);
				break;
			case 'k':
				word.push_back(new Kk);
				break;
			case 'l':
				word.push_back(new Ll);
				break;
			case 'm':
				word.push_back(new Mm);
				break;
			case 'n':
				word.push_back(new Nn);
				break;
			case 'o':
				word.push_back(new Oo);
				break;
			case 'p':
				word.push_back(new Pp);
				break;
			case 'q':
				word.push_back(new Qq);
				break;
			case 'r':
				word.push_back(new Rr);
				break;
			case 's':
				word.push_back(new Ss);
				break;
			case 't':
				word.push_back(new Tt);
				break;
			case 'u':
				word.push_back(new Uu);
				break;
			case 'v':
				word.push_back(new Vv);
				break;
			case 'w':
				word.push_back(new Ww);
				break;
			case 'x':
				word.push_back(new Xx);
				break;
			case 'y':
				word.push_back(new Yy);
				break;
			case 'z':
				word.push_back(new Zz);
				break;
		}
	}
}

void Mot::dessine() const	//dessine le mot
{
	for(unsigned int i=0; i<word.size(); ++i)
	{
		word[i]->dessine();		//fait apelle aux méthode dessine de chaque lettre du tableau (résolution dynamique)
		glTranslated(0,3.5,0);	// pour que les lettres ne se déssine pas les unes sur les autres
	}
}
