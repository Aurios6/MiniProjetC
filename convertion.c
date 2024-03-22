#include "convertion.h"

void affTest(){
      printf("hello world\n");

}
/*
      verifier format prend en paramètre un pointeur vers Char
      Scan the char *ipAdress and stop when the pointer point to the caracter that close a chain
      Move across the chain wihe ipAdress++
*/
int verifierFormat(const char *ipAdress){
     
     //Check if there is the correct number of . and /
      if (charNbOfChar(ipAdress, '.') != 3 || charNbOfChar(ipAdress, '/') != 1){
            return 0;
      }
      
      const char *testStrToInt = "76674585";
      printf("STR \"%s\" to INT = %d\n",testStrToInt, strToInt(testStrToInt));

      while(*ipAdress != '\0'){
            //do the test of the format
            

            // Show the ipAdress caracter by caracter
            printf("%c",*ipAdress);
            ipAdress ++;
      }
      printf("\n");


      return 1;
}