#ifndef PRJ_GAZ_H
#define PRJ_GAZ_H

#include "Particule.h"	//Pour l'héritage de Particule
#define MASSE_HE 4.002602		//constantes de préprocesseur
#define MASSE_NE 20.1797		//cf Wikipédia pour les valeurs
#define MASSE_AR 39.948
#define MASSE_KR 83.798
#define MASSE_XE 131.293
#define MASSE_RA 222

class TXTHelium : public Particule	//Helium est une particule
{
public:
	TXTHelium();	//constructeur par défaut qui apelle le constructeur par défaut de Particule (qui on le rapelle construit une particule d'hélium)
	//constructeur explicite, avec une valeur par défaut de la masse
	TXTHelium(Vecteur const& p, Vecteur const& v, double const& m = MASSE_HE);
	TXTHelium(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_HE);
	virtual void dessine() const override;		//redéfinition
};

class TXTNeon : public Particule
{				//cf TXThélium pour les commentaires généraux
public:
	TXTNeon(double const& m = MASSE_NE);	//le constructeur par défaut de Particule ne fait plus l'affaire, car ce n'est plus de l'hélium
	TXTNeon(Vecteur const& p, Vecteur const& v, double const& m = MASSE_NE);
	TXTNeon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_NE);
	virtual void dessine() const override;
};

class TXTArgon : public Particule
{
public:
	TXTArgon(double const& m = MASSE_AR);	//on a un constructeur par défaut si on ne spécifie pas la masse
	TXTArgon(Vecteur const& p, Vecteur const& v,  double const& m = MASSE_AR);
	TXTArgon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_AR);
	virtual void dessine() const override;
};

class TXTKrypton: public Particule
{
public:
	TXTKrypton(double const& m = MASSE_KR);
	TXTKrypton(Vecteur const& p, Vecteur const& v,  double const& m = MASSE_KR);
	TXTKrypton(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_KR);
	virtual void dessine() const override;
};

class TXTXenon: public Particule
{
public:
	TXTXenon(double const& m = MASSE_XE);
	TXTXenon(Vecteur const& p, Vecteur const& v,  double const& m = MASSE_XE);
	TXTXenon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_XE);
	virtual void dessine() const override;
};

class TXTRadon: public Particule
{
public:
	TXTRadon(double const& m = MASSE_RA);
	TXTRadon(Vecteur const& p, Vecteur const& v,  double const& m = MASSE_RA);
	TXTRadon(double const& a, double const& b, double const& c, double const& va, double const& vb, double const& vc, double const& m = MASSE_RA);
	virtual void dessine() const override;
};

#endif //PRJ_GAZ_H
