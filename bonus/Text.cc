/* Copyright 2014 Samuel Sekarski and Christine Nguyen */

#include "Text.h"
using namespace std;

Text::~Text()	//destructeur qui libère la mémoire
{
	for(unsigned int i=0; i<phrase.size(); ++i)
	{
		delete phrase[i];		//comme d'habitude
		phrase[i] = nullptr;
	}
}

void Text::linkphrase()		//lie la string au tableau de Mot
{
	unsigned int j(0);
	for(unsigned int i=0; i<txt_phrase.length(); ++i)	// on itère sur la string
	{	
		if(txt_phrase[i] == ' ' or i==txt_phrase.length()-1)	//si on arrive a un espace, ou qu'on arrive a la fin de la string
		{
			if(i == txt_phrase.length() -1)	//cas spécial: fin de la string sans espace
			{
				// on ajoute au tableau le mot donc la string va depuis le dernier espace a la position courante
				phrase.push_back(new Mot(txt_phrase.substr(j,i-j+1)));
			}
			else
			{
				//idem mais si on ce n'est pas la fin de la string (ie: on arrive a un espace
				phrase.push_back(new Mot(txt_phrase.substr(j,i-j)));
				j=i+1;		//indique la position de l'espace
			}
		}
	}
}

void Text::dessine() const	//Méthode qui "écrit" le text de façon "justifiée"
{
	//accrochez vous, j'ai fais ça assez vite fait
	//J'ai vraiment pas envie de devoir commenter ça... et vous avez surment pas envie de lire ça...
	//ça m'aprendra de faire tout d'un coup -.-''
	//un jour je reprendrais le projet, et je referrais toute cette partie correctement
	//bon je me lance quand même
	
	glPushMatrix();	
	unsigned int nbr_char(0);		//compte le nombre de charactère par ligne
	unsigned int k(0);	//compte le nombre de mot par ligne
	for(unsigned int i=0; i<phrase.size(); ++i)
	{	
		if(nbr_char + phrase[i]->length() + 1 <60 and i!=phrase.size()-1)	//si le mot suivant n'est ni le dernier, ni dépasse la taille fixée par ligne (60 ici)
		{
			++k;	//on incrément le compteur de mot/ligne
			nbr_char += (phrase[i]->length() + 1);	//on ajout la longeur du mot et de l'espace qui le suit au compteur du nombre de char/ligne
		}
		else if(i == phrase.size() -1)	//sinon si c'est le dernier mot de la phrase
		{
			if(nbr_char + phrase[i]->length() + 1 < 60)	//s'il tiens encore sur une ligne
			{
				++k;	//on incrément la comteur mot/ligne
				nbr_char += (phrase[i]->length() +1);	//on ajoute sa longeur au nbr de char/ligne
				glPopMatrix();
				glTranslated(-8,0,0);	//on passe a la ligne (rappelle hauteur d'une lettre: 5 unité
				glPushMatrix();
				for(unsigned int j=i-k+1; j<=i; ++j)
				{
					phrase[j]->dessine();	// et on dessine chaque mot
					glTranslated(0,7,0);	// séparé d'un espace (rappelle largeur d'une lettre: 3.5 unité (on ajout une petite marge))
				}
			}			//sinon s'il ne tient pas sur la même ligne
			else
			{
				glPopMatrix();
				glTranslated(-8,0,0); //on fait un retoure a la ligne
				glPushMatrix();
				unsigned int delta(60-nbr_char);	//Compte le nombre de charactères qu'il manque sur la ligne
				double machin(delta);	//ah mince, vous disiez de mettre des noms porteur de sens...... ._____. en gros transforme juste l'unsigned int dela en double
				double truc(k);		//hum idem
				//on a commencé une nouvelle ligne, du coup faut remettre a zeros le compteur...
				//... (puis lui ajouter la longeur du mot qui ne tenait pas sur la ligne précédente
				nbr_char=phrase[i]->length()+1;	
				phrase[i-k]->dessine();	//on dessine le 1er mot (ça m'arrenge plus de ne pas le mettre dans la boucle)
				for(unsigned int j=i-k+1; j<i-1; ++j)
				{
					//on dessine chaque mots, sparé du nombre de lettre manquante de la ligne divisé par le nombre de mots sur la ligne
					glTranslated(0,(machin/(truc-1)+1)*3.5,0);	//ça fait la justification
					phrase[j]->dessine();
				}
				glPopMatrix();
				glTranslated(-8,0,0);	//retour a la ligne
				glPushMatrix();
				phrase[i]->dessine();	//dessine le dernier mot du text
			}
		}	//sinon si on n'arrive pas a mettre le mot sur la ligne, mais que c'est pas le dernier
		else
		{	//même principe que ci-dessus globalement
			glPopMatrix();
			glTranslated(-8,0,0);	//retour a la ligne
			glPushMatrix();
			unsigned int delta(60-nbr_char);
			double machin(delta);	//int --> double
			double truc(k);			//int --> double
			nbr_char=phrase[i]->length()+1;
			phrase[i-k]->dessine();
			for(unsigned int j=i-k+1; j<i; ++j)
			{
				glTranslated(0,(machin/(truc-1)+1)*3.5,0);	//justification du text
				phrase[j]->dessine();
			}
			k=1;	// on recommence pour la prochaine ligne de text
		}		
	}
	glPopMatrix();
}


//ça va ? vous êtes toujours avec moi ? je m'excuse encore

//dessine de matinère "centrée"
void Text::dessineC() const
{
	//même principe pour le nombre de characètre par ligne, seul différence c'est on centre au lieu de justifier
	//con fer dessine() pour le commentaire généraux
	glPushMatrix();
	unsigned int k(0);
	unsigned int nbr_char(0);
	for(unsigned int i=0; i<phrase.size(); ++i)
	{	
		if(nbr_char + phrase[i]->length() + 1 <30 and i!=phrase.size()-1)	//on a désider de mettre le nombre de char/lign a 30 ici, ne me demandez pas pourquoi, il était tard quand j'ai fait ça
		{
			++k;
			nbr_char += (phrase[i]->length() + 1);
		}
		else if(i == phrase.size() -1)
		{
			
			if(nbr_char + phrase[i]->length() + 1 < 30)
			{
				++k;
				nbr_char += (phrase[i]->length() +1);
				glPopMatrix();
				glTranslated(-8,0,0);
				glPushMatrix();
				//cast des unsigned int en double et translation d'une demi fois le nombre de characètre "vide" sur la ligne
				glTranslated(0,(double)nbr_char/-2.0*3.5,0);	//centrage	
				for(unsigned int j=i-k+1; j<=i; ++j)
				{
					phrase[j]->dessine();
					glTranslated(0,3.5,0);
				}
			}
			else
			{
				glPopMatrix();
				glTranslated(-8,0,0);
				glPushMatrix();
				glTranslated(0,(double)nbr_char/-2.0*3.5,0);
				nbr_char=phrase[i]->length()+1;
				phrase[i-k]->dessine();
				for(unsigned int j=i-k+1; j<i/*-1*/; ++j)
				{
					glTranslated(0,3.5,0);
					phrase[j]->dessine();
				}
				glPopMatrix();
				glTranslated(-8,0,0);
				glPushMatrix();
				glTranslated(0,(double)nbr_char/-2.0*3.5,0);
				phrase[i]->dessine();
			}
		}
		else
		{
			glPopMatrix();
			glTranslated(-8,0,0);
			glPushMatrix();
			glTranslated(0,(double)nbr_char/-2.0*3.5,0);
			nbr_char=phrase[i]->length()+1;
			phrase[i-k]->dessine();
			for(unsigned int j=i-k+1; j<i; ++j)
			{
				glTranslated(0,3.5,0);
				phrase[j]->dessine();
			}
			k=1;
		}		
	}
	glPopMatrix();
}
