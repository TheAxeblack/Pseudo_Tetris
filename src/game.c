#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include <MLV/MLV_all.h>

int partie_finie(puit p) {
    int i;
    for (i = 1; i < (LIGNES - 2); i++) {
        if (p[i][0] == 1) {
            return 1;
        }
    }
    return 0;
}


void message_fin(puit p) {
    if (partie_finie(p)) {
        MLV_draw_text_box(310, 204, 320, 106, "la partie est finis", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    }
}


/*vérifie si une ligne est complète  */
int check_lgn(puit p, int j) {
    int i;
    for (i = 1; i < LIGNES - 2; i++) {
        if (p[i][j] == 0) {
            return 1;
        }
    }
    return 0;
}


/*calcul du score*/
int calc_score(puit p) {
    int i, k, s;
    k = 0;
    s = 0;
    for (i = COLONNES - 1; i > 0; i--) {
        if (check_lgn(p, i)) {
            k++;
        }
        switch (k) {
            case 1:
                s = s + 10;
                break;

            case 2:
                s = s + 25;
                break;

            case 3:
                s = s + 40;
                break;
            case 4:
                s = s + 55;
                break;
            case 5:
                s = s + 100;
                break;
            default:
                s = s + 0;
                break;
        }
    }
    return s;
}


void affichage_score(puit p) {

    int i;
    i = calc_score(p);
    MLV_draw_text(10, 10, "Score:%d", MLV_COLOR_MAGENTA, i);
}

/*supprime si une ligne est complète*/
void supp_lcp(puit p) {
    int i, j, tmp;
    for (j = 0; j < COLONNES - 2; j++) {
        if (check_lgn(p, j)) {

            tmp = p[i][j];
            while (i != 0) {
                p[i][j] = p[i + 1][j];
                i--;
            }
            p[0][j] = tmp;
        }
    }
}


