/*************************************************************************
                           Personne  -  description
                             -------------------
    début                : 15 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Interface de la classe <Personne> (fichier Personne.h) ------
#if ! defined ( PERSONNE_H_ )
#define PERSONNE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Adresse.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Personne>
// 
//
//------------------------------------------------------------------------

class Personne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const ;		
    // affichage
    void Epouser(const char * n);
    // modification du nom
    void Demenager(const char * r);
    // modification de la rue seule
    int  Age() const;
    // donner l'age

//-------------------------------------------- Constructeurs - destructeur
    Personne(const char* lePrenom="", int leJour=0, int leMois=0, int lAn=0, const char* laRue="", const char* leCode="", const char* laVille="");
    // constructeur I avec toutes les informations de bas niveau

    Personne( const string & lePrenom, const Date& laDateDeNaiss, const Adresse& lAdressePerso);
    // constructeur II avec quatre parametres 

    virtual ~Personne ();
    // destruction

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string prenom;
	Adresse adressePerso;
	Date dateNaissance;
};

//--------------------------- Autres définitions dépendantes de <Personne>

#endif // PERSONNE_H_
