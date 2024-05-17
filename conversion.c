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
            printf("Return 0 nb char . /\n");
            return 0;
      }

      int ipAdressLen = strlen(ipAdress);
      char ipAdressArray[ipAdressLen + 1];
      strcpy(ipAdressArray, ipAdress);

      char *separator = "./";
      char *strToken = strtok(ipAdressArray,separator);

      /*
            Check if  non numerical value in string
      */

      for(int i=0; ipAdress[i] != '\0'; i++){
            if(!isdigit(ipAdress[i]) && ipAdress[i] != '.' && ipAdress[i] != '/'){
                  printf("NOT A DIGIT\n");
                  return 1;
            }      
      }

      /*
            Change string to int
      */

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
            printf("INVALID IP ADRESS size\n");
            return 0;
      }

      /*
            Chack value
      */
      
      for(int i = 0; i<indexIpTab;i++){
            if(ipAdressIntTab[i]<0 || ipAdressIntTab[i] > 255){
                  printf("INVALID IP ADRESS value\n");
                  return 1;
            }
      }

      /*
            ceck mask value
      */

      if(ipAdressIntTab[4] < 0 || ipAdressIntTab[4] > 32){
            printf("INVALID IP ADRESS mask\n");
            return 1;
      }

      printf("Valid Ip adress\n");
      return 0;
}


