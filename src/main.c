#include "main.h"

int main(int argc, char *argv[]) {
    grille g;
    joueur j;

    initialiser_grille(&g);
    initialiser_joueur(&j);



    MLV_create_window("Tetris", "Tetris", HAUTEUR_GRILLE * TAILLE_CASE + 60, LARGEUR_GRILLE * TAILLE_CASE);

    while(1) {
        dessiner_grille(&g);

    }
    MLV_wait_seconds(5);
    MLV_free_window();

    exit(EXIT_SUCCESS);
}
