#include <stdio.h>
#include "convertion.h"

int main(){

      //affTest();
      const char* ipTest = "145.79.198.6/24";
      printf("%s\n",ipTest);
      verifierFormat(ipTest);

      return 0;
}