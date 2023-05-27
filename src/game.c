#include "game.h"

int verifier_deplacement(forme *f, grille *g, int nouvelle_x, int nouvelle_y)
{
    int i, j;

    if (nouvelle_x < 0 || nouvelle_x + f->dimensions.largeur > LARGEUR_GRILLE || nouvelle_y + f->dimensions.hauteur > HAUTEUR_GRILLE)
        return 0;

    /* On verifie les collisions avec d'autres pieces dans la grille */
    for (i = 0; i < f->dimensions.hauteur; i++)
    {
        for (j = 0; j < f->dimensions.largeur; j++)
        {
            if (f->matrice[i][j] == 1 && g->matrice[nouvelle_x + i][nouvelle_y + j] != 0)
                return 0;
        }
    }
    return 1;
}

void deplacer_forme_gauche(forme *f, grille *g)
{
    if (verifier_deplacement(f, g, f->x - 1, f->y))
        f->x--;
}

void deplacer_forme_droite(forme *f, grille *g)
{
    if (verifier_deplacement(f, g, f->x + 1, f->y))
        f->x++;
}

void deplacer_forme_bas(forme *f, grille *g)
{
    if (verifier_deplacement(f, g, f->x, f->y + 1))
        f->y++;
}

void rotation_piece(forme *f, grille *g)
{
    int i, j;
    forme temp; /* Pièce temporaire pour stocker la nouvelle configuration après rotation */

    /* Copier la pièce originale dans la pièce temporaire */
    memcpy(&temp, f, sizeof(forme));

    /* Effectuer la rotation en modifiant la matrice de la pièce temporaire */
    for (i = 0; i < f->dimensions.hauteur; i++)
    {
        for (j = 0; j < f->dimensions.largeur; j++)
        {
            temp.matrice[j][f->dimensions.hauteur - 1 - i] = f->matrice[i][j];
        }
    }

    /* Vérifier si la rotation est possible en utilisant la pièce temporaire */
    if (verifier_deplacement(&temp, g, f->x, f->y))
    {
        /* Si la rotation est autorisée, copier la pièce temporaire dans la pièce d'origine */
        memcpy(f, &temp, sizeof(forme));
    }
}

void deplacer_forme(forme *f, grille *g, MLV_Event event, MLV_Keyboard_button sym, MLV_Button_state state)
{
    if (event == MLV_KEY && sym == MLV_KEYBOARD_d && state == MLV_PRESSED)
    {
        deplacer_forme_droite(f, g);
    }
    else if (event == MLV_KEY && sym == MLV_KEYBOARD_q && state == MLV_PRESSED)
    {
        deplacer_forme_gauche(f, g);
    }
    else if (event == MLV_KEY && sym == MLV_KEYBOARD_SPACE && state == MLV_PRESSED)
    {
        rotation_piece(f, g);
    }
    else
    {
        deplacer_forme_bas(f, g);
    }
}

void supprimer_lignes_complete(grille *g, int *score)
{
    int i, j, k;
    int lignes_complete[LARGEUR_GRILLE]; /* Tableau pour stocker les indices des lignes complètes */
    int nb_lignes_complete;              /* Nombre de lignes complètes trouvées */

    nb_lignes_complete = 0;
    /* Parcourir chaque ligne de la grille pour détecter les lignes complètes */
    for (i = 0; i < HAUTEUR_GRILLE; i++)
    {
        int ligne_complete = 1; /* Indicateur de ligne complète, initialisé à vrai */

        for (j = 0; j < LARGEUR_GRILLE; j++)
        {
            if (g->matrice[i][j] == 0) /* Si une case est vide, la ligne n'est pas complète */
            {
                ligne_complete = 0;
                break;
            }
        }

        if (ligne_complete)
        {
            lignes_complete[nb_lignes_complete] = i;
            nb_lignes_complete++;
        }
    }

    /* Supprimer les lignes complètes et faire descendre les pièces restantes */
    for (k = 0; k < nb_lignes_complete; k++)
    {
        int ligne = lignes_complete[k];

        /* Décaler les lignes au-dessus de la ligne supprimée vers le bas */
        for (i = ligne; i > 0; i--)
        {
            for (j = 0; j < LARGEUR_GRILLE; j++)
            {
                g->matrice[i][j] = g->matrice[i - 1][j];
            }
        }

        /* Réinitialiser la ligne supérieure */
        for (j = 0; j < LARGEUR_GRILLE; j++)
        {
            g->matrice[0][j] = 0;
        }
    }

    score += nb_lignes_complete * 100;
}

int verifier_defaite(forme *f)
{
    return (f->y <= 0); /* Si la pièce est en haut de la grille, c'est la défaite */
}