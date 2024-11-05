//============================================================================
// Name        : TClassesDuProjet.cpp
// Author      : psc
// Version     : 2012
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Adresse.h"
#include "Date.h"
#include "Personne.h"


void testAdresse()
{
  cout << endl << "tests de la classe adresse :"<<endl;
  //creation d'un objet adresse non initialise :
  Adresse sans;
  cout<< "adresse non initialisee : ";
  sans.Afficher();
  cout << endl;

  //initialisation de cet objet :
  sans.MettreAJour("12345", "PARIS" );
  cout<< "adresse apres initialisation : ";
  sans.Afficher();
  cout << endl;

  //initialisation de cet objet :
  sans.MettreAJourLaRue("Place des vosges" );
  cout<< "adresse apres initialisation : ";
  sans.Afficher();
  cout << endl;

  cout<< "instanciation avec bonne initialisation :  ";
  Adresse loin( "29", "Quimper", "3 rue des prunelles");
  loin.Afficher();
  cout << endl;

}

void testDate()
{
  cout<<"tests de la classe date"<<endl;
  //creation d'un objet date non initialise :
  Date vide;
  cout<< "date vide : ";
  vide.Afficher();
  cout << endl;

  //creation d'un objet date erronne :
  Date fausse(56,13,-33);
  cout<< "date erronnee rectifiee en : ";
  fausse.Afficher();
  cout << endl;

  //creation d'un objet date erronne annee non bissextile :
  Date fausse2(29,2,1900);
  cout<< "date erronnee annee non bissextile rectifiee en  : ";
  fausse2.Afficher();
  cout << endl;

  //creation d'un objet date annee bissextile :
  Date autre(29,2,2000);
  cout<< "date  annee bissextile  : ";
  autre.Afficher();
  cout << endl;

  Date autre2(1,1,2001);
  cout<< "date autre : ";
  autre2.Afficher();
  autre2.Modifier(2,2,2002);
  autre2.Afficher();
  cout << "c etait en l'an : " << autre2.Annee() << endl;
  cout << endl;
}

void testPersonne()
{

	  cout << "tests de la classe personne :"<<endl;

	  cout << "tests du constructeur I :"<<endl;
	  Personne p1("Dupont", 1,1,1933);
	  cout << "test methode Afficher :"<<endl;
	  p1.Afficher();		
	  cout << "test methode Epouser :"<<endl;
	  p1.Epouser("Moulinot");             
	  cout << "test methode Demenager :"<<endl;
	  p1.Demenager("12 rue du Port");
	  cout<<"***** p1 apres mariage et demenagement :";
	  p1.Afficher();		
	  cout << "test methode Age :"<<endl;
	  cout << "Age de p1 : " << p1.Age()<<endl;

	  Date d1(2,2, 1992);
	  Adresse a1("69100", "Villeurbanne", "20 avenue Albert Einstein");
	  cout << "tests du constructeur II :"<<endl;
	  Personne p2("Dupont", d1, a1);
	  p2.Afficher();

}

void testSalarie()
{
	  // liste du personnel simplifiee allouee a la compilation
	  // sous forme d'un tableau de pointeurs sur Personne
	  Personne * personnel[10];
	  int nbPersonnes = 0;

	  Personne *pt1= new Personne("Dupont");
	  pt1->Epouser("LENORMAND");
	  // pt1->Demenager("14390","Cabourg","12 rue du Port");
	  personnel[0]=pt1;
	  Personne p1("Dupont");
	  personnel[1]=&p1;
	  nbPersonnes = 2;

/*	  cout << "tests de la classe Salarie"<<endl;
	  cout << "test du constructeur I :"<<endl;
	  Salarie *pt2= new Salarie("RICH", 1,1,1970, 1000.0 );
	  pt2->Augmenter(15000.);
	  personnel[2]=pt2;
	  Salarie p2("PLUSRICH", 1,1, 1990, 2000.0);
	  personnel[3]=&p2;
	  nbPersonnes = 4;
*/
	  cout << "*****liste du personnel de l'entreprise : "<< endl;
	  for ( int i=0;i<nbPersonnes;i++)
	  		personnel[i]->Afficher();
	  cout << "*****fin de liste du personnel de l'entreprise"<<endl;
	  delete pt1;
/*	  delete pt2;
*/
	  cout<<"***** c'est fini "	<<endl;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

//	testAdresse();
//	testDate();
	testPersonne();
//	testSalarie();
	cout << "!!!Fin des tests!!!" << endl;
	return 0;
}
