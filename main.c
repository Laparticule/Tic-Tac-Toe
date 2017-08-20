#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char case_grid[10] = {'0','1','2','3','4','5','6','7','8','9'}; 
	char player1[20] = {0};
	char player2[20] = {0};
	int game = 1;
	int player1sturn = 1;
	int case_number;
	char player_symbol;

	printf("Bienvenue dans le jeu du morpion ! Quels sont vos noms ?\n");

	printf("Joueur1 ? ");
	scanf("%s", player1);

	printf("Joueur2 ? ");
	scanf("%s", player2);

	printf("Bienvenue à vous deux, %s et %s \n", player1, player2);

	printf("%c %c %c \n%c %c %c \n%c %c %c \n", case_grid[1], case_grid[2], case_grid[3], case_grid[4], case_grid[5], case_grid[6], case_grid[7], case_grid[8], case_grid[9]);


	while (game == 1)
	{
		if (player1sturn == 1)
		{
			printf("\e[1m%s\e[0m, c'est à vous. Entrez la case à changer\n", player1);
			scanf("%d", &case_number);
			player_symbol = 'X';
			player1sturn = 0;
		}
		else
		{
			printf("\e[1m%s\e[0m c'est à vous. Entrez la case à changer\n", player2);
			scanf("%d", &case_number);
			player_symbol = 'O';
			player1sturn = 1;
		}

		if (case_grid[case_number] != 'X' && case_grid[case_number] != 'O')
			case_grid[case_number] = player_symbol;
		else
		{
			printf("Oh le tricheur ! Vous ne pouvez pas réécrire sur cette case ! \n");
			if (player_symbol == 'X')
				player1sturn = 1;
			if (player_symbol == 'O')
				player1sturn = 0;
		}

	   	printf("%c %c %c \n%c %c %c \n%c %c %c \n", case_grid[1], case_grid[2], case_grid[3], case_grid[4], case_grid[5], case_grid[6], case_grid[7], case_grid[8], case_grid[9]);


		if ((case_grid[1] == case_grid[2] && case_grid[2] == case_grid[3]) || (case_grid[4] == case_grid[5] && case_grid[5] == case_grid[6]) || (case_grid[7] == case_grid[8] && case_grid[8] == case_grid[9]) || (case_grid[1] == case_grid[4] && case_grid[4] == case_grid[7]) || (case_grid[2] == case_grid[5] && case_grid[5] == case_grid[8]) || (case_grid[3] == case_grid[6] && case_grid[6] == case_grid[9]) || (case_grid[3] == case_grid[5] && case_grid[5] == case_grid[7]) || (case_grid[1] == case_grid[5] && case_grid[5] == case_grid[9]))
			game = 0;
	}
	if (player1sturn == 1)
		printf("Toutes mes félicitations %s ! Vous avez gagné !", player2);
	else
		printf("Toutes mes félicitations %s ! Vous avez gagné !", player1);
}
