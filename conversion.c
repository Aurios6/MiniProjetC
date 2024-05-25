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
*  Nom du fichier : conversion.c                                              *
*                                                                             *
******************************************************************************/

#include "conversion.h"

/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/


int verifierFormat(char *ipAdress){

      int ipAdressIntTab [10];

      if (nbOfChar(ipAdress, '.') != 3 || nbOfChar(ipAdress, '/') != 1){
            printf("Return 0 nb char . /\n\n");
            return 0;
      }

      /*
            Check if  non numerical value in string
      */

      for(int i=0; ipAdress[i] != '\0'; i++){
            if(!isdigit(ipAdress[i]) && ipAdress[i] != '.' && ipAdress[i] != '/'){
                  printf("NOT A DIGIT\n\n");
                  return 1;
            }      
      }

      /*
            Change string to int
      */

      int ipAdressLen = strlen(ipAdress);
      char ipAdressArray[ipAdressLen + 1];
      strcpy(ipAdressArray, ipAdress);

      char *separator = "./";
      char *strToken = strtok(ipAdressArray,separator);

      int indexIpTab = 0;
      while (strToken != NULL){
            ipAdressIntTab[indexIpTab] = atoi(strToken);
            printf("%d.", ipAdressIntTab[indexIpTab]);
            indexIpTab++;
            strToken = strtok(NULL,separator);
      }
      printf("\n");

      /*
            Check size
      */

      if(indexIpTab!=5){
            printf("INVALID IP ADRESS size\n\n");
            return 0;
      }

      /*
            Chack value
      */
      
      for(int i = 0; i<indexIpTab;i++){
            if(ipAdressIntTab[i]<0 || ipAdressIntTab[i] > 255){
                  printf("INVALID IP ADRESS value\n\n");
                  return 1;
            }
      }

      if(ipAdressIntTab[4] < 0 || ipAdressIntTab[4] > 32){
            printf("INVALID IP ADRESS mask\n\n");
            return 1;
      }

      printf("Valid Ip adress\n\n");          

      return 0;
}

/*
      Check the class
*/

char *checkClass(int *tab) {

        if (tab[0] >= 0 && tab[0] <= 127 && tab[0] == 10) {
            return "Classe A, privée";
        }
        else if (tab[0] >= 0 && tab[0] <= 127 && tab[0] != 10) {
            return "Class A, publique";
        }
        else if (tab[0] == 172 && tab[1] >= 16 && tab[1] <=31) {
            return "Class B, privée";
        }
        else if (tab[0] >= 128 && tab[0] <= 191) {
            return "Class B, publique";
        }else if (tab[0] >= 192 && tab[1] ==168) {
            return "Class C, privée";
        }
        else if (tab[0] >= 192 && tab[0] <= 223) {
            return "Class C, publique";
        } 
        else if (tab[0] >= 224 && tab[0] <= 239) {
            return "Class D, adresse multicast";
        } 
        else if (tab[0] >= 240 && tab[0] <= 255) {
            return "Class E, adresse experimentale";
      }

        return "Classe invalide";
    }


/*
      int ipAdressLen = strlen(ipAdress);
      char ipAdressArray[ipAdressLen + 1];
      strcpy(ipAdressArray, ipAdress);

      char *separator = "./";
      char *strToken = strtok(ipAdressArray,separator);

      int indexReturnArray = 0;

      printf("THE IP ADRESS --> ");
      while (strToken){
            printf("%s ", strToken);
            strncpy(returnArray[indexReturnArray],strToken,10);
            printf("CP2\n");
            strToken = strtok(NULL,separator);
            indexReturnArray++;
      }

      
      printf("\n");

      return ;
      
}
*/