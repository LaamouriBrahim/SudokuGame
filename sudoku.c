#include<stdio.h>



typedef int grille[9][9];

/*
grille g = {{ 1, 2, 3, 4, 5, 6, 4, 8, 9},
	        { 4, 5, 6, 7, 8, 9, 1, 2, 3},
	        { 7, 8, 9, 1, 2, 3, 4, 5, 6},
	        { 2, 3, 1, 5, 6, 4, 8, 9, 7},
	        { 5, 6, 4, 8, 9, 7, 2, 3, 1},
	        { 8, 9, 7, 2, 3, 1, 5, 6, 4},
	        { 3, 1, 2, 6, 4, 5, 9, 7, 8},
	        { 6, 3, 5, 9, 7, 8, 3, 1, 2},
	        { 9, 7, 8, 3, 1, 2, 6, 4, 5} };
*/


void affiche_grille(grille g){
	for(int i = 0 ; i < 9; i++)
	{
		printf("\n");
		if(i%3==0){printf("\n");
	}
		for(int j = 0 ; j < 9 ; j++)
		{
			if(j%3==0)
				{
					printf("\t");
				}
			if(g[i][j]!=0 && g[i][j]<=9 && g[i][j]>=1)
				{
					printf("%d ",g[i][j]);
				}
			else
				{
					printf("  ");
				}

		}
	}
	printf("\n\n");
}




int check_col(grille g , int col)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(g[i][col] == g[j][col] && i != j)
			{
	//			printf("la colonne numéro %d est incorrecte \n",col);
				return 0;
			}
		}
	}
	//printf("la colonne numéro %d est correcte \n",col);
	return 1;
}


int check_ligne(grille g , int lgn)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(g[lgn][i] == g[lgn][j] && i != j)
			{
				//printf("la ligne numéro %d est incorrecte \n",lgn);
				return 0;
			}
		}
	}
	//printf("la ligne numéro %d est correcte \n",lgn);
	return 1;
}


void determine_elem_bloc(grille g, int nb/*nb_bloc*/,int outputlist[9])
{
	int ref[9] = {  g[3*(nb/3)][3*(nb%3)] , g[3*(nb/3)][3*(nb%3)+1]  , g[3*(nb/3)][3*(nb%3)+2],    //tois premiers élements du block/ligne 1					
				g[3*(nb/3)+1][3*(nb%3)],g[3*(nb/3)+1][3*(nb%3)+1],g[3*(nb/3)+1][3*(nb%3)+2],   //ligne 2 du block
				g[3*(nb/3)+2][3*(nb%3)],g[3*(nb/3)+2][3*(nb%3)+1],g[3*(nb/3)+2][3*(nb%3)+2] }; //ligne 3 du block

	for(int i = 0 ;i < 9 ; i++)
	{
		outputlist[i]=ref[i];
	}
}





int check_block(grille g ,int nb )
{  //on compte les blocks ligne par ligne càd les colonnes 0,1,2 sont ceux de la premiére ligne .

	int ref[9] = {  g[3*(nb/3)][3*(nb%3)] , g[3*(nb/3)][3*(nb%3)+1]  , g[3*(nb/3)][3*(nb%3)+2],    //tois premiers élements du block/ligne 1
					g[3*(nb/3)+1][3*(nb%3)],g[3*(nb/3)+1][3*(nb%3)+1],g[3*(nb/3)+1][3*(nb%3)+2],   //ligne 2 du block
					g[3*(nb/3)+2][3*(nb%3)],g[3*(nb/3)+2][3*(nb%3)+1],g[3*(nb/3)+2][3*(nb%3)+2] }; //ligne 3 du block

	// nb/3 est la division euclidienne car nb et 3 sont les deux des entiers --> le resultat de 3*(nb/3) n'est pas forcement nb
	 // nb%3 (GOLDEN RULE) took me a while to get this :3(yes i'm good at maths)

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(ref[i] == ref[j] && i != j)
			{
				//printf("la block numéro %d est incorrecte \n",nb);
				return 0;
			}
		}
	}
	//printf("la block numéro %d est correcte \n",nb);
	return 1;
}

int check_grid(grille g)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		if(check_block(g,i)==0|| check_ligne(g,i) == 0 || check_col(g,i)==0)
		{
			printf("%d\n",i);
			printf("Cette grille est incorrecte \n");
			return 0;
		}
		printf("Bien joué,Cette grille est correcte \n");
		return 1;
	}

}

int check_if_complete(grille g)
{
	for(int i =0 ; i<9 ; i++)
	{
		for(int j=0 ; j<9 ;j++)
		{
			if(g[i][j]==0)
			{
				return 0;
			}
		}
	}
	return 1;
}


void input(grille g)
{
	if( check_if_complete(g) == 1 )
	{
		affiche_grille(g);

		printf("Cette Grille est complete\n");

		check_grid(g);

		return;
	}

	affiche_grille(g);
	int x,y,val;

	printf("Saisissez le numéro de la ligne :\n");
	scanf("%d",&y);

	printf("Saisissez le numéro de la colonne :\n");
	scanf("%d",&x);

	printf("Saisissez la valeur à inserer : \n");
	scanf("%d",&val);

	if (g[y][x] == 0)
	{
		g[y][x] = val;
		printf("C'est fait ! \n");
	}

	else
	{
		printf("Les informations que vous avez saisi sont incorrectes\n ");
		// Veuillez prendre en compte que la numérotation des lignes et colonne commence par 0 et termine à 8
	}

	if(check_if_complete(g) == 1)
	{	
		affiche_grille(g);
		check_grid(g);
		return;
	}

	input(g);
}



// JOUEUR ORDINATEUR

int determin_bloc(int x,int y)
{

	int coordx_bloc, coordy_bloc;
	int CAS[3][3]={{0,3,6},{1,4,7},{2,5,8}};// premier sous_table pour coordx=0 , deuxiéme coordx = 1 ....

	// determine coordx_bloc (coordonnées du bloc , comme ça on determine le bloc)
	if(x<3)
		{
			coordx_bloc=0;
		}
	if(x>5)
		{
			coordx_bloc=2;
		}
	else
		{
			coordx_bloc=1;
		}
	// determine coordy_bloc
	if(y<3)
		{
			coordy_bloc=0;
		}
	if(y>5)
		{
			coordy_bloc=2;
		}
	else
		{
			coordy_bloc=1;
		}

	return CAS[coordx_bloc][coordy_bloc];
}



void calcul_ligne_colonne_block(grille g , int x , int y , int lgn[9] , int col[9] , int bloc[9])
{
	int nb_bloc = determin_bloc(x,y);

	for(int i=0 ; i<9 ;i++)
	{
		int temp_elem_bloc[9];
		determine_elem_bloc(g,i,temp_elem_bloc);
		lgn[i]=g[y][i];
		col[i]=g[i][x];
		bloc[i]=temp_elem_bloc[i];
	}

}




	



int main()
{

int elem_bloc[9];

grille g = {{ 1, 2, 3, 4, 5, 6, 7, 8, 9},
	        { 4, 5, 0, 7, 8, 9, 1, 2, 3},
	        { 7, 8, 9, 1, 2, 3, 4, 5, 6},
	        { 2, 3, 1, 5, 6, 4, 8, 9, 7},
	        { 5, 6, 4, 8, 4, 7, 2, 3, 1},
	        { 8, 9, 7, 2, 3, 1, 5, 6, 4},
	        { 3, 1, 2, 6, 4, 5, 9, 7, 8},
	        { 6, 4, 5, 9, 7, 8, 3, 1, 2},
	        { 9, 7, 8, 3, 1, 2, 6, 0, 5}};

	int lgn[9];
	int col[9];
	int bloc[9];

	unsigned int nb_error = 0;

	/*check_ligne(g,0);
	check_ligne(g,1);   // test
	check_col(g,0);
	check_col(g,1);*/

	/*        	
	affiche_grille(g);
	check_block(g,0);
	check_block(g,1);
	*/

	/*       
	affiche_grille(g);
	check_grid(g);
	*/

	input(g);


	return 0;
}