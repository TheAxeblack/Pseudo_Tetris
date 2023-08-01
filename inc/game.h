#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "forme.h"
#include "grille.h"

int verifier_deplacement(forme *f, grille *g, int nouvelle_x, int nouvelle_y); /* Verifie si le deplacement est possible */

void deplacer_forme_gauche(forme *f, grille *g); /* Deplace la forme vers la gauche */

void deplacer_forme_droite(forme *f, grille *g); /* Deplace la forme vers la droite */

void deplacer_forme_bas(forme *f, grille *g); /* Deplace la forme vers le bas */

void rotation_piece(forme *f, grille *g); /* Effectue la rotation de la piece */

void supprimer_lignes_complete(grille *g, int *score); /* Supprime les lignes completes */

void deplacer_forme(forme *f, grille *g, MLV_Event event, MLV_Keyboard_button sym, MLV_Button_state state); /* Deplace la forme */

int verifier_defaite(grille *g); /* Verifie si le joueur a perdu */
#endif                           /* GAME_H */