#ifndef STRUKTURY_H

typedef struct przedmiot_t przedmiot_t;
typedef struct postac_t postac_t; //okreslenie typu dla postac_t


struct postac_t{
    przedmiot_t *bron;
    char *nazwa;
    int (* dodaj)(int, int, postac_t);
    void (* wezpzedmiot)(postac_t*, przedmiot_t*);
    void (* okrzyk)(postac_t);
    

};
struct przedmiot_t{
    char *nazwa;
    char *opis;
    const char *rodzajstr;
    int cecha;
    enum rodzaj {BRON, PANCERZ, NARZEDZIE, JEDZENIE} rodzaj;
};


#define STRUKTURY_H
#endif