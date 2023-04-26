#include "save.h"
#include <MLV/MLV_all.h>

int save_partie(puit p, forme *f) {
    int i, j;
    FILE *fic = NULL;

    fic = fopen("game.save", "w");
    if (fic == NULL)
        return 1;

    for (i = 0; i < LIGNES; i++) {
        for (j = 0; j < COLONNES; j++) {
            fprintf(fic, "%d", p[i][j]);
        }
        fputc('\n', fic);
    }

    fclose(fic);
    return 0;
}

int load_partie(puit p) {
    int i, j;
    FILE *fic;

    fic = fopen("game.save", "r");
    if (fic == NULL)
        return 1;

    for (i = 0; i < LIGNES; i++) {
        for (j = 0; j < COLONNES; j++) {
            fscanf(fic, "%d", &p[i][j]);
        }
    }
    return 0;
}