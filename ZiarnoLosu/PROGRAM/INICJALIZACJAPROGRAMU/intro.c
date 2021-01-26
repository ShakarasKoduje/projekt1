/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include "../STEROWANIEPROGRAMEM/sterowanie.h"


#define MAXODCZYT 1024

void WyswietlWprowadzenie(){
    FILE *plik;

    plik = fopen("PLIKITEKSTOWE/intro.txt", "r");
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