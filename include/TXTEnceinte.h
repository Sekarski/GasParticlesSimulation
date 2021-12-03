#ifndef PRJ_TXTENCEINTE_H
#define PRJ_TXTENCEINTE_H

#include "Enceinte.h"

class TXTEnceinte: public Enceinte	//comme d'habitude EST-UN
{
public:
	virtual void dessine() const override;
	TXTEnceinte();							//enceinte par défaut
	virtual ~TXTEnceinte();					//pas vraiment nécessaire, vu que c'est le dernier niveau d'héritage
	TXTEnceinte(double const& p, double const& l, double const& h);

};

#endif //PRJ_TXTENCEINTE_H
