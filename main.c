#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "tetris.h"

int main(void) {
    /* Section de definition des variables */
    puit puit1;
    forme forme1;
    tab tab1;

    /* Generation de la graine pour l'aleatoire */
    srand(time(NULL));

    /* Setup du tetris */
    init_jeux(puit1);
    init_tab(tab1);
    genererForme(tab1);

    /* Initialisation des variables */
    forme1 = choisirAlea(tab1);


    /* Section de programme */
    printf("\n");
    insert(puit1, forme1, 20, 4);
    afficher_terrain(puit1);
    printf("\n");
    descendre(puit1, forme1);
    afficher_terrain(puit1);
    exit(EXIT_SUCCESS);
}
