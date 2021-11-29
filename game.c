#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include <MLV/MLV_all.h>


int partie_finie



/*calcul du score*/

int score(puit p){
  int i,k,s;
  s=0
    for(i=COLONNES-1;i>0;i--)
      {
       if(check_lgn(puit p,int i))
	 {
	  k++;
	 }
       switch(k) {

       case 1:
    
       s=s+10;
       break;
    
       case 2:
    
       s=s+25;
       break;

       case 3:
    
       s=s+40;
       break;

       case 4:

       s=s+55;
       break;

       case 5:

       s=s+100;
       break;
       
       default:
       s=s+0;
       break;
       } 

      

      }
  return s;
  
  


}

void affichage_score(puit p){

  char 


}
