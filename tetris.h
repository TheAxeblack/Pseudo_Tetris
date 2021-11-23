/* Définitions des Macros */
#define LIGNES 23 /* Définition d'une macro nommée LIGNES de valeur 22 représentant le nombre de lignes */
#define COLONNES 12 /* Définition d'une macro nommée COLONNES de valeur 12  représentant le nombre de colonnes */
#define NB_FORMES 7 /* Définition d'une macro nommée NB_FORMES de valeur 7 représentant le nombre de formes différentes */
#define H_MAX 4     /* Definition d'une macro nommée H_MAX de 4 representant la hauteur max d'une forme */
/* Définitions des nouveaux types nécéssaires au Tetris */

typedef struct { /* définition d'un type forme qui est une structure de donnée formée */
    int matrice[LIGNES][COLONNES]; /* d'un tabeau d'entier nommé matrice*/
    int length; /* d'un entier length représentant la longueur */
    int width; /* d'un entier width représentant la largeur */
} forme;


typedef forme tab[NB_FORMES]; /* définition d'un type tab qui est un tableau de formes de taille NB_FORMES */

typedef int puit[LIGNES][COLONNES];


/* Prototypages des fonctions implémentées */
void init_jeux(puit p);

void afficher_terrain(puit p);

int lire_case(puit p, int num_ligne, int num_col);

int init_tab(tab t);

int genererForme(tab t);

void afficherForme(forme f);

forme choisirAlea(tab t);

void insert(puit p, forme f);