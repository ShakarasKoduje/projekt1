
#include "struktura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS_PRZEDMIOTOW 10;

/*------------------------
zmienne globalne dla lokalizacja_t 
i wskaznikow do nich
-------------------------*/
lokalizacja_t salon={0};
lokalizacja_t korytarz={0};
lokalizacja_t *wsk_korytarz;
lokalizacja_t *wsk_salon;
lokalizacja_t **lokalizacje;

void UtworzKorytarz();
void UtworzSalon();

void UtworzLokalizacje(){
    UtworzKorytarz();
    UtworzSalon();
    //wsk_korytarz->zachod = wsk_salon;
    //wsk_salon->wschod = wsk_korytarz;
    lokalizacje = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*5);
    lokalizacje[0] = wsk_korytarz;
    lokalizacje[1] = wsk_salon;
    printf("Z tablicy lokazlizacji:  %s\n", lokalizacje[0]->nazwa);
}

void UtworzKorytarz(){
    //lokalizacja_t korytarz = {0};
    korytarz.nazwa = "Korytarz";
    korytarz.opis = "Stary zatechly hol, pograzony w ciszy i mroku.";
    korytarz.zachod = &salon;
    int size = MAKS_PRZEDMIOTOW;
    korytarz.przedmioty = (przedmiot_t*)malloc(sizeof(przedmiot_t)*size);
    przedmiot_t kosa={.nazwa="Kosa", .cecha=2, .opis="brudny, zardzewialy majcher", .rodzaj=BRON, .rodzajstr="bron"};
    przedmiot_t bron1={.nazwa="Kosa2", .cecha=2, .opis="brudny, zardzewialy majcher", .rodzaj=BRON, .rodzajstr="bron"};
    przedmiot_t bron2={.nazwa="Kosa3", .cecha=2, .opis="brudny, zardzewialy majcher", .rodzaj=BRON, .rodzajstr="bron"};
    przedmiot_t bron3={.nazwa="Kosa4", .cecha=2, .opis="brudny, zardzewialy majcher", .rodzaj=BRON, .rodzajstr="bron"};
    przedmiot_t bron4={.nazwa="Kosa5", .cecha=2, .opis="brudny, zardzewialy majcher", .rodzaj=BRON, .rodzajstr="bron"};
    for (int i =0; i<size; i++){
        przedmiot_t p={0};
        korytarz.przedmioty[i] = p;
    }
    korytarz.przedmioty[0] =  kosa;
    korytarz.przedmioty[1] =  bron1;
    korytarz.przedmioty[2] =  bron2;
    korytarz.przedmioty[3] =  bron3;
    korytarz.przedmioty[4] =  bron4;
    printf("A coz to za przedmiot %s\n", korytarz.przedmioty[0].nazwa);
    if(korytarz.przedmioty[5].nazwa == NULL){
        puts("PUSTO");
    }
    char *listaprzedmiotow;
    listaprzedmiotow = (char*)malloc(1024*sizeof(char));
    strcpy(listaprzedmiotow, "");

    for(int i =0; i<size; i++){
        /*STRCAT NIE PRZYJMIE NULL JAKO ARGUMENTU*/
          if(korytarz.przedmioty[i].nazwa != NULL){
            strcat(listaprzedmiotow, korytarz.przedmioty[i].nazwa);
            strcat(listaprzedmiotow, " ");
        }
    }
    printf("Przedmioty w lokalizacji: %s\n", listaprzedmiotow);
    free(listaprzedmiotow);
    wsk_korytarz = &korytarz;
}

void UtworzSalon(){
    //lokalizacja_t salon = {0};
    salon.nazwa = "Salon";
    salon.opis = "Niegdys miejsce wypoczynku i rozrywki wlascicieli, obecnie ponure miejsce, w ktorym doszlo do bestialskiej walki.";
    salon.wschod = &korytarz;
    wsk_salon = &salon;

}
void UwolnijPamiecLokalizacji(){
    free(korytarz.przedmioty);
    free(lokalizacje);
}



