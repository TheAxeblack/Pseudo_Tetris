#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

int main(void) {
    /* Section de definition des variables */
    puit p;
    puit *pointp;
    forme f;
    tab t;

    /* Generation de la graine pour l'aleatoire */
    srand(time(NULL));

    /* Section de programme */
    p = init_jeux();
    pointp = &p;
    init_tab(t);
    afficher_terrain(p);
    printf("\n");
    genererForme(t);
    f = choisirAlea(t);
    afficherForme(f);
    printf("\n");
    insert(pointp, f, 0, 4);
    afficher_terrain(p);
    exit(EXIT_SUCCESS);
}
