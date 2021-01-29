#include "inicjalizacjagry.c"
#include "deinicjalizacja.c"


void InicjalizacjaGry(lokalizacja_t ***,lokalizacja_t**, postac_t***);
void StworzPostac(postac_t **);
void StworzPotwory(postac_t ***);
void UtworzPrzedmioty(przedmiot_t ***, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***);
void PrzypiszPrzedmiotyDoLokalizacji(lokalizacja_t ***, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***);


//Czyszczenie pamięci
void UsunLokacje(lokalizacja_t ***l);
void UsunPotwory(postac_t ***p);
void UsunPostac(postac_t **p);
void UsunPrzedmioty(przedmiot_t *** bron, przedmiot_t ***tarcze, przedmiot_t ***pancerze, przedmiot_t ***narzedzia, przedmiot_t ***jedzenie);