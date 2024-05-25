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
*  Nom du fichier : conversion.h                                              *
*                                                                             *
******************************************************************************/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auxiliaryFunction.h"

void affTest();
int verifierFormat(char *ipAdress);
char* scopeExtract(char *ipAdress, char **returnArray);
void convertToInt(char **ipAdressArrayString, char *maskString, int* ipAdressArrayInt, int *maskInt );
void global(char *ipAdress);
int nbOfChar (char *str, char target);