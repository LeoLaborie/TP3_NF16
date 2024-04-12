#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int main(){   
    printf("saisissez le nombre de sommet de votre graphe\n");
    int nbr_sommet;
    scanf("%d", &nbr_sommet);
    graphe *g = construireGraphe(nbr_sommet);
    afficherGraphe(*g);
    return 0;
}
