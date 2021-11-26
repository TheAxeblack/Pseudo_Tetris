#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"


/* Fonctions liées au terrain de jeu */
void init_jeux(puit p) {
    int i, j;

    for (i = 0; i < LIGNES; i++) {
        for (j = 0; j < COLONNES; j++) {
            if (i == (LIGNES - 1) || j == 0 || j == (COLONNES - 1))
                p[i][j] = 1;
            else
                p[i][j] = 0;
        }
    }
}

/* Fonction qui affiche le terrain de jeu */
void afficher_terrain(puit p) {
    int i, j;

    for (i = 0; i < (LIGNES); i++) {
        for (j = 0; j < COLONNES; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}


/* Lecture d'une case */
int lire_case(puit p, int num_ligne, int num_col) {
    if ((num_ligne >= 0 && num_ligne < LIGNES - 1) && (num_col > 0 && num_col < COLONNES))
        return p[num_ligne][num_col];
    else
        return (-1);
}


/* Fonctions liées aux formes */

/* Initialisation d'un tableau de formes a 0 */
int init_tab(tab t) {
    int i, j, k;

    for (i = 1; i <= NB_FORMES; i++) {
        t[i].longueur = 0;
        t[i].largeur = 0;
        for (j = 0; j < t[i].largeur; j++)
            for (k = 0; k < t[i].longueur; k++)
                t[i].matrice[j][k] = 0;
    }
    return 0;
}


/* Generation des differentes formes */
int genererForme(tab t) {
    int i, j, k;

    for (i = 1; i <= NB_FORMES; i++) {
        for (j = 0; j < H_MAX; j++) {
            for (k = 0; k < H_MAX; k++) {
                switch (i) {
                    case 1: /* Cas du tétrimino I */
                        t[i].matrice[j][k] = (j != 0) ? 0 : 1;
                        break;
                    case 2: /* Cas du tétrimino O */
                        t[i].matrice[j][k] = (j >= 2 || k >= 2) ? 0 : 1;
                        break;
                    case 3: /* Cas du tétrimino T */
                        t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 1)) ? 0 : 1;
                        break;
                    case 4: /* Cas du tétrimino L */
                        t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 0)) ? 0 : 1;
                        break;
                    case 5: /* Cas du tétrimino J */
                        t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 1 && k != 2)) ? 0 : 1;
                        break;
                    case 6: /* Cas du tétrimino Z */
                        t[i].matrice[j][k] = ((j >= 2 || k >= 3) || (j == 0 && k >= 2) || (j == 1 && (k < 1 || k >= 3)))
                                             ? 0 : 1;
                        break;
                    default: /* Cas du tétrimino S */
                        t[i].matrice[j][k] = ((j >= 2 || k >= 3) ||
                                              ((j == 0 && (k < 1 || k >= 3)) || (j == 1 && k >= 2))) ? 0 : 1;
                        break;
                }
            }
        }
    }
    return 0;
}


/* Choix aleatoire d'une forme */
forme choisirAlea(tab t) {
    int alea;
    alea = (rand() % 7) + 1;
    return t[alea];
}

/* Affichage des formes */
void afficherForme(forme f) {
    int i, j;

    for (i = 0; i < H_MAX; i++) {
        for (j = 0; j < H_MAX; j++) {
            printf("%d ", f.matrice[i][j]);
        }
        printf("\n");
    }
}

/* Fonction qui insert une forme dans le terrain de jeu */
void insert(puit p, forme f) {
    int i, j;

    for (i = 0; i < f.largeur; i++) {
        for (j = 0; j < f.longueur; j++) {
            if (f.matrice[i][j] == 1)
                p[f.largeur + i][f.longueur + j] += f.matrice[i][j];
        }
    }
}


int positon_forme(puit p, forme f) {
    int i, j;

    for (i = 0; i < H_MAX; i++) {
        for (j = 0; j < H_MAX; j++) {
            if (f.longueur + j < 0 || f.longueur + j >= COLONNES || f.largeur + i >= LIGNES) {
                if (f.matrice[i][j] == 0)
                    return 1;
            } else if (p[f.largeur + i][f.largeur + j] == 0 && f.matrice[i][j] == 0)
                return 2;
        }
    }
    return 0;
}

/*
int descendre(puit p, forme f)
{
    int i, j;
    for (i = 0; i < LIGNES; i++)
    {
        for (j = 0; j < COLONNES; j++)
        {
            while (f.matrice[i][j] != 2) {
                */
/* instructions pour faire descendre *//*

            }
            return 1
        }
    }
    return 0;
}
*/
