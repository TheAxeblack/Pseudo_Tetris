#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include <MLV/MLV_all.h>

/* vérifie si la partie est finie */
int partie_finie(puit p) {
    int i;
    for (i = 1; i < (LIGNES - 1); i++)
        if (p[i][0] != 0)
            return 1;
    return 0;
}

/* affiche un message si la partie est finie */
void message_fin(puit p) {
    if (partie_finie(p))
        MLV_draw_text_box(310, 204, 320, 106, "la partie est finis", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}


/* vérifie si une ligne est complète  */
int check_lgn(puit p, int i) {
    int j;
    for (j = 1; j < (COLONNES - 1); j++)
        if (p[i][j] == 0)
            return 0;
    return 1;
}


/*calcul du score et supprime les lignes complètes */
int calc_score(puit p) {
    int i, j, k, s;
    s = 0;
    for (i = 1; i < (LIGNES - 1); i++) {
        if (check_lgn(p, i)) {
            s += 10;
            for (j = i; j > 1; j--)
                for (k = 1; k < (COLONNES - 1); k++)
                    p[j][k] = p[j - 1][k];
            for (j = 1; j < (COLONNES - 1); j++)
                p[1][j] = 0;
            i--;
        }
    }
    return s;
}


void affichage_score(puit p) {
    int score;
    char score_str[20];
    score = calc_score(p);
    sprintf(score_str, "Score:%d", score);
    MLV_draw_text(10, 10, score_str, MLV_COLOR_MAGENTA);
}

/*supprime si une ligne est complète*/
void supp_lcp(puit p) {
    int i, j, k;
    for (i = 1; i < (LIGNES - 1); i++) {
        if (check_lgn(p, i)) {
            for (j = i; j > 1; j--) {
                for (k = 1; k < COLONNES - 1; k++) {
                    p[j][k] = p[j - 1][k];
                }
            }
            for (j = 1; j < COLONNES - 1; j++) {
                p[1][j] = 0;
            }
            i--;
        }
    }
}


