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
    
    if(wybor < (**al)->ilusasiadow) {
            lokalizacja_t **tmp = (lokalizacja_t **)malloc(sizeof(lokalizacja_t*));
            *tmp = (**al)->sasiedzi[wybor];
            *al = tmp;

        }
}

void Przeszukaj(){
    puts("PRZESZUKAJ");

}

void Podnies(postac_t **p, lokalizacja_t ***l){
    if((**l)->ileskarbow == 0){
        puts("Nie ma tu niczego wartościowego do zabrania.");
    }
    else{
        puts("Który z przedmiotów chcesz podnieść?");
        puts("Wybierz z poniższych przedmiotów:");

        for(int i = 0; i < (**l)->ileskarbow; i++){
            printf("\t%d) Przedmiot: %s\n", i, (**l)->przedmioty[i]->nazwa );
        }
        puts("Lub wybierz inny znak by zrezygnować z akcji");
        int wybor;
        scanf("%d", &wybor);
        getchar();
        if(wybor < (**l)->ileskarbow){
            printf("Wybór: %d < skarbów: %d\n", wybor, (**l)->ileskarbow);
            (**p).wezpzedmiot(&(**p).udzwig, &(*p)->plecak, (**l)->przedmioty[wybor]);

            int nowyrozmiar = (**l)->ileskarbow - 1;
            przedmiot_t **tmpPrzedmioty = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*nowyrozmiar);

            for(int i =0, j = 0; i < (**l)->ileskarbow; i++){
                if(i==wybor){
                    puts("Ten przedmiot zostanie usunięty.");
                    continue;
                }
                else{
                    tmpPrzedmioty[j] = (**l)->przedmioty[i];
                    j++;
                }
            }
            free((**l)->przedmioty);
            (**l)->przedmioty = tmpPrzedmioty;
            --((**l)->ileskarbow);
        }
        else{
            printf("Wybór: %d > skarbów: %d\n", wybor, (**l)->ileskarbow);
        }

    }
    PrzejdzDalejCzyscEkran();


}
void Uzyj(postac_t **p, lokalizacja_t ***l, lokalizacja_t const *** warunek){

    puts("\tChcesz użyć przedmiotu na siebie, czy w lokalizacji?");
    puts("\t1) Na sobie\t2) W lokalizacji\t Inna cyfra to zmiana decyzji");
    
    char wybor;
     PONOWWYBOR:
     ;
    scanf("%c", &wybor);
    getchar();
    if(isdigit(wybor)){
        switch(wybor){
            case '1':
                puts("Użyj przedmiotu z ekwipunku");
                (*p)->uzyjprzedmiotnasobie(&p);    
                break;
            case '2':
                puts("Użyj przedmiotu w lokalizacji.");
                (*p)->uzyjprzedmiotlokalizacja(&p, &l, &warunek);

                puts("UŻYJ");
                break;
            default:
                break;
        }
    }
    else{
        puts("Nie wprowadziłeś cyfry, spróbuj raz jeszcze.");
        goto PONOWWYBOR;
    }
    PrzejdzDalejCzyscEkran();

}

 


void Ekwipunek(postac_t const ** p){
    system("clear");
    puts("EKWIPUNEK w plecaku: ");
    for(int i = 0 ; i < (*p)->udzwig; i++){

        printf("\t %s KLUCZ: %d\n", (*p)->plecak[i]->nazwa, (*p)->plecak[i]->cecha);
    }
    PrzejdzDalejCzyscEkran();

}

void Postac(postac_t const ** p){
    system("clear");
    puts("POSTAC");
    printf("%s\n", (*p)->nazwa);
    printf("Charakterystyka postaci: \n\twalka %d; \n\tzwinność %d; \n\tpercepcja %d; \n\tżywotność %d\n",
    (*p)->walka, (*p)->zwinnosc, (*p)->percepcja,  (*p)->zywotnosc);
    PrzejdzDalejCzyscEkran();

}