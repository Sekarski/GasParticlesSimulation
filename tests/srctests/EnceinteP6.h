#ifndef PRJ_ENCEINTEP6_H		//pour éviter de complier plusieurs fois cette classe...
#define PRJ_ENCEINTEP6_H		//...si par erreur on l'aurait inclu plusieurs fois dans le projet

class Enceinte
{
protected:
double hauteur;
double largeur;
double profondeur;

public:
/*_______________________Constructeurs________________________*/
Enceinte(); //Constructeur par défaut
Enceinte(double const& h, double const& l, double const& p); //initialiser
virtual ~Enceinte();
double getHauteur() const;
double getLargeur() const;
double getProfondeur() const;
void setHauteur(double const& h);
void setLargeur(double const& l);
void setProfondeur(double const& p);

/*__________________________Méthodes__________________________*/
double volume() const;
};

#endif // PRJ_ENCEINTEP6_H
