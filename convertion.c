#include "convertion.h"
/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/

int verifierFormat(char *ipAdress){

      int sizeIpIntArray;

     //Check if there is the correct number of . and /
      if (nbOfChar(ipAdress, '.') != 3 || nbOfChar(ipAdress, '/') != 1){
            printf("Return 0 nb char . /\n");
            return 0;
      }
      printf("Valid\n");
      return 1;
}


