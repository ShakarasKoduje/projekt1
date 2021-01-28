#ifndef FUNKCJESTRUKTUR_H
#include "funkcjestruktur.c" //plik c z kodem funkcji
//#include "kosci.c"
//#include "struktura.h" //plik h ze strukturami


void atak(postac_t ***, postac_t ***);
void okrzykbojowy(postac_t const ***);
void PodniesPrzedmiot(int *, przedmiot_t ***, przedmiot_t **);
void UzyjPrzedmiotNaSobie(postac_t ***p);
void UzyjPrzedmiotLokalizacja(postac_t ***p, lokalizacja_t **l);

/*
int pododawaj(int,int, postac_t); //prototyp funkcji
void podniespzedmiot(postac_t*, przedmiot_t*);

void Krzyk(postac_t p);
void UtworzOrki();
void FreeOrki();
*/
//int k100();
#define FUNKCJESTRUKTUR_H
#endif