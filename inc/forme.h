#ifndef FORME_H
#define FORME_H

#include "types.h"

/* prototypages des fonctions */

/* génère les différentes formes et les stocke dans le tableau t */
int generer_formes(forme t[NB_FORMES]);

/* dessine la forme f */
void dessiner_forme(forme f);

#endif /* FORME_H */