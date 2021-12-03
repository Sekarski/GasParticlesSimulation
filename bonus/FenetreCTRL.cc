/*Copyright 2014 Christine Nguyen and Samuel Sekarski */
#include "FenetreCTRL.h"
using namespace std;
 
	FenetreCTRL::FenetreCTRL(wxString titre, wxSize taille)
: wxFrame(0, wxID_ANY, titre, wxDefaultPosition, taille, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX)), max(3000)
{
 
//####################### Initialisation des attributs #######################
 
//Texte de Présentation
//pas la peine d'en faire des attributs de la fenetre, on ne les manipuleras pas
wxStaticText* intro1 = new wxStaticText(this, wxID_ANY, wxT("Projet de Programation 2014"));
wxStaticText* intro2 = new wxStaticText(this, wxID_ANY, wxT("par Christine Nguyen et Samuel Sekarski"));
/*on mets en gras et penché, le wxFONTFAMILY_SCRIPT ne semble pas marcher 
 * (ou alors j'ai pas compris ce que c'était), et une taille relative*/
intro1->SetFont(wxFont(wxNORMAL_FONT->GetPointSize()*1.2, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_SLANT, wxFONTWEIGHT_BOLD));
intro2->SetFont(wxFont(wxNORMAL_FONT->GetPointSize()*1.2, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_SLANT, wxFONTWEIGHT_BOLD));

//celui la non plus pas la peine d'en faire un attribut de la fenêtre
wxStaticText* texteInfo = new wxStaticText(this, wxID_ANY, wxT("Choix du Nombre de Paticules a initialiser:"));

//Génère des IDs non utilisé 
wxWindowID ID_SLIDER_HE=NewControlId();
wxWindowID ID_SLIDER_NE=NewControlId();
wxWindowID ID_SLIDER_AR=NewControlId();
wxWindowID ID_SLIDER_KR=NewControlId();
wxWindowID ID_SLIDER_XE=NewControlId();
wxWindowID ID_SLIDER_RA=NewControlId();
wxWindowID ID_SLIDER_THE=NewControlId();
wxWindowID ID_SLIDER_TNE=NewControlId();
wxWindowID ID_SLIDER_TAR=NewControlId();
wxWindowID ID_SLIDER_TKR=NewControlId();
wxWindowID ID_SLIDER_TXE=NewControlId();
wxWindowID ID_SLIDER_TRA=NewControlId();
wxWindowID ID_LONGEUR_TRA=NewControlId();

//alloue les sliders avec 0 comme minimum, la valeur de max comme maximum,et 200 comme valeur courante
sliderHelium = new wxSlider(this, ID_SLIDER_HE, 200, 0, max);	//hum faudrait juste éviter que  max < 200*6 ...
sliderNeon = new wxSlider(this, ID_SLIDER_NE, 200, 0, max);
sliderArgon = new wxSlider(this, ID_SLIDER_AR, 200, 0, max);
sliderKrypton = new wxSlider(this, ID_SLIDER_KR, 200, 0, max);
sliderXenon = new wxSlider(this, ID_SLIDER_XE, 200, 0, max);
sliderRadon = new wxSlider(this, ID_SLIDER_RA, 200, 0, max);

//sliders pour les particules tracée
sliderTHE = new wxSlider(this, ID_SLIDER_THE, 0,0,3);
sliderTNE = new wxSlider(this, ID_SLIDER_TNE, 0,0,3);
sliderTAR = new wxSlider(this, ID_SLIDER_TAR, 0,0,3);
sliderTKR = new wxSlider(this, ID_SLIDER_TKR, 0,0,3);
sliderTXE = new wxSlider(this, ID_SLIDER_TXE, 0,0,3);
sliderTRA = new wxSlider(this, ID_SLIDER_TRA, 0,0,3);

//slider pour la longeur de la trace
longeurTrace = new wxSlider(this, ID_LONGEUR_TRA, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL);

//Pour le nombre maximum de Particules
nbrMax = new wxStaticText(this, wxID_ANY, wxT(""));
wxString txt = wxT("Le nombre maximum de particule est ");
txt << max;	//conversion d'int en wxString et concaténation. Remarque: on aurait pu utiliser la méthode qui fait ça
txt << wxT(", vous en avez:");	//concaténation de la string
nbrMax->SetLabel(txt);

//alloue les texts statics, ils appartiennent a l'instnace courante, d'ou le this, 
// on n'en ferras rien de spécial du coup on ne leurs donne pas des ID spécifiques
// et on utilise la macro wxT() pour convertir une chaine literal en wxString
texteHelium = new wxStaticText(this, wxID_ANY, wxT("He"));
texteNeon = new wxStaticText(this, wxID_ANY, wxT("Ne"));
texteArgon = new wxStaticText(this, wxID_ANY, wxT("Ar"));
texteKrypton = new wxStaticText(this, wxID_ANY, wxT("Kr"));
texteXenon = new wxStaticText(this, wxID_ANY, wxT("Xe"));
texteRadon = new wxStaticText(this, wxID_ANY, wxT("Ra"));
txtTot = new wxStaticText(this, wxID_ANY, wxT("Total"));
txtTrace = new wxStaticText(this, wxID_ANY, wxT("Tracée"));

//Pour les Particules tracée
wxStaticText* Helium = new wxStaticText(this, wxID_ANY, wxT("Helium"));
wxStaticText* Neon = new wxStaticText(this, wxID_ANY, wxT("Neon"));
wxStaticText* Argon = new wxStaticText(this, wxID_ANY, wxT("Argon"));
wxStaticText* Krypton = new wxStaticText(this, wxID_ANY, wxT("Krypton"));
wxStaticText* Xenon = new wxStaticText(this, wxID_ANY, wxT("Xenon"));
wxStaticText* Radon = new wxStaticText(this, wxID_ANY, wxT("Radon"));
wxStaticText* lt = new wxStaticText(this, wxID_ANY, wxT("longeur"));

// en gros la même chose a la différence pret qu'on converti des ints en wxString (avec la méthode défini plus bas)
nbrHe = new wxStaticText(this, wxID_ANY, int2wxString(sliderHelium->GetValue()));
nbrNe = new wxStaticText(this, wxID_ANY, int2wxString(sliderNeon->GetValue()));		//la plupart des widgets on une méthode GetValue() qui retourne leurs valeur
nbrAr = new wxStaticText(this, wxID_ANY, int2wxString(sliderArgon->GetValue()));
nbrKr = new wxStaticText(this, wxID_ANY, int2wxString(sliderKrypton->GetValue()));
nbrXe = new wxStaticText(this, wxID_ANY, int2wxString(sliderXenon->GetValue()));
nbrRa = new wxStaticText(this, wxID_ANY, int2wxString(sliderRadon->GetValue()));
nbrTot = new wxStaticText(this, wxID_ANY, int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));

//Pour les particules tracée
nbrTHE = new wxStaticText(this, wxID_ANY, int2wxString(sliderTHE->GetValue()));
nbrTNE = new wxStaticText(this, wxID_ANY, int2wxString(sliderTNE->GetValue()));
nbrTAR = new wxStaticText(this, wxID_ANY, int2wxString(sliderTAR->GetValue()));
nbrTKR = new wxStaticText(this, wxID_ANY, int2wxString(sliderTKR->GetValue()));
nbrTXE = new wxStaticText(this, wxID_ANY, int2wxString(sliderTXE->GetValue()));
nbrTRA = new wxStaticText(this, wxID_ANY, int2wxString(sliderTRA->GetValue()));
nbrTrace = new wxStaticText(this, wxID_ANY, int2wxString(longeurTrace->GetValue()));


//Ajout: choix du moteur de simulation (ou du modèle de choc si vous préférez)
wxWindowID ID_MOTEUR = NewControlId();
//en lecture seule (wxCB_READONLY) pour par que l'utilisateur écrive quelquechose
moteur = new wxComboBox(this, ID_MOTEUR, wxT("Modèle2"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);
moteur->Append(wxT("Modèle 1"));
moteur->Append(wxT("Modèle 2"));
moteur->SetSelection(1);	// par défaut on choisi le modèle récent
txtMoteur = new wxStaticText(this, wxID_ANY, wxT("Choix du modèle de collision, 2 étant plus performant"));

//Bouton Pour lancer la simulation
boutonEnvoyer=new wxButton(this, wxID_ANY, wxT("Lancer la Simulation"));

//Bouton pour faire défiler les crédits
boutonCredits=new wxButton(this, wxID_ANY, wxT("Credits"));


//########################### Mise en Page ################################
/* On utilise pour la mise en page le principe des sizers, c'est a dire découper la
 * page en tableau de tableau, etc... (le principe de l'HTML quoi). C'est donc des positions
 * relative, et pas absolues. L'idée est que si on redimension la fenêtre la mise en page n'est pas a refaire*/
 
//Premier sizer
wxBoxSizer* sizer1=new wxBoxSizer(wxHORIZONTAL);
 
//Second sizer
wxBoxSizer* sizer2=new wxBoxSizer(wxVERTICAL);


//------------------------SizerParticuleTracee------------------------
wxFlexGridSizer* sizerParticuleTracee = new wxFlexGridSizer(3,6,0,0);
sizerParticuleTracee->AddGrowableCol(0);	//
sizerParticuleTracee->AddGrowableCol(1);
sizerParticuleTracee->AddGrowableCol(2);
sizerParticuleTracee->AddGrowableCol(3);
sizerParticuleTracee->AddGrowableCol(4);
sizerParticuleTracee->AddGrowableCol(5);

sizerParticuleTracee->Add(Helium, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(Neon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(Argon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(Krypton, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(Xenon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(Radon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

//bon vous avez compris le principe

sizerParticuleTracee->Add(sliderTHE, 1,wxEXPAND, 5);
sizerParticuleTracee->Add(sliderTNE, 1,wxEXPAND, 5);
sizerParticuleTracee->Add(sliderTAR, 1,wxEXPAND, 5);
sizerParticuleTracee->Add(sliderTKR, 1,wxEXPAND, 5);
sizerParticuleTracee->Add(sliderTXE, 1,wxEXPAND, 5);
sizerParticuleTracee->Add(sliderTRA, 1,wxEXPAND, 5);

//si seulement on avait le droit de définir des macros.... c'est vraiment répétitif	
sizerParticuleTracee->Add(nbrTHE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(nbrTNE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(nbrTAR, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(nbrTKR, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(nbrTXE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
sizerParticuleTracee->Add(nbrTRA, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

//------------------------- SizerSelecParticule----------------------------

wxFlexGridSizer* sizerSelecParticule= new wxFlexGridSizer(7, 3, 0, 0);		//les sizer ça me fait penser a l'HTML
sizerSelecParticule->AddGrowableCol(1);
sizerSelecParticule->Add(texteHelium, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderHelium, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrHe, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(texteNeon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderNeon, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrNe, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(texteArgon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderArgon, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrAr, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(texteKrypton, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderKrypton, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrKr, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(texteXenon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderXenon, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrXe, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(texteRadon, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(sliderRadon, 1, wxEXPAND, 5);
sizerSelecParticule->Add(nbrRa, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(txtTot, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(nbrMax, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);
sizerSelecParticule->Add(nbrTot, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);


//------------------------SizerTrace--------------------------
wxFlexGridSizer* SizerTrace = new wxFlexGridSizer(1,3,0,0);
SizerTrace->AddGrowableCol(1);

SizerTrace->Add(txtTrace, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL,5);
SizerTrace->Add(sizerParticuleTracee, 1, wxEXPAND, 5);

//----------------------------LTrace1--------------------
wxFlexGridSizer* LTrace1 = new wxFlexGridSizer(1,2,0,0);
LTrace1->AddGrowableRow(0);
LTrace1->Add(longeurTrace, 1, wxEXPAND, 5);
LTrace1->Add(nbrTrace, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL,5);

//-----------------------LTrace2--------------------------
wxFlexGridSizer* LTrace2 = new wxFlexGridSizer(2,1,0,0);
LTrace2->AddGrowableRow(1);
LTrace2->Add(lt, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
LTrace2->Add(LTrace1, 1, wxEXPAND,5);

SizerTrace->Add(LTrace2, 1, wxEXPAND, 5);

//-----------------------Sizer Moteur---------------------
wxFlexGridSizer* sizerMoteur = new wxFlexGridSizer(1,2,0,0);
sizerMoteur->AddGrowableCol(0);

sizerMoteur->Add(txtMoteur, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5);
sizerMoteur->Add(moteur, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5);

//-----------------------------------------------------

sizer2->Add(intro1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3);
sizer2->Add(intro2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 3);

sizer2->Add(sizerMoteur, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 20);

sizer2->Add(texteInfo, 0, wxTOP, 10);

//On ajoute le wxFlexGridSizer au wxBoxSizer
sizer2->Add(sizerSelecParticule, 1, wxEXPAND, 20);

wxStaticText* infoTrace = new wxStaticText(this, wxID_ANY, wxT("Nous ne prenons pas en compte les particules tracées dans le total car la consigne stipule \n qu'il faut en mettre que quelque-unes, ce que nous considérons comme négligeable"));

sizer2->Add(SizerTrace, 0, wxEXPAND,10);
sizer2->Add(infoTrace, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 40);

//Ajout au wxBoxSizer, aligné en bas à droite, avec une bordure de 10 px en haut.
sizer2->Add(boutonEnvoyer, 0, wxEXPAND, 10);

sizer2->Add(boutonCredits, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxTOP, 10);

sizer1->Add(sizer2, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 15);
 
//On sélectionne le sizer de base
SetSizer(sizer1);

//############### Connection des evenements aux méthode de gestion ########################

//remarque: on aurait aussi pu utiliser un Event Table

//connecter le bouton a la fonction
boutonEnvoyer->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(FenetreCTRL::run_simulation),
        NULL, this);
boutonCredits->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FenetreCTRL::run_credits), NULL, this);
Connect(ID_SLIDER_HE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::helium_maj));
Connect(ID_SLIDER_NE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::neon_maj));
Connect(ID_SLIDER_AR, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::argon_maj));
Connect(ID_SLIDER_KR, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::krypton_maj));
Connect(ID_SLIDER_XE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::xenon_maj));
Connect(ID_SLIDER_RA, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::radon_maj));
Connect(ID_SLIDER_THE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::heliumT_maj));
Connect(ID_SLIDER_TNE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::neonT_maj));
Connect(ID_SLIDER_TAR, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::argonT_maj));
Connect(ID_SLIDER_TKR, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::kryptonT_maj));
Connect(ID_SLIDER_TXE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::xenonT_maj));
Connect(ID_SLIDER_TRA, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::radonT_maj));
Connect(ID_LONGEUR_TRA, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(FenetreCTRL::longT_maj));
Connect(ID_MOTEUR, wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(FenetreCTRL::moteur_maj));
//Et on affiche la fenêtre
Show(true);  
}

//######################### fin du constructeur ##########################

void FenetreCTRL::run_simulation(wxCommandEvent& WXUNUSED(event))
{
	int init[] = {					//juste un petit tableau a la C pour éviter de passer 12 paramètre au constructeur, j'espère que vous m'en voulez pas :S
		sliderHelium->GetValue(),
		sliderNeon->GetValue(),
		sliderArgon->GetValue(),
		sliderKrypton->GetValue(),
		sliderXenon->GetValue(),
		sliderRadon->GetValue(),
		sliderTHE->GetValue(),
		sliderTNE->GetValue(),
		sliderTAR->GetValue(),
		sliderTKR->GetValue(),
		sliderTXE->GetValue(),
		sliderTRA->GetValue(),
		longeurTrace->GetValue()
		};
	
	if(moteur->GetSelection() == 0)	//si on choisi le 1er modèle de choc
	{
		Fenetre* f = new Fenetre(wxT("Simulation temps reel"),
							init, false,
                           wxSize(800, 600));
	}
	else
	{		//sinon si on choisi le 2eme modèle de choc
		Fenetre* f = new Fenetre(wxT("Simulation temps reel"),
							init, true,
                           wxSize(800, 600));
	}                       
}

void FenetreCTRL::run_credits(wxCommandEvent& WXUNUSED(event))
{
	FenetreSTAT* f = new FenetreSTAT(wxT("Credits"),
							
                           wxSize(1000, 700));
}

wxString FenetreCTRL::int2wxString(int const& i)
{
    wxString string = wxString()<<i;
    return string;
}

//méthode qui gère les événement liée au slider Helium
void FenetreCTRL::helium_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderHelium->SetValue(max - (sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
		
	}
	nbrHe->SetLabel(int2wxString(sliderHelium->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//idem mais pour le Neon
void FenetreCTRL::neon_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderNeon->SetValue(max - (sliderHelium->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
	}
	nbrNe->SetLabel(int2wxString(sliderNeon->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//idem pour l'argon
void FenetreCTRL::argon_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderArgon->SetValue(max - (sliderNeon->GetValue() + sliderHelium->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
	}
	nbrAr->SetLabel(int2wxString(sliderArgon->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//idem pour le krypton
void FenetreCTRL::krypton_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderKrypton->SetValue(max - (sliderNeon->GetValue() + sliderArgon->GetValue() + sliderHelium->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
	}
	nbrKr->SetLabel(int2wxString(sliderKrypton->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//idem Xenon
void FenetreCTRL::xenon_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderXenon->SetValue(max - (sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderHelium->GetValue() + sliderRadon->GetValue()));
	}
	nbrXe->SetLabel(int2wxString(sliderXenon->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//idem Radon
void FenetreCTRL::radon_maj(wxCommandEvent& WXUNUSED(event))
{
	if(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue() > max)
	{
		sliderRadon->SetValue(max - (sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderHelium->GetValue()));
	}
	nbrRa->SetLabel(int2wxString(sliderRadon->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}

//Méthode qui est apellée quand un slider sans ID est MAJ
void FenetreCTRL::heliumT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTHE->SetLabel(int2wxString(sliderTHE->GetValue()));
}

void FenetreCTRL::neonT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTNE->SetLabel(int2wxString(sliderTNE->GetValue()));
}

void FenetreCTRL::argonT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTAR->SetLabel(int2wxString(sliderTAR->GetValue()));
}

void FenetreCTRL::kryptonT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTKR->SetLabel(int2wxString(sliderTKR->GetValue()));
}

void FenetreCTRL::xenonT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTXE->SetLabel(int2wxString(sliderTXE->GetValue()));
}

void FenetreCTRL::radonT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTRA->SetLabel(int2wxString(sliderTRA->GetValue()));
}

void FenetreCTRL::longT_maj(wxCommandEvent& WXUNUSED(event))
{
	nbrTrace->SetLabel(int2wxString(longeurTrace->GetValue()));
}

//Méthode qui est apellée quand on modifie la seleciton du modèle
void FenetreCTRL::moteur_maj(wxCommandEvent& WXUNUSED(event))	//on aimerait un nombre différent de particule max, en fonciton du modèle choisi
{
	int value(0);
	if(moteur->GetCurrentSelection() == 0)	//si on choisi le 1er modèle
	{
		max = 1000;
		value = 50;	
	}
	else
	{
		max = 3000;	//on a testé avec 10'000 et ça marchait encore, mais pour garantire une bonne fluidité on bloque a 3'000
		value = 200;
	}
	wxString txt(wxT("Le nombre maximum de particule est "));
	txt << max;
	txt << wxT(", vous en avez:");
	nbrMax->SetLabel(txt);
	/*Pour tout les sliders on change la valeur max, et la valeure courante qu'on met a une valeur prédéfini
	 * (imaginons qu'on passe du modèle 2 avec les maximum de particule au modèle 1
	 * du coup il y aura un bug de slider*/
	sliderHelium->SetValue(value);
	sliderHelium->SetMax(max);
	sliderNeon->SetValue(value);
	sliderNeon->SetMax(max);
	sliderArgon->SetValue(value);
	sliderArgon->SetMax(max);
	sliderKrypton->SetValue(value);
	sliderKrypton->SetMax(max);
	sliderXenon->SetValue(value);
	sliderXenon->SetMax(max);
	sliderRadon->SetValue(value);
	sliderRadon->SetMax(max);
	
	/*on met a jour les texts aussi*/
	nbrHe->SetLabel(int2wxString(sliderHelium->GetValue()));
	nbrNe->SetLabel(int2wxString(sliderNeon->GetValue()));
	nbrAr->SetLabel(int2wxString(sliderArgon->GetValue()));
	nbrKr->SetLabel(int2wxString(sliderKrypton->GetValue()));
	nbrXe->SetLabel(int2wxString(sliderXenon->GetValue()));
	nbrRa->SetLabel(int2wxString(sliderRadon->GetValue()));
	nbrTot->SetLabel(int2wxString(sliderHelium->GetValue() + sliderNeon->GetValue() + sliderArgon->GetValue() + sliderKrypton->GetValue() + sliderXenon->GetValue() + sliderRadon->GetValue()));
}
