/*************************************************************************
                           Adresse  -  description
                             -------------------
    début                : 10 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Réalisation de la classe <Adresse> (fichier Adresse.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Adresse.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Adresse::MettreAJour(const char * leCode, const char * laVille, const char * laRue)
{
#ifdef MAP
cout << "Adresse::MettreAJour()"<<endl;
#endif
  init_adr(leCode,laVille,laRue);
}

void Adresse::MettreAJourLaRue(const char * laRue)
// code postal et ville restent inchanges
{
#ifdef MAP
cout << "Adresse::MettreAJour()"<<endl;
#endif
  rue = laRue;
}

void Adresse::Afficher() const
// affichage avec formatage simple
{
#ifdef MAP
cout << "Adresse::Afficher()"<<endl;
#endif
  cout.fill('*');cout.width(LG_RUE);cout.setf(ios::left,ios::adjustfield);
  cout<<rue.c_str();
  cout.width(LG_COD);cout.fill('*');
  cout<<codepostal.c_str();
  cout.width(LG_VIL);cout.fill('*');
  cout<< ville.c_str()<<endl;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Adresse::Adresse(const char * leCode, const char * laVille, const char * laRue)
// Algorithme :
//
{
#ifdef MAP
    cout << "Adresse::Constructeur avec trois parametres" << endl;
#endif
    init_adr(leCode, laVille, laRue);
} //----- Fin de Adresse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Adresse::init_adr (const char * c, const char * v,const char * r)
{
#ifdef MAP
cout << "Adresse::init_adr()"<<endl;
#endif
  codepostal = c;
  ville = v;
  rue = r;
}
