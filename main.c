#include <stdio.h>
#include <stdlib.h>
#include "petlagry.h"

int main(){
    char *name = malloc(sizeof(char*)); // zmienna string dla imienia postaci
    postac_t p = TworzeniePostaci(name); //tworzenie postaci
    TwoPost();
    PetlaGry(&p); //petla gry zgarnia adres utworzonej postaci

    free(name); //uwalniamy pamiec

    
    return 0;
}