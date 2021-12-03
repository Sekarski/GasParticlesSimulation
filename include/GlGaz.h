#ifndef PRJ_GLGAZ_H
#define PRJ_GLGAZ_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/glcanvas.h" // Pour combiner wxWidgets et OpenGL
#include "Vecteur.h"
#include "Particule.h"	//Pour l'héritage de Particule
#include "Tracable.h"


class GlHelium : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlHelium();
	GlHelium(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 4.002602);
	GlHelium(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t = 0, double const& m = 4.002602);
	virtual ~GlHelium();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};


class GlNeon : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlNeon();
	GlNeon(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 20.1797);
	GlNeon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t = 0, double const& m = 20.1797);
	virtual ~GlNeon();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};


class GlArgon : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlArgon();
	GlArgon(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 39.948);
	GlArgon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t = 0, double const& m = 39.948);
	virtual ~GlArgon();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};



class GlKrypton : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlKrypton();
	GlKrypton(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 83.798);
	GlKrypton(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t= 0, double const& m = 83.798);
	virtual ~GlKrypton();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};

class GlXenon : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlXenon();
	GlXenon(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 131.293);
	GlXenon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t = 0, double const& m = 131.293);
	virtual ~GlXenon();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};

class GlRadon : public Particule, public Tracable
{
private:
	GLUquadric* sphere;
	
public:

	GlRadon();
	GlRadon(Vecteur const& p, Vecteur const& v, unsigned int const& t = 0, double const& m = 222);
	GlRadon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, unsigned int const& t = 0, double const& m = 222);
	virtual ~GlRadon();
	virtual void dessine() const override;
	virtual void evolue(double const& dt) override;
};


#endif //PRJ_GAZ_H
