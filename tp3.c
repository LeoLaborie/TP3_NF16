#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>
graphe* creerGraphe(){
    graphe *g;
    return g;
}

void creerSommet(graphe *g, int id){
    sommet s;
    s.indice = id;
    // voisin voisin_creer;
    // voisin_creer.indice = 0;
    // while (voisin_creer.indice != -1){
    //     printf("veuiller rentrer un voisin pour le sommet %d (-1 pour quitter)\n", id);
    //     scanf("%d", &voisin_creer.indice);
    //     if (voisin_creer.indice != -1){
    //         voisin_creer.suiv = s.voisin;
    //         s.voisin = &voisin_creer;
    //     }
    // }
    s.suiv = (*g).sommet;
    g->sommet = &s;
    
}

sommet* rechercherSommet(graphe g, int id){
    sommet *sommet_temp = g.sommet;
    while (sommet_temp != NULL){ 

        if ((*sommet_temp).indice == id){
         return sommet_temp;
        }
        sommet_temp = (*sommet_temp).suiv;
    
    }
    return 0;

}

void ajouterArete(graphe *g, int id1, int id2){
    sommet *s1 = rechercherSommet(*g,id1); 
    sommet *s2 = rechercherSommet(*g,id2); 
    printf("nonnon");
    if (s1 != NULL && s2 != NULL && !(is_in_voisin(*s1, id2)) && !(is_in_voisin(*s2, id1))){ // verifie si les sommets existent, et ne sont pas deja voisin
        voisin voisin_cree1;
        voisin_cree1.indice = id2;
        voisin_cree1.suiv = (*s1).voisin;
        (*s1).voisin = &voisin_cree1;

        voisin voisin_cree2;
        voisin_cree2.indice = id1;
        voisin_cree2.suiv = (*s2).voisin;
        (*s2).voisin = &voisin_cree2;
        printf("oui moi c'est ouioui");

    }
}

graphe* construireGraphe(int N){
    graphe *g = creerGraphe();
    for (int i = 0; i<N; i++){
        int indice_sommet;
        printf("saisissez l'id d'un sommet à créer\n");
        scanf("%d", &indice_sommet);
        creerSommet(g, indice_sommet);
    }
    int indice_sommet1;
    int indice_sommet2;
    while (indice_sommet1 != -1){
        printf("saisissez les id de deux sommets à relier, faire '-1 -1' pour sortir\n");
        scanf("%d %d", &indice_sommet1, &indice_sommet2);
        if (indice_sommet1 != -1) ajouterArete(g, indice_sommet1, indice_sommet2);
    }

    return g;

}

void afficherGraphe(graphe g){
    sommet *sommet_temp = g.sommet;
    while (sommet_temp != NULL) {
        printf("%d - ", (*sommet_temp).indice);
        voisin *voisin_temp = (*sommet_temp).voisin;
        while (voisin_temp != NULL){
            printf("%d ->", (*voisin_temp).indice);
            voisin_temp = (*voisin_temp).suiv;
        }
        printf("\n|\n");
        sommet_temp = (*sommet_temp).suiv;
    }
}

int rechercherDegre(graphe g){
    sommet *sommet_temp = g.sommet;
    int degre_max = 0;
    while (sommet_temp != NULL){
        voisin *voisin_temp = (*sommet_temp).voisin;
        int nbr_voisins = 0;
        while (voisin_temp != NULL){
            nbr_voisins++;
            voisin_temp = (*voisin_temp).suiv;
        }
        if (nbr_voisins > degre_max){
            degre_max = nbr_voisins;
        }
    }
    return degre_max;
}

void supprimerSommet(graphe *g, int id){
    sommet sommet_temp = *g->sommet;
    if (g->sommet->indice == id){
        *g->sommet = *g->sommet->suiv;
        // free(sommet_temp); //on doit le free mais ca fait une erreur
        return;
    }
    while (sommet_temp.suiv != NULL){
        if ((*sommet_temp.suiv).indice == id){
            sommet_temp.suiv = sommet_temp.suiv->suiv;
        }
    }
}

int contientBoucle(graphe g){
    sommet *sommet_temp = g.sommet;
    
    while (sommet_temp != NULL){
        voisin *voisin_temp = (*sommet_temp).voisin;
        while (voisin_temp != NULL){
            if ((*voisin_temp).indice == (*sommet_temp).indice) return 1;
            voisin_temp = (*voisin_temp).suiv;
        }
    }
    return 0;

}

void fusionnerSommet(graphe *g, int idSommet1, int idSommet2){
    sommet *s1 = rechercherSommet(*g, idSommet1);
    sommet *s2 = rechercherSommet(*g, idSommet2);

    if ((*s1).indice >= (*s2).indice && (*s2).voisin != NULL){
        sommet *p = s1;
        s1 = s2;
        s2 = p;
    }
    voisin *voisin2_temp = (*s2).voisin;
    while (voisin2_temp != NULL){
        if (!(is_in_voisin(*s1, (*voisin2_temp).indice) || (*voisin2_temp).indice == idSommet2)){
            ajouterArete(g, (*s1).indice, (*voisin2_temp).indice);
        }

        voisin2_temp = (*voisin2_temp).suiv;
    }

    supprimerSommet(g, idSommet2);
}


int is_in_voisin(sommet s, int id_sommet){ //renvoie 1 si id_sommet est un voisin du sommet s, sinon retourne 0
    voisin *voisin_temp = s.voisin;
    while (voisin_temp != NULL){
        if ((*voisin_temp).indice == id_sommet) return 1;
        voisin_temp = (*voisin_temp).suiv;
    }
    return 0;
}