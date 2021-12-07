#include<stdio.h>
#include<stdlib.h>
#include <MLV/MLV_all.h>

typedef enum{nvlprt, chargerprt, score, regle, quitter} Menu;



int main(){
  Menu c;
  int cl=0;
  int x,y;
  MLV_Image *image;
  int a, b;
  a=260;b=280;
  
  MLV_create_window( "tetris", "menu", 640, 480 );

  image=MLV_load_image( "image/logo.jpg" );
  MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLACK);
  MLV_resize_image_with_proportions( image, 640, 480);
  MLV_draw_image( image, 0, 0 );  
  MLV_draw_text_box(260,280,120,46,"Cliquez pour commencer",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);

  
  MLV_actualise_window();
  
  MLV_wait_mouse_or_seconds(NULL, NULL, 4);
  MLV_get_mouse_position(&a,&b);
  
  while(cl == 0){
    
    
    
    MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLACK);
    MLV_draw_text_box(260,30,120,46,"nouvelle partie",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_draw_text_box(260,122,120,46,"charger la partie",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_draw_text_box(260,216,120,46,"meilleur score",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_draw_text_box(260,310,120,46,"regle du jeux",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_draw_text_box(260,404,120,46,"quitter",10,MLV_COLOR_BLUE3,MLV_COLOR_WHITE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
    MLV_get_mouse_position(&x, &y);
    MLV_actualise_window();
    
    if((x > 260 && x < 360) && (y > 30 && y < 80)){
      
      if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
	MLV_wait_mouse(&x, &y);
        cl = 1;
        c = nvlprt;
	MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE);
      }
    }

    if((x > 260 && x < 360) && (y > 122 && y < 172)){
      
      if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
        MLV_wait_mouse(&x, &y);
        cl = 1;
        c = chargerprt;
	MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE);
      }
    }

    if((x > 260 && x < 360) && (y > 216 && y < 266)){
      
      if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
        MLV_wait_mouse(&x, &y);
        cl = 1;
        c = score;
	MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE);
      }
    }

    if((x > 260 && x < 360) && (y > 310 && y < 360)){
     
      if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
        MLV_wait_mouse(&x, &y);
        cl = 1;
        c = regle;
	MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE);
      }
    }

    if((x > 260 && x < 360) && (y > 404 && y < 454)){
      if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
        
	MLV_wait_mouse(&x, &y);
        cl = 1;
        c = quitter;
	MLV_draw_filled_rectangle(0, 0, 640, 480, MLV_COLOR_BLUE);
      }
    }
    

    
    
    if(cl != 2){
      MLV_actualise_window();
    }
  }



       
 
  MLV_actualise_window(); 
  
  
  MLV_wait_seconds( 100 );
        
  
        
  MLV_free_window();
  return c;
}
