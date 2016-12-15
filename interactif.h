#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void inscription_histo_interactif()
{
	FILE* fichierhistorique = NULL;
	fichierhistorique = fopen("fichierhistorique.c", "a+");
	time_t heure;
	
	struct tm* info;
	time(&heure);
	info=localtime(&heure);
	
	fprintf(fichierhistorique, "saver interactif : %s\n", asctime(info));
	fclose(fichierhistorique);
}

void interactif()
{
	inscription_histo_interactif();
	printf("\n");
	printf("Désolé! On n'a pas eu le temps!\n");
	printf(" \n");
}

