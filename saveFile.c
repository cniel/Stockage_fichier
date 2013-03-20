/*
Programme qui stocke le contenu d'fichier dans une variable (ici tab).
   ' '    qui reçoit un paramètre : le nom du fichier (avec le chemin).
En l'essayant sur des fichiers qui commencent à être volumineux, il plante. 
Par exemple, avec knownGene.txt, ça marche si on ne garde que les 558 premières lignes, mais au dessus, ça plante.
Ça à l'air d'être parce que j'atteins un nombre de caractères seuil.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100000

int main(int argc,char* argv[]) {
	
	char** tab=(char**)malloc((100000)*sizeof(char*));  //Contiendra l'ensemble des lignes.
	char ** temp=tab;
	char* parcours=(char*)malloc((TAILLE_MAX)*sizeof(char)); //Contiendra le contenu d'une ligne à la fois.
	int j=0;
  	FILE * fichier=fopen(argv[1],"r");
  	
  	if(argc!=2){
  		printf("Nombre d'arguments incorrect.\n");
  		exit(1);
  	}
  	
  	if(fichier==NULL) {
  		printf("Erreur lors du chargement du fichier.\n");
  		exit(2);
  	}

  	while(fgets(parcours,TAILLE_MAX,fichier) != NULL) {
      	temp[j]=(char*)malloc((strlen(parcours))*sizeof(char));
      	strcpy(temp[j],parcours);
      	j++;
   	}
  	
  	/*Affichage du contenu du fichier:
  	int tailleTab=0;
  	tailleTab=j;
  	printf("%d",tailleTab);
  	j=0;
 		
 	while(j<tailleTab) {
   		printf("%s",tab[j]);
		j++;
  	}
  	*/
  	printf("chargement effectué.\n");
  	free(tab);
  	free(parcours);
	fclose(fichier);
	
	return 0;
}
