#include "struktura.h"
#include <stdio.h>
#include <stdlib.h>
#include "../STEROWANIEPROGRAMEM/kosci.h"

void atak(postac_t ***a, postac_t *** o){
    printf("%s uzbrojony w %s atakuje %s.\n ", (**a)->nazwa, (**a)->bron->nazwa , (**o)->nazwa);
    printf("Obrońca %s chroni się %s nosi %s.\n ", (**o)->nazwa, (**o)->tarcza->nazwa , (**o)->pancerz->nazwa);

    (**a)->okrzyk(a);
    int rzut = k100();
    
    if(rzut <= (**a)->walka + (**a)->bron->premia -(**o)->tarcza->cecha ) {
        puts("Trafienie!");
        int obrazenia = (**a)->walka/10 + (**a)->bron->cecha + rand()%6 - (**o)->pancerz->cecha;
        (**o)->zywotnosc -= obrazenia;
        printf("Atak zadał %d obrażeń walczy %s, pozostało %d żywotności\n",
        obrazenia, (**a)->bron->nazwa ,(**o)->zywotnosc);
    }
    else{
        puts("Pudło.");
    }
    
    if((**o)->zywotnosc < 1) {
            puts("Poniżej 0");
            (**o)->czyZyje = false;
        }
}

void okrzykbojowy(postac_t const ***p){
    printf("[%s]: wrzeszczy \n", (**p)->nazwa );
}

void PodniesPrzedmiot(int * u, przedmiot_t ***plecak, przedmiot_t ** przed){
    int nowyudzwig = *u+1;


    przedmiot_t ** tmp = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*nowyudzwig);
    tmp[*u] =(przedmiot_t*)malloc(sizeof(przedmiot_t));
    tmp[*u] = *przed;


    ++(*u);
    printf("NOWY UDZWIG %d/%d" , nowyudzwig, *u);
}

void UzyjPrzedmiotNaSobie(postac_t ***p){

}

void UzyjPrzedmiotLokalizacja(postac_t ***p, lokalizacja_t **l){
    
}