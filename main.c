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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include "conversion.h"
#include "auxiliaryFunction.h"

int main(){

      //affTest();
      char* ipTest = "145.79.198.6/24";
      char* ipTest2 = "175.79.198.675/24";
      char* ipTest3 = "145.79.18.6/24";
      char* ipTest4 = ".../";

      printf("\nTest1\n");
      verifierFormat(ipTest);
      printf("\nTest2\n");
      verifierFormat(ipTest2);
      printf("\nTest3\n");
      verifierFormat(ipTest3);
      printf("\nTest4\n");
      verifierFormat(ipTest4);

      char extractedScope[5][10];

      if (verifierFormat(ipTest) == 0){
            scopeExtract(ipTest,extractedScope);
      }

      printf("Part 2\n");
      for(int i=0;i<5;i++ ){
            printf("%s ",extractedScope[i]);
      }
      
      return 0;
}