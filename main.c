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
      
      //Valeur de retour
      char **returnArrayString;
      char *returnMask;

     global(ipTest);
     global(ipTest2);
     global(ipTest3);
     global(ipTest4);

      //décode IP
      int tabAPriv[4] = {10,0,0,1};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabAPriv));

      int tabAPub[4] = {11, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabAPub));

      int tabBPriv[4] = {172,16,0,0};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabBPriv));

      int tabBPub[4] = {172, 13, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabBPub));

      int tabCPriv[4] = {192,168,0,0};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabCPriv));

      int tabCPub[4] = {192, 167, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabCPub));

      int tabD[4] = {225, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabD));

      int tabE[4] = {255, 127, 21, 255};
      printf("%d.%d.%d.%d: %s\n", tabAPriv[0], tabAPriv[1], tabAPriv[2], tabAPriv[3], decoderIP(tabE));

      return 0;
}