#include "save.h"
#include <MLV/MLV_all.h>

int save_partie(puit p) {
    int i;
    FILE *fic = NULL;

    fic = fopen(SAVE_FILE_NAME, SAVE_FILE_MODE);
    if (fic == NULL)
        return 1;

    for (i = 0; i < LIGNES; i++) {
        fwrite(p[i], sizeof(int), COLONNES, fic);
    }

    fclose(fic);
    return 0;
}

int load_partie(puit p) {
    int i;
    FILE *fic;

    fic = fopen("game.save", "rb");
    if (fic == NULL)
        return 1;

    for (i = 0; i < LIGNES; i++) {
        fread(p[i], sizeof(int), COLONNES, fic);
    }

    return 0;
}