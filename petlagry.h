
#include <stdio.h>
#include <stdlib.h>
#include "struktura.h" // sa w petlagry.c i tak lepiej to dzial
#include "funkcje.h" // inaczej jest blad, konflikt pomiedzy plikami
#include "petlagry.c"

//moze tutaj sprobowac zadeklarowac postac_t bohater; a Tworzenie postaci zrobic void?


void TwoPost(); //Tworzy postac do gry poprzez void
void PetlaGry(postac_t*);
postac_t TworzeniePostaci(char*);
