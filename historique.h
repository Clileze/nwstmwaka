#include <stdlib.h>
#include <stdio.h>

void historique	()
{
	
	FILE* fichierhistorique = NULL;
	char c[1000] = "";
	
	fichierhistorique = fopen("fichierhistorique.c", "a+");
	
	if(fichierhistorique != NULL)
	{
		while(fgets(c,1000,fichierhistorique) != NULL)  
		{
			printf("%s\n", c);
		}
	}
 	
	close(fichierhistorique);
	
}
