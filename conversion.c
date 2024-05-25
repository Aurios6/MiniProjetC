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
*  Nom du fichier : conversion.c                                              *
*                                                                             *
******************************************************************************/
#include "conversion.h"

int verifierFormat(char *ipAdress){

      int ipAdressIntTab[10];

      if (nbOfChar(ipAdress, '.') != 3 || nbOfChar(ipAdress, '/') != 1){
            fprintf(stderr,"Return 0 nb char . /\n");
            return 0;
      }

      /*
            Check if  non numerical value in string
      */

      for(int i=0; ipAdress[i] != '\0'; i++){
            if(!isdigit(ipAdress[i]) && ipAdress[i] != '.' && ipAdress[i] != '/'){
                  fprintf(stderr,"NOT A DIGIT\n");
                  return 0;
            }      
      }

      /*
            Change string to int
      */

      int ipAdressLen = strlen(ipAdress);
      char ipAdressArray[ipAdressLen + 1];
      strcpy(ipAdressArray, ipAdress);

      char *separator = "./";
      char *strToken = strtok(ipAdressArray,separator);

      int indexIpTab = 0;
      while (strToken != NULL){
            ipAdressIntTab[indexIpTab] = atoi(strToken);
            indexIpTab++;
            strToken = strtok(NULL,separator);
      }

      /*
            Check size
      */

      if(indexIpTab!=5){
            fprintf(stderr,"INVALID IP ADRESS size\n");
            return 0;
      }

      /*
            Chack value
      */
      
      for(int i = 0; i<indexIpTab;i++){
            if(ipAdressIntTab[i]<0 || ipAdressIntTab[i] > 255){
                  fprintf(stderr,"INVALID IP ADRESS value\n");
                  return 0;
            }
      }

      /*
            check mask value
      */

      if(ipAdressIntTab[4] < 0 || ipAdressIntTab[4] > 32){
            fprintf(stderr,"INVALID IP ADRESS mask\n");
            return 0;
      }

      return 1;
}

char* scopeExtract(char *ipAdress,char **returnArray){
      char *start = ipAdress;
      char *end;

      int i = 0;
      while ((end = strchr(start, '.')) || (end = strchr(start, '/'))) {
            size_t size = end - start;
            returnArray[i] = malloc(sizeof(char) * size);
            if(!returnArray[i])
                  fprintf(stderr,"Erreur lors de l'allocation memoire pour de la partie %d de l'addresse IP.\n", i);
            if(!memcpy(returnArray[i], start, size))
                  fprintf(stderr,"Erreur lors de la copie du contenu de l'addresse IP a l'octet %d.\n", i);
            returnArray[i++][size] = '\0';
            
            

            start = end + 1;
      }
      //Return the mask
      return start;
}

void convertToInt(char **ipAdressArrayString, char *maskString, int* ipAdressArrayInt, int *maskInt ){
      for(int i=0; i<4;i++){
            ipAdressArrayInt[i] = atoi(ipAdressArrayString[i]);
      }
      *maskInt = atoi(maskString);
}


void global(char *ipAdress){
      printf("AdressIP : %s\n", ipAdress);

      char* extractedScope[4];
      char *mask;
      int ipAdressArrayInt[4];
      int maskInt;
      
      if (verifierFormat(ipAdress) == 0){
            printf("ERREUR\n");
      }else{
            mask = scopeExtract(ipAdress,extractedScope);
            convertToInt(extractedScope,mask,ipAdressArrayInt,&maskInt);


            //affichage
            for(int i=0;i<4;i++ ){
                  printf("%d ",ipAdressArrayInt[i]);
            }
            printf("/");
            printf("%d\n",maskInt);
      }
      printf("\n");
}


int nbOfChar (char *str, char target){
    
    int res = 0;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == target){
            res += 1;
        }
    }
    return res;
}