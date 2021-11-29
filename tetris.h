/* Définitions des Macros */
#define NB_MAX 150
#define LIGNES 23 /* Définition d'une macro nommée LIGNES de valeur 22 représentant le nombre de lignes */
#define COLONNES 12 /* Définition d'une macro nommée COLONNES de valeur 12  représentant le nombre de colonnes */
#define NB_FORMES 7 /* Définition d'une macro nommée NB_FORMES de valeur 7 représentant le nombre de formes différentes */
#define H_MAX 4     /* Definition d'une macro nommée H_MAX de 4 representant la hauteur max d'une forme */


/* Définitions des nouveaux types nécéssaires au Tetris */

typedef struct {                    /* définition d'un type forme qui est une structure de donnée formée */
    int matrice[LIGNES][COLONNES];  /* d'un tabeau d'entier nommé matrice*/
    int longueur;                   /* d'un entier longueur représentant la longueur */
    int largeur;                    /* d'un entier largeur représentant la largeur */
} forme;

typedef forme tab[NB_FORMES]; /* définition d'un type tab qui est un tableau de formes de taille NB_FORMES */

typedef int puit[LIGNES][COLONNES]; /* définition d'un type puit qui est un tableau d'entiers a double entrées */


/* Prototypages des fonctions implémentées */
void init_jeux(puit p);

void afficher_terrain(puit p);

int lire_case(puit p, int num_ligne, int num_col);

int init_tab(tab t);

int genererForme(tab t);

void afficherForme(forme f);

forme choisirAlea(tab t);

void insert(puit p, forme f, int x, int y);

void retirer(puit p, forme f, int x, int y);

int check_vert(forme f);

int descendre(puit p, forme * f);

int dep_horizontal_d(puit p, forme f);