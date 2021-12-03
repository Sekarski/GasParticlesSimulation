#ifndef PRJ_FENETREOPTION_H
#define PRJ_FENETREOPTION_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

// fenetre(s) de control
class FenetreOPT: public wxFrame
{
public:
  FenetreOPT(wxWindow* parent, wxString titre, wxSize taille);
  //Pour accèder au valeurs des sliders
  double getDT() const;	//pour chopper le pas de temps
  double getEX() const;	//pour prendre la profondeur de l'enceinte
  double getEY() const;	//  "    "      " Largeur    "   "    "
  double getEZ() const;	//  "    "      " Hauteur    "   "    "
  double getZOOM() const;		//retourne le niveau de zoom choisi
  double getRPHI() const;		//retourne l'angle de rotation phi
  double getRTHETA() const;		//retourne l'angle de rotation thetha
  bool getActionCam() const;	//détermine si on veux placer la camera sur une particule
  
  //pour mettre a jour les sliders quand on appuie sur des touches du clavier
  void setZOOM(double const& z);
  void setRPHI(double const& p);
  void setRTHETA(double const& t);

protected:

	//Attributs pour changer le pas de temps
	wxSlider* sliderDT;		//le Slider
	wxStaticText* txtDT;	//le text a afficher a gauche
	wxStaticText* valDT;	//le text qui indique la valeur du slider
	
	//Pour changer la Profondeur de l'enceinte
	wxSlider* sliderEX;		//idem
	wxStaticText* txtEX;
	wxStaticText* valEX;
	
	//Pour changer la Largeur de l'enceinte
	wxSlider* sliderEY;
	wxStaticText* txtEY;
	wxStaticText* valEY;
	
	//Pour changer la Hauteur de l'enceinte
	wxSlider* sliderEZ;
	wxStaticText* txtEZ;
	wxStaticText* valEZ;
	
	//Pour changer le niveau de zoom
	wxSlider* sliderZOOM;
	wxStaticText* txtZOOM;
	wxStaticText* valZOOM;
	
	//Pour changer l'angle phi
	wxSlider* sliderRPHI;
	wxStaticText* txtRPHI;
	wxStaticText* valRPHI;
	
	//Pour changer l'angle theta
	wxSlider* sliderRTHETA;
	wxStaticText* txtRTHETA;
	wxStaticText* valRTHETA;
	
	//Pour choisir de voir se que voit une particule (Camera d'Action)
	wxCheckBox* boxActionCam;	// 2 valeurs uniquement true ou false
	wxStaticText* txtActionCam;	// text a afficher a gauche
	
private:
	wxString int2wxString(int i);	//méthode outil pour convertir des ints en wxSting
	wxString double2wxString(double i);		//idem mais pour des doubles
	void sliderUpdate(wxCommandEvent& WXUNUSED(event));	//méthode qui est appellée quand un silder (n'importe lequel) est MAJ
	void rafraichir(wxCommandEvent& WXUNUSED(event));	//demande a la classe parente de redessine le dessin (Refresh)
	void OnExit(wxCloseEvent& event);	//on gère manuellement de nouveau la fermeture de la fenetre (enfait ici on enpêche la fermeture de cette fenetre avec la croix)
	DECLARE_EVENT_TABLE()	//on déclarer un table d'evenement
};

#endif //PRJ_FENETREOPTION_H
