#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

/* Fonctions liées au terrain de jeu */
int init_jeux(puit p) {
    int i;
    int j;

    for (i = 0; i < LIGNES; i++) {
        for (j = 0; j < COLONNES; j++) {
            if (i == (LIGNES - 1) || j == 0 || j == (COLONNES - 1))
                p[i][j] = 1;
            else
                p[i][j] = 0;
        }
    }
    return 0;
}


void afficher_terrain(puit p) {
    int i;
    int j;

    for (i = 0; i < (LIGNES - 1); i++) {
        for (j = 0; j < COLONNES; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}

int lire_case(puit p, int num_ligne, int num_col) {
    if ((num_ligne >= 0 && num_ligne < LIGNES - 1) && (num_col > 0 && num_col < COLONNES))
        return p[num_ligne][num_col];
    else {
        printf("Erreur cette case est en dehors des limites d'affichages !\n");
        return (-1);
    }
}


/* Fonction liées aux formes */

/* Initialisation d'un tableau de formes a 0 */
int init_tab(tab t) {
    int i;
    int j;
    int k;
    for (i = 1; i <= NB_FORMES; i++)
    {
        t[i].length = 0;
        t[i].width = 0;
        for (j = 0; j < t[i].width; j++)
            for (k = 0; k < t[i].length; k++)
                t[i].matrice[j][k] = 0;
    }
    return 0;
}


/* Generation des differentes formes */
int genererForme(tab t) {
    int i;
    int j;
    int k;

    for (i = 1; i <= NB_FORMES; i++) {
        if (i == 1) /* Cas du tétrimino I */
        {
            t[i].length = 4;
            t[i].width = 1;
            for (j = 0; j < t[i].length; j++)
                t[i].matrice[0][j] = 1;
            printf("t[1] ok\n");
        }
        else if (i == 2) /* Cas du tétrimino O */
        {
            t[i].length = 2;
            t[i].width = 2;
            for (j = 0; j < t[i].width; j++)
                for (k = 0; k < t[i].length; k++)
                    t[i].matrice[j][k] = 1;
            printf("t[2] ok\n");
        }
        else {
            t[i].length = 3;
            t[i].width = 2;
            for (j = 0; j < t[i].width; j++) {
                for (k = 0; k < t[i].length; k++) {
                    switch (i) {
                        case 3: /* Cas du tétrimino T */
                            t[i].matrice[j][k] = (j == 1 && k != 1) ? 0 : 1;
                            break;
                        case 4: /* Cas du tétrimino L */
                            t[i].matrice[j][k] = (j == 1 && k != 0) ? 0 : 1;
                            break;
                        case 5: /* Cas du tétrimino J */
                            t[i].matrice[j][k] = (j == 1 && k != 2) ? 0 : 1;
                            break;
                        case 6: /* Cas du tétrimino Z */
                            t[i].matrice[j][k] = ((j == 0 && k != 2) || (j == 1 && k != 0)) ? 1 : 0;
                            break;
                        default: /* Cas du tétrimino S */
                            t[i].matrice[j][k] = ((j == 0 && k != 0) || (j == 1 && k != 2)) ? 1 : 0;
                            break;
                    }
                }
            }
            printf("t[%d] ok\n", i);
        }
    }
    return 0;
}

void afficherForme(forme f) /* Fonction qui affiche la forme placé en parametre */
{
    int i;
    int j;
    for (i = 0; i < f.width; i++)
    {
        for (j = 0; j < f.length; j++)
        {
            if (f.matrice[i][j] == 0)
                printf(" ");
            else
                printf("%d", f.matrice[i][j]);
        }
        printf("\n");
    }
}

forme choisirAlea(tab t) /* Fonction qui choisit aleatoirement une forme */
{
    int alea;
    alea = (rand() % (7 - 1 + 1)) + 1;
    return t[alea];
}