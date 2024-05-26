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


int main(int argc, char *argv[]){

      if(argc>1){
            char *fileName = argv[1];
            FILE *file = fopen(fileName, "r");
            if (file == NULL){
                  fprintf(stderr, "Erreur ouverture du fichier\n");
                  return 1;
            }
            
            //Lis le fichier en entrer
            char line[100];
            while(fgets(line,sizeof(line), file) != NULL){
                  char *newline_ptr = strchr(line, '\n');
                  if (newline_ptr != NULL) {
                        *newline_ptr = '\0';
                  }
                  global(line);
            }
            fclose(file);
      }else{
            char ipAdress;

            printf("Veuillez entrer une adress IP: ");
            scanf("%s", &ipAdress);
            global(&ipAdress); 
      }

      //décode IP
      int tabAPriv[4] = {10,0,0,1};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabAPriv));

      int tabAPub[4] = {11, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabAPub));

      int tabBPriv[4] = {172,16,0,0};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabBPriv));

      int tabBPub[4] = {172, 13, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabBPub));

      int tabCPriv[4] = {192,168,0,0};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabCPriv));

      int tabCPub[4] = {192, 167, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabCPub));

      int tabD[4] = {225, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabD));

      int tabE[4] = {255, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabE));

      return 0;
}