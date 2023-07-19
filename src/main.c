#include "main.h"

int main(void)
{
    grille g;
    joueur j;
    forme f;
    forme formes[NB_FORMES];
    MLV_Event event;
    MLV_Keyboard_button touche;
    MLV_Button_state etat_touche;
    int continuer;

    srand(time(NULL));

    continuer = 1;

    /* On initialise la grille et les formes */
    initialiser_grille(&g);
    initialiser_joueur(&j);
    generer_formes(formes);

    /* On cree la fenetre MLV */
    MLV_create_window("Tetris", "Tetris", HAUTEUR_GRILLE * TAILLE_CASE + 60, LARGEUR_GRILLE * TAILLE_CASE);

    /* On rentre dans la Game Loop */

    while (continuer)
    {
        ajouter_forme(&g, formes);
        /* Gestion des evenements */
        event = MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &etat_touche);

        deplacer_forme(&f, &g, event, touche, etat_touche);

        /* On dessine la grille */
        dessiner_grille(&g);

        if (verifier_defaite(&f))
        {
            continuer = 0;
        }
        
        supprimer_lignes_complete(&g, &j.score);
    }

    MLV_wait_seconds(2);
    MLV_free_window();

    exit(EXIT_SUCCESS);
}
