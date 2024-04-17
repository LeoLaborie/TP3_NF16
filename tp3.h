#ifndef TP3_H
#define TP3_H
#include <stdlib.h>
typedef struct sommet{
    int indice;
    struct sommet *suiv;
    struct voisin *voisin;
}sommet;

typedef struct voisin{
    int indice;
    struct voisin *suiv;
}voisin;

typedef struct graphe{
    struct sommet *sommet;
}graphe;

graphe* creerGraphe();

void creerSommet(graphe *g, int id);

sommet* rechercherSommet(graphe g, int id);

void ajouterArete(graphe *g, int id1, int id2);

graphe* construireGraphe(int N);

void afficherGraphe(graphe g);

int rechercherDegre(graphe g);

void supprimerSommet(graphe *g, int id);

int contientBoucle(graphe g);

void fusionnerSommet(graphe *g, int idSommet1, int idSommet2);

int is_in_voisin(sommet s, int id_sommet);

void liberer_proprement_sommets(sommet *s);

void liberer_proprement_voisins(voisin *vois);
#endif