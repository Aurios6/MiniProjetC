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

      /*
            ceck mask value
      */

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

int checkClass(int *firstOctet, int *secondOctet)
{
    for (int i = 0; i < 8; i++) {
        if (firstOctet[i] >= 0 && firstOctet[i] <= 127 && firstOctet[i] == 10) {
            printf("Class A, private\n");
        }
        else if (firstOctet[i] >= 0 && firstOctet[i] <= 127 && firstOctet[i] != 10) {
            printf("Class A, public\n");
        }
        else if (firstOctet[i] == 172 && secondOctet[i] >= 16 && secondOctet[i] <=31) {
            printf("Class B, private\n");
        }
        else if (firstOctet[i] >= 128 && firstOctet[i] <= 191) {
            printf("Class B, public\n");
        }else if (firstOctet[i] >= 192 && secondOctet[i] ==168) {
            printf("Class C, private\n");
        }
        else if (firstOctet[i] >= 192 && firstOctet[i] <= 223) {
            printf("Class C, public\n");
        } else if (firstOctet[i] >= 224 && firstOctet[i] <= 239) {
            printf("Class D, multicast\n");
        } else if (firstOctet[i] >= 240 && firstOctet[i] <= 255) {
            printf("Class E, experimental\n");
        }
    }


    return 0;
}


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