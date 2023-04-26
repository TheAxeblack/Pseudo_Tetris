#include<stdio.h>
#include<stdlib.h>
#include <MLV/MLV_all.h>
#include "tetris.h"

Menu aff_menu() {
    Menu c;
    int cl = 0;
    int x, y;
    int a, b;
    a = 260;
    b = 280;

    MLV_create_window("tetris", "menu", 640, 480);

    MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLACK);
    MLV_draw_text_box(260, 280, 120, 46, "cliquer pour\ncontinuer", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE,
                      MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);


    MLV_actualise_window();


    MLV_wait_mouse(&a, &b);

    while (cl == 0) {


        MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLACK);
        MLV_draw_text_box(260, 30, 120, 46, "nouvelle partie", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                          MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(160, 122, 120, 46, "charger la partie", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                          MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(360, 122, 120, 46, "sauvegarder la partie", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(260, 216, 120, 46, "meilleur score", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                          MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(260, 310, 120, 46, "regle du jeux", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                          MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(260, 404, 120, 46, "quitter", 10, MLV_COLOR_BLUE3, MLV_COLOR_WHITE, MLV_COLOR_BLACK,
                          MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_wait_mouse(&x, &y);


        if ((x > 260 && x < 380) && (y > 30 && y < 80)) {

            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                cl = 1;
                c = nvlprt;

            }
        }

        if ((x > 160 && x < 280) && (y > 122 && y < 172)) {
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                cl = 1;
                c = chargerprt;

            }
        }
        if ((x > 360 && x < 480) && (y > 122 && y < 172)) {

            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {

                cl = 1;
                c = save;

            }
        }
        if ((x > 260 && x < 380) && (y > 216 && y < 266)) {
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                cl = 1;
                c = score;

            }
        }

        if ((x > 260 && x < 380) && (y > 310 && y < 360)) {
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                cl = 1;
                c = regle;

            }
        }

        if ((x > 260 && x < 380) && (y > 404 && y < 454)) {
            if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
                cl = 1;
                c = quitter;

            }
        }

        if (cl != 2) {
            MLV_actualise_window();
        }
    }


    MLV_actualise_window();


    MLV_wait_seconds(100);


    MLV_free_window();
    return c;
}
