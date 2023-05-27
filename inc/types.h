#ifndef TYPES_H
#define TYPES_H

/* Inclusion des bibliothèques */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <MLV/MLV_all.h>

/* Définitions des Macros */
#define NB_MAX 150        /* # max d'élements */
#define LARGEUR_GRILLE 23 /* # colonnes dans la grille du jeu */
#define HAUTEUR_GRILLE 12 /* # de lignes dans la grille du jeu*/
#define NB_FORMES 7       /* # formes != */
#define H_MAX 4           /* Hauteur maximale d'une forme*/
#define TAILLE_CASE 30    /* Taille d'une case de la grille en pixels */

/* Définitions des nouveaux types nécéssaires au Tetris */
typedef struct
{                              /* définition d'un type forme qui est une structure de donnée formée */
    int matrice[H_MAX][H_MAX]; /* d'un tabeau d'entier nommé matrice*/
    struct
    {
        int largeur;
        int hauteur;
    } dimensions;    /* d'une structure représentant les dimensions */
    int x;           /* d'une coordonnée x */
    int y;           /* d'une coordonnée y */
    MLV_Color color; /* d'une couleur */
} forme;

typedef struct
{               /* définition d'un type joueur qui est une structure de donnée formée */
    int score;  /* d'un entier nommé score */
    int niveau; /* d'un entier nommé niveau */
} joueur;

typedef struct
{                                                /* définition d'un type grille qui est une structure de donnée formée */
    int matrice[HAUTEUR_GRILLE][LARGEUR_GRILLE]; /* d'un tableau d'entier nommé matrice */
    forme formes[NB_MAX];                        /* d'un tableau de forme nommé formes */
    int nb_formes;                               /* d'un entier nommé nb_formes */
} grille;

#endif