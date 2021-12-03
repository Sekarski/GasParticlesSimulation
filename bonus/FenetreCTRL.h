#ifndef PRJ_FENETRECTRL_H
#define PRJ_FENETRECTRL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "../include/Fenetre.h"	//la fenetre qui contiendra la simulation
#include "FenetreSTAT.h"		//la fenetre qui contiendra les crédits

// fenetre(s) de control
class FenetreCTRL: public wxFrame
{
public:
  FenetreCTRL(wxString titre, wxSize taille);
  void run_simulation(wxCommandEvent& WXUNUSED(event));	//se charge de lancer la fênetre de simulation
  void run_credits(wxCommandEvent& WXUNUSED(event));	//se charge de lancer la fenêtre de crédits

protected:
	//texts indiquant le type de particule auquel le slider se rapporte
	wxStaticText* texteHelium;
	wxStaticText* texteNeon;		//de type static text, car on ne veut pas que l'utilisteur puisse les modifier
	wxStaticText* texteArgon;
	wxStaticText* texteKrypton;
	wxStaticText* texteXenon;
	wxStaticText* texteRadon;
	wxStaticText* txtTot;
	
	wxStaticText* txtTrace;
	

	//texts indiquant la valeur actuelle des sliders
	wxStaticText* nbrHe;
	wxStaticText* nbrNe;
	wxStaticText* nbrAr;
	wxStaticText* nbrKr;
	wxStaticText* nbrXe;
	wxStaticText* nbrRa;
	wxStaticText* nbrTot;
	
	wxStaticText* nbrTHE;
	wxStaticText* nbrTNE;
	wxStaticText* nbrTAR;
	wxStaticText* nbrTKR;
	wxStaticText* nbrTXE;
	wxStaticText* nbrTRA;
	wxStaticText* nbrTrace;
	
	//Les Sliders de chaque gaz
	wxSlider* sliderHelium;
	wxSlider* sliderNeon;
	wxSlider* sliderArgon;
	wxSlider* sliderKrypton;
	wxSlider* sliderXenon;
	wxSlider* sliderRadon;
	wxStaticText* nbrMax;	//sauf celuilà qui est un text, mais pour la clareté dans je le met ici (car il est dans la même sizer)
	
	/*Sliders pour les Particules tracée, on nous dit dans la donnée 
	 * qu'il ne faut ne mettres que quelques unes, du coup on ne vas pas
	 * les comptabiliser dans le nombre de particules total, (ce qui va
	 * nous simplifier la vie, puisqu'on rajoute ça après, et on ne veux
	 * pas modifier notre code) on considère qu'une dizaine de particules
	 * par rapport a 1'000 ne fait pas énormément de différence. */
	 wxSlider* sliderTHE;
	 wxSlider* sliderTNE;
	 wxSlider* sliderTAR;
	 wxSlider* sliderTKR;
	 wxSlider* sliderTXE;
	 wxSlider* sliderTRA;
	 
	 wxSlider* longeurTrace;
	
	//deux boutons
	wxButton* boutonCredits;	//bouton qui va lancer les crédits
	wxButton* boutonEnvoyer;	//bouton qui va lancer la simulation

	//Selection du moteur de simulation (modèle de choc)
	wxStaticText* txtMoteur;
	wxStaticText* infoMoteur;
	wxComboBox* moteur;

	int max;	//nombre max de particules, comme il sera modifié, on en a fait un attribut

private:
	wxString int2wxString(int const& i);	//pour convertir les ints en wxString
	//méthodes Handlers (gestion d'evénements)
	void helium_maj(wxCommandEvent& WXUNUSED(event));
	void neon_maj(wxCommandEvent& WXUNUSED(event));
	void argon_maj(wxCommandEvent& WXUNUSED(event));
	void krypton_maj(wxCommandEvent& WXUNUSED(event));
	void xenon_maj(wxCommandEvent& WXUNUSED(event));
	void radon_maj(wxCommandEvent& WXUNUSED(event));
	void moteur_maj(wxCommandEvent& WXUNUSED(event));
	void heliumT_maj(wxCommandEvent& WXUNUSED(event));
	void neonT_maj(wxCommandEvent& WXUNUSED(event));
	void argonT_maj(wxCommandEvent& WXUNUSED(event));
	void kryptonT_maj(wxCommandEvent& WXUNUSED(event));
	void xenonT_maj(wxCommandEvent& WXUNUSED(event));
	void radonT_maj(wxCommandEvent& WXUNUSED(event));
	void longT_maj(wxCommandEvent& WXUNUSED(event));


};

#endif //PRJ_FENETRECTRL_H
