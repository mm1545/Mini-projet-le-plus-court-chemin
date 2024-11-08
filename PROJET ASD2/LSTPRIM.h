#ifndef _LSTPRIM_H
#define _LSTPRIM_H
#include"LSTSDD.h"
//les primitives du deuxieme partie
NOEUD noeudCreer(ELEMENT e,int w);
void noeudDetruire(NOEUD n);
int inserer (NOEUD tab[], ELEMENT e, int pos);
int supprimer (GRAPHE G, char nom[20] );
void listeAfficher(NOEUD tab[24]);
GRAPHE grapheCreer(int v);
void GraphDetruire(GRAPHE);
void grapheAfficher(GRAPHE);
void ajoutarete(GRAPHE G,ELEMENT source,ELEMENT dest,int w);
int trouverNoeud(GRAPHE G, char nom[20]);
int minpoidsneoud(int *distance, int *visite, int n);
void shortestPath(GRAPHE G, char source[20], char dest[20]);
void changerdistance(GRAPHE G,char source[20],char dest[20],int n);
//les primitives du premier partie
void ajoutaretechar(GRAPHE1,CHARACTERE,CHARACTERE,int);
void changerdistancechar(GRAPHE1,char,char,int);
int trouverNoeudchar(GRAPHE1, char);
void shortestPathchar(GRAPHE1, char, char);
void grapheAfficherchar(GRAPHE1);
GRAPHE1 grapheCreerchar(int);
void GraphDetruirechar(GRAPHE1);
void noeudDetruirechar(NOEUD1);
NOEUD1 noeudCreerchar(CHARACTERE, int);






#endif
