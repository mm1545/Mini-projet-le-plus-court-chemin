#define MAX_DIS 100000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LSTPRIM.h"
#include"ELTPRIM.h"
NOEUD noeudCreer(ELEMENT e, int w){
    NOEUD n;
    n = (NOEUD)malloc(sizeof(structNoeud));
    if (!n)
        printf("\nPlus d'espace");
    else {
        elementAffecter(&(n->info),e);
        n->w = w;
        n->suivant = NULL;
    }
    return n;
}

void noeudDetruire(NOEUD n) {
    elementDetruire(n->info);
    free(n);
}

int inserer(NOEUD tab[], ELEMENT e, int pos) {
    int i,taille=0;
for (i=1; i<pos; i++) {
taille++;
}
    int success = 1;

    if (taille == 24) {
        printf("\nListe saturée");
        success = 0;
    } else if (pos < 0 || pos > 24) {
        printf("\nPosition invalide");
        success = 0;
    } else {
        NOEUD n1 = noeudCreer(e,0);
        n1->suivant = NULL;
        for (i = taille-1; i >= pos; i--) {
            tab[i+1] = tab[i];
        }
        tab[pos] = n1;
    }
    return success;
}
void GraphDetruire(GRAPHE G)
{
    int i;
    NOEUD svt,svtNode;
    for (i=0; i<G->v;i++)
    {
        svt=G->adjList[i];
        while(svt->suivant!=NULL)
        {
            svtNode=svt->suivant->suivant;
            noeudDetruire(svt);
            svt=svtNode;
        }noeudDetruire(svt);
    }
    free(G);
}
GRAPHE grapheCreer(int v) {
    GRAPHE G = malloc(sizeof(structGraph));
     if (!G)
    {
        printf("\n Problème de mémoire");
        exit(0);}
    else{
    G->v=v;
   ELEMENT e= elementCreer();
   int i;
    for (i = 0 ; i < v; i++) {
        G->adjList[i] = malloc(sizeof(structNoeud));
        G->adjList[i]->info = e;
        G->adjList[i]->w = 0;
        G->adjList[i]->suivant = NULL;
    }}
    return G;
}
void grapheAfficher(GRAPHE G) {
    int i, j,n;
    n=G->v;
    for (i = 0; i <n ; i++) {
        for (j = i+1; j <n; j++) {
            NOEUD amn = G->adjList[i];
            NOEUD amn1 =  G->adjList[j];
            if (strcmpi(amn->info->nom, amn1->info->nom) > 0) {
                NOEUD tmp = G->adjList[i];
                G->adjList[i] = G->adjList[j];
                G->adjList[j] = tmp;}
        }}
    printf("\t\tgouvernorats   ses voisins\n\n");
    for (i = 0; i<n ; i++) {
        NOEUD p=G->adjList[i];
        NOEUD q=G->adjList[i]->suivant;
        printf("|%s|    \t",p->info->nom);
    while(q!=NULL){
        printf("%s",q->info->nom);
        printf("(%d)   ",q->w);
      q=q->suivant;

    }        printf("\n\n");
}}
void ajoutarete(GRAPHE G,ELEMENT source,ELEMENT dest,int w){
int n,i,found=0;
n=G->v;
NOEUD a=noeudCreer(dest,w);
  a->suivant = NULL;
  NOEUD b=noeudCreer(source,w);
    b->suivant = NULL;
for(i=0;i<n;i++){
 ELEMENT e1=elementCreer();
 e1=G->adjList[i]->info;
 if(elementComparer(e1,source)==0){
    NOEUD q= G->adjList[i]->suivant;
    NOEUD p=G->adjList[i];
    while(q!=NULL){
        p=q;
      q=q->suivant;
    }
    p->suivant = a;
        found=1;
 }
 }
 if(!found){printf("sommet n existe pas ");}}

int trouverNoeud(GRAPHE G, char nom[20]) {
    for (int i = 0; i <G->v; i++) {
        if (strcmp(G->adjList[i]->info->nom, nom) == 0) {
            return i;}}
    return -1;
}

int minpoidsneoud(int *distance, int *visite, int n) {
    int min=MAX_DIS,minindice;
    for (int i = 0; i <n; i++) {
        if (!visite[i] && distance[i] <= min) {
            min = distance[i];
            minindice = i;
        }
    }
    return minindice;
}

void shortestPath(GRAPHE G, char source[20], char dest[20]) {
    int i;
    int indicesource=trouverNoeud(G, source);
    if (indicesource==-1) {
        printf("Le gouvernorat source n existe pas \n");
    }

    int indicedes=trouverNoeud(G, dest);
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
        NOEUD q=G->adjList[u]->suivant;
        while (q!=NULL) {
           int v=trouverNoeud(G,q->info->nom);
            int wq=q->w;
            if ((!visite[v] && distance[u]!=MAX_DIS) && distance[u]+wq<distance[v]) {
                distance[v] = distance[u]+wq;
                parent[v]=u;}
            q=q->suivant;}}}
    if (distance[indicedes]==MAX_DIS) {
    printf("Il n'y a pas de chemin entre %s et %s\n",source,dest);
    }else{
    int chemin[G->v];
    int taille=0,indice=indicedes;
    while (indice!=indicesource) {
        chemin[taille++]=indice;
        indice=parent[indice];
    }
    chemin[taille]=indicesource;
    printf("de %s a %s la plus courte chemin est : \n", source, dest);
    for (int i=taille;i>=0;i--) {
        printf("%s",G->adjList[chemin[i]]->info->nom);
        if (i>0){
            printf(" --> ");}
    }
    printf("\navec une distance de %d km\n",distance[indicedes]);}}

int supprimer (GRAPHE G, char nom[20]) {
int i,taille=0,pos;
for(i=0;i<G->v;i++){
if (strcmp(nom,G->adjList[i]->info->nom)==0) {pos=i;}}
for (i=0; i<pos; i++) {
taille++;
}
int succee=1;
if (taille==0) {

printf ("graphe vide");
succee=0;}

else {
for(i=0;i<G->v;i++){
if (strcmp(nom,G->adjList[i]->info->nom)==0) {
elementDetruire(G->adjList[pos]->info);
for(i=pos;i<G->v;i++)

elementAffecter(&G->adjList[i]->info,G->adjList[i+1]->info);

(G->v)--;
}}}
 return(succee);
}

void changerdistance(GRAPHE G, char source[20], char dest[20], int n) {
    int i;
    NOEUD s,d,q,p;
    for (i=0;i<G->v;i++) {
        if (strcmp(source, G->adjList[i]->info->nom) == 0) {
            s = G->adjList[i];}
         if (strcmp(dest, G->adjList[i]->info->nom) == 0) {
            d = G->adjList[i];}}
    q = s->suivant;
    p = d->suivant;
    while (q!= NULL) {
        if (strcmp(dest, q->info->nom) == 0) {
             q->w = n;}
        q = q->suivant;}
    while (p!= NULL) {
        if (strcmp(source, p->info->nom) == 0) {
             p->w = n;}
        p = p->suivant;}}
