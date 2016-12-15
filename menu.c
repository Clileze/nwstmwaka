#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "statique.h"
#include "dynamique.h"
#include "interactif.h"
#include "historique.h"

void choix_saver()
{
	int saver_aleatoire = 0;
	const int MAX=3, MIN=1;
	srand(time(NULL));
	saver_aleatoire = (rand()%(MAX-MIN+1)+MIN);
	
	if(saver_aleatoire == 1)
		statique();
	if(saver_aleatoire == 2)
		dynamique();
	if(saver_aleatoire == 3)
		interactif();
	else 
	{
		exit(EXIT_FAILURE);
	}
}

int main()
{
	//system ("clear");
	
	int choix;
	while (1)
	{
		printf("Bienvenue sur le launcher d'exiaSaver !\n");
		printf("Tapez 1 pour lancer le statique\n");
		printf("Tapez 2 pour lancer le dynamique\n");
		printf("Tapez 3 pour lancer l'interactif\n");
		printf("Tapez 4 pour lancer aleatoirement\n");
		printf("Tapez 5 pour lancer l'historique\n");
		printf("Que voulez vous faire ?\n");
		scanf("%d", &choix); 
	
		if(choix == 1)
			statique();
		else if(choix == 2)
			dynamique();
		else if(choix == 3)
			interactif();
		else if(choix == 4)
			choix_saver();
		else if(choix == 5)
			historique();
		else
		{
			exit(EXIT_FAILURE);
		}
		
	} 
	return 0;
	system ("clear");
}
# nwstmwaka
