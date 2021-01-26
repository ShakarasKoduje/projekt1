
#include <stdio.h>
#include <time.h>

#include "../STRUKTURY/struktura.h"
#include "../STEROWANIEPROGRAMEM/sterowanie.h"

#define MAXODCZYT 1024
#define KOMNATY 12
#define POTWORY 3

void UtworzLokalizacje(lokalizacja_t * const * lokalizacje); 
void StworzPotwory(postac_t ***potwory);
void ZapelnijPotwory(postac_t * const * potwory);

void InicjalizacjaGry(lokalizacja_t ***lokalizacje, lokalizacja_t **startowa, postac_t ***potwory){
    *startowa = (lokalizacja_t*)malloc(sizeof(lokalizacja_t));
    puts("Inicjalizacja gry.");
    lokalizacja_t ** tmp = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*KOMNATY);

    for(int i = 0 ; i < KOMNATY; i++){
        tmp[i] = (lokalizacja_t*)malloc(sizeof(lokalizacja_t));        
    }

    UtworzLokalizacje(tmp);
    *lokalizacje = tmp;
    (**lokalizacje)->ilekomnat = KOMNATY;

    StworzPotwory(&potwory);

}

void UtworzLokalizacje(lokalizacja_t * const * lokalizacje){
    char komnaty[12][64] = {
    "Składzik", "Izba Dzienna", "Hol", "Sypialnia A", "Sypialnia B", 
    "Mesa", "Sypialnia C","Kuchnia", 
    "Magazyn", "Biuro", 
    "Mechanizm Sygnałowy", "Platforma Obserwacyjna"};

    for(int i = 0 ; i < KOMNATY; i++){
        lokalizacje[i]->nazwa = (char*)malloc(sizeof(char)*64);
    }
    int ilu=0;
    for(int i = 0 ; i < KOMNATY; i++){
        //printf("%s ", komnaty + i);
        strcpy(lokalizacje[i]->nazwa, komnaty +i);
        switch(i){
            case 5:
                ilu =4; 
                lokalizacje[i]->ilusasiadow = ilu;
                lokalizacje[i]->sasiedzi = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*ilu);
                break;
            case 0:
            case 2:
                ilu = 3;
                lokalizacje[i]->ilusasiadow = ilu;
                lokalizacje[i]->sasiedzi = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*ilu);

                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                ilu=2;
                lokalizacje[i]->ilusasiadow = ilu;
                lokalizacje[i]->sasiedzi = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*ilu);

                break;
            default:
                ilu = 1;
                lokalizacje[i]->ilusasiadow = ilu;
                lokalizacje[i]->sasiedzi = (lokalizacja_t**)malloc(sizeof(lokalizacja_t*)*ilu);

                break;
        }

        
    }
    /*=================================
    USTAWIANIE SĄSIADÓW DLA LOKALIZACJI
    ==================================*/ 


    /*
            PARTER
    */

    //Składzik       
    lokalizacje[0]->sasiedzi[0] = lokalizacje[1]; //izba dzienna
    lokalizacje[0]->sasiedzi[1] = lokalizacje[2]; //hol
    lokalizacje[0]->sasiedzi[2] = lokalizacje[5]; //mesa na 1 piętrze

    //Izba dzienna
    lokalizacje[1]->sasiedzi[0] = lokalizacje[0]; //składzik

    //Hol
    lokalizacje[2]->sasiedzi[0]= lokalizacje[0]; //składzik
    lokalizacje[2]->sasiedzi[1]= lokalizacje[3]; //sypialnia A
    lokalizacje[2]->sasiedzi[2]= lokalizacje[4]; //sypialnia B

    //sypialnia A
    lokalizacje[3]->sasiedzi[0] = lokalizacje[2]; //hol

    //sypialnia B
    lokalizacje[4]->sasiedzi[0] = lokalizacje[2]; //hol


    /*
        I piętro
    */

   //mesa
   lokalizacje[5]->sasiedzi[0] = lokalizacje[0]; //składzik parter
   lokalizacje[5]->sasiedzi[1] = lokalizacje[6]; // sypialnia C
   lokalizacje[5]->sasiedzi[2] = lokalizacje[7]; //kuchnia
   lokalizacje[5]->sasiedzi[3] = lokalizacje[8]; // magazyn 2 piętro

    //sypialnia C
   lokalizacje[6]->sasiedzi[0] = lokalizacje[5]; // mesa
   lokalizacje[6]->sasiedzi[1] = lokalizacje[7]; // kuchnia

   //kuchnia
   lokalizacje[7]->sasiedzi[0] = lokalizacje[5]; // mesa
   lokalizacje[7]->sasiedzi[1] = lokalizacje[6]; // sypialnia C

   /*
    2 piętro
    */

   //magazyn
   lokalizacje[8]->sasiedzi[0] = lokalizacje[5]; // mesa
   lokalizacje[8]->sasiedzi[1] = lokalizacje[9]; // biuro


    //biuro
   lokalizacje[9]->sasiedzi[0] = lokalizacje[8]; // magazyn
   lokalizacje[9]->sasiedzi[1] = lokalizacje[10]; // mechanizm sygnałowy

   /*
   3 piętro
   */
  //mechanizm sygnałowy
   lokalizacje[10]->sasiedzi[0] = lokalizacje[9]; // biuro
   lokalizacje[10]->sasiedzi[1] = lokalizacje[11]; // platformaobserwacyjna

    //platforma obserwacyjna
    lokalizacje[11]->sasiedzi[0] = lokalizacje[10]; //mechanizm sygnałowy

}

void StworzPostac(postac_t **p){
    char chSP;
    puts("Tworzenie postaci.");
    char imie[250];
    *p = (postac_t*)malloc(sizeof(postac_t));
    (*p)->nazwa = (char*)malloc(sizeof(char)*250);

    FILE *plik; int linia = 1;
    plik = fopen("PLIKITEKSTOWE/tworzeniepostaci.txt", "r");
    char odczyt[MAXODCZYT];
    if(!plik){
                puts("brak pliku!");
            }
    else{
        while(fgets(odczyt, MAXODCZYT, plik)){

            printf("%s", odczyt);
            if(linia == 14){
                scanf("%s", imie);
                chSP = getchar(); 
                system("clear"); 
            }
            linia++;
                
            } 
    PrzejdzDalejCzyscEkran();
    }

    strcpy((*p)->nazwa, imie);
    (*p)->walka = 30;
    (*p)->zwinnosc = 30;
    (*p)->percepcja = 30;
    (*p)->silawoli = 30;
    (*p)->zywotnosc = 30;

    fclose(plik);
}

void StworzPotwory(postac_t ***potwory){
    postac_t ** tmp = (postac_t**)malloc(sizeof(postac_t*)*POTWORY);
    for(int i = 0 ; i < POTWORY; i++){
        tmp[i] = (postac_t*)malloc(sizeof(postac_t));        
    }
    ZapelnijPotwory(tmp);
    **potwory = tmp;
}

void ZapelnijPotwory(postac_t * const * potwory){
    for(int i = 0; i < POTWORY; i++){
        potwory[i]->nazwa = (char*)malloc(sizeof(char)*128);
    }

    strcpy(potwory[0]->nazwa, "Ungor");
    strcpy(potwory[1]->nazwa, "Gor");
    strcpy(potwory[2]->nazwa, "Bestigor");
    for(int i = 0; i < POTWORY; i++){
        printf("POTWÓR: %s \n", potwory[i]->nazwa);
    }

}