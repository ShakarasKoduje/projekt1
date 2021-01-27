#include "sterowanie.h"


void Ruch(postac_t **p, lokalizacja_t ***al){
    puts("RUCH");
    //printf("%s jest w %s\n %s\n", (*p)->nazwa, (**al)->nazwa, (**al)->opis);
    for(int i = 0; i < (**al)->ilusasiadow ; i++){
        printf("\t%d -> %s\n ", i, (**al)->sasiedzi[i]->nazwa);
        }
    int wybor;
    scanf("%d", &wybor);
    getchar();
    printf("ILUS SASIADOW %d\n", (**al)->ilusasiadow);
    if(wybor < (**al)->ilusasiadow) {
            lokalizacja_t **tmp = (lokalizacja_t **)malloc(sizeof(lokalizacja_t*));
            *tmp = (**al)->sasiedzi[wybor];
            *al = tmp;

        }
}

void Przeszukaj(){
    puts("PRZESZUKAJ");

}
void Podnies(){
    puts("PODNIEŚ");
}
void Uzyj(){
    puts("UŻYJ");


}

void Ekwipunek(postac_t const ** p){
    puts("EKWIPUNEK");
}

void Postac(postac_t const ** p){
    puts("POSTAC");
    printf("%s\n", (*p)->nazwa);
    printf("Charakterystyka postaci: \n\twalka %d; \n\tzwinność %d; \n\tpercepcja %d; \n\tsiła woli %d; \n\tżywotność %d\n",
    (*p)->walka, (*p)->zwinnosc, (*p)->percepcja, (*p)->silawoli, (*p)->zywotnosc);
    PrzejdzDalejCzyscEkran();

}