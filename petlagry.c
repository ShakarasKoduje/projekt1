#include "struktura.h"
#include "funkcje.h"
#include <stdio.h>


postac_t bohater={0}; //bohater gracza
postac_t *wskBoh = &bohater; //wskaznik na bohater

void PetlaGry(postac_t *boh){    

    UtworzOrki();
    for(int i =0; i<5; i++){
        (*orki[i].okrzyk)(orki[i]);
    }
    //postac zostala zadeklarowana w pliku funkcje.c i jak najbardziej ja tu widac.
    postac.nazwa = "Polpotron";
    printf("Imie postaci z innego pliku to: %s\n", postac.nazwa);
    //UTWORZENIE P I NADANIE IM WLASCIWOSCI
    postac_t p = {.nazwa = "Waldemor"};
    p.dodaj = &pododawaj; // wskazanie adresu funkcji pododawaj dla wskaznika struktury
    (*p.dodaj)(9,4,p); // wywolanie funkcji poprzez wskaznik struktury
    p.wezpzedmiot = &podniespzedmiot;
    
    //UTWORZENIE PRZEDMIOTU TASAK I UZYCIE FUNKCJI PRZEZ STRUKTURY TYPU POSTAC   
    przedmiot_t tasak = {.nazwa="Tasak", .opis="o szerokim ostrzu, na ktorym widac zakrzepla krew.", .cecha=3, .rodzaj=BRON};
    (*p.wezpzedmiot)(&p,&tasak);
    (*bohater.wezpzedmiot)(&bohater,&tasak);
    (*boh->wezpzedmiot)(boh, &tasak); //bohater jest wskaznikiem, dlatego nie daje . po bohater, i pozniej&przed bohater.
    
    //WYNIK POWYZSZYCH OPERACJI
    printf("%s dzierzy %s, %s, [b.obrazen %d]\n", p.nazwa, p.bron->nazwa, p.bron->opis, p.bron->cecha);
    printf("%s dzierzy %s, %s\n", boh->nazwa, boh->bron->nazwa, boh->bron->opis);
    printf("%s dzierzy %s\n", bohater.nazwa, bohater.bron->nazwa);
    printf("(wskaznik) %s dzierzy %s\n", wskBoh->nazwa, wskBoh->bron->nazwa); //wskBoh wskazuje na bohatera
    if(boh->bron){
        printf("Ma bron\n");
    }
    if(bohater.bron){
        printf("Ma bron\n");
    }
    FreeOrki();
}

postac_t TworzeniePostaci(char *name){
    postac_t p = {0};  
    printf("Podaj imie dla swojej postaci: ");
    scanf("%s",name);
    p.nazwa = name;
    //PRZYPISANIE FUNKCJI DLA STRUKTURY
    p.wezpzedmiot = &podniespzedmiot;
    p.dodaj = &pododawaj;
    return p;
}

void TwoPost(){
    printf("TwoPOST: Podaj imie dla swojej postaci: ");
    char name[100];
    scanf("%s",name);
    bohater.nazwa = name;
    //PRZYPISANIE FUNKCJI DLA STRUKTURY
    bohater.wezpzedmiot = &podniespzedmiot;
    bohater.dodaj = &pododawaj;
}