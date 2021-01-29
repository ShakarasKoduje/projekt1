#ifndef FUNKCJESTRUKTUR_H
#include "funkcjestruktur.c" //plik c z kodem funkcji



void atak(postac_t ***, postac_t ***);
void okrzykbojowy(postac_t const ***);
void PodniesPrzedmiot(int *, przedmiot_t ***, przedmiot_t **);
void UzyjPrzedmiotNaSobie(postac_t ***p);
void UzyjPrzedmiotLokalizacja(postac_t ***p, lokalizacja_t ****l, lokalizacja_t const ****);


#define FUNKCJESTRUKTUR_H
#endif