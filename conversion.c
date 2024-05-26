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
            fprintf(stderr, "ERREURE : ");
            fprintf(stderr,"Pas suffisament de \". /\"\n");
            return 1;
      }

      /*
            Verifie la valeur numerique des chaines de caractères
      */

      for(int i=0; ipAdress[i] != '\0'; i++){
            if(!isdigit(ipAdress[i]) && ipAdress[i] != '.' && ipAdress[i] != '/'){
                  fprintf(stderr, "ERREURE : ");
                  fprintf(stderr,"Contient une valeur non numerique\n");
                  return 1;
            }      
      }

      /*
            Change string en int
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
            Verifie la taille
      */

      if(indexIpTab!=5){
            fprintf(stderr, "ERREURE : ");
            fprintf(stderr,"Taille de l'adresse IP invalide\n");
            return 1;
      }


      /*
            Verifie que la valeur de l'IP est correcte
      */
      
      for(int i = 0; i<indexIpTab;i++){
            if(ipAdressIntTab[i]<0 || ipAdressIntTab[i] > 255){
                  fprintf(stderr, "ERREURE : ");
                  fprintf(stderr,"Valeur de l'adresse IP invalide\n");
                  return 1;
            }
      }

      /*
            Verifie que la valeur du masque est correcte
      */

      if(ipAdressIntTab[4] <= 0 || ipAdressIntTab[4] >= 32){
            fprintf(stderr, "ERREURE : ");
            fprintf(stderr,"Masque de l'adresse IP invalide\n");
            return 1;
      }

      return 0;
}

char* extractionDesChamps(char *ipAdress,char **returnArray){
      char *start = ipAdress;
      char *end;

      /*
            Retourne un tableau de string depuis le pointeur pris en paramètre
      */


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

      /*
            Retourne le masque
      */

      return start;
}

void convertToInt(char **ipAdressArrayString, char *maskString, int* ipAdressArrayInt, int *maskInt ){
      for(int i=0; i<4;i++){
            ipAdressArrayInt[i] = atoi(ipAdressArrayString[i]);
      }
      *maskInt = atoi(maskString);
}


char *decoderIP(int *tab) {
        if (tab[0] >= 0 && tab[0] <= 127 && tab[0] == 10) {
            return "Class A et est prive";
        }
        else if (tab[0] >= 0 && tab[0] <= 127 && tab[0] != 10) {
            return "Class A et est public";
        }
        else if (tab[0] == 172 && tab[1] >= 16 && tab[1] <=31) {
            return "Class B et est prive";
        }
        else if (tab[0] >= 128 && tab[0] <= 191) {
            return "Class B et est public";
        }else if (tab[0] >= 192 && tab[1] ==168) {
            return "Class C et est prive";
        }
        else if (tab[0] >= 192 && tab[0] <= 223) {
            return "Class C et est public";
        } else if (tab[0] >= 224 && tab[0] <= 239) {
            return "Class D et est multicast";
        } else if (tab[0] >= 240 && tab[0] <= 255) {
            return "Class E et est experimental";
      }

        return " invalide";
}


void decoderMasqueIP(int *arrayIp, int masque, FILE *nomFichier){

      unsigned long long ipAdressFull = 0;
      unsigned long long masqueComplet = 0;

      /*
            Conversion de l'adresse IP en entier pour ensuite utiliser les oppérateurs sur les bits
      */

     
      for(int j = 0; j < 4; j++){
            ipAdressFull |= (unsigned int)(arrayIp[j]);
            if(j!=3){
                  ipAdressFull = ipAdressFull << 8;
            }
      }
     
     /*
      convertis le masque en long long pour ensuite utiliser les oppérateurs sur les bits
     */

    // 

      
      int puissance = 32 - masque;
      unsigned long long val = 1;
      for(int k = 0; k<puissance;k++){
            val *= 2;
      }
      
      masqueComplet = 4294967296 - val;

      unsigned long long adresseReseaux = ipAdressFull & masqueComplet;
      unsigned long long adresseHote = ipAdressFull & ~masqueComplet;

      fprintf(nomFichier,"L'adresse réseaux est : ");
      afficherAdresseIpDepuisLLU(adresseReseaux, nomFichier);
      fprintf(nomFichier,"L'adresse réseaux est : ");
      afficherAdresseIpDepuisLLU(adresseHote, nomFichier);

      return;
}


void global(char *ipAdress, int *aOuvert){

      /*
            Verifie si le fichier a déja été ouvert depuis la première exécution du programme
            pour eviter d'écraser le contenu du fichier
      */

      char *modeOuverture;
      if(*aOuvert == 0){
            modeOuverture = "w";
            *aOuvert = 1;
      }else{
            modeOuverture = "a";
      }

      FILE *fichierSortie = fopen("fichierDeSortie.txt", modeOuverture);
      if(fichierSortie == NULL){
            fprintf(stderr, "Le fichier n'a pas pu etre créé ni ouvert");
            return;
      }

      /*
            Interprète le résultat des différentes fonctions
      */

      char* champsExtraitString[4];
      char *mask;
      int ipAdressArrayInt[4];
      int maskInt;
      
      if (verifierFormat(ipAdress) == 1){
            return;
      }else{
            mask = extractionDesChamps(ipAdress,champsExtraitString);
            convertToInt(champsExtraitString,mask,ipAdressArrayInt,&maskInt);
            //affichage

            fprintf(fichierSortie, "L'adresse IP : %d.%d.%d.%d:%d \n", ipAdressArrayInt[0], ipAdressArrayInt[1],
            ipAdressArrayInt[2], ipAdressArrayInt[3], maskInt);
            fprintf(fichierSortie, "Est de type %s \n",decoderIP(ipAdressArrayInt));
            decoderMasqueIP(ipAdressArrayInt,maskInt, fichierSortie);
            
            fprintf(fichierSortie,"\n");
            fclose(fichierSortie);

            // champsExtraitString n'a plus d'utilité il faut donc libérer le mémoire
            for(int indexExScope = 0 ; indexExScope < 4 ; indexExScope++){
                  free(champsExtraitString[indexExScope]);
            }
      }
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

int entierVersBin(unsigned long long entier){

      unsigned long long a[128];
      int i; 
      for(i=0;entier>0;i++)    
      {    
            a[i]=entier%2;    
            entier=entier/2;
      }    

      for(i=i-1;i>=0;i--)    
      {    
            printf("%d",a[i]);    
      }
      return 0;  
}


void afficherAdresseIpDepuisLLU(unsigned long long adresse, FILE *nomFichier){
      char adresseIPString[33];
      int compteur = 0;

      for(int i = 31; i >= 0; i--){
            fprintf(nomFichier, "%d",(adresse >> i) & 1);
            compteur ++;

            //Le i != 1 permet d'eviter d'ecrire un point à la fin de l'adresse IP
            if(compteur == 8 && i != 0){
                  fprintf(nomFichier,".");
                  compteur = 0;
            }
      }
      adresseIPString[33] = '\0';
      fprintf(nomFichier,"\n");
}


