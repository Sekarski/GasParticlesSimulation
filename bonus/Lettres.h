#ifndef GUI_LETTRES_H
#define GUI_LETTRES_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL

class Couleur
{
private:
	int r;	//red
	int g;	//green
	int b;	//blue
public:
	Couleur():r(255), g(255), b(0){}		//Jaune par défaut
	int R() const {return r;}	//getters
	int G() const {return g;}
	int B() const {return b;}
};

class Lettre	//on aurait pu faire de l'héritage de Dessinable, mais bon tant pis
{
protected:
	Couleur c;
	
public:
	virtual ~Lettre(){}
	virtual void dessine() const = 0;	//Chaque lettre aura sa propre méthode de dessin
};

class Aa: public Lettre	//on ne fait pas la distinction entre majuscules et minuscules
{
public:
	virtual void dessine() const override;	//c'est assez explicit...
};

class Bb: public Lettre
{
public:
	virtual void dessine() const override;
};


class Cc: public Lettre
{
public:
	virtual void dessine() const override;
};


class Dd: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ee: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ff: public Lettre
{
public:
	virtual void dessine() const override;
};


class Gg: public Lettre
{
public:
	virtual void dessine() const override;
};


class Hh: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ii: public Lettre
{
public:
	virtual void dessine() const override;
};


class Jj: public Lettre
{
public:
	virtual void dessine() const override;
};


class Kk: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ll: public Lettre
{
public:
	virtual void dessine() const override;
};


class Mm: public Lettre
{
public:
	virtual void dessine() const override;
};


class Nn: public Lettre
{
public:
	virtual void dessine() const override;
};


class Oo: public Lettre
{
public:
	virtual void dessine() const override;
};


class Pp: public Lettre
{
public:
	virtual void dessine() const override;
};


class Qq: public Lettre
{
public:
	virtual void dessine() const override;
};

class Rr: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ss: public Lettre
{
public:
	virtual void dessine() const override;
};


class Tt: public Lettre
{
public:
	virtual void dessine() const override;
};


class Uu: public Lettre
{
public:
	virtual void dessine() const override;
};


class Vv: public Lettre
{
public:
	virtual void dessine() const override;
};


class Ww: public Lettre
{
public:
	virtual void dessine() const override;
};

class Xx: public Lettre
{
public:
	virtual void dessine() const override;
};

class Yy: public Lettre
{
public:
	virtual void dessine() const override;
};

class Zz: public Lettre
{
public:
	virtual void dessine() const override;
};


#endif //GUI_LETTRES_H
