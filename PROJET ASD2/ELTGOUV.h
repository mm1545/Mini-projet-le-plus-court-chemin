#ifndef _ELTGOUV_H
#define _ELTGOUV_H
//element du premier partie
typedef char CHARACTERE;
//element du deuxieme partie
typedef struct{
int j;
int m;
int a;
}Date;
typedef struct{
char nom[20];
Date creation;
int pop;
int super;
int muni;
}gouv,*ELEMENT;
#endif
