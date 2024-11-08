#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ELTPRIM.h"
 ELEMENT elementCreer (void) {
ELEMENT L;
L = (ELEMENT)malloc(sizeof(gouv));
return L;
}
void elementDetruire (ELEMENT elt) {
free (elt);
}
void elementLire(ELEMENT* e) {
    printf("Donnez le nom du gouvernat : ");
    fflush(stdin);
    fgets((*e)->nom,20,stdin);
    printf("Donnez la date de sa creation : ");
    scanf("%d %d %d",&((*e)->creation).j,&((*e)->creation).m,&((*e)->creation).a);
    printf("Donnez la population : ");
    scanf("%d", &((*e)->pop));
    printf("Donnez le superficie  : ");
    scanf("%d", &((*e)->super));
    printf("Donnez le nombre de municipalites  : ");
    scanf("%d", &((*e)->muni));
    }

void elementAfficher(ELEMENT elt) {
printf("nom = %s\ndate de creation= %d/%d/%d\npopulation = %d\nsuperficie= %d\nmunicipalites=%d\n",elt->nom,((elt)->creation).j,((elt)->creation).m,((elt)->creation).a,elt->pop,elt->super, elt->muni);
}
void elementAffecter(ELEMENT* e1, ELEMENT e2) {
*e1 = e2 ;
}
int elementCopier(ELEMENT *e1, ELEMENT e2) {
strcpy((*e1)->nom, e2->nom);
(*e1)->creation.j= e2->creation.j;
(*e1)->creation.m= e2->creation.m;
(*e1)->creation.a= e2->creation.a;
(*e1)->pop= e2->pop;
(*e1)->super= e2->super;
(*e1)->muni= e2->muni;}
int elementComparer(ELEMENT e1, ELEMENT e2) {
return ((e1->pop)-(e2->pop)) ;
}
