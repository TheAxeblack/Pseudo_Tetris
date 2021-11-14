#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int main(void) {
    puit p;
    init_jeux(p);
    afficher_terrain(p);
    exit(EXIT_SUCCESS);
}
