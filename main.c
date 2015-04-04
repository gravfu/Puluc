#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "conio.h"


void joueurs(char *j1, char *j2);
void debut(char *plateau);
int alea_des(int *des);
int pion_jouable(int deplacement, char pion, char *plateau, int joueur);
void liste_pion_jouable(char *plateau, char *liste_pt, int deplacement, int joueur);

void deplacement_jeu(char *plateau, char pion, int deplacement);


int main()
{
	char plateau[11][10];
	char nom_j1[20];
	char nom_j2[20];
	char liste_pt_jouable[5];

	int des[4];
	char pion;

	int tour = 1;
	int y, x, i;

	int pion_bougeable = 0;
	int compt_j1 = 0;
	int compt_j2 = 0;

	int sortie;
	int rejouer = 0;
	int jj;
	char repe = 1;

	do
	{

		// On demande le nom des joueurs
		joueurs(nom_j1, nom_j2);



		system("cls");

		// On demande de choisir qui commence
		/*printf("Qui commence? (1/2)");
		do
		{
			scanf("%d", &jj);
		} while (jj < 1 || jj > 2);
		if (jj == 2)
		{
			tour = -1;
		}
		*/

		// On initialise les tableaux à 0
		debut(plateau);


		do
		{


			for (y = 0; y<10; y++)
			{

				//system("cls");
				printf("/////// PULUC \\\\\\\\n\n");
				printf("\n");
				for (y = 0; y < 10; y++)
				{
					printf("\n");
					for (x = 0; x<11; x++)
					{
						printf("| %c", plateau[x][y]);
					}
				}
			}

			pion_bougeable = 0;

			if (tour == 1)
			{
				printf("\n C'est a %s de jouer (j1)", nom_j1);

				printf("\nLancer les dés\n");
				system("pause");
				des[4] = alea_des(des);

				printf("\ndes: %d %d %d %d", des[0], des[1], des[2], des[3]);
				printf("\navancement de %d cases", des[4]);

				liste_pion_jouable(plateau, liste_pt_jouable, des[4], tour);
				printf("\nVous pouvez jouer:  %c %c %c %c %c", liste_pt_jouable[0], liste_pt_jouable[1], liste_pt_jouable[2], liste_pt_jouable[3], liste_pt_jouable[4]);

				if (liste_pt_jouable[0] != 0 || liste_pt_jouable[1] != 0 || liste_pt_jouable[2] != 0 || liste_pt_jouable[3] != 0 || liste_pt_jouable[4] != 0)
				{
					do
					{

						printf("\n Lettre du pion a jouer: ");
						do
						{
							scanf("%c", &pion);
						} while (pion < 'A' || pion > 'E');
						printf("test");

						pion_bougeable = pion_jouable(des[4], pion, plateau, 1);

                        printf("test");
					} while (pion_bougeable != 1);
                    printf("test");
					deplacement_jeu(plateau, pion, des[4]);
					printf("test");
				}

				tour = -1;
			}

			else if (tour == -1)
			{
				if (repe == 'o')
				{
					printf("\n C'est a IA de jouer", nom_j2);

					des[4] = alea_des(des);
					printf("\n des: %d %d %d %d", des[0], des[1], des[2], des[3]);
					printf("\n avancement de %d cases", des[4]);

					liste_pion_jouable(plateau, liste_pt_jouable, des[4], tour);
					printf("\nVous pouvez jouer:  %c %c %c %c %c", liste_pt_jouable[0], liste_pt_jouable[1], liste_pt_jouable[2], liste_pt_jouable[3], liste_pt_jouable[4]);

					if (liste_pt_jouable[0] != 0 || liste_pt_jouable[1] != 0 || liste_pt_jouable[2] != 0 || liste_pt_jouable[3] != 0 || liste_pt_jouable[4] != 0)
					{
						for (i = 0; i < 5; i++)
						{
							if (liste_pt_jouable[i] != 0)
							{
								pion = liste_pt_jouable[i];
							}
						}

						pion_bougeable = pion_jouable(des[4], pion, plateau, 2);

						deplacement_jeu(plateau, pion, des[4]);

					}

					//system("pause");
					tour = 1;
				}
				else
				{
					printf("\n C'est a %s de jouer (j2)", nom_j2);

					printf("\nLancer les dés");
					system("pause");
					des[4] = -alea_des(des);
					printf("\n des: %d %d %d %d", des[0], des[1], des[2], des[3]);
					printf("\n avancement de %d cases", des[4]);

					liste_pion_jouable(plateau, liste_pt_jouable, des[4], tour);
					printf("\nVous pouvez jouer:  %c %c %c %c %c", liste_pt_jouable[0], liste_pt_jouable[1], liste_pt_jouable[2], liste_pt_jouable[3], liste_pt_jouable[4]);

					if (liste_pt_jouable[0] != 0 || liste_pt_jouable[1] != 0 || liste_pt_jouable[2] != 0 || liste_pt_jouable[3] != 0 || liste_pt_jouable[4] != 0)
					{
						do
						{
							printf("\n Chiffre du pion a jouer: ");
							do
							{
								scanf("%c", &pion);
							} while (pion < '1' || pion > '5');

							printf("test");

							pion_bougeable = pion_jouable(des[4], pion, plateau, 2);

						} while (pion_bougeable < 1);




						deplacement_jeu(plateau, pion, des[4]);

					}

					//system("pause");
					tour = 1;
				}
				
			}


			//Detection si la partie est fini
			for (x = 0; x<11; x++)
			{
				printf("\n  ");
					if (plateau[x][0] > 48 && plateau[x][0] < 54)
						compt_j1++;
					if (plateau[x][0] > 64 && plateau[x][0] < 70)
						compt_j2++;
			}
			if (compt_j1 == 0)
			{
				printf("Victoire de %s", nom_j2);
				system("pause");
				sortie = 0;
			}

			if (compt_j2 == 0)
			{
				printf("/!\  Victoire de %s (j1)", nom_j1);
				system("pause");
				sortie = 0;
			}

		} while (sortie != 0);

		printf("/////// PULUC \\\\\\\\n\n");
		printf("\nVoulez-vous rejouer? (o/n): ");
		do
		{
			scanf("%c", &rejouer);
		} while (rejouer != 'o' || rejouer != 'n');


	}while (rejouer != 0);

	return 0;
}

void joueurs(char *j1, char *j2)
{
	char tab[20];
	int i;

	//j1

	for (i = 0; i<20; i++)
	{
		tab[i] = 0;
	}

	system("cls");

	printf("Nom du joueur 1: ");
	scanf("%s", tab);

	for (i = 0; i<20; i++)
	{
		*(j1 + i) = tab[i];
	}

	//j2

	for (i = 0; i<20; i++)
	{
		tab[i] = 0;
	}

	system("cls");
	printf("Nom du joueur 2: ");
	scanf("%s", tab);

	for (i = 0; i<20; i++)
	{
		*(j2 + i) = tab[i];
	}

}

void debut(char *plateau)
{
	int y, x;

	//On initialise les valeurs du tableau à 0
	for (y = 0; y<11; y++)
	{
		for (x = 0; x<11; x++)
		{
			*(plateau + (y)+10 * (x)) = 0;
		}
	}
	//j1
	*(plateau) = 'A';
	*(plateau + 1) = 'B';
	*(plateau + 2) = 'C';
	*(plateau + 3) = 'D';
	*(plateau + 4) = 'E';

	//j2
	*(plateau + 10 * 10) = '1';
	*(plateau + 1 + 10 * 10) = '2';
	*(plateau + 2 + 10 * 10) = '3';
	*(plateau + 3 + 10 * 10) = '4';
	*(plateau + 4 + 10 * 10) = '5';




}

int alea_des(int *des)
{
	int des_1 = 0, des_2 = 0, des_3 = 0, des_4 = 0, deplacement = 0;
	const int min = 0, max = 1;

	srand(time(NULL));

	des_1 = (rand() % (max - min + 1)) + min;
	//printf("d1 %d\n",des_1);
	des_2 = (rand() % (max - min + 1)) + min;
	//printf("d2 %d\n",des_2);
	des_3 = (rand() % (max - min + 1)) + min;
	//printf("d3 %d\n",des_3);
	des_4 = (rand() % (max - min + 1)) + min;
	//printf("d4 %d\n",des_4);

	*(des) = des_1;
	*(des + 1) = des_2;
	*(des + 2) = des_3;
	*(des + 3) = des_4;
	deplacement = des_1 + des_2 + des_3 + des_4;

	if (deplacement == 0)
	{
		deplacement = 5;
	}

	return deplacement;
}



int pion_jouable(int deplacement, char pion, char *plateau, int joueur)
{
	int x, y;
	int yp, xp;

	// On recherche le pion selectionné par le joueur sur le plateau
	for (x = 0; x<11; x++)
	{
		for (y = 0; y<10; y++)
		{
			if (*(plateau + 10 * x + y) == pion)
			{
				xp = x;
				yp = y;

				x = 15;
				y = 15;
			}

		}
	}

	// On annule les coups non autorisés.
	//printf(" yp = %d", yp);
	if (yp == 0)
	{
		if (xp + deplacement < 0)
			return 0;
		else if (xp + deplacement > 10)
			return 0;
		else if (joueur == 1)
		{
			if (*(plateau + 10 * (xp + deplacement)) < 'F' && *(plateau + 10 * (xp + deplacement)) > '@')
				return 0;
		}
		else if (joueur == 2)
		{
			if (*(plateau + 10 * (xp + deplacement)) < '6' && *(plateau + 10 * (xp + deplacement)) > '0')
				return 0;
		}
	}



	if (yp == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}



	return 0;

}

void liste_pion_jouable(char *plateau, char *liste_pt, int deplacement, int tour)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		*(liste_pt + i) = 0;
	}
	if(tour == 1)
	{
		if (pion_jouable(deplacement, 'A', plateau, 1) == 1 )
            *(liste_pt) = 'A';
		if (pion_jouable(deplacement, 'B', plateau, 1) == 1 )
            *(liste_pt + 1) = 'B';
		if (pion_jouable(deplacement, 'C', plateau, 1) == 1 )
            *(liste_pt + 2) = 'C';
        if(pion_jouable(deplacement, 'D', plateau, 1) == 1 )
            *(liste_pt + 3) = 'D';
		if (pion_jouable(deplacement, 'E', plateau, 1) == 1 )
            *(liste_pt + 4) = 'E';
	}

    if(tour == -1)
	{
		if (pion_jouable(deplacement, '1', plateau, 2) == 1 )
            *(liste_pt) = '1';
		if (pion_jouable(deplacement, '2', plateau, 2) == 1 )
            *(liste_pt + 1) = '2';
		if (pion_jouable(deplacement, '3', plateau, 2) == 1 )
            *(liste_pt + 2) = '3';
		if (pion_jouable(deplacement, '4', plateau, 2) == 1 )
            *(liste_pt + 3) = '4';
		if (pion_jouable(deplacement, '5', plateau, 2) == 1 )
            *(liste_pt + 4) = '5';
	}


}

void deplacement_jeu(char *plateau, char pion, int deplacement)
{
	int x, y, i;
	int xp = 0;
	int yp = 0;
	int n = 0;
	int	ng;
	// On recherche le pion selectionné par le joueur sur le plateau
	printf("deplacement jeu");
	printf("pion = %c  ", pion);
	for (x = 0; x<11; x++)
	{
		for (y = 0; y<10; y++)
		{
			if (*(plateau + 10 * x + y) == pion)
			{
				xp = x;
				yp = y;

				x = 15;
				y = 15;
			}

		}
	}
	printf("xp = %d, yp = %d |", xp, yp);

	if (xp + deplacement == 10)
	{
	    printf("test2");
		for (i = 0; i<10; i++)
		{
			if (*(plateau + i) == 0)
			{

				if (*(plateau + 10 * xp + 1) < '@')
				{
					for (y = 1; y<10; y++)
					{
						if (*(plateau + 10 * xp + y) < '@')
						{
							y = 50;
						}
						else
							*(plateau + 10 * xp + y) = 0;
					}
					*(plateau + i) = pion;
					*(plateau + 10 * xp + yp) = 0;

					for (y = 0; y<10; y++)
					{
						if (*(plateau + 10 * xp + y) = 0)
						{
							for (x = y; x<10; x++)
							{
								if (*(plateau + 10 * xp + x) != 0)
								{
									*(plateau + 10 * xp + y) = *(plateau + 10 * xp + x);
									x = 50;
								}
							}
						}
					}


				}

				i = 50;
			}
		}
	}

	else if (xp + deplacement == 0)
	{
		printf("xp + deplacement\n");
		for (i = 0; i<10; i++)
		{
			if ( *(plateau + 10*10 + i) == 0)
			{

				if (*(plateau + 10 * xp + 1) > '@')
				{
					for (y = 1; y<10; y++)
					{
						if (*(plateau + 10 * xp + y) > '@')
						{
							y = 50;
						}
						else
							*(plateau + 10 * xp + y) = 0;
					}
					*(plateau + 10*xp + i) = pion;
					*(plateau + 10 * xp + yp) = 0;

					for (y = 0; y<10; y++)
					{
						if (*(plateau + 10 * xp + y) = 0)
						{
							for (x = y; x<10; x++)
							{
								if (*(plateau + 10 * xp + x) != 0)
								{
									*(plateau + 10 * xp + y) = *(plateau + 10 * xp + x);
									x = 50;
								}
							}
						}
					}



				}

				i = 50;
			}
		}
	}

	else if (*(plateau + 10 * (xp + deplacement)) == 0)
	{
		printf("\n(plateau + 10 * (xp + deplacement)) == 0 \n");
		if (pion > '@')
		{
			printf("\npion > '@'\n");
			for (y = 1; y < 10; y++)
			{
				if (*(plateau + 10 * xp + y) > '@')
				{
					y = 50;
				}
				else if (*(plateau + 10 * xp + y) != 0)
				{
					n = n + 1;
				}
			}
			ng = n + 1;

			// Déplacement
			printf("ng = %d", ng);
			for (i = 0; i < ng; i++)
			{
				//printf("\ntest\n");
				*(plateau + 10 * (xp + deplacement) + i) = *(plateau + 10 * (xp)+i);
				*(plateau + 10 * (xp)+i) = 0;


			}
			printf("test 3");

			/*for (y = 0; y<10; y++)
			{

				printf("\n  ");

				for (x = 0; x<11; x++)
				{
					printf("| %c", *(plateau + 10 * x + y));
				}
			}*/

			//Décallage origine vers le haut.
			for (x = 0; x < 10; x++)
			{
				if (*(plateau + 10 * xp + x) == 0)
				{
					for (y = x; y < 10; y++)
					{
						if (*(plateau + 10 * xp + y) != 0)
						{
							*(plateau + 10 * xp + x) = *(plateau + 10 * xp + y);
							*(plateau + 10 * xp + y) = 0;
							y = 50;
						}
					}
				}
			}
			/*printf("\n  ");
			for (y = 0; y<10; y++)
			{

				printf("\n  ");

				for (x = 0; x<11; x++)
				{
					printf("| %c", *(plateau + 10 * x + y));
				}
			} */



		}

		else if (pion < '6' && pion > '0')
		{
			printf("pion < '6' && pion > '0'");
			for (y = 1; y < 10; y++)
			{
				if (*(plateau + 10 * xp + y) < '6' && *(plateau + 10 * xp + y) > '0')
				{
					y = 50;
				}
				else if (*(plateau + 10 * xp + y) != 0)
				{
					n = n + 1;
				}
			}

			printf("nombre prisonnier = %d ", n);

			ng = n + 1;

			// Déplacement
			for (i = 0; i < ng; i++)
			{

				*(plateau + 10 * (xp + deplacement) + i) = *(plateau + 10 * (xp)+i);
				*(plateau + 10 * (xp)+i) = 0;


			}

			//Décallage origine vers le haut.
			for (x = 0; x < 10; x++)
			{
				if (*(plateau + 10 * xp + x) == 0)
				{
					for (y = x; y < 10; y++)
					{
						if (*(plateau + 10 * xp + y) != 0)
						{
							*(plateau + 10 * xp + x) = *(plateau + 10 * xp + y);
							*(plateau + 10 * xp + y) = 0;
							y = 50;
						}
					}
				}
			}





		}
	}

	//Partie Capture du pion.
	else if (*(plateau + 10 * (xp + deplacement)) != 0)
	{
		//printf("*(plateau + 10 * (xp + deplacement)) != 0");
		if (pion > '@')
		{
			for (y = 1; y < 10; y++)
			{
				if (*(plateau + 10 * xp + y) > '@')
				{
					y = 50;
				}
				else if (*(plateau + 10 * xp + y) > '0' && *(plateau + 10 * xp + y) < '6')
				{
					n = n + 1;
				}
			}

			//printf("nombre prisonnier = %d ", n);

			ng = n + 1;
			//décallage
			for (i = 10 - ng; i > -1; i--)
			{
				*(plateau + 10 * (xp + deplacement) + i + ng) = *(plateau + 10 * (xp + deplacement) + i);
				*(plateau + 10 * (xp + deplacement) + i - 1) = 0;
			}

			// Déplacement
			for (i = 0; i < ng; i++)
			{
				*(plateau + 10 * (xp + deplacement) + i) = *(plateau + 10 * xp + i);
				*(plateau + 10 * (xp)+i) = 0;



			}

			//Décallage origine vers le haut.
			for (x = 0; x < 10; x++)
			{
				if (*(plateau + 10 * xp + x) == 0)
				{
					for (y = x; y < 10; y++)
					{
						if (*(plateau + 10 * xp + y) != 0)
						{
							*(plateau + 10 * xp + x) = *(plateau + 10 * xp + y);
							*(plateau + 10 * xp + y) = 0;
							y = 50;
						}
					}
				}
			}




		}

		else if (pion < '6' && pion > '0')
		{
			for (y = 1; y < 10; y++)
			{
				if (*(plateau + 10 * xp + y) < '6' && *(plateau + 10 * xp + y) > '0')
				{
					y = 50;
				}
				else if (*(plateau + 10 * xp + y) != 0)
				{
					n = n+1;
				}
			}

			//printf("nombre prisonnier = %d ", n);

			ng = n + 1;
			//décallage
			for (i = 10 - ng; i > -1; i--)
			{
				*(plateau + 10 * (xp + deplacement) + i + ng ) = *(plateau + 10 * (xp + deplacement) + i);
				*(plateau + 10 * (xp + deplacement) + i) = 0;
			}

			// Déplacement
			for (i = 0; i < ng; i++)
			{
				*(plateau + 10 * (xp + deplacement) + i) = *(plateau + 10 * (xp)+i);
				*(plateau + 10 * (xp)+i) = 0;

			}

			//Décallage origine vers le haut.
			for (x = 0; x < 10; x++)
			{
				if (*(plateau + 10 * xp + x) == 0)
				{
					for (y = x; y < 10; y++)
					{
						if (*(plateau + 10 * xp + y) != 0)
						{
							*(plateau + 10 * xp + x) = *(plateau + 10 * xp + y);
							*(plateau + 10 * xp + y) = 0;
							y = 50;
						}
					}
				}
			}




		}

	}

	//printf("\nxp = %d, yp = %d, deplacement = %d   ", xp, yp, deplacement);
	//system("pause");
}
