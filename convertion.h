#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strManipulation.h"

void affTest();
int verifierFormat(const char *ipAdress);
int* cutIpV4Adress(const char *cutIpAdress, int *size);