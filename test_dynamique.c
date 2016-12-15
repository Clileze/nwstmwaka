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
    Image heure1;
    Image heure2;
    Image minute1;
    Image minute2;
    Image seconde1;
    Image seconde2;
   
    int i, j, k, l, m, n;
    char* nomFichier = choix_aleatoire();
    inscription_histo();
    image = lire_fichier(nomFichier);
    //centrerImage();
    //afficher_image(image);
    heure1 = lire_fichier("2.pbm");
    heure2 = lire_fichier("1.pbm");
    minute1 = lire_fichier("3.pbm");
    minute2 = lire_fichier("0.pbm");
    seconde1 = lire_fichier("4.pbm");
    seconde2 = lire_fichier("5.pbm");
   
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;
    
    
    while(i < heure1.hauteur*heure1.largeur) {
        if(i%heure1.largeur == 0) {
            while(j < heure2.hauteur*heure2.largeur) {
                if(j%heure2.largeur == 0) {
                    while(k < minute1.hauteur*minute1.largeur) {
                        if(k%minute1.largeur == 0) {
                            while(l < minute2.hauteur*minute2.largeur) {
                                if(l%minute2.largeur == 0) {
                                    while(m < seconde1.hauteur*seconde1.largeur) {
                                        if(m%seconde1.largeur == 0) {
                                            while(n <seconde2.hauteur*seconde2.largeur) {
                                                if(n%seconde2.largeur == 0) {
                                                    printf("\n");
                                                    n++
                                                    break;
                                                }
                                                if(seconde2.donnees[n] == 0)
                                                    printf(" ");
                                                else if(seconde2.donnees[n] == 1)
                                                    printf ("X");
                                                n++
                                                }
                                            m++
                                            break; //sortir boucle
                                        }
                                        if(seconde1.donnees[m] == 0)
                                            printf(" ");
                                        else if(seconde1.donnees[m] == 1)
                                            printf("X");
                                        m++
                                    }
                                    l++;
                                    break;
                                }
                                if(minute2.donnees[l] == 0)
                                    printf(" ");
                                else if(minute2.donnees[l] == 1)
                                    printf("X");
                                l++;
                            }
                            k++;
                            break;                           
                        }
                        if(minute1.donnees[k] == 0)
                            printf(" ");
                        else if(minute1.donnees[k] == 1)
                            printf("X");
                        k++;
                    }
                    j++;
                    break;
                }
                if(heure2.donnees[j] == 0)
                    printf(" ");
                else if(heure2.donnees[j] == 1)
                    printf("X");
                j++;
            }
        }
        else {
            if(heure1.donnees[i] == 0)
                printf(" ");
            else if(heure1.donnees[i] == 1)
                printf("X");
        }
        i++;
    }
}

    /*time(&temps);
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
    printf("seconde : %d", seconde);*/
