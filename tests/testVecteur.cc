
#include <iostream>
#include "../include/Vecteur.h"	//pour pouvoir utiliser nos vecteurs :)
using namespace std;

/*                _,.---.---.---.--.._ 
*             _.-' `--.`---.`---'-. _,`--.._
*            /`--._ .'.     `.     `,`-.`-._\
*           ||   \  `.`---.__`__..-`. ,'`-._/
*      _  ,`\ `-._\   \    `.    `_.-`-._,``-.
*   ,`   `-_ \/ `-.`--.\    _\_.-'\__.-`-.`-._`.
*  (_.o> ,--. `._/'--.-`,--`  \_.-'       \`-._ \
*   `---'    `._ `---._/__,----`           `-. `-\
*             /_, ,  _..-'                    `-._\
*             \_, \/ ._(
*              \_, \/ ._\
*               `._,\/ ._\
*                 `._// ./`-._
*                   `-._-_-_.-'
*/


void test_comparaison(Vecteur const& v1, Vecteur const& v2, Vecteur const& v3); //test l'égalité de v1 avec v2, pui avec v3
void test_operation(Vecteur const& v1, Vecteur const& v2, char const& op);
/* test les operations définies pour les vecteurs.
 * op peut prendre les valeurs suivante:
 * '+' pour l'addition
 * '-' pour la soustraction
 * '*' pour le produit scalaire
 * '^' pour le produit vectoriel */
void test_norme(Vecteur const& v);	// test les méthodes norme() et norme_carre()
void test_oppose(Vecteur const& v1, Vecteur const& v2);	//vérifie que l'additon de l'opposé = la soustraction
void test_mult(Vecteur const& v, double const& k);	//test la multiplication scalaire


int main()
{
	Vecteur vect1(1.0, 2.0, -0.1);
	Vecteur vect2(2.6, 3.5, 4.1);
	Vecteur vect3 = vect1;
	Vecteur vnul;

	//test l'affichage
	cout <<"Vecteur 1: " << vect1 << endl;
	cout <<"Vecteur 2: " << vect2 << endl;
	
	cout << endl << endl << "----------Test1: comparaison---------" <<endl;
	test_comparaison(vect1, vect2, vect3);
	
	cout << endl << endl << "----------Test2: addition---------" << endl;
	test_operation(vect1, vect2, '+');
	test_operation(vect2, vect1, '+');		//vérifie la commutativité de +
	test_operation(vect1, vnul, '+');		//vérifie l'addition du vecteur nul
	test_operation(vnul, vect1, '+');		//idem
	test_operation(vect2, vect2, '+');		//faut encore vérifier toutes les opérations d'auto-affectation (+=,-=, etc...)
	
	cout << endl << endl << "----------Test3: soustraction---------" << endl;
	test_operation(vect1, vect2, '-');
	test_operation(vect2, vect1, '-');		//commutativité
	
	
	cout << endl << endl << "----------Test4: produit scalire---------" << endl;
	test_operation(vect1, vect2, '*');
	test_operation(vect2, vect1, '*');		//commutativité
	
	cout << endl << endl << "----------Test5: produit vectoriel---------" << endl;
	test_operation(vect1, vect2, '^');
	test_operation(vect2, vect1, '^');		//commutativité
	
	cout << endl << endl << "----------Test6: opposé---------" << endl;
	test_oppose(vect1, vect2);
	
	cout << endl << endl << "----------Test7: multiplicaiton scalaire---------" << endl;
	test_mult(vect1, 3.0);					//test aussi la commutativité (cf. définition de la fonction)
	
	cout << endl << endl << "----------Test8: norme---------" << endl;
	test_norme(vect1);						//test aussi la fonction norme_carre()
	test_norme(vect2);
	
	Vecteur v4(1.0,1.0,1.0);
	cout << v4.sym(Vecteur(0.0,1.0,0.0)) << endl;	//test la symétrique vectorielle
	
	return 0;	
}

void test_comparaison(Vecteur const& v1, Vecteur const& v2, Vecteur const& v3)
{
	cout << "le Vecteur 1 est ";
	if(v1 == v2)
	{
		cout << "egal au ";
	}
	else
	{
		cout << "différent du ";
	}
	cout << "vecteur 2" << endl << "et est ";
	if(v1 != v3)
	{
		cout << "différent du ";
	}
	else
	{
		cout << "egal au ";
	}
	cout << "vecteur 3" << endl;
}

void test_operation(Vecteur const& v1, Vecteur const& v2, char const& op)
{
	cout << v1 <<" " << op <<" " << v2 << " = ";
	if(op == '+')		//j'vais peut etre mettre un "switch" a la place de tout ces "else if"
	{
		cout << v1 + v2;
	}
	else if (op == '-')
	{
		cout << v1 - v2;
	}
	else if(op == '*')
	{
		cout << v1 * v2;
	}
	else if(op == '^')
	{
		cout << (v1^v2);		//je sais pas pourquoi, mais quand je mets pas les () ça foire, contrairement aux autre opérations
	}							//EDIT: en fait c'est la priorité des opérations: << est prioritaire sur ^
	cout << endl;
}

/* TTTTT  H   H  EEEEE     GGGGG  AAAAA  M   M  EEEEE
 *   T    H   H  E         G      A   A  MM MM  E
 *   T    HHHHH  EEE       G  GG  AAAAA  M M M  EEE
 *   T    H   H  E         G   G  A   A  M   M  E
 *   T    H   H  EEEEE     GGGGG  A   A  M   M  EEEEE */

void test_norme(Vecteur const& v)
{
	cout << "||" << v << "||^2 = " << v.norme_carre() << endl;	
	cout << "||" << v << "|| = " << v.norme() << endl;
}

void test_oppose(Vecteur const& v1, Vecteur const& v2)
{
	cout << "-" << v1 << " = " << -v1 << endl;	
	cout << "-" << v2 <<" + "<< v1 << " = " << -v2 + v1 << endl;

}

void test_mult(Vecteur const& v, double const& k)
{
	cout << " " << k <<" * " << v << " = " << k*v << endl;
	cout << " " << v <<" * " << k << " = " << v*k << endl;
}
