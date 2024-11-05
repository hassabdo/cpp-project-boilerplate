/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 10 déc. 2008
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <ctime>
#include <string>
//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes
int Date::nbjours[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string Date::nomdumois[]={"JANVIER","FEVRIER","MARS","AVRIL","MAI","JUIN",
	"JUILLET","AOUT","SEPTEMBRE","OCTOBRE","NOVEMBRE","DECEMBRE"};
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Date::Modifier(int nouveauJour, int nouveauMois, int nouveauAn)
{
#ifdef MAP
cout << "Date::Modifier()"<<endl;
#endif
  // a faire : les memes tests de validite que dans le constructeur!!
  jour=nouveauJour;
  mois=nouveauMois;
  an=nouveauAn;
}

void Date::Afficher() const
{
#ifdef MAP
cout << "Date::Afficher()"<<endl;
#endif
  cout.width(2);cout.fill('0');cout.setf(ios::right,ios::adjustfield);
  cout<<jour<<"/";
  cout.fill('*');cout.setf(ios::left,ios::adjustfield); cout.width(10);
  cout<<nomdumois[mois-1].c_str()<<"/";
  cout.width(4);cout.fill('0');cout.setf(ios::right, ios::adjustfield);
  cout<<an<<endl;
}

int Date::Annee() const
{
#ifdef MAP
cout << "Date::Annee()"<<endl;
#endif
	return an;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Date::Date(int jj, int mm, int aa)
// constructeur garantissant une initialisation correcte de l'objet Date :
// on vérifie la valeur du jour en tenant compte des années bissextiles
// en cas d'erreur, on prend la date du jour actuel !
// quand les parametres valent (0/0/0), on prend aussi la date du jour actuel !
{
#ifdef MAP
cout << "Date::Date()"<<endl;
#endif
  // pour connaitre la date systeme locale, utiliser la struct tm :
  /*
   int tm_sec;    // Seconds after the minute - [0,59]
   int tm_min;    // Minutes after the hour - [0,59]
   int tm_hour;   // Hours since midnight - [0,23]
   int tm_mday;   // Day of the month - [1,31]
   int tm_mon;    // Months since January - [0,11]
   int tm_year;   // Years since 1900
   int tm_wday;   // Days since Sunday - [0,6]
   int tm_yday;   // Days since January 1 - [0,365]
   int tm_isdst;  // Daylight-saving-time flag
*/
  int max; // nb jours du mois tenant compte des annees bissextiles
  bool erreur = false;
  struct tm *aujourdhui;
  time_t today;
  time( &today ); 	             	// donne la date en secondes dans un entier long today
  aujourdhui  = localtime( &today );	// convertit les secondes en jour, mois, an dans la structure aujourd'hui
  jour =  jj ? jj : aujourdhui->tm_mday;
  mois =  mm ? mm : aujourdhui->tm_mon+1 ;
  an   =  aa ? aa : aujourdhui->tm_year+1900;
  // on verifie l'année
  if ( an < 0 )
  {
	  erreur = true;
  }
  // on verifie le mois
  if ( mois < 0 || mm > 12 )
  {
	  erreur=true;
  }
  // on verifie le jour
  max = nbjours[mois-1];
  if (  // annee bissextile
  	((an % 400 == 0) ||  ( (an % 100!=0) && (an%4==0) ) )
  	// et fevrier
  	&& mois ==2 )
  {
	max++;
  }
  if ( jour < 0 || jour > max )
  {
	erreur = true;
  }
  if (erreur == true)
  {
	an=aujourdhui->tm_year+1900;
	mois = aujourdhui->tm_mon+1;
	jour = aujourdhui->tm_mday;
  }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
