#define LIGNES 22
#define COLONNES 10

typedef struct {
    int **matrice;
    int i;
    int j;
} forme;

typedef struct {
    int n;
    int m;
    int **matrice;
} puit;

int init_jeux(puit puit1);