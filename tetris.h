#define LIGNES 22
#define COLONNES 10

typedef struct {
    int **matrice;
    int i;
    int j;
} forme;

typedef int puit[LIGNES][COLONNES];

int init_jeux(puit p);
void afficher_terrain(puit p);
