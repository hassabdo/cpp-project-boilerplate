/*************************************************************************
                           Personne  -  description
                             -------------------
    début                : 29 nov. 2012
    copyright            : (C) 2010 par pcoquard
*************************************************************************/

//---------- Réalisation de la classe <Personne> (fichier Personne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Personne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Personne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void Personne::Afficher() const
    {
#ifdef MAP
    cout << "Personne::Afficher()" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
    }

    void Personne::Epouser(const char * n)
    {
#ifdef MAP
    cout << "Personne::Epouser()" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
    }
    
    void Personne::Demenager(const char * r)
    {
#ifdef MAP
        cout << "Personne::Demenager() " << endl;
#endif
    	cout << "Votre code a inserer ici ..." << endl;
    }

    int  Personne::Age() const
    {
#ifdef MAP
        cout << "Personne::Age()" << endl;
#endif
    	cout << "Votre code a inserer ici ..." << endl;
        return 20;// pourquoi pas !
    }

//-------------------------------------------- Constructeurs - destructeur
    Personne::Personne(const char* lePrenom, int leJour, int leMois, int lAn, const char* laRue, const char* leCode, const char* laVille)
    // constructeur I avec toutes les informations de bas niveau
    {
#ifdef MAP
    cout << "Appel au constructeur I de <Personne>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
    }

    Personne::Personne(const string & lePrenom, const Date& laDateDeNaiss, const Adresse& lAdressePerso)
    // constructeur II avec quatre parametres
    {
#ifdef MAP
    cout << "Appel au constructeur II de <Personne>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
    }

    Personne::~Personne ( )
    // Algorithme :
    //
    {
#ifdef MAP
    cout << "Appel au destructeur de <Personne>" << endl;
#endif
	cout << "Votre code a inserer ici ..." << endl;
    } //----- Fin de ~Personne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
