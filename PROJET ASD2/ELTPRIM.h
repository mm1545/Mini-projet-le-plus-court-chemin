#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include"ELTSDD.h"
//les primitives du deuxieme partie
void elementLire(ELEMENT*);
void elementAfficher(ELEMENT);
void elementAffecter(ELEMENT*, ELEMENT);
int elementCopier(ELEMENT *, ELEMENT) ;
int elementComparer(ELEMENT, ELEMENT);
ELEMENT elementCreer(void) ;
void elementDetruire (ELEMENT);
//les primitives du premier partie
CHARACTERE caractereCreer(void);
int caractereComparer(CHARACTERE ch1,CHARACTERE ch2);
void caractereDetruire (CHARACTERE);
void caractereAffecter(CHARACTERE*,CHARACTERE);
CHARACTERE caractereLire(CHARACTERE*);
#endif
