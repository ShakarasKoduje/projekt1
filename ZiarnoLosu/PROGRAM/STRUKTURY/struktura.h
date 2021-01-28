#ifndef STRUKTURY_H
#include <stdbool.h>


typedef struct przedmiot_t przedmiot_t;
typedef struct postac_t postac_t; //okreslenie typu dla postac_t
typedef struct lokalizacja_t lokalizacja_t;
typedef struct skarb_t skarb_t;
typedef struct opis_t opis_t;

struct postac_t{
    przedmiot_t *bron, *tarcza, *pancerz;
    przedmiot_t **plecak;
    char *nazwa, *opis;

    void (* atakuj)(postac_t***, postac_t***);
    void (* wezpzedmiot)(int *, przedmiot_t***, przedmiot_t**);
    void (* uzyjprzedmiotlokalizacja)(postac_t***, przedmiot_t*);
    void (* uzyjprzedmiotnasobie) (postac_t ***);
    void (* okrzyk)(postac_t const ***);
    unsigned int walka, zwinnosc, percepcja, punktyzwyciestwa, udzwig;   
    int zywotnosc;
    bool czyZyje;

};
struct przedmiot_t{
    char *nazwa;
    char *opis;
    const char *rodzajstr;
    int cecha; // to moze byc wartosc pancerze, obrazenia broni, ilosc zywotnosci zwracanej prze zywnosc, czy klucz dostepu narzedzia
    int premia; // do cechy podczas uzywania np. miecz +5 do walki podczas ataku
    enum rodzaj {BRON, TARCZA, PANCERZ, NARZEDZIE, JEDZENIE} rodzaj;
};

struct lokalizacja_t{
    char *nazwa, *plik;
    char *opis;
    unsigned int ilekomnat;
    unsigned int zamek;
    unsigned int ilusasiadow;

    const lokalizacja_t **sasiedzi; //tablica z sasiednimi lokalizacjami
    przedmiot_t **przedmioty;
    unsigned int ileskarbow;

};



#define STRUKTURY_H
#endif