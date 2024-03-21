#include "convertion.h"

void affTest(){
      printf("hello world\n");

}
/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/
void verifierFormat(char *ipAdress){
     
      while(*ipAdress != '\0'){
            //do the test of the format
            

            // Show the ipAdress caracter by caracter
            printf("%c\n",*ipAdress);
            ipAdress ++;
      }
}