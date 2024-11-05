/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 10 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ------
#if ! defined ( DATE_H_ )
#define DATE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Date>
// 
// Classe simple qui permet de gerer des dates contenant les informations de (jour, mois, an)
// Remarque : un objet construit sans parametres correspond a la date du jour
//
//------------------------------------------------------------------------

class Date
{

//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Modifier(int nouveauJour=0, int nouveauMois=0, int nouveauAn=0);
    // Modifier une date existante
    void Afficher() const;
    // Afficher une date sous la forme jj/mm/aaaa
    int Annee() const;
    // Retourner l'année

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Date(int j=0, int m=0, int a=0);
    // Par défaut (0/0/0), la date est initialisée à la date du jour
    // En cas d'erreur 
    // (numero du jour invalide pour le mois donné, mois <0, an<0 ),
    // la date est aussi initialisée à la date du jour

//------------------------------------------------------------------ PRIVE

protected:
	static int nbjours[12];
	static string nomdumois[12];
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int jour;	// 1 a 31
	int mois;	// 1 a 12
	int an;		// sur quatre digits
};

//--------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H_
