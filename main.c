#include <stdio.h>
#include "convertion.h"

int main(){

      //affTest();
      const char* ipTest = "145.79.198.6/24";
      const char* ipTest2 = "175.79.198.675/24";
      const char* ipTest3 = "145.79.1z8.6/24";
      const char* ipTest4 = ".../";

      printf("%s\n",ipTest);
      verifierFormat(ipTest);
      verifierFormat(ipTest2);
      verifierFormat(ipTest3);
      verifierFormat(ipTest4);
      
      return 0;
}