#ifndef STRUKTURY_H
#include <stdbool.h>


typedef struct przedmiot_t przedmiot_t;
typedef struct postac_t postac_t; //okreslenie typu dla postac_t
typedef struct lokalizacja_t lokalizacja_t;
typedef struct skarb_t skarb_t;
typedef struct opis_t opis_t;

struct postac_t{
    przedmiot_t *bron;
    char *nazwa;
    int (* dodaj)(int, int, postac_t);
    void (* wezpzedmiot)(postac_t*, przedmiot_t*);
    void (* okrzyk)(postac_t);
    unsigned int walka, zwinnosc, percepcja, silawoli, zywotnosc;   

};
struct przedmiot_t{
    char *nazwa;
    char *opis;
    const char *rodzajstr;
    int cecha; // to moze byc wartosc pancerze, obrazenia broni, ilosc zywotnosci zwracanej prze zywnosc, czy klucz dostepu narzedzia
    enum rodzaj {BRON, PANCERZ, NARZEDZIE, JEDZENIE} rodzaj;
};

struct lokalizacja_t{
    char *nazwa;
    char *opis;
    unsigned int ilekomnat;
    unsigned int zamek;
    unsigned int ilusasiadow;

    const lokalizacja_t **sasiedzi; //tablica z sasiednimi lokalizacjami
    przedmiot_t *przedmioty;
    unsigned int ileskarbow;
    skarb_t *skarbiec;
};

struct skarb_t{
    bool czyjest;
    przedmiot_t skarb;
    char *opis; //to jest opis ktory ma byc dolaczony do opisu lokalizacji;

};

struct opis_t{
    char **opisy;
};



#define STRUKTURY_H
#endif