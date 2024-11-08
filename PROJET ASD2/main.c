#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LSTPRIM.h"
#include"ELTPRIM.h"
#define MAX 1000

int main()
{
GRAPHE G=grapheCreer(24);
GRAPHE1 G1;
  FILE *f;
    int i=0,ordre;
    char filename[] = "C:/Users/TOSHIBA/Desktop/caracteristiques.txt";
    char line[MAX];
    char *token;
    FILE *f1;
char filename1[] = "C:/Users/TOSHIBA/Desktop/distances.txt";
char line1[MAX];
char *token1;
 char source[20],dest[20],s[20],continuer='o';
 char sour,desti,c1='o',c='o';
 int choix1,choix2,choix3,n,w,found;
 while(continuer=='o'||continuer=='O'){
  do{
printf("vous voulez poursuivre la partie 1 ou 2 : \n");
scanf("%d",&choix1);}
while(choix1!=1&&choix1!=2);
switch(choix1){
  case 1:
    while(c=='o'||c=='O'){
   do{ printf("1/creer le graphe\n2/ajouter les aretes\n3/changer la distance\n4/le plus court chemin\n5/afficher le graphe\necrire un nombre : ");
    scanf("%d",&choix3);}
    while(choix3!=1&&choix3!=2&&choix3!=3&&choix3!=4&&choix3!=5);
  switch(choix3){
  case 1 :
    printf("donner l'ordre du graphe : \n");
    scanf("%d",&ordre);
    G1=grapheCreerchar(ordre);
    for (int i=0;i<G1->v;i++){
        CHARACTERE ch=caractereCreer();
        caractereLire(&ch);
     NOEUD1 n=noeudCreerchar(ch,0);
     G1->adjList[i]=n;
    }
    break;
  case 2 :
    printf("donner la localisation : \n");
    fflush(stdin);
    scanf("%c",&sour);
    printf("donner la destination : \n");
    fflush(stdin);
    scanf("%c",&desti);
     printf("donner le poids : \n");
    scanf("%d",&w);
    CHARACTERE ch1=caractereCreer();
    ch1=sour;
     CHARACTERE ch2=caractereCreer();
    ch2=desti;
    ajoutaretechar(G1,ch1,ch2,w);
    break;
  case 3 :
     printf("donner la localisation : \n");
    fflush(stdin);
    scanf("%c",&sour);
    printf("donner la destination : \n");
    fflush(stdin);
    scanf("%c",&desti);
     printf("donner le nouveau poids : \n");
    scanf("%d",&w);
    changerdistancechar(G1,sour,desti,w);
    break;
  case 4 :
     printf("donner la localisation : \n");
    fflush(stdin);
    scanf("%c",&sour);
    printf("donner la destination : \n");
    fflush(stdin);
    scanf("%c",&desti);
    shortestPathchar(G1,sour,desti);
    break;
  case 5 :
    grapheAfficherchar(G1);
  }
  printf("voulez vous traiter une autre chose : \n");
  fflush(stdin);
  scanf("%c",&c);}
  break;
   case 2 :
while (c1=='o' ||c1=='O'){
do{printf("1/creer le graphe de la tunisie\n2/ajouter les aretes\n3/changer la distance entre deux gouvernorats\n4/le plus court chemin\n5/afficher le graphe\necrire un nombre : ");
scanf("%d",&choix2);}
 while(choix2!=1&&choix2!=2&&choix2!=3&&choix2!=4&&choix2!=5);
switch(choix2){
  case 1 :
      f=fopen(filename,"r");
    if (f == NULL) {
        printf("Erreur lors de l ouverture du fichier");
        return 1;
    }
    while (fgets(line, MAX, f)) {
        int j,m,a;
        token = strtok(line, "#");
        char nom[20];
        strcpy(nom, token);
        token = strtok(NULL, "#");
        sscanf(token, "%d/%d/%d", &j, &m, &a);
        token = strtok(NULL, "#");
        int pop = atoi(token);
        token = strtok(NULL, "#");
        int super = atoi(token);
        token = strtok(NULL, "#");
        int muni = atoi(token);
        ELEMENT e = elementCreer();
        strcpy(e->nom, nom);
        e->creation.j=j;
        e->creation.m=m;
        e->creation.a=a;
        e->pop = pop;
        e->super = super;
        e->muni = muni;
        G->adjList[i]->info=e;
        i++;}
        for(i=0;i<G->v;i++){
            printf("%s\n",G->adjList[i]->info->nom);
        }fclose(f);
  break;
  case 2:
     for(i=0;i<G->v;i++){
    fflush(stdin);
    strcpy(s,G->adjList[i]->info->nom);
   int indices=trouverNoeud(G,s);
    found = 0;
    f1 = fopen(filename1, "r");
    if (f1 == NULL) {
    printf("Erreur lors de l ouverture du fichier.\n");
    return 1;
}
while (fgets(line1, MAX, f1)) {

    char nom1[20], nom2[20],d[20];
    int dist;
    token1 = strtok(line1, "#");
    strcpy(nom1, token1);
    token1 = strtok(NULL, "#");
    strcpy(nom2, token1);
    token1 = strtok(NULL, "#");
    dist = atoi(token1);
    if(strcmp(nom1, s) == 0|| strcmp(nom2, s) == 0) {

        if(strcmp(nom1, s) == 0){
            strcpy(d,nom2);}
        else {strcpy(d,nom1);
        }
        int indiced = trouverNoeud(G, d);
        ELEMENT e1=elementCreer();
        ELEMENT e2=elementCreer();
        elementAffecter(&e1, G->adjList[indices]->info);
        elementAffecter(&e2, G->adjList[indiced]->info);
        ajoutarete(G, e1, e2, dist);
        found=1;
        }}

if (!found) {
    printf("Aucun gouvernorat trouvé.\n");
}

fclose(f1);
}if(found) printf("ajout effectue avec succes\n");
    break;
  case 3:
      printf("donnez le gouvernorat source : \n");
    fflush(stdin);
    gets(source);
    printf("donner le gouvernorat de destination : \n");
    fflush(stdin);
    gets(dest);
    printf("donner la nouvelle distance : \n");
    scanf("%d",&n);
    changerdistance(G,source,dest,n);
        break;
  case 4:
    printf("donnez la localisation actuelle : \n");
 fflush(stdin);
 gets(source);
 printf("donnez la destination souhaitee : \n");
 fflush(stdin);
 gets(dest);
 shortestPath(G,source,dest);
 break;
  case 5:
    grapheAfficher(G);
 }
 printf("voulez vous traiter une autre chose : \n");
  fflush(stdin);
  scanf("%c",&c1);}
  }
  printf("voulez vous revenir au menu principal : \n");
  fflush(stdin);
  scanf("%c",&continuer);}
  GraphDetruire(G);
  GraphDetruirechar(G1);
    return 0;
}
