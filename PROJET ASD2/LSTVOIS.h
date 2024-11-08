#ifndef _LSTVOIS_H
#define _LSTVOIS_H
#include"ELTPRIM.h"
//la structure du deuxieme partie
typedef struct structNoeud{
ELEMENT info;
int w;
struct structNoeud *suivant;
}structNoeud,*NOEUD;
typedef struct {
int v;
NOEUD adjList[24];
}structGraph,*GRAPHE;
//la structure du premiere partie
typedef struct structNoeud1{
CHARACTERE info;
int w;
struct structNoeud1 *suivant;
}structNoeud1,*NOEUD1;
typedef struct {
int v;
NOEUD1 adjList[24];
}structGraph1,*GRAPHE1;
#endif
