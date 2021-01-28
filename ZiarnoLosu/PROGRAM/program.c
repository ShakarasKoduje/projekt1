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
//#include "wskaznik.c"
#include "STRUKTURY/struktura.h"
#include "STEROWANIEPROGRAMEM/sterowanie.h"


postac_t *bohater = NULL; //Protagonista, którego losami kieruje gracz.

lokalizacja_t **lokalizacje  =NULL;
postac_t **potworyTemplatka = NULL;

przedmiot_t **bron = NULL;
przedmiot_t **pancerze = NULL;
przedmiot_t **tarcze = NULL;
przedmiot_t **narzedzia = NULL;
przedmiot_t **jedzenie = NULL;



lokalizacja_t *aktualnaLokalizacja = NULL;

void MenuGlowne();

void program(){
    setlocale(LC_COLLATE, "pl_PL");
    time_t czas;
    srand((unsigned) time(&czas)); //ziarno losu zostalo zasiane ;)
    UtworzPrzedmioty(&bron, &tarcze, &pancerze, &narzedzia, &jedzenie);


    InicjalizacjaGry(&lokalizacje,&aktualnaLokalizacja, &potworyTemplatka);
    aktualnaLokalizacja = lokalizacje[0];

    PrzypiszPrzedmiotyDoLokalizacji(&lokalizacje, &bron, &tarcze, &pancerze, &narzedzia, &jedzenie);
    
    
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
                bohater->bron = (przedmiot_t*)malloc(sizeof(przedmiot_t));
                bohater->tarcza = (przedmiot_t*)malloc(sizeof(przedmiot_t));
                bohater->pancerz = (przedmiot_t*)malloc(sizeof(przedmiot_t));
                bohater->bron = bron[0]; bohater->tarcza = tarcze[0]; bohater->pancerz = pancerze[2];

                printf("Ropoczynasz Grę %s z bronią %s.\n", bohater->nazwa , bohater->bron->nazwa);
                
                PetlaGry(&bohater, &lokalizacje, &aktualnaLokalizacja, &potworyTemplatka, &bron, &tarcze, &pancerze);
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
