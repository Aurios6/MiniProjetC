#include "strManipulation.h"


int charNbOfChar(const char *str, char target)
{     
      int size = 0;
      while(*str != '\0'){
            if(*str == target)
                  size ++;
            str++;
      }
      return size;
}

int charLenght(const char* str)
{
      int size = 0;
      while(*str != '\0'){
            size++;
            str++;
      }
      return size;
}

int* charLocationByIndice(const char *str, char target, int *size)
{
      *size = charNbOfChar(str, target);

      int* indiceArray = (int*) malloc(*size * sizeof(int));
      if(indiceArray == NULL){
            fprintf(stderr, "indiceArray memory allocation failed");
            exit(EXIT_FAILURE);
      }

      int index = 0;
      for(int i = 0; str[i] != '\0'; i++){
            if (str[i] == target){
                  indiceArray[index] = i;
                  index++;
            }
      }
      return indiceArray;
}


int strToInt(const char *str)
{
      int result = 0;

      while(*str != '\0'){
            if(*str < '0' || *str > '9'){
                  return -1;
            }
            result = result * 10 + (*str - '0');
            str++;
      }
      return result;
}
