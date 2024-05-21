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

      int tab[8] = {10,11,172,173,192,192,228,255};
      int tab2[8] = {0,127,21,255,168,169,123,112};
      checkClass(tab, tab2);
      return 0;
}