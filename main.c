/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 2                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse adresse IP                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Vincent--Randonnier-Aurélien                                 *
*                                                                             *
*  Nom-prénom2 : Daunis Nathanael                                             *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include "conversion.h"
#include "auxiliaryFunction.h"


int main(int argc, char *argv[]){

      int aOuvert = 0;

      if(argc>1){
            char *fileName = argv[1];
            FILE *file = fopen(fileName, "r");
            if (file == NULL){
                  fprintf(stderr, "Erreur ouverture du fichier\n");
                  return 1;
            }
            char line[100];
            while(fgets(line,sizeof(line), file) != NULL){
                  char *newline_ptr = strchr(line, '\n');
                  if (newline_ptr != NULL) {
                        *newline_ptr = '\0';
                  }
                  printf("\n");
                  global(line,&aOuvert);
            }
            fclose(file);
      }else{
            char ipAdress;

            printf("Veuillez entrer une adress IP: ");
            scanf("%s", &ipAdress);
            global(&ipAdress, &aOuvert); 
      }

      return 0;
}