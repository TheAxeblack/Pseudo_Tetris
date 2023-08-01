#ifndef GRILLE_H
#define GRILLE_H

#include "types.h"
#include "forme.h"
/* prototypages des fonctions */
void initialiser_grille(grille *g); /* Initialise la grille avec  toutes les cases inoccupée */

void dessiner_grille(grille *g); /* Dessine la grille */

void ajouter_forme(grille *g, forme *f); /* Ajoute une forme dans la grille */
#endif
