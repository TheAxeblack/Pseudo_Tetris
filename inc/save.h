#ifndef SAVE_H
#define SAVE_H

#include "tetris.h"

#define SAVE_FILE_NAME "game.save"
#define SAVE_FILE_MODE "wb"
#define LOAD_FILE_MODE "rb"

/* Prototypes des fonctions */
int save_partie(puit p);

int load_partie(puit p);

#endif