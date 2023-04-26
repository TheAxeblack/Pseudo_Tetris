#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "tetris.h"

int main(){
    Menu menu1;
    puit puit1;
    tab tab1;
    srand(time(NULL));

    /* Setup du tetris */
    init_jeux(puit1);
    init_tab(tab1);
    genererForme(tab1);

    /* variables */
    menu1 = aff_menu();

    /* Section de programme */
    while(menu1 != quitter){
        if(menu1==nvlprt){
            MLV_create_window("jeu", "tetris", 640, 480);
            partie(puit1, tab1);
        }
        else if (menu1 == chargerprt) {
            MLV_create_window("jeu", "tetris", 640, 480);
            MLV_free_window();
        }
        else if (menu1 == save) {
            MLV_create_window("jeu", "tetris", 640, 480);
            MLV_free_window();
        }
        else if(menu1 == score){
            MLV_create_window("jeu", "tetris", 640, 480);
            MLV_free_window();
        }
        if(menu1 == regle){
            MLV_create_window("jeu", "tetris", 640, 480);
            MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE3);
            MLV_draw_text( 30, 50, "Tetris met le joueur au défi de réaliser des lignes complètes en déplaçant des pièces de formes différentes, les tétrominos, qui défilent depuis le haut jusqu'au bas de l'écran.", MLV_COLOR_MAGENTA);
            MLV_draw_text( 30, 130,  "Les lignes complétées disparaissent tout en rapportant des points et le joueur peut de nouveau remplir les cases libérées.", MLV_COLOR_MAGENTA);
            MLV_free_window();
        }
    }

    exit(EXIT_SUCCESS);
}
