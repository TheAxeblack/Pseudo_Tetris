#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "tetris.h"

int main(void) {
    /* Section de definition des variables */
    puit puit1;
    forme forme1;
    forme *ptr_forme1;
    tab tab1;

    /* Generation de la graine pour l'aleatoire */
    srand(time(NULL));

    /* Setup du tetris */
    init_jeux(puit1);
    init_tab(tab1);
    genererForme(tab1);

    /* Initialisation des variables */
    forme1 = choisirAlea(tab1);
    ptr_forme1 = &forme1;


    /* Section de programme */
    printf("\n");
    insert(puit1, forme1, 0, forme1.longueur);
    /* dep_horizontal_d(puit1, forme1); */
    descendre(puit1, ptr_forme1);
    printf("\n");
    /* descendre(puit1, forme1); */

    exit(EXIT_SUCCESS);
}