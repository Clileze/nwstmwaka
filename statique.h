#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Vérifier si le fichier est ouvert correctement
 * Centrer image dans la console
**/

typedef struct Image
{
	int largeur;
	int hauteur;
	int* donnees;
	
}Image;  //creer objet correspondant à image
 
Image lire_fichier(char* nomFichier)
{
	Image image; //creer variable type image.
    FILE* fichier;
    int c;
    char* dimensions; //string 
    char ligne[10]; 
    int i = 0;
    
    fichier = fopen(nomFichier, "r+");
    fgets(ligne,30,fichier);
    
    if(strcmp(ligne,"P1")==0 || strcmp(ligne,"P3")==0)
    {
        printf("erreur fichier\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }
    
    fgets(ligne, 10, fichier);
    dimensions = strtok(ligne, " "); // dimension vaut premiere partie (coupe ligne en partie en enlevant espace)
	image.largeur = atoi(dimensions); //transforme en int
	dimensions = strtok(NULL, " "); // recupere deuxieme token
	image.hauteur = atoi(dimensions);
	image.donnees = (int*) malloc(sizeof(int)*image.largeur*image.hauteur); // pointeur initialiser avec largeur hauteur de n octets
	
    while((c = fgetc(fichier)) != EOF)  
    {
        if(c != ' ' && c != '\n' && c != '\r' && c != EOF) {
			image.donnees[i] = c-48; //recentre à partir de 0
			i++;
		}
    }
    fclose(fichier);
    return image; // renvoie objet image
}
 
void afficher_image(Image image)
{    
    int i;
    for(i = 0; i < image.hauteur*image.largeur; i++) {
		if(i%image.largeur == 0) // verifie si on arrive à la fin de largeur, on arrive au multiple largeur on revient ligne
			printf("\n");
		if(image.donnees[i] == 0)
			printf(" ");
		else if(image.donnees[i] == 1)
			printf("X");
	}
	printf("\n");
}

char* choix_aleatoire() //string tableau caractere 
{
	int img_aleatoire = 0;
	const int MAX=5, MIN=1;
	srand(time(NULL));
	img_aleatoire = (rand()%(MAX-MIN+1)+MIN);

	
	if(img_aleatoire == 1)
	{
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "crane : %s\n", asctime(info));
		fclose(fichierhistorique);
		return "crane.pbm";
		
	}
	if(img_aleatoire == 2)
	{
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "frog : %s\n", asctime(info));
		fclose(fichierhistorique);
		
		return "frog.pbm";
	}
	if(img_aleatoire == 3)
	{
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "mushroom : %s\n", asctime(info));
		fclose(fichierhistorique);
		return "mushroom.pbm";
	}
	if(img_aleatoire == 4)
	{
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "poulet : %s\n", asctime(info));
		fclose(fichierhistorique);
		return "POULETMALADE.pbm";
	}
	if(img_aleatoire == 5)
	{
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "exia : %s\n", asctime(info));
		fclose(fichierhistorique);
		return "exia.pbm";
	}
	else
	{
		printf("erreur fichier\n");
		
		FILE* fichierhistorique = NULL;
		fichierhistorique = fopen("fichierhistorique.c", "a+");
		time_t heure;
		struct tm* info;
		time(&heure);
		info=localtime(&heure);
		fprintf(fichierhistorique, "crane : %s\n", asctime(info));
		fclose(fichierhistorique);
		return "crane.pbm";
	}

}

/*void centrerImage()
{
	Image image;
	
	//determiner l'endroit a partir de laquelle il faut mettre l'image a centrer
	
	image.largeur = (80-image.largeur) / 2;
	image.hauteur = (24-image.hauteur) / 2;
	
}*/

void inscription_histo()
{
	FILE* fichierhistorique = NULL;
	fichierhistorique = fopen("fichierhistorique.c", "a+");
	time_t heure;
	
	struct tm* info;
	time(&heure);
	info=localtime(&heure);
	
	fprintf(fichierhistorique, "saver statique : %s\n", asctime(info));
	fclose(fichierhistorique);
}
 
void statique()
{
	Image image;
	char* nomFichier = choix_aleatoire();
	inscription_histo();
	image = lire_fichier(nomFichier);
	//centrerImage();
    afficher_image(image);
}
