#ifndef PRJ_VUEOPENGL_H
#define PRJ_VUEOPENGL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Dessinable.h"
#include "Systeme.h"	
#include "GlGaz.h"
#include "GlEnceinte.h"	
#include "../bonus/FenetreOPT.h"		//la fenetre a option

// sous-fenetre de dessin OpenGL
class Vue_OpenGL : public wxGLCanvas
{
public:
  Vue_OpenGL( wxWindow*      parent		//l'instance qui possède une Vue_opengl
			, bool mod = true	//pour choisir le modèle de choc a utiliser
            , wxSize  const& taille   = wxDefaultSize
            , wxPoint const& position = wxDefaultPosition
            );


  void InitOpenGL(int init[]);	//méthode qui initialise Vue_OpenGL, en paramètre on passe le nombre de chaque particule qu'on veut initialiser
  void InitSysteme(int init[]);	//méthode qui initialise le Système, on passe la même chose en paramètre
  double getTemps() const;	//Getter qui renvoie le pas de temps dt
  wxTimer* getTimer();		//renvoie un pointeur sur un wxTimer, pour qu'on puisse l'arrêter dans la classe parente

protected:
  void dessine(wxPaintEvent& evenement);		//dessine le système lorsqu'on demande un rafraichissement d'écran
  void OnSize(wxSizeEvent& evenement);			//Handler qui gère la redimension de la fenetre
  void OnKeyDown(wxKeyEvent& evenement);		//Gère l'appuie sur des touches
  void OnEnterWindow(wxMouseEvent& evenement) { SetFocus(); }
  void OnTimer(wxTimerEvent& event);			//Méthode qui fait quelquechose tout les X secondes (ici on fait évoluer le système)

  void RotateTheta(GLdouble deg);		//méthode qui modifie l'angle theta
  void RotatePhi(GLdouble deg);			//modifie l'angle phi
  void deplace(double dr);				//modifie R, c'est a dire s'occuper du zoom
  
private:
  static int attributelist[3];		//pour résoudre le problème de profondeur (cf. moodle)
  double theta;
  double phi;
  double r;				//distance du point de viséee
  Systeme sys;
  double dt;		//pas de temps

	FenetreOPT* fc;		//Fenètre d'option de simulation
	bool modele;	//true pour utiliser le modèle 2 de collision, celui avec les cases, false pour l'ancien

  wxTimer* timer;		//le Chronomètre
  static int TIMER_ID;	//avec son ID



DECLARE_EVENT_TABLE()	//on déclare qu'il y aura une table d'événement-handlers
};

#endif //PRJ_VUEOPENGL_H
