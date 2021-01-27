#include "struktura.h"
#include <stdio.h>
#include <stdlib.h>
#include "../STEROWANIEPROGRAMEM/kosci.h"

void atak(postac_t ***a, postac_t *** o){
    printf("Postac %s atakuje postac %s ", (**a)->nazwa, (**o)->nazwa);
    (**a)->okrzyk(o);
    (**o)->zywotnosc -= k10();
    if((**o)->zywotnosc < 1) {
            puts("Poniżej 0");
            (**o)->czyZyje = false;
        }
}

void okrzykbojowy(postac_t const ***p){
    printf("Wrzeszczy %s\n", (**p)->nazwa );
}