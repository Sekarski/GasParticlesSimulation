#ifndef PRJ_VUEOPENGLP11_H
#define PRJ_VUEOPENGLP11_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "../../include/Dessinable.h"		//est ce que je dois include ceci ou est-ce que c'est superfaitatoire ?
#include <vector>		//hum ça devrait pas être inclu dans le .cc ça ?
#include "../../include/Systeme.h"	
#include "../../include/GlGaz.h"		//idem ?
#include "../../include/GlEnceinte.h"	

// sous-fenetre de dessin OpenGL
class Vue_OpenGL : public wxGLCanvas
{
public:
  Vue_OpenGL( wxWindow*      parent
            , wxSize  const& taille   = wxDefaultSize     
            , wxPoint const& position = wxDefaultPosition
            );


  void InitOpenGL();
  wxTimer* getTimer();

protected:
  void dessine(wxPaintEvent& evenement);
  void OnSize(wxSizeEvent& evenement);
  void OnKeyDown(wxKeyEvent& evenement);
  void OnEnterWindow(wxMouseEvent& evenement) { SetFocus(); }
  void OnTimer(wxTimerEvent& event);

  void RotateTheta(GLdouble deg);
  void RotatePhi(GLdouble deg);
  void deplace(double dr);
  void InitSysteme11();
  
private:
  static int attributelist[3];
  double theta;
  double phi;
  double r;
  Systeme sys;
  double dt;

  // le "Timer"
  wxTimer* timer;
  static int TIMER_ID;



DECLARE_EVENT_TABLE()
};

#endif //PRJ_VUEOPENGLP11_H
