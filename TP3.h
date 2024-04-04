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
