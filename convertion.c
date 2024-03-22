#include "convertion.h"
/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/
int verifierFormat(const char *ipAdress){


      int sizeIpAdress = charLenght(ipAdress);
     
      int sizeIndexArrayDot;
      int *indexArrayDot = charLocationByIndice(ipAdress, '.', &sizeIndexArrayDot);
      int lowerBound = 0;
      int upperBound = indexArrayDot[0];

      int *indexArraySlash = charLocationByIndice(ipAdress, '/', &sizeIndexArrayDot);
      
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
      
      for(int i = 0; i < sizeIndexArrayDot; i++){
            char*subStr = extractSubString(ipAdress, lowerBound, upperBound);
            int bitIP = strToInt(subStr);
            printf("Str to INT %d\n", bitIP);
            if (bitIP < 0 || bitIP > 255){
                  printf("Return 0 first\n");
                  return 0;
            }
            lowerBound = upperBound;
            upperBound =  indexArrayDot[i];
      }
      char* subStr2 = extractSubString(ipAdress,indexArrayDot[sizeIndexArrayDot], *indexArraySlash);
      if (strToInt(subStr2) < 0 || strToInt(subStr2) < 255){
            printf("Return 0 mid\n");
            return 0;
      }

      char* subStr3 = extractSubString(ipAdress, *indexArraySlash, sizeIpAdress);
      if (strToInt(subStr3) < 0 || strToInt(subStr3) < 255){
            printf("Return 0 last\n");
            return 0;
      }

      printf("Return 1\n");
      return 1;
}