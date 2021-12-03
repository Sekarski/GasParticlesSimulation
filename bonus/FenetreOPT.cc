/* Copyright 2014 Christine Nguyen and Samuel Sekarski */

#include "FenetreOPT.h"

BEGIN_EVENT_TABLE(FenetreOPT, wxFrame)
    EVT_CLOSE(FenetreOPT::OnExit)		//lors d'un evenement de fermeture le handler OnExit est appelé (pour gerer nous même la fermeture)
END_EVENT_TABLE()


	FenetreOPT::FenetreOPT(wxWindow* parent, wxString titre, wxSize taille)
: wxFrame(parent, wxID_ANY, titre, wxPoint(1000,0), taille, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	
//######################### initialisation des attribut ##########################	
	//Texte d'information
	wxStaticText* texteInfo = new wxStaticText(this, wxID_ANY, wxT("Options de simulation:"));
	
	sliderDT = new wxSlider(this, wxID_ANY, 10, 1, 30);		//la valeur "réel" est divisée par 1000, car on ne peut pas mettre de double dans les sliders
	txtDT = new wxStaticText(this, wxID_ANY, wxT("pas de temps:"));
	valDT = new wxStaticText(this, wxID_ANY, double2wxString(sliderDT->GetValue()/1000.0));	//pour donner l'illusion que le slider est en double

	//on crée un nouvelle id (truc qui determine uniquement un element) qui n'est pas encore utilisé
	//Bon ici ce n'est pas trop nécessaire vu qu'on gère tout les slider d'un coup,
	//du coup on aurait très bien pu mettre simplement wxID_ANY comme pour les statictext
	wxWindowID ID_SLIDEREX=NewControlId();	
	sliderEX = new wxSlider(this, ID_SLIDEREX, 100, 20, 200);
	txtEX = new wxStaticText(this, wxID_ANY, wxT("Profondeur de l'enceinte:"));
	valEX = new wxStaticText(this, wxID_ANY, double2wxString(sliderEX->GetValue()));	//initialisation de du champ de valeur, avec la valeur courante du slider

	wxWindowID ID_SLIDEREY=NewControlId();
	sliderEY = new wxSlider(this, ID_SLIDEREY, 100, 20, 200);
	txtEY = new wxStaticText(this, wxID_ANY, wxT("Largeur de l'enceinte:"));
	valEY = new wxStaticText(this, wxID_ANY, double2wxString(sliderEY->GetValue()));

	wxWindowID ID_SLIDEREZ=NewControlId();
	sliderEZ = new wxSlider(this, ID_SLIDEREZ, 100, 20, 200);
	txtEZ = new wxStaticText(this, wxID_ANY, wxT("Hauteur de l'enceinte:"));
	valEZ = new wxStaticText(this, wxID_ANY, double2wxString(sliderEZ->GetValue()));

	wxWindowID ID_SLIDER_ZOOM=NewControlId();
	sliderZOOM = new wxSlider(this, ID_SLIDER_ZOOM, 0 , -100, 100);
	txtZOOM = new wxStaticText(this, wxID_ANY, wxT("Niveau de zoom:"));
	valZOOM = new wxStaticText(this, wxID_ANY, double2wxString(sliderZOOM->GetValue()));

	wxWindowID ID_SLIDER_RPHI=NewControlId();
	sliderRPHI = new wxSlider(this, ID_SLIDER_RPHI, 180, 0, 360);
	txtRPHI = new wxStaticText(this, wxID_ANY, wxT("Rotation d'angle phi:"));
	valRPHI = new wxStaticText(this, wxID_ANY, double2wxString(sliderRPHI->GetValue()));

	wxWindowID ID_SLIDER_RTHETA=NewControlId();
	sliderRTHETA = new wxSlider(this, ID_SLIDER_RTHETA, 0, -180, 180);
	txtRTHETA = new wxStaticText(this, wxID_ANY, wxT("Rotation d'angle theta:"));
	valRTHETA = new wxStaticText(this, wxID_ANY, double2wxString(sliderRTHETA->GetValue()));

	wxWindowID ID_ACTIONCAM=NewControlId();
	boxActionCam = new wxCheckBox(this, ID_ACTIONCAM, wxT("Action Camera on/off"));
	txtActionCam = new wxStaticText(this, wxID_ANY, wxT("AC"));
	
	
//######################## Mise en Page ############################## (a la HTML)
	//Premier sizer
	wxBoxSizer* sizer1=new wxBoxSizer(wxHORIZONTAL);
	 
	//Second sizer
	wxBoxSizer* sizer2=new wxBoxSizer(wxVERTICAL);
	 
	//Ajout au sizer
	sizer2->Add(texteInfo, 0, wxTOP, 10);

	// Tableau avec lignes et colones multiples
	wxFlexGridSizer* sizerOption= new wxFlexGridSizer(9, 3, 0, 0);	// tableau de 9x3
	sizerOption->AddGrowableCol(1);	// la 2ème colonne doit s'adapter a la place disponible

	/*Mise en page approximatif:
	 *              Colone 0						Colonne 1					Colonne 2
	 * 
	 * Ligne 0       txt...     ------------------------o------------------   val...
	 * Ligne 1       txt...     ---------------o---------------------------   val...
	 * Ligne 2       txt...     ----------------------o--------------------   val...
	 * ...
	 */
	 
	 
	sizerOption->Add(txtDT, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);	//on ajoute txtDT au tableau multicases, aligné au centre verticallement et a droite, avec une bordure de 5
	sizerOption->Add(sliderDT, 1, wxEXPAND, 5);	//on ajoute sliderDT a tableau, on veut qu'il prenne toute la place disponible => on met 1 et wxEXPAND
	sizerOption->Add(valDT, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);	//ajout de valDT au tableau

	sizerOption->Add(txtEX, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);	//etc...
	sizerOption->Add(sliderEX, 1, wxEXPAND, 5);
	sizerOption->Add(valEX, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtEY, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(sliderEY, 1, wxEXPAND, 5);
	sizerOption->Add(valEY, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtEZ, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(sliderEZ, 1, wxEXPAND, 5);
	sizerOption->Add(valEZ, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtZOOM, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(sliderZOOM, 1, wxEXPAND, 5);
	sizerOption->Add(valZOOM, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtRPHI, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(sliderRPHI, 1, wxEXPAND, 5);
	sizerOption->Add(valRPHI, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtRTHETA, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(sliderRTHETA, 1, wxEXPAND, 5);
	sizerOption->Add(valRTHETA, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	sizerOption->Add(txtActionCam, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
	sizerOption->Add(boxActionCam, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

	//On ajoute le wxFlexGridSizer au wxBoxSizer
	sizer2->Add(sizerOption, 1, wxEXPAND, 20);	//on ajoute maintenant le tableau a la case qui l'englobe

	sizer1->Add(sizer2, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 15); //on ajoute l'autre case a l'intérieure de la principale
	 
	//On sélectionne le sizer de base
	SetSizer(sizer1);	//on définit sizer1 comme étant le principal

//###################### Association d'evénement a des méthodes ####################

	//Connect l'evenement de MAJ d'un slider a la méthode qui gère cet evenement, ici sliderUpdate
	Connect(wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreOPT::sliderUpdate));

	//Connect l'évenenemt (argh comment sa s'apelle en français ) "tic/untic the checkbox" a la méthode qui gère ça. Ici on fait juste un rafraichissement d'écran, et c'est Vue_OpenGl qui vérifie quel valeur a le checkbox
	Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(FenetreOPT::rafraichir));


//Et on affiche la fenêtre
Show(true);
}
//############################### fin du Constructeur ################################################


//Converti des ints en wxSting
wxString FenetreOPT::int2wxString(int i)
{
    wxString string = wxString()<<i;
    return string;
}

//Converti des doubles en wxString
wxString FenetreOPT::double2wxString(double i)
{
    wxString string = wxString()<<i;
    return string;
}

//Fonction qui demande le rafraisissement du dessin
void FenetreOPT::rafraichir(wxCommandEvent& WXUNUSED(event)){GetParent()->Refresh(false);}

void FenetreOPT::sliderUpdate(wxCommandEvent& WXUNUSED(event))	//si un slider est modifié, on met tous les slider a jour
{
	valDT->SetLabel(double2wxString(sliderDT->GetValue()/1000.0));	// pour avoir des pseudo double, car les valeurs des sliders sont en int
	valEX->SetLabel(double2wxString(sliderEX->GetValue()));
	valEY->SetLabel(double2wxString(sliderEY->GetValue()));
	valEZ->SetLabel(double2wxString(sliderEZ->GetValue()));
	valZOOM->SetLabel(double2wxString(sliderZOOM->GetValue()));
	valRPHI->SetLabel(double2wxString(sliderRPHI->GetValue()));
	valRTHETA->SetLabel(double2wxString(sliderRTHETA->GetValue()));
	GetParent()->Refresh(false);	//on demande a Vue_OpenGL de redessiner le système (vu qu'il y a eu des modification)
}

//Accesseur des Slider
double FenetreOPT::getDT() const{return sliderDT->GetValue()/1000.0;}	//pour avoir des pseudo double, car les valeurs des sliders sont en int
double FenetreOPT::getEX() const{return sliderEX->GetValue();}
double FenetreOPT::getEY() const{return sliderEY->GetValue();}
double FenetreOPT::getEZ() const{return sliderEZ->GetValue();}
double FenetreOPT::getZOOM() const{return sliderZOOM->GetValue();}
double FenetreOPT::getRPHI() const{return sliderRPHI->GetValue();}
double FenetreOPT::getRTHETA() const{return sliderRTHETA->GetValue();}
bool FenetreOPT::getActionCam() const{return boxActionCam->GetValue();}

//Setters pour les Sliders zoom, rotation phi, rotation theta, car Dans Vue_OpenGL on peut modifier ces attribut avec des touches de clavier, donc on aimerais aussi que les Slider se MAJ
void FenetreOPT::setZOOM(double const& z){sliderZOOM->SetValue(z); valZOOM->SetLabel(double2wxString(z));}	//on MAJ la veleur et le label corespondant 
void FenetreOPT::setRPHI(double const& p){sliderRPHI->SetValue(p); valRPHI->SetLabel(double2wxString(p));}
void FenetreOPT::setRTHETA(double const& t){sliderRTHETA->SetValue(t); valRTHETA->SetLabel(double2wxString(t));}

void FenetreOPT::OnExit(wxCloseEvent& event) //on gère nous même la fermeture de la fenêtre pour éviter d'avoir un segmentation fault
{ 
	/*on veut empêcher de fermer cette fenetre avant la fin de la simulation (Vue_OpenGl) 
	 * car Vue_OpenGL va chercher des informations de cette fenetre, 
	 * du coup si on fermais cette fenêtre avant la simulation il y aurait un segmentation fault*/
	 wxMessageBox(wxT("Attention vous devez fermer la fenetre de simulation, pas celle-ci !"),wxT("Fermeture"));
}

