#include "forme.h"

int generer_formes(forme t[NB_FORMES])
{
    int i, j, k;

    for (i = 0; i < NB_FORMES; i++)
    {
        for (j = 0; j < H_MAX; j++)
        {
            for (k = 0; k < H_MAX; k++)
            {
                switch (i)
                {
                case 0:
                    /* Cas du tétrimino I */
                    t[i].matrice[j][k] = (j == 0) ? 1 : 0;
                    t[i].dimensions.largeur = 1;
                    t[i].dimensions.hauteur = j + 1;
                    t[i].color = MLV_COLOR_CYAN;
                    break;
                case 1:
                    /* Cas du tétrimino O */
                    t[i].matrice[j][k] = (j <= 1 && k <= 1) ? 1 : 0;
                    t[i].dimensions.largeur = 2;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_YELLOW;
                    break;
                case 2:
                    /* Cas du tétrimino T */
                    t[i].matrice[j][k] = ((j == 1 && k == 1) || (j == 0 && k <= 2) || (j == 1 && k == 0)) ? 1 : 0;
                    t[i].dimensions.largeur = 3;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_PURPLE;
                    break;
                case 3:
                    /* Cas du tétrimino L */
                    t[i].matrice[j][k] = ((j == 1 && k <= 2) || (j == 0 && k == 0)) ? 1 : 0;
                    t[i].dimensions.largeur = 3;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_ORANGE;
                    break;
                case 4: /* Cas du tétrimino J */
                    t[i].matrice[j][k] = ((j == 1 && k >= 1) || (j == 0 && k <= 2)) ? 1 : 0;
                    t[i].dimensions.largeur = 3;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_BLUE;
                    break;
                case 5:
                    /* Cas du tétrimino Z */
                    t[i].matrice[j][k] = ((j == 0 && k >= 1 && k <= 2) || (j == 1 && k >= 0 && k <= 1)) ? 1 : 0;
                    t[i].dimensions.largeur = 3;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_RED;
                    break;
                case 6:
                    /* Cas du tétrimino S */
                    t[i].matrice[j][k] = ((j == 0 && k >= 0 && k <= 1) || (j == 1 && k >= 1 && k <= 2)) ? 1 : 0;
                    t[i].dimensions.largeur = 3;
                    t[i].dimensions.hauteur = 2;
                    t[i].color = MLV_COLOR_GREEN;
                    break;
                default:
                    fprintf(stderr, "Erreur dans la génération des formes.\nValeur inattendue de i : %d\n", i);
                    return 1;
                }
            }
        }
    }
    return 0;
}

void dessiner_forme(forme f)
{
    int i, j;
    int x, y;
    MLV_Color color;
    int px, py;

    x = f.x;
    y = f.y;
    color = f.color;

    for (i = 0; i < f.dimensions.hauteur; i++)
    {
        for (j = 0; j < f.dimensions.largeur; j++)
        {
            if (f.matrice[i][j])
            {
                px = x + j * TAILLE_CASE;
                py = y + i * TAILLE_CASE;
                MLV_draw_filled_rectangle(px, py, TAILLE_CASE, TAILLE_CASE, color);
            }
        }
    }
}