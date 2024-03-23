#include "strManipulation.h"

int charLenght(const char* str)
{
      int size = 0;
      while(*str != '\0'){
            size++;
            str++;
      }
      return size;
}

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



// TODO: make work if str est vide. pb result =0 start

int strToInt(const char *str)
{
      int result = 0;

      while(*str != '\0'){
            if((*str < '0' || *str > '9')){
                  return -1;
            }
            result = result * 10 + (*str - '0');
            str++;
      }
      return result;
}

char* extractSubString(const char *str, int start, int end){
      int size = end - start + 1;
      char *subStr = (char*) malloc(size * sizeof(char));

      if (subStr == NULL){
            fprintf(stderr, "subStr memory allocation failed");
            exit(EXIT_FAILURE);
      }

      for(int i = 0; i < size; i++){
            subStr[i] = str[start+i];
      }
      subStr[size] = '\0';
      return subStr;
}
