/*
program.c zawiera wywołania wszystkich funkji kluczowych do działania
programu, tj. petlagry()

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>// do funkcji isdigit
#include <locale.h>
#include <string.h>

#include "petlagry.h"
#include "INICJALIZACJAPROGRAMU/intro.h"
#include "INICJALIZACJAPROGRAMU/inicjalizacjagry.h"
#include "wskaznik.c"
#include "STRUKTURY/struktura.h"
#include "STEROWANIEPROGRAMEM/sterowanie.h"

void MenuGlowne();

void program(){
    setlocale(LC_COLLATE, "pl_PL");
    time_t czas;
    srand((unsigned) time(&czas)); //ziarno losu zostalo zasiane ;)
    InicjalizacjaGry(&lokalizacje,&aktualnaLokalizacja, &potworyTemplatka);
    aktualnaLokalizacja = lokalizacje[0];
    WyswietlWprowadzenie();
    MenuGlowne();
    puts("Koniec Programu.");
    PrzejdzDalej();

}


void MenuGlowne(){
    char ch;
    char wybor;
    
    do{
        puts("Menu Główne. Dokonaj wyboru:\n1) Rozpocznij Grę \n0) Zakończ Program");
        scanf("%c", &wybor);
        ch = getchar();
        if(isdigit(wybor)) {
        /*
            ZGODNIE Z TABELĄ ASCII '1' TO LICZBA 49, A '0' TO 48.

        */
            switch (wybor)
            {
            case 49:
                StworzPostac(&bohater);
                printf("Ropoczynasz Grę %s .\n", bohater->nazwa);
                PetlaGry(&bohater, &lokalizacje, &aktualnaLokalizacja,&potworyTemplatka);
                system("clear");
                break;

            case 48:
                system("clear");
                if(bohater != NULL){
                    free(bohater->nazwa);
                    bohater->nazwa = NULL;
                    free(bohater);
                    bohater = NULL;
                }
                break;
            
            default:
                printf("%c ", wybor);
                puts("Nieprawidłowe polecenie");
                system("clear");
                break;
            }
        }
    }while(wybor != 48);

}
