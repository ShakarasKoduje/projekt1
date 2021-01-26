#include<stdio.h>
#include<stdlib.h>

#include "../STRUKTURY/struktura.h"

void Walka(postac_t **p, postac_t ***potw){
    puts("WALKA WALKA WALKA WALKA WALKA");
    printf("\tWalkę podejmuje %s\n z %s\n", (*p)->nazwa, (**potw[0]).nazwa);
    (*p)->zywotnosc -= 5;
    puts("WALKA WALKA WALKA WALKA WALKA");
}