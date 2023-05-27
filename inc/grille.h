#ifndef GRILLE_H
#define GRILLE_H

#include "types.h"
#include "forme.h"
/* prototypages des fonctions */
void initialiser_grille(grille *g);

/* Dessine la grille */
void dessiner_grille(grille *g);

/* Ajoute une forme dans la grille */
void ajouter_forme(grille *g, forme *f);
#endif
