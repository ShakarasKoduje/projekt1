#include "../STRUKTURY/struktura.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXODCZYT 1024

void odczytpostac(postac_t ** p){
    size_t odczyt_bajtow;
    size_t rozmiar_wiersza = MAXODCZYT;
    int liczba_wierszy =0;

    char **strona;
    char *string;



    FILE *plikkomnaty;

    printf("\n %s \n ==== ", (*p)->nazwa);
    char *plik = (char*)malloc(sizeof(char)*64);
    strcpy(plik, "PLIKITEKSTOWE/POTWORY/");
    strcat(plik, (*p)->nazwa);
    strcat(plik, ".txt");
    //printf("plik potwory: %s\n", plik);
    plikkomnaty = fopen(plik, "r"); 
    if(!plikkomnaty){
            puts("brak pliku!");
    }

    else{
        string = (char*)malloc(sizeof(char)*rozmiar_wiersza);

        while(getline(&string, &rozmiar_wiersza, plikkomnaty) != -1) liczba_wierszy++;

        rewind(plikkomnaty);

        strona = (char**)malloc(liczba_wierszy*sizeof(char*));
        //printf("Liczba wierszy : %d\n", liczba_wierszy); 
        strcpy((*p)->opis, "");
        for(int i = 0; i < liczba_wierszy || odczyt_bajtow==-1; i++){
            odczyt_bajtow = getline(&string, &rozmiar_wiersza, plikkomnaty);
            strona[i] = (char*)malloc(strlen(string)*sizeof(char));
            strcpy(strona[i], string);
            //printf("%s", strona[i]); 
            
            strcat((*p)->opis, strona[i]);            
        }
        //printf("%s", (*p)->opis); 
        fclose(plikkomnaty); 
    }
}


void odczytkomnata(lokalizacja_t **l){

    size_t odczyt_bajtow;
    size_t rozmiar_wiersza = MAXODCZYT;
    int liczba_wierszy =0;

    char **strona;
    char *string;



    FILE *plikkomnaty;

    //printf("\n %s  / %s\n ==== ", (*l)->nazwa, (*l)->plik);
    char *plik = (char*)malloc(sizeof(char)*64);
    strcpy(plik, "PLIKITEKSTOWE/KOMNATY/");
    strcat(plik, (*l)->plik);
    strcat(plik, ".txt");
    plikkomnaty = fopen(plik, "r"); 
    if(!plikkomnaty){
            puts("brak pliku!");
    }

    else{
        string = (char*)malloc(sizeof(char)*rozmiar_wiersza);

        while(getline(&string, &rozmiar_wiersza, plikkomnaty) != -1) liczba_wierszy++;

        rewind(plikkomnaty);

        strona = (char**)malloc(liczba_wierszy*sizeof(char*));
        //printf("Liczba wierszy : %d\n", liczba_wierszy); 
        strcpy((*l)->opis, "");
        for(int i = 0; i < liczba_wierszy || odczyt_bajtow==-1; i++){
            odczyt_bajtow = getline(&string, &rozmiar_wiersza, plikkomnaty);
            strona[i] = (char*)malloc(strlen(string)*sizeof(char));
            strcpy(strona[i], string);
            //printf("%s", strona[i]); 
            
            strcat((*l)->opis, strona[i]);            
        }
        //printf("%s", (*l)->opis); 
        fclose(plikkomnaty); 
    }

}



void odczytprzedmiotu(przedmiot_t ** p, int rodzaj, int iteracje){
    FILE *plikprzedmiotu;
       
    char *name , *opis;
    name = (char*)malloc(sizeof(char)*64);
    opis = (char*)malloc(sizeof(char)*256);
    int c, premia , r;

    if(rodzaj == 0){
        plikprzedmiotu = fopen("PLIKITEKSTOWE/PRZEDMIOTY/bron.dat", "r");
        if(!plikprzedmiotu){
            puts("Nie ma takiego pliku");
        }
        else{
            puts("OTWARTO PLIK BRON");

            int i = 0;
            while(fscanf(plikprzedmiotu, "%s %d %d %d %s", name, &c, &premia, &r, opis ) != EOF){
            //printf("Przedmiot [%d]: %s %d %d %d %s \n" , i, name, c, premia, r, opis);
            p[i]->premia = premia; p[i]->cecha = c; p[i]->rodzaj = r;
            strcpy(p[i]->nazwa, name); strcpy(p[i]->opis, opis);
            i++;
            if(i == iteracje) break;
            }
            fclose(plikprzedmiotu);
        }
    }
/*
JEZELI TARCZE
*/
    if(rodzaj == 1){
        plikprzedmiotu = fopen("PLIKITEKSTOWE/PRZEDMIOTY/tarcze.dat", "r");
        if(!plikprzedmiotu){

        }
        else{
            puts("OTWARTO PLIK TARCZE");

            int i = 0;
            while(fscanf(plikprzedmiotu, "%s %d %d %d %s", name, &c, &premia, &r, opis ) != EOF){
            //printf("Przedmiot [%d]: %s %d %d %d %s \n" , i, name, c, premia, r, opis);
            p[i]->premia = premia; p[i]->cecha = c; p[i]->rodzaj = r;
            strcpy(p[i]->nazwa, name); strcpy(p[i]->opis, opis);
            i++;
            if(i == iteracje) break;
            }
            fclose(plikprzedmiotu);
        }
    }

    if(rodzaj == 2){
        plikprzedmiotu = fopen("PLIKITEKSTOWE/PRZEDMIOTY/pancerze.dat", "r");
        if(!plikprzedmiotu){

        }
        else{
            puts("OTWARTO PLIK PANCERZE");
                        int i = 0;
            while(fscanf(plikprzedmiotu, "%s %d %d %d %s", name, &c, &premia, &r, opis ) != EOF){
            //printf("Przedmiot [%d]: %s %d %d %d %s \n" , i, name, c, premia, r, opis);
            p[i]->premia = premia; p[i]->cecha = c; p[i]->rodzaj = r;
            strcpy(p[i]->nazwa, name); strcpy(p[i]->opis, opis);
            i++;
            if(i == iteracje) break;
            }
            fclose(plikprzedmiotu);
        }
    }

    if(rodzaj == 3){
        plikprzedmiotu = fopen("PLIKITEKSTOWE/PRZEDMIOTY/narzedzia.dat", "r");
        if(!plikprzedmiotu){

        }
        else{
            puts("OTWARTO PLIK NARZEDZIA");
                        int i = 0;
            while(fscanf(plikprzedmiotu, "%s %d %d %d %s", name, &c, &premia, &r, opis ) != EOF){
            //printf("Przedmiot [%d]: %s %d %d %d %s \n" , i, name, c, premia, r, opis);
            p[i]->premia = premia; p[i]->cecha = c; p[i]->rodzaj = r;
            strcpy(p[i]->nazwa, name); strcpy(p[i]->opis, opis);
            i++;
            if(i == iteracje) break;
            }
            fclose(plikprzedmiotu);
        }
    }
    if(rodzaj == 4){
        plikprzedmiotu = fopen("PLIKITEKSTOWE/PRZEDMIOTY/jedzenie.dat", "r");
        if(!plikprzedmiotu){

        }
        else{
            puts("OTWARTO PLIK JEDZENIE");
                        int i = 0;
            while(fscanf(plikprzedmiotu, "%s %d %d %d %s", name, &c, &premia, &r, opis ) != EOF){
            //printf("Przedmiot [%d]: %s %d %d %d %s \n" , i, name, c, premia, r, opis);
            p[i]->premia = premia; p[i]->cecha = c; p[i]->rodzaj = r;
            strcpy(p[i]->nazwa, name); strcpy(p[i]->opis, opis);
            i++;
            if(i == iteracje) break;
            }
            fclose(plikprzedmiotu);
        }
    }
/* koniec */
}
