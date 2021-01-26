//#include <stdio.h>
//#include <stdlib.h>

#include <stdbool.h>

#include "STRUKTURY/struktura.h"

#include "STEROWANIEPROGRAMEM/sterowanie.h"
#include "STEROWANIEPROGRAMEM/sterowaniepostacia.h"

bool wrog, warunek, koniec;
int ryzyko;
int tura;
int zagrozenie;

void ProwadzGre(postac_t *, lokalizacja_t **, lokalizacja_t const **, postac_t**);


void PetlaGry(postac_t **p,lokalizacja_t ***l, lokalizacja_t **startowalokalizacja, postac_t ***potwory){

    tura = 1; zagrozenie = 5;
    char ch;
    printf("Ropoczęcie gry. Twój bohater %s ma nielada problemy...\n", (*p)->nazwa );
    printf("Aktualna lokalizacja: %s\n", (*startowalokalizacja)->nazwa);
    //(*p)->zywotnosc -= 7;
    ProwadzGre(*p, startowalokalizacja, *l, *potwory);
    PrzejdzDalejCzyscEkran();
}

void ProwadzGre(postac_t *p, lokalizacja_t **al, lokalizacja_t const **l, postac_t **potwory){
    koniec = false;
    
    
    do{
            printf("POTWOR %s\n", (*potwory[0]).nazwa);
            warunek =false;
            char wybor;
            do{
                ryzyko = rand()%100+1;
                if(ryzyko < zagrozenie) wrog = true;
                else wrog = false;
                if(wrog){
                    printf("%d WALKA; zagrozenie=%d \n", wrog, zagrozenie);
                    Walka(&p,&potwory);
                }
                puts("Co robisz?. Dokonaj wyboru:\n1) Przejdz do innego pomieszczenia \n2) Przeszukaj pomieszczenie \n3) Podnies przedmiot \n4) Uzyj przedmiotu\n5)Twój ekwipunek\n6)Twoja Postać\n7)Zakończ grę");
                printf("TURA: %d; zagrozenie=%d \n", tura, zagrozenie);
                scanf("%c", &wybor);
                getchar();
                if(isdigit(wybor)) {
                    switch (wybor)
                    {
                    case '1':
                        Ruch(&p,&al);
                        warunek = true;
                        tura++; zagrozenie++;
                        break;
                    case '2':
                        Przeszukaj();
                        warunek = true;
                        tura++; zagrozenie++;
                        break;            
                    case '3':
                        Podnies();
                        warunek = true;
                        tura++; zagrozenie++;
                        break;  
                    case '4':
                        Uzyj();
                        warunek = true;
                        tura++; zagrozenie++;
                        break;  
                    case '5':
                        Ekwipunek(&p);
                        warunek = true;
                        break;  
                    case '6':
                        system("clear");
                        Postac(&p);
                        warunek = true;
                        break;  
                    case '7':
                        warunek = true;
                        koniec = true;
                        break;                    
                    default:
                        break;
                    }
                }
                
            }while(!warunek);

    /*
        for(int k = 0;k < 10;k++){
            

                printf("Charakterystyka postaci: \n\twalka %d; \n\tzwinność %d; \n\tpercepcja %d; \n\tsiła woli %d; \n\tżywotność %d\n",
        (*p).walka, (*p).zwinnosc, (*p).percepcja, (*p).silawoli, (*p).zywotnosc);

            printf("============ %s || %s sasiadow: %d =====\n", (*p).nazwa, (*al)->nazwa, (*al)->ilusasiadow);
            puts("Wybierz do kąd chcesz przejść: ");
            for(int i = 0; i < (*al)->ilusasiadow ; i++){
                printf("\t%d -> %s\n ", i, (*al)->sasiedzi[i]->nazwa);
            }
            int wybor;
            scanf("%d", &wybor);
            getchar();

            if(wybor < (*al)->ilusasiadow) {
                lokalizacja_t **tmp = (lokalizacja_t **)malloc(sizeof(lokalizacja_t*));
                *tmp = (*al)->sasiedzi[wybor];
                al = tmp;

            }
            tura++; zagrozenie++;
        }
        */
        
        
    }while(!koniec);
}