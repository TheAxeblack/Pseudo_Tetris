#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris.h"

int main(void) {
    /* Section de definition des variables */
    puit p;
    forme f;
    forme f2;
    tab t;

    /* Generation de la graine pour l'aleatoire */
    srand(time(NULL));

    /* Section de programme */
    init_jeux(p);
    init_tab(t);
    afficher_terrain(p);
    printf("La case présente à la ligne %d et a la colonne %d a une valeur de %d\n", 6, 3, lire_case(p, 6, 3));
    printf("\n");
    genererForme(t);
    f = choisirAlea(t);
    afficherForme(f);
    printf("\n");
    f2 = choisirAlea(t);
    afficherForme(f2);
    exit(EXIT_SUCCESS);
}
