#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void inscription_histo_dynamique()
{
	FILE* fichierhistorique = NULL;
	fichierhistorique = fopen("fichierhistorique.c", "a+");
	time_t heure;
	
	struct tm* info;
	time(&heure);
	info=localtime(&heure);
	
	fprintf(fichierhistorique, "saver dynamique : %s\n", asctime(info));
	fclose(fichierhistorique);
}

void dynamique()
{
	/*time_t heure;
    struct tm* timeinfo;
    time(&heure);
    timeinfo=localtime(&heure);
    printf("date et heure : %s", asctime (timeinfo));*/
    
    int heure;
    int minute;
    int seconde;
    char* hhmmss;
    char hms[128];
	time_t temps;
	struct tm date;
	
	inscription_histo_dynamique();
	
    time(&temps);
	date=*localtime(&temps);

    strftime(hms, 128, "%X", &date);
	puts(hms);
	
	hhmmss = strtok(hms, ":"); 
	heure = atoi(hhmmss);
	
	printf("heure : %d", heure);
	hhmmss = strtok(NULL, ":");
	minute = atoi(hhmmss);
	printf("minute : %d", minute);
	hhmmss = strtok(NULL, ":");
	seconde = atoi(hhmmss);
	printf("seconde : %d", seconde);
	
	
}
