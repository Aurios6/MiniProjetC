#include "convertion.h"
/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/
int verifierFormat(const char *ipAdress){



      int sizeIpIntArray;
     /*
     char* subStr = extractSubString(ipAdress, 0,2);
     printf("SubSTR est : %s\n", subStr);
     printf("En INT : %d\n", strToInt(subStr));
     */

     //Check if there is the correct number of . and /
      if (charNbOfChar(ipAdress, '.') != 3 || charNbOfChar(ipAdress, '/') != 1){
            printf("Return 0 nb char . /\n");
            return 0;
      }
      
      int* arrayIpCut = cutIpV4Adress(ipAdress, &sizeIpIntArray);
      for(int i = 0; i < sizeIpIntArray; i++){
            printf("%d ",arrayIpCut[i]);
      }
      printf("\n");

     return 1;
}


