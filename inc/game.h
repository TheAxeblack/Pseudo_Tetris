#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "forme.h"
#include "grille.h"

int verifier_deplacement(forme *f, grille *g, int nouvelle_x, int nouvelle_y);

void deplacer_forme_gauche(forme *f, grille *g);

void deplacer_forme_droite(forme *f, grille *g);

void deplacer_forme_bas(forme *f, grille *g);

void rotation_piece(forme *f, grille *g);

void supprimer_lignes_complete(grille *g, int *score);

void deplacer_forme(forme *f, grille *g, MLV_Event event, MLV_Keyboard_button sym, MLV_Button_state state);

int verifier_defaite(forme *f);
#endif