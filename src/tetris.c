#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

/* Fonctions liées au terrain de jeu */
void init_jeux(puit p)
{
    int i, j;

    for (i = 0; i < LIGNES; i++)
    {
        for (j = 0; j < COLONNES; j++)
        {
            if (i == (LIGNES - 1) || j == 0 || j == (COLONNES - 1))
                p[i][j] = 9;
            else
                p[i][j] = 0;
        }
    }
}

/* Fonction qui affiche le terrain de jeu */
void afficher_terrain(puit p)
{
    int i, j;

    for (i = 0; i < (LIGNES); i++)
    {
        for (j = 0; j < COLONNES; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}

/* Lecture d'une case */
int lire_case(puit p, int num_ligne, int num_col)
{
    if ((num_ligne >= 0 && num_ligne < LIGNES - 1) && (num_col > 0 && num_col < COLONNES))
        return p[num_ligne][num_col];
    else
        return (-1);
}

/* Fonctions liées aux formes */

/* Initialisation d'un tableau de formes a 0 */
int init_tab(tab t)
{
    int i, j, k;

    for (i = 1; i <= NB_FORMES; i++)
    {
        t[i].longueur = 0;
        t[i].largeur = 0;
        for (j = 0; j < t[i].largeur; j++)
            for (k = 0; k < t[i].longueur; k++)
                t[i].matrice[j][k] = 0;
    }
    return 0;
}

/* Generation des differentes formes */
int genererForme(tab t)
{
    int i, j, k;

    for (i = 1; i <= NB_FORMES; i++)
    {
        for (j = 0; j < H_MAX; j++)
        {
            for (k = 0; k < H_MAX; k++)
            {
                switch (i)
                {
                case 1: /* Cas du tétrimino I */
                    t[i].matrice[j][k] = (j != 0) ? 0 : 1;
                    t[i].largeur = 1;
                    t[i].longueur = k + 1;
                    break;
                case 2: /* Cas du tétrimino O */
                    t[i].matrice[j][k] = (j >= 2 || k >= 2) ? 0 : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = (k + 1) / 2;
                    break;
                case 3: /* Cas du tétrimino T */
                    t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 1)) ? 0 : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = k;
                    break;
                case 4: /* Cas du tétrimino L */
                    t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 0)) ? 0 : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = k;
                    break;
                case 5: /* Cas du tétrimino J */
                    t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 2)) ? 0 : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = k;
                    break;
                case 6: /* Cas du tétrimino Z */
                    t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 0 && k >= 2) || (j == 1 && (k < 1 || k >= 3)))
                                             ? 0
                                             : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = k;
                    break;
                default: /* Cas du tétrimino S */
                    t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 0 && (k < 1 || k >= 3)) || (j == 1 && k >= 2))
                                             ? 0
                                             : 1;
                    t[i].largeur = (j + 1) / 2;
                    t[i].longueur = k;
                    break;
                }
            }
        }
    }
    return 0;
}

/* Choix aleatoire d'une forme */
forme choisirAlea(tab t)
{
    int alea;
    alea = (rand() % 7) + 1;
    return t[alea];
}

/* Affichage des formes */
void afficherForme(forme f)
{
    int i, j;

    for (i = 0; i < H_MAX; i++)
    {
        for (j = 0; j < H_MAX; j++)
        {
            printf("%d ", f.matrice[i][j]);
        }
        printf("\n");
    }
}

/* Fonction qui insert une forme dans le terrain de jeu */
void insertionForme(puit p, forme *f, int x, int y)
{
    int i, j;

    for (i = 0; i < f->largeur; i++)
    {
        for (j = 0; j < f->longueur; j++)
        {
            if (f->matrice[i][j] == 1)
            {
                p[x + i][y + j] += f->matrice[i][j];
                f->x = x;
                f->y = y;
            }
        }
    }
}

/* Fonction qui retire une forme du terrain de jeu */
void retirer(puit p, forme *f, int x, int y)
{
    int i, j;

    for (i = 0; i < f->largeur; i++)
    {
        for (j = 0; j < f->longueur; j++)
        {
            if (f->matrice[i][j] == 1)
                p[x + i][y + j] = 0;
        }
    }
}

/* Fonctions permettant de savoir si une forme peut être deplacée */
/* En vertical */
int check_vert(puit p, forme *f)
{
    int i, j;

    for (i = 0; i < f->largeur; i++)
    {
        for (j = 0; j < f->longueur; j++)
        {
            if (f->longueur < 4)
            {
                if (p[f->x + 2][f->y] != 0 && f->matrice[1][2] != 1)
                    return 1;
                else if (p[f->x + 2][f->y] != 0)
                    return 2;
            }
            else
            {
                if (p[f->x + 1][f->y] != 0)
                    return 1;
            }
        }
    }
    return 0;
}

/* En horizontal */
int check_hor_d(forme *f)
{
    int i, j;

    if (f->longueur < 4)
    {
        for (i = 0; i < f->largeur; i++)
        {
            for (j = 1; j < (f->longueur - 1); j++)
            {
                if (f->matrice[i][j + 2] == 9)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < f->largeur; i++)
        {
            for (j = 2; j < (f->longueur - 1); j++)
            {
                if (f->matrice[i][j + 2] == 9)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check_hor_g(forme *f, puit p)
{
    if (p[f->x][f->y - 1] != 0 || p[f->x + 1][f->y - 1] != 0)
    {
        return 1;
    }
    return 0;
}

/* Fonctions permettant le mouvement des formes */

/* En vertical */
int descendre(puit p, forme *f)
{
    int i;

    i = 1;
    if (check_vert(p, f) == 1)
    {
        return 1;
    }
    while (check_vert(p, f) == 0)
    {
        retirer(p, f, f->x, f->y);
        insertionForme(p, f, f->x + 1, f->y);
        afficher_terrain(p);

        printf("\n");
        i++;
    }
    return 0;
}

/* En horizontal */

/* a droite */
int dep_horizontal_d(puit p, forme *f, int x)
{
    int i;

    i = 1;
    while ((lire_case(p, x, i) == 0 && lire_case(p, x + 1, i) == 0))
    {
        i++;
    }
    if (check_hor_d(f) == 1)
    {
        return 1;
    }
    else if (check_hor_d(f) == 0 && i < (COLONNES - f->longueur - 1))
    {
        retirer(p, f, f->x, f->y);
        insertionForme(p, f, f->x, f->y + 1);
    }
    afficher_terrain(p);
    printf("\n");
    return 0;
}

/* a gauche */
int dep_horizontal_g(puit p, forme *f)
{
    if (check_hor_g(f, p) == 1)
        return 1;
    else
    {
        retirer(p, f, f->x, f->y);
        insertionForme(p, f, f->x, f->y - 1);
    }
    afficher_terrain(p);
    printf("\n");
    return 0;
}

/* rotation */

/*
void rotationDroite(tab t, forme *f) {

    int i, j, k;
    if (f == t[3] || f == t[4] || f == t[5]) {
        for (i = 0; i < f->largeur; i++) {
            for (j = 0, k = 0; j < f->longueur; j++, k++) {
                f->matrice[i][j] = f->matrice[f->y][f->x];
            }
        }
    }
}*/
