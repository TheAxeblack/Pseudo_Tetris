
int acceuil(){
  int c;
  printf("*******************************\n");
  printf("**   MENU PRINCIPALE  **\n");
   printf("*******************************\n");
  printf("1.Nouvelle partie\n");
  printf("2.Afficher les scores\n");
  printf("3.Sauvegarder la partie\n");
  printf("4.Quitter la partie\n");
  printf("réponse: ");
  if(scanf("%d",&c)!=1){
    printf("erreur de saisie\n");
    exit(EXIT_FAILURE);
  }
  return c;
}


int main(){
  switch(choix){
  case 1:
    printf("-----------Nouvelle partie-----------\n");
    /*appel à la fonction pour commencer une nouvelle partie*/
  case 2:
    printf("-----------Les scores-----------\n");
    /*appel à la fonction qui affiche les scores */
    break;
  case 3:
    printf("-----------Sauvegarder-----------\n");
    /*appel à la fonction qui sauvegarde*/
    break;
  case 4:
    printf("-----------Quitter la partie-----------\n");
    /*appel à la fonction qui permet de quitter la partie*/
     
    break;
  default:
    printf("\n");
  }
}



/*vérifie si une ligne est complète  */
int check_lgn(puit p,int j){
  int i;
    for (i = 1; i < LIGNES-2; i++){
      if (p[i][j] == 0){
	return 0;
      }
      return 1;
    }
  }
}

/*supprime si une ligne est complète*/
void  supp_lcp(puit p ){
  int i,j,tmp;
  for(j=0; j < COLONNES-2; j++){
  if(ligne_cplt (p, j)){
    
      tmp=p[i][j];
      while(i!=0){
	p[i][j]=p[i+1][j];
	i--;
		    

      }
      p[0][j]=tmp;
	
    }

  }
}

/*

void sauvegarde(int M,int X,char *joueur1,int O,char *joueur2,int NU){
  FILE *fichier=NULL;
  fichier=fopen("score.txt","a+");
  if(fichier==NULL){
    printf("fichier inexistant\n");
  }
  else{
    fprintf(fichier,"%d %d %s %d %s %d\n",M,X,joueur1,O,joueur2,NU);
  }
  fclose(fichier);
}
void lecture_fichier(tab_score *s){
    FILE *fichier=NULL;
  fichier=fopen("score.txt","r+");
  s->nb_ligne=0;
  if(fichier!=NULL){
    while(fscanf(fichier,"%d %d %s %d %s %d",&s->tab[s->nb_ligne].m,&s->tab[s->nb_ligne].x,s->tab[s->nb_ligne].j1,&s->tab[s->nb_ligne].o,s->tab[s->nb_ligne].j2,&s->tab[s->nb_ligne].n)==6 && s->nb_ligne<400 ){
      s->nb_ligne++;
    }
  }
  else{
    printf("fichier inexistant\n");
    exit(-1);
  }
  fclose(fichier);
}*/
