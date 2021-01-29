#include <stdio.h>


#include "../STRUKTURY/struktura.h"

#define KOMNATY 12
#define POTWORY 3

void UsunLokacje(lokalizacja_t ***l){
    for(int i = 0; i < KOMNATY; i++){
        free((*l)[i]);
        (*l)[i] =NULL;
    }
    free(*l);
    *l = NULL;    

}

void UsunPotwory(postac_t ***p){
    for(int i = 0; i < POTWORY; i++){
        free((*p)[i]);
        (*p)[i] =NULL;
    }
    free(*p);
    *p = NULL;     
}

void UsunPostac(postac_t **p){
    free((*p));
    *p = NULL;
}

void UsunPrzedmioty(przedmiot_t *** bron, przedmiot_t ***tarcze, przedmiot_t ***pancerze, przedmiot_t ***narzedzia, przedmiot_t ***jedzenie){
    int sztukbroni = 5, sztuktarcz = 3, sztukpancerza = 4, sztuknarzedzi = 3, sztukjedzenia = 3;

    for(int i = 0; i < sztukbroni; i++){
        free((*bron)[i]);
        (*bron)[i] =NULL;
    }
    free(*bron);
    *bron = NULL;

    for(int i = 0; i < sztuktarcz; i++){
        free((*tarcze)[i]);
        (*tarcze)[i] =NULL;
    }
    free(*tarcze);
    *tarcze = NULL;

    for(int i = 0; i < sztukpancerza; i++){
        free((*pancerze)[i]);
        (*pancerze)[i] =NULL;
    }
    free(*pancerze);
    *pancerze = NULL;   

    for(int i = 0; i < sztuknarzedzi; i++){
        free((*narzedzia)[i]);
        (*narzedzia)[i] =NULL;
    }
    free(*narzedzia);
    *narzedzia = NULL;   

    for(int i = 0; i < sztukjedzenia; i++){
        free((*jedzenie)[i]);
        (*jedzenie)[i] =NULL;
    }
    free(*jedzenie);
    *jedzenie = NULL;   

}