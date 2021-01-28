
#include <stdio.h>
#include <time.h>

#include "../STRUKTURY/struktura.h"
#include "../STRUKTURY/funkcjestruktur.h"
#include "../STEROWANIEPROGRAMEM/sterowanie.h"
#include "../STEROWANIEPROGRAMEM/odczytpliku.h"


#define MAXODCZYT 1024
#define KOMNATY 12
#define POTWORY 3


void WypelnijPrzedmioty(przedmiot_t * const *, int, int);
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
    "Składzik", "Izba Dzienna", "Hol", "Sypialnia Molli", "Sypialnia Rhodniego i Franza", 
    "Mesa", "Sypialnia Głównego Oficera Sygnałowego","Kuchnia", 
    "Magazyn", "Biuro", 
    "Mechanizm Sygnałowy", "Platforma Obserwacyjna"};
    char komnatyplik[12][64] = {
    "Skladzik", "IzbaDzienna", "Hol", "SypialniaA", "SypialniaB", 
    "Mesa", "SypialniaC","Kuchnia", 
    "Magazyn", "Biuro", 
    "MechanizmSygnalowy", "PlatformaObserwacyjna"};


    for(int i = 0 ; i < KOMNATY; i++){
        lokalizacje[i]->nazwa = (char*)malloc(sizeof(char)*64);
        lokalizacje[i]->plik = (char*)malloc(sizeof(char)*64);
        lokalizacje[i]->przedmioty =(przedmiot_t**)malloc(sizeof(przedmiot_t*));
        lokalizacje[i]->ileskarbow = 0;
        lokalizacje[i]->zamek = 0;
        if(i == 10)lokalizacje[i]->zamek = 113; //Trybiki
    }
    int ilu=0;
    /*
        PRZYPISANIE SĄSIADÓW I NAZW DO LOKALIZACJI
    */
    for(int i = 0 ; i < KOMNATY; i++){
        //printf("%s ", komnaty + i);
        strcpy(lokalizacje[i]->nazwa, komnaty +i);
        strcpy(lokalizacje[i]->plik, komnatyplik +i);
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

   //lokalizacje[5]->przedmioty = (przedmiot_t*)malloc(sizeof(przedmiot_t));


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


    /*
        DODAWANIE OPISÓW DO LOKALIZACJI
    */


    for(int i = 0 ; i < KOMNATY; i++){
        lokalizacje[i]->opis = (char*)malloc(sizeof(char)*MAXODCZYT);
        odczytkomnata(&lokalizacje[i]);   
        
    }

}

void StworzPostac(postac_t **p){
    char chSP;
    puts("Tworzenie postaci.");
    char imie[250];
    *p = (postac_t*)malloc(sizeof(postac_t));
    (*p)->nazwa = (char*)malloc(sizeof(char)*250);
    (*p)->bron = (przedmiot_t*)malloc(sizeof(przedmiot_t));
    (*p)->udzwig = 0;  
    (*p)->atakuj = &atak;
    (*p)->okrzyk = &okrzykbojowy;
    (*p)->wezpzedmiot = &PodniesPrzedmiot;
    (*p)->uzyjprzedmiotnasobie = &UzyjPrzedmiotNaSobie;
    (*p)->uzyjprzedmiotlokalizacja = &UzyjPrzedmiotLokalizacja;


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

    (*p)->walka = 20 + k10() + k10();
    (*p)->zwinnosc = 20 + k10() + k10();
    (*p)->percepcja = 20 + k10() + k10();
    (*p)->zywotnosc = 30;
    (*p)->punktyzwyciestwa = 0;
    (*p)->czyZyje = true;
    (*p)->plecak = (przedmiot_t**)malloc(sizeof(przedmiot_t*));
    /* Zrobić osobną funkcję do zarządzania plecakiem. Dodawanie/Usuwanie przedmiotów
    for(int i = 0; i < (*p)->walka; i++){
        (*p)->plecak[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    */


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
        potwory[i]->opis = (char*)malloc(sizeof(char)*MAXODCZYT);
        potwory[i]->atakuj = &atak;
        potwory[i]->okrzyk = &okrzykbojowy;
    }

    strcpy(potwory[0]->nazwa, "Ungor");
    potwory[0]->walka = 10; potwory[0]->zywotnosc = 5;
    potwory[0]->punktyzwyciestwa = 1;

    strcpy(potwory[1]->nazwa, "Gor");
    potwory[1]->walka = 20; potwory[1]->zywotnosc = 10;
    potwory[1]->punktyzwyciestwa = 2;

    strcpy(potwory[2]->nazwa, "Bestigor");
    potwory[2]->walka = 30; potwory[2]->zywotnosc = 20;
    potwory[2]->punktyzwyciestwa = 5;

    for(int i = 0; i < POTWORY; i++){
        
        odczytpostac(&potwory[i]);
        //printf("\nPOTWÓR: %s \n", potwory[i]->nazwa);
    }

}

void UtworzPrzedmioty(przedmiot_t *** bron, przedmiot_t ***tarcze, przedmiot_t ***pancerze, przedmiot_t ***narzedzia, przedmiot_t ***jedzenie){
    puts("START");
    int sztukbroni = 5, sztuktarcz = 3, sztukpancerza = 4, sztuknarzedzi = 3, sztukjedzenia = 3;
 
    przedmiot_t ** tmpB = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*sztukbroni);
    przedmiot_t ** tmpT = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*sztuktarcz);
    przedmiot_t ** tmpP= (przedmiot_t**)malloc(sizeof(przedmiot_t*)*sztukpancerza);
    przedmiot_t ** tmpN= (przedmiot_t**)malloc(sizeof(przedmiot_t*)*sztuknarzedzi);
    przedmiot_t ** tmpJ= (przedmiot_t**)malloc(sizeof(przedmiot_t*)*sztukjedzenia);

    for(int i = 0 ; i < sztukbroni; i++){
        tmpB[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    WypelnijPrzedmioty(tmpB, 0, sztukbroni);
    *bron = tmpB;

    for(int i = 0 ; i < sztuktarcz; i++){
        tmpT[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    WypelnijPrzedmioty(tmpT,  1, sztuktarcz);
    *tarcze = tmpT;

    for(int i = 0 ; i < sztukpancerza; i++){
        tmpP[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    WypelnijPrzedmioty(tmpP, 2, sztukpancerza);
    *pancerze = tmpP;

    for(int i = 0 ; i < sztuknarzedzi; i++){
        tmpN[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    WypelnijPrzedmioty(tmpN,  3, sztuknarzedzi);
    *narzedzia = tmpN;

    for(int i = 0 ; i < sztukjedzenia; i++){
        tmpJ[i] = (przedmiot_t*)malloc(sizeof(przedmiot_t));        
    }
    WypelnijPrzedmioty(tmpJ,  4, sztukjedzenia);

    *jedzenie = tmpJ;
}


void WypelnijPrzedmioty(przedmiot_t * const * przedmioty, int rodzaj, int iteracje){


    if(rodzaj == 0){
        //puts("Broń ");
        for(int i = 0;i < iteracje; i++){
            przedmioty[i]->nazwa = (char*)malloc(sizeof(char)*64);
            przedmioty[i]->opis= (char*)malloc(sizeof(char)*256);
        }        
    }
    if(rodzaj == 1){
        //puts("Tarcza");
        for(int i = 0;i < iteracje; i++){
            przedmioty[i]->nazwa = (char*)malloc(sizeof(char)*64);
            przedmioty[i]->opis= (char*)malloc(sizeof(char)*256);
        }   

    }
    if(rodzaj == 2){
        //puts("Pancerz");
        for(int i = 0;i < iteracje; i++){
            przedmioty[i]->nazwa = (char*)malloc(sizeof(char)*64);
            przedmioty[i]->opis= (char*)malloc(sizeof(char)*256);
        }   

    }
    if(rodzaj == 3){
        //puts("Narzędzia");
        for(int i = 0;i < iteracje; i++){
            przedmioty[i]->nazwa = (char*)malloc(sizeof(char)*64);
            przedmioty[i]->opis= (char*)malloc(sizeof(char)*256);
        }   

    }
    if(rodzaj == 4){
        //puts("JEdzenie");
        for(int i = 0;i < iteracje; i++){
            przedmioty[i]->nazwa = (char*)malloc(sizeof(char)*64);
            przedmioty[i]->opis= (char*)malloc(sizeof(char)*256);
        }   

    }

    odczytprzedmiotu(przedmioty, rodzaj, iteracje);
}


void PrzypiszPrzedmiotyDoLokalizacji(lokalizacja_t *** lok, przedmiot_t *** b, przedmiot_t *** t, przedmiot_t ***p, przedmiot_t *** n, przedmiot_t *** j){
    puts("OLOLOLOLOLOLOLOLOLO");
    (*lok)[0]->ileskarbow = 1; (*lok)[0]->przedmioty[0] = (*n)[1];
}

