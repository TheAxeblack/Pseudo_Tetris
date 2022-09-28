#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "menu.h"
#include "save.h"

int main(void) {
    /* Section de definition des variables */
    puit puit1;
    puit puit2;
    forme forme1;
    forme forme2;
    forme *ptr_forme1;
    forme *ptr_forme2;
    tab tab1;

    /* Generation de la graine pour l'aleatoire */
    srand(time(NULL));

    /* Setup du tetris */
    init_jeux(puit1);
    init_jeux(puit2);
    init_tab(tab1);
    genererForme(tab1);

    /* Initialisation des variables */
    forme1 = choisirAlea(tab1);
    ptr_forme1 = &forme1;

    forme2 = choisirAlea(tab1);
    ptr_forme2 = &forme2;

    /* Section de programme */
    printf("\n");
    afficher_terrain(puit1);
    printf("\n");
    insertionForme(puit1, ptr_forme1, 0, 5);
    afficher_terrain(puit1);
    printf("\n");
    dep_horizontal_g(puit1, ptr_forme1);
    dep_horizontal_d(puit1, ptr_forme1, ptr_forme1->x);
    descendre(puit1, ptr_forme1);
    insertionForme(puit1, ptr_forme2, 0, 5);
    descendre(puit1, ptr_forme2);
    save_partie(puit1, ptr_forme1);
    afficher_terrain(puit2);
    load_partie(puit2);
    afficher_terrain(puit2);
    exit(EXIT_SUCCESS);
}