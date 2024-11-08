#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ELTPRIM.h"
#include"LSTPRIM.h"
#define MAX_DIS 100000
CHARACTERE caractereCreer(void){}
CHARACTERE caractereLire(CHARACTERE* ch){
printf("donner un caractere : \n");
fflush(stdin);
scanf("%c",&(*ch));
return(*ch);
}
void caractereAffecter(CHARACTERE* ch1,CHARACTERE ch2) {
*ch1 = ch2 ;
}
void caractereDetruire (CHARACTERE ch) {}
NOEUD1 noeudCreerchar(CHARACTERE ch, int w) {
    NOEUD1 n;
    n = (NOEUD1)malloc(sizeof(structNoeud1));
    if (!n)
        printf("\nPlus d'espace");
    else {
        caractereAffecter(&(n->info),ch);
        n->w = w;
        n->suivant = NULL;
    }
    return n;
}
void noeudDetruirechar(NOEUD1 n) {
    caractereDetruire(n->info);
    free(n);
}
GRAPHE1 grapheCreerchar(int v) {
    GRAPHE1 G = malloc(sizeof(structGraph1));
     if (!G)
    {
        printf("\n Problème de mémoire");
        exit(0);}
    else{
    G->v=v;
   CHARACTERE ch=caractereCreer();
   int i;
    for (i = 0 ; i < v; i++) {
        G->adjList[i] = malloc(sizeof(structNoeud1));
        G->adjList[i]->info = ch;
        G->adjList[i]->w = 0;
        G->adjList[i]->suivant = NULL;
    }}
    return G;
}
void GraphDetruirechar(GRAPHE1 G)
{
    int i;
    NOEUD1 svt,svtNode;
    for (i=0; i<G->v;i++)
    {
        svt=G->adjList[i]->suivant;
        while(svt!=NULL)
        {
            svtNode=svt->suivant;
            noeudDetruirechar(svt);
            svt=svtNode;
        }
    }
    free(G);
}
int caractereComparer(CHARACTERE ch1,CHARACTERE ch2){
if(ch1==ch2)
    return 0;
else return 1;
}
void ajoutaretechar(GRAPHE1 G,CHARACTERE source,CHARACTERE dest,int w){
int n,i,found=0;
n=G->v;
NOEUD1 a=noeudCreerchar(dest,w);
  a->suivant = NULL;
  NOEUD1 b=noeudCreerchar(source,w);
    b->suivant = NULL;
for(i=0;i<n;i++){
 CHARACTERE ch1=caractereCreer();
 ch1=G->adjList[i]->info;
 if(caractereComparer(ch1,source)==0){
    NOEUD1 q= G->adjList[i]->suivant;
    NOEUD1 p=G->adjList[i];
    while(q!=NULL){
        p=q;
      q=q->suivant;
    }
    p->suivant = a;
        found=1;
 }if(caractereComparer(ch1,dest)==0){
    NOEUD1 q= G->adjList[i]->suivant;
    NOEUD1 p=G->adjList[i];
    while(q!=NULL){
        p=q;
      q=q->suivant;
    }
    p->suivant = b;
        found=1;
 }}
 if(!found){printf("sommet n existe pas ");}}

 void changerdistancechar(GRAPHE1 G, char source, char dest, int n) {
    int i;
    NOEUD1 s,d,q,p;
    for (i=0;i<G->v;i++) {
        if (G->adjList[i]->info==source) {
            s = G->adjList[i];}
        if (G->adjList[i]->info==dest) {
            d = G->adjList[i];}}
    q = s->suivant;
    p = d->suivant;
    while (q!= NULL) {
         if (q->info==dest){
             q->w = n;}
        q = q->suivant;}
    while (p!= NULL) {
        if (p->info==source) {
             p->w = n;}
        p = p->suivant;}}

int trouverNoeudchar(GRAPHE1 G, char nom) {
    for (int i=0;i<G->v; i++) {
        if (G->adjList[i]->info==nom){
            return i;
        }
    }
    return -1;
}
void shortestPathchar(GRAPHE1 G, char source, char dest) {
    int i;
    int indicesource=trouverNoeudchar(G, source);
    if (indicesource==-1) {
        printf("Le gouvernorat source n existe pas \n");
    }

    int indicedes=trouverNoeudchar(G, dest);
    if (indicedes==-1) {
        printf("Le gouvernorat destination n existe pas \n");
    }
    int distance[G->v];
    int visite[G->v];
    int parent[G->v];
    for (i=0;i<G->v;i++) {
    visite[i]=0;
    distance[i]=MAX_DIS;;
    parent[i]=-1;
    }
    distance[indicesource]=0;
    for(i=0;i<G->v;i++){
    if(i!=indicesource){
        int u=minpoidsneoud(distance,visite, G->v);
        visite[u]=1;
        NOEUD1 q=G->adjList[u]->suivant;
        while (q!=NULL) {
           int v=trouverNoeudchar(G,q->info);
            int wq=q->w;
            if ((!visite[v] && distance[u]!=MAX_DIS) && distance[u]+wq<distance[v]) {
                distance[v] = distance[u]+wq;
                parent[v]=u;}
            q=q->suivant;}}}
    if (distance[indicedes]==MAX_DIS) {
    printf("Il n'y a pas de chemin entre %c et %c\n",source,dest);
    }else{
    int chemin[G->v];
    int taille=0,indice=indicedes;
    while (indice!=indicesource) {
        chemin[taille++]=indice;
        indice=parent[indice];
    }
    chemin[taille]=indicesource;
    printf("de %c a %c la plus courte chemin est : \n", source, dest);
    for (int i=taille;i>=0;i--) {
        printf("%c",G->adjList[chemin[i]]->info);
        if (i>0){
            printf(" --> ");}
    }
    printf("\navec une distance de %d\n",distance[indicedes]);}}
    void grapheAfficherchar(GRAPHE1 G) {
    int i, j,n;
    n=G->v;
    for (i=0;i<n;i++) {
        for (j =i+1;j<n;j++) {
            NOEUD1 amn=G->adjList[i];
            NOEUD1 amn1=G->adjList[j];
            if (amn->info>amn1->info) {
                NOEUD1 tmp = G->adjList[i];
                G->adjList[i] = G->adjList[j];
                G->adjList[j] = tmp;}
        }}
    for (i=0;i<n;i++) {
        NOEUD1 p=(G)->adjList[i];
        NOEUD1 q=(G)->adjList[i]->suivant;
        printf("|%c|    \t",p->info);
    while(q!=NULL){
        printf("%c",q->info);
        printf("(%d)   ",q->w);
      q=q->suivant;

    }        printf("\n\n");
}}

