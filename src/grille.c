#include "grille.h"

void initialiser_grille(grille *g) {
    int i, j;
    g->nb_formes = 0;
    g->formes = generer_formes();
    for (i = 0; i < HAUTEUR_GRILLE; i++) {
        for (j = 0; j < LARGEUR_GRILLE; j++) {
            if (i == 0 || i == HAUTEUR_GRILLE - 1 || j == LARGEUR_GRILLE - 1)
                g->matrice[i][j] = -1;
            else
                g->matrice[i][j] = 0;
        }
    }
}

void dessiner_grille(grille *g) {
    int i, j;
    for (i = 0; i < HAUTEUR_GRILLE; i++) {
        for (j = 0; j < LARGEUR_GRILLE; j++) {
            if (g->matrice[i][j] == -1) {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE,
                                          MLV_COLOR_LIGHT_GREY);
            } else if (g->matrice[i][j] == 0) {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_BLACK);
            } else {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE,
                                          g->formes[g->matrice[i][j] - 1].color);
            }
            MLV_draw_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_WHITE);
        }
    }
    MLV_actualise_window();
}