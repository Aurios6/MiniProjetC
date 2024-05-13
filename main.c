#include <stdio.h>
#include "conversion.h"
#include "auxiliaryFunction.h"

int main(){

      //affTest();
      char* ipTest = "145.79.198.6/24";
      char* ipTest2 = "175.79.198.675/24";
      char* ipTest3 = "145.79.1z8.6/24";
      char* ipTest4 = ".../";

      printf("%s\n",ipTest);
      verifierFormat(ipTest);
      verifierFormat(ipTest2);
      verifierFormat(ipTest3);
      verifierFormat(ipTest4);
      
      return 0;
}