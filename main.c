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
      /*
      char* ipTest2 = "175.79.198.675/24";
      char* ipTest3 = "145.79.18.6/24";
      char* ipTest4 = ".../";
      */
      
      //Valeur de retour
      char **returnArrayString;
      char *returnMask;
      printf("WTF");

      if(verifierFormat(ipTest) == 0){
            printf("ERREUR");
      }else{            
            scopeExtract(ipTest,returnArrayString,returnMask);

            //Affichage des string de scopeExtract TEMPORAIRE
            for(int i = 0;i<4;i++){
                  printf("%s ",returnArrayString[i]);
            }
            printf("/");
            printf("%s\n",returnMask);
      }
      
      return 0;
}