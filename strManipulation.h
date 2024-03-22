#pragma once
#include <stdio.h>
#include <stdlib.h>

int* charLocationByIndice(const char *str, char target, int *size);
int charNbOfChar(const char *str, char target);
int charLenght(const char* str);
int strToInt(const char *str);
char* extractSubString(const char *str, int start, int end);