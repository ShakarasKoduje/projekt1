#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../STRUKTURY/struktura.h"
#include "kosci.h"
#include "sterowanie.h"
#include "../STRUKTURY/funkcjestruktur.h"

postac_t przyklad;
postac_t *wsk_przykl;
postac_t **wsk_przykl2;

void Walka(postac_t **p, postac_t **potw, przedmiot_t ***bron, przedmiot_t ***tarcze, przedmiot_t ***pancerze){

    for(int i = 0 ; i < 4; i++){
        printf("Pancerz: %s %s\n", (*pancerze)[i]->nazwa,  (*pancerze)[i]->opis);
    }


    przyklad = **potw;
    wsk_przykl = &przyklad;
    wsk_przykl2 = &wsk_przykl;

    (**wsk_przykl2).walka += k10();
    (**wsk_przykl2).zywotnosc += k10();
    (**wsk_przykl2).czyZyje = true;
    int los;
    los = rand()%5;
    (**wsk_przykl2).bron = (przedmiot_t*)malloc(sizeof(przedmiot_t));
    (**wsk_przykl2).bron = (*bron)[los];
    los = rand()%3;
    (**wsk_przykl2).tarcza = (przedmiot_t*)malloc(sizeof(przedmiot_t));
    (**wsk_przykl2).tarcza = (*tarcze)[los];
    los = rand()%4;
    (**wsk_przykl2).pancerz = (przedmiot_t*)malloc(sizeof(przedmiot_t));
    (**wsk_przykl2).pancerz = (*pancerze)[los];




    (*potw)->czyZyje = true;

    
    puts("================= ROZPOCZĘŁA SIĘ WALKA! ======================");
    while((*wsk_przykl2)->czyZyje && (*p)->czyZyje){
        //printf("\n\t zywotnosc: %d", (*wsk_przykl2)->zywotnosc);
        if((*p)->czyZyje) (*p)->atakuj(&p, &wsk_przykl2); //wywołanie funkcji przypisanej do struktury


        if((*wsk_przykl2)->czyZyje) (*wsk_przykl2)->atakuj(&wsk_przykl2, &p);
        //PrzejdzDalej();
    }

    if((*p)->czyZyje && !(*wsk_przykl2)->czyZyje){
        puts("Postać zwyciężyła starcie. Otrzyma punkt zwycięstwa.");
        (*p)->punktyzwyciestwa = (*p)->punktyzwyciestwa + (*wsk_przykl2)->punktyzwyciestwa;
        puts("Zwycięstwo w starciu poprawiło twoje zdolności bojowe");
        (*p)->walka = (*p)->walka + (*wsk_przykl2)->punktyzwyciestwa;
        printf("Aktualne punkty zwycięstwa postaci wynoszą %d\n", (*p)->punktyzwyciestwa);
        PrzejdzDalej();
    }


    puts("\n======================== KONIEC STARCIA =================");

}