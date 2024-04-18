#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>

graphe* creerGraphe(){
    graphe *g = malloc(sizeof(graphe));
    if (g==NULL) printf("Erreur malloc creerGraphe\n");
    g->sommet = NULL;
    return g;
}

void creerSommet(graphe *g, int id){
    if (id > 0){
        if (rechercherSommet(*g,id) != NULL){
            printf("impossible de creer un sommet qui existe deja !\n");
        }
        else{
            sommet *s = malloc(sizeof(sommet));
            if (s==NULL) printf("Erreur malloc creerSommet\n");

            if (g->sommet == NULL) {
                g->sommet = (sommet *)malloc(sizeof(sommet));
                g->sommet->indice = id;
                g->sommet->suiv = NULL;
            } 
            else if(g->sommet->indice > id){
                sommet *temp = g->sommet;
                g->sommet = (sommet *)malloc(sizeof(sommet));
                g->sommet->indice = id;
                g->sommet->suiv = temp;
            }
            else {
                
                sommet *buffer = g->sommet;
                while (buffer->suiv != NULL && buffer->suiv->indice < id) {
                    buffer = buffer->suiv;
                }
            
                
                    sommet *temp = buffer->suiv;
                    buffer->suiv = (sommet *)malloc(sizeof(sommet));
                    buffer->suiv->indice = id;
                    buffer->suiv->suiv = temp;
            }
        }
    }
    else{ 
        printf("ID sommet non valide");
    }
}   


sommet* rechercherSommet(graphe g, int id){
    sommet *sommet_temp = g.sommet;
    while (sommet_temp != NULL){ 

        if ((*sommet_temp).indice == id){
            // printf("sommet trouve");
            return sommet_temp;
        }
        sommet_temp = (*sommet_temp).suiv;
    
    }
    return 0;

}


void ajouterArete(graphe *g, int id1, int id2){

    sommet *s1 = rechercherSommet(*g,id1); 
    sommet *s2 = rechercherSommet(*g,id2); 
    if (s1 != NULL && s2 != NULL && !(is_in_voisin(*s1, id2)) && !(is_in_voisin(*s2, id1))){ // verifie si les sommets existent, et ne sont pas deja voisin
        //ajout de id2 comme voisin à id1
        if (s1->voisin == NULL) {
            s1->voisin = (voisin *)malloc(sizeof(voisin));
            s1->voisin->indice = id2;
            s1->voisin->suiv = NULL;
        } 
        else if(s1->voisin->indice > id2){
            voisin *temp = s1->voisin;
            s1->voisin = (voisin *)malloc(sizeof(voisin));
            s1->voisin->indice = id2;
            s1->voisin->suiv = temp;
        }
        else {
            
            voisin *buffer = s1->voisin;
            while (buffer->suiv != NULL && buffer->suiv->indice < id2) {
                buffer = buffer->suiv;
            }
            voisin *temp = buffer->suiv;
            buffer->suiv = (voisin *)malloc(sizeof(voisin));
            buffer->suiv->indice = id2;
            buffer->suiv->suiv = temp;
        }

        //ajout de id1 comme voisin à id2
        if (s1 != s2){
        if (s2->voisin == NULL) {
            s2->voisin = (voisin *)malloc(sizeof(voisin));
            s2->voisin->indice = id1;
            s2->voisin->suiv = NULL;
        } 
        else if(s2->voisin->indice > id1){
            voisin *temp = s2->voisin;
            s2->voisin = (voisin *)malloc(sizeof(voisin));
            s2->voisin->indice = id1;
            s2->voisin->suiv = temp;
        }
        else {
            
            voisin *buffer = s2->voisin;
            while (buffer->suiv != NULL && buffer->suiv->indice < id1) {
                buffer = buffer->suiv;
            }
            voisin *temp = buffer->suiv;
            buffer->suiv = (voisin *)malloc(sizeof(voisin));
            buffer->suiv->indice = id1;
            buffer->suiv->suiv = temp;
        }
        }
    }
}

graphe* construireGraphe(int N){
    graphe *g = creerGraphe();
    for (int i = 0; i<N; i++){
        int indice_sommet;
        printf("saisissez l'id d'un sommet à créer\n");
        scanf("%d", &indice_sommet);
        if (indice_sommet <= 0) {
            printf("interdit de nommer un sommet <=0\n");
            i--;
        }
        else creerSommet(g, indice_sommet);
        
    }
    printf("Combien d'arretes souhaitez vous ajouter ?\n");
    int nbr_arrete;
    scanf("%d", &nbr_arrete);

    int indice_sommet1;
    int indice_sommet2;
    for (int i = 0; i<nbr_arrete; i++){

        printf("saisissez l'id du premier sommet à relier avec une arrete\n");
        scanf("%d", &indice_sommet1);
        printf("saisissez l'id du second sommet à relier avec une arrete au sommet %d\n", indice_sommet1);
        scanf("%d", &indice_sommet2);

        ajouterArete(g, indice_sommet1, indice_sommet2);
        printf("Les sommets %d et %d ont correctement été reliés avec une arrête.\n", indice_sommet1, indice_sommet2);
        
    }
    return g;

}

void afficherGraphe(graphe g){
    printf("------------------------------------------------\n");
    if (g.sommet == NULL) printf("votre graphe est vide");
    sommet *sommet_temp = g.sommet;
    while (sommet_temp != NULL) {
        printf("%d ", sommet_temp->indice);
        voisin *voisin_temp = sommet_temp->voisin;
        while (voisin_temp != NULL){
            printf("-> %d ", voisin_temp->indice); 
            voisin_temp = voisin_temp->suiv;
        }
        sommet_temp = sommet_temp->suiv;
        if (sommet_temp != NULL) printf("\n|\n");
    }
}

int rechercherDegre(graphe g){
    sommet *sommet_temp = g.sommet;
    int degre_max = 0;
    while (sommet_temp != NULL){
        voisin *voisin_temp = sommet_temp->voisin;
        int nbr_voisins = 0;
        while (voisin_temp != NULL){
            nbr_voisins++;
            voisin_temp = voisin_temp->suiv;
        }
        if (nbr_voisins > degre_max){
            degre_max = nbr_voisins;
        }
        sommet_temp = sommet_temp->suiv;
    }
    return degre_max;
}

void supprimerSommet(graphe *g, int id){
    //supprimer le sommet id
    if (g->sommet->indice == id){
        sommet *sommet_temp = g->sommet->suiv;
        liberer_proprement_voisins(g->sommet->voisin);
        g->sommet = sommet_temp;
    }
    else{
        sommet *buffer = g->sommet;
        while (buffer->suiv->indice != id){
            buffer = buffer->suiv;
        }
        sommet *sommet_temp = buffer->suiv->suiv;
        liberer_proprement_voisins(buffer->suiv->voisin);
        buffer->suiv = sommet_temp; 
    }
    // supprimer les voisins id
    sommet *buffer1 = g->sommet;
    voisin *voisin_temp;
    while (buffer1 != NULL){
        voisin_temp = buffer1->voisin;
        if (voisin_temp!=NULL && voisin_temp->indice == id){
            voisin_temp = buffer1->voisin->suiv;
            free(buffer1->voisin);
            buffer1->voisin = voisin_temp;
        }
        else{
            while (voisin_temp!=NULL && voisin_temp->suiv != NULL){
                if (voisin_temp->suiv->indice == id){
                    voisin_temp->suiv = voisin_temp->suiv->suiv;
                }
                voisin_temp = voisin_temp->suiv;
            }
            if (voisin_temp!=NULL && voisin_temp->indice == id){
                voisin_temp = NULL;
            }
        }
        buffer1 = buffer1->suiv;
    }



}

int contientBoucle(graphe g){
    sommet *sommet_temp = g.sommet;
    
    while (sommet_temp != NULL){
        voisin *voisin_temp = sommet_temp->voisin;
        while (voisin_temp != NULL){
            if (voisin_temp->indice == sommet_temp->indice) return 1;
            voisin_temp = voisin_temp->suiv;
        }
        sommet_temp = sommet_temp->suiv;
    }
    return 0;

}

void fusionnerSommet(graphe *g, int idSommet1, int idSommet2){
    sommet *s1 = rechercherSommet(*g, idSommet1);
    sommet *s2 = rechercherSommet(*g, idSommet2);

    if (s1->indice >= s2->indice && s2->voisin != NULL){
        sommet *p = s1;
        s1 = s2;
        s2 = p;
    }
    voisin *voisin2_temp = s2->voisin;
    while (voisin2_temp != NULL){
        if (!(is_in_voisin(*s1, voisin2_temp->indice) || voisin2_temp->indice == idSommet2)){
            ajouterArete(g, (*s1).indice, (*voisin2_temp).indice);
        }
        voisin2_temp = voisin2_temp->suiv;
    }

    supprimerSommet(g, idSommet2);
}


int is_in_voisin(sommet s, int id_sommet){ //renvoie 1 si id_sommet est un voisin du sommet s, sinon retourne 0
    voisin *voisin_temp = s.voisin;
    while (voisin_temp != NULL){
        if (voisin_temp->indice == id_sommet) return 1;
        voisin_temp = voisin_temp->suiv;
    }
    return 0;
}

void liberer_proprement_sommets(sommet *s){
    if (s != NULL && s->suiv != NULL) {
        liberer_proprement_sommets(s->suiv);
    }
    if (s!=NULL) liberer_proprement_voisins(s->voisin);
    free(s);
}

void liberer_proprement_voisins(voisin *vois){
    if (vois != NULL && vois->suiv != NULL) {
        liberer_proprement_voisins(vois->suiv);
    }
    free(vois);
}