#include "convertion.h"
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

      int indexIpTab = 0;
      while (strToken != NULL){
            /*
            strToken = ipAdressIntTab[indexIpTab];
            printf("%d\n",ipAdressIntTab[indexIpTab]);
            i++;
            */
            printf("%s\n",strToken);
            strToken = strtok(NULL,separator);
      }



      printf("Valid\n");
      return 1;
}


