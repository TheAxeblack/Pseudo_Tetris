#include "grille.h"

void initialiser_grille(grille *g)
{
    int i, j;         /* Incréments de boucles */
    g->nb_formes = 0; /* Aucune forme dans la grille */
    for (i = 0; i < HAUTEUR_GRILLE; i++)
    {
        for (j = 0; j < LARGEUR_GRILLE; j++)
        {
            if (i == 0 || i == (HAUTEUR_GRILLE - 1) || j == (LARGEUR_GRILLE - 1))
                g->matrice[i][j] = -1;                                            
            else
                g->matrice[i][j] = 0;
        }
    }
}

void dessiner_grille(grille *g)
{
    int i, j;
    for (i = 0; i < HAUTEUR_GRILLE; i++)
    {
        for (j = 0; j < LARGEUR_GRILLE; j++)
        {
            if (g->matrice[i][j] == -1)
            {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE,
                                          MLV_COLOR_LIGHT_GREY);
            }
            else if (g->matrice[i][j] == 0)
            {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_BLACK);
            }
            else
            {
                MLV_draw_filled_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE,
                                          g->formes[g->matrice[i][j] - 1].color);
            }
            MLV_draw_rectangle(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_WHITE);
        }
    }
    MLV_actualise_window();
}

void ajouter_forme(grille *g, forme *f)
{
    int indice_forme;
    forme nouvelle_forme;
    int i, j;
    int x, y;

    indice_forme = rand() % NB_FORMES;

    nouvelle_forme = g->formes[indice_forme];
    nouvelle_forme.x = (LARGEUR_GRILLE - nouvelle_forme.dimensions.hauteur) / 2;
    nouvelle_forme.y = 0;

    for (i = 0; i < nouvelle_forme.dimensions.hauteur; i++)
    {
        for (j = 0; j < nouvelle_forme.dimensions.largeur; j++)
        {
            if (nouvelle_forme.matrice[i][j])
            {
                x = nouvelle_forme.x + j;
                y = nouvelle_forme.y + i;
                if (g->matrice[x][y])
                {
                    fprintf(stderr, "Erreur : la case (%d, %d) est déjà occupée.\n", x, y);
                    exit(EXIT_FAILURE);
                }
                g->matrice[x][y] = indice_forme + 1;
            }
        }
    }
}