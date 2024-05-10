#include <string.h>
#include "auxiliaryFunction.h"

int nbOfChar (char *str, char target){
    
    int res = 0;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == target){
            res += 1;
        }
    }
    return res;
}

