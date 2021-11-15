#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int main(void) {
    puit p;
    tab t;
    init_jeux(p);
    init_tab(t);
    afficher_terrain(p);
    printf("La case présente à la ligne %d et a la colonne %d a une valeur de %d\n", 6, 3, lire_case(p, 6, 3));
    printf("\n");
    genererForme(t);
    exit(EXIT_SUCCESS);
}
