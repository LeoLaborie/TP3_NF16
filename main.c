#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tp3.c"
#include "tp3.h"


int main(){
    printf("NF16 - P024 - TP3 : Les listes Lineaires Chainees\n");
    printf("Laborie Leo - Playez Romain\n");
    bool continuer=true;
    int choix;
    graphe *g = NULL;
    sommet *s = NULL;
    int nombre_sommets;
    int idSommet, idSommet2;

    while (continuer==true){

        printf("\n------------------------------------------------\n");
        printf("1. Creer un graphe vide\n");
        printf("2. Construire un graphe de N sommets\n");
        printf("3. Ajouter un sommet\n");
        printf("4. Ajouter une arete\n");
        printf("5. Afficher un graphe\n");
        printf("6. Donner le degre maximal du graphe\n");
        printf("7. Supprimer un sommet\n");
        printf("8. Verifier si le graphe contient une boucle\n");
        printf("9. Fusionner deux sommets\n");
        printf("10. Quitter\n");
        printf("------------------------------------------------\n");

        scanf("%d", &choix);

        switch(choix){
            case 1: //Créer un graphe vide
                if(g != NULL){
                    printf("Suppresion du graphe précédent...");
                    free(g);
                }else{
                    g = creerGraphe();
                }
                break;
            case 2: //Construire un graphe de N sommets
                if(g != NULL){
                    printf("Suppresion du graphe précédent...");
                    free(g);
                }else{
                    printf("Veuillez saisir le nombre de sommets pour le graphe\n");
                    scanf("%d", &nombre_sommets);
                    if(nombre_sommets==0){
                        g = creerGraphe();
                    }else if(nombre_sommets>0){
                        g = construireGraphe(nombre_sommets);
                    }else{
                        printf("Vous ne pouvez construire un graphe qu'avec un nombre de sommet positif");
                    }
                }
                break;
            case 3: //Ajouter un sommet
                        if(g == 0){
                            printf("Veuillez dans un premier temps creer un graphe");
                        }
                        printf("Veuillez saisir l'indice du sommet :\n");
                        scanf("%d", &idSommet);
                        s = rechercherSommet(*g, idSommet);
                        if(s!=NULL){
                            printf("Ce sommet existe déjà");
                        } else {
                            //fonction ajouter sommet
                        }
                        break;
            case 4: //Ajouter une arête
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                    printf("Pour ajouter une arete, veuillez saisir l'indice du premier sommet :\n");
                    scanf("%d", &idSommet);
                    printf("Veuillez saisir l'indice du second sommet :\n");
                    scanf("%d", &idSommet2);
                    sommet *s = rechercherSommet(*g, idSommet);
                    sommet *s2 = rechercherSommet(*g, idSommet2);
                    if(s == NULL){
                        printf("Le sommet %d n'existe pas", idSommet);
                    }else if(s2 == NULL){
                        printf("Le sommet %d n'existe pas", idSommet2);
                    }else{
                        //appel fonction arete
                    }
                }

                break;
            case 5: //appel fonction Afficher un graphe
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                afficherGraphe(*g);
                }
                break;
            case 6: //appel fonction Donner le degré maximal du graphe
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                    printf("Le degre maximal du graphe est %d\n", rechercherDegre(*g));
                }
                break;
            case 7: //appel fonction Supprimer un sommet
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                    printf("Veuillez saisir l'indice du sommet à supprimer :\n");
                    scanf("%d", &idSommet);
                    sommet *s = rechercherSommet(*g, idSommet);
                    if(s == NULL){
                        printf("Le sommet %d n'existe pas", idSommet);
                    }else{
                        //appel fonction supprimer sommet
                    }
                }
                break;
            case 8: //appel fonction Vérifier si le graphe contient une boucle
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                    if(contientBoucle(*g)){
                        printf("Le graphe contient une boucle");
                    }else{
                        printf("Le graphe ne contient pas de boucles");
                    }
                }
                break;
            case 9: //appel fonction Fusionner deux sommets
                if(g == 0){
                    printf("Veuillez dans un premier temps creer un graphe");
                } else {
                    printf("Veuillez l'indice du premier sommet");
                    scanf("%d", &idSommet);
                    printf("Veuillez saisir l'indice du second sommet");
                    scanf("%d", &idSommet2);
                    sommet *s = rechercherSommet(*g, idSommet);
                    sommet *s2 = rechercherSommet(*g, idSommet2);
                    if(s == NULL){
                        printf("Le sommet %d n'existe pas", idSommet);
                    }else if(s2 == NULL){
                        printf("Le sommet %d n'existe pas", idSommet2);
                    }else{
                        //appel fonction fusionner deux sommets
                    }
                }
                break;
            case 10: //Quitter
                continuer = false;
                if(g!=NULL){
                    free(g);
                }
                break;
            default :
                printf("Ce choix n'est pas valide dans le menu precedent...");
                break;
        }

    }

    return 0;
}
