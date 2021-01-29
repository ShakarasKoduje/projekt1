#include <stdio.h>
#include <stdlib.h>
#include "../STEROWANIEPROGRAMEM/sterowanie.h"


#define MAXODCZYT 1024

void WyswietlZakonczenieSmierc(){
    FILE *plik;

    plik = fopen("PLIKITEKSTOWE/zakonczeniesmierc.txt", "r");
    char odczyt[MAXODCZYT];

    char chWW;


    if(!plik){
        puts("brak pliku!");
    }
    else{
        while(fgets(odczyt, MAXODCZYT, plik)){
            printf("%s", odczyt);            

        }
        
        puts("\nKliknij ENTER by kontynuować...");
    }
    fclose(plik);
    //PrzejdzDalejCzyscEkran();
    while((chWW = getchar()) != '\n');
    system("clear");
}


void WyswietlZakonczenie(){
    FILE *plik;

    plik = fopen("PLIKITEKSTOWE/zakonczenie.txt", "r");
    char odczyt[MAXODCZYT];

    char chWW;


    if(!plik){
        puts("brak pliku!");
    }
    else{
        while(fgets(odczyt, MAXODCZYT, plik)){
            printf("%s", odczyt);            

        }
        
        puts("\nKliknij ENTER by kontynuować...");
    }
    fclose(plik);
    //PrzejdzDalejCzyscEkran();
    while((chWW = getchar()) != '\n');
    system("clear");

}