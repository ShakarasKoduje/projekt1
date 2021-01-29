//#include <stdio.h>
//#include <stdlib.h>

#include <stdbool.h>

#include "STRUKTURY/struktura.h"

#include "STEROWANIEPROGRAMEM/sterowanie.h"
#include "STEROWANIEPROGRAMEM/sterowaniepostacia.h"
#include "STEROWANIEPROGRAMEM/kosci.h"
//#include "INICJALIZACJAPROGRAMU/intro.h"
#include "INICJALIZACJAPROGRAMU/zakonczenie.h"

bool wrog, warunek, koniec;
int ryzyko;
int tura;
int zagrozenie, jakiprzeciwnik;

void ProwadzGre(postac_t *, lokalizacja_t **, lokalizacja_t const **, postac_t**, przedmiot_t ***, przedmiot_t ***, przedmiot_t ***);


void PetlaGry(postac_t **p,lokalizacja_t ***l, lokalizacja_t **startowalokalizacja, postac_t ***potwory, przedmiot_t ***bron, przedmiot_t ***tarcze, przedmiot_t *** pancerz){

    tura = 1; zagrozenie = 75;
    char ch;

     
    ProwadzGre(*p, startowalokalizacja, *l, *potwory, bron, tarcze, pancerz);

    if((*l)[11]->zamekotwarty1){
        puts("WIKTORIA!!!!!!!");


        WyswietlZakonczenie();
        printf("\n%s nadał sygnał w kierunku fortecy Helmgard! Być może jest jeszcze nadzieja.", (*p)->nazwa);
        printf("\nW trakcie gry zdobyłeś %d punktów zwycięstwa.", (*p)->punktyzwyciestwa);
    }
    else if ( (*p)->czyZyje == false  )
    {   
        WyswietlZakonczenieSmierc();
        printf("\n%s poległ w Wieży Sygnałowej. Nie zdołał nadać sygnału.", (*p)->nazwa);
        printf("\nW trakciegry zdobyłeś %d punktów zwycięstwa.", (*p)->punktyzwyciestwa);
    }
    
    PrzejdzDalejCzyscEkran();
}

void ProwadzGre(postac_t *p, lokalizacja_t **al, lokalizacja_t const **l, postac_t **potwory, przedmiot_t ***bron, przedmiot_t ***tarcze, przedmiot_t *** pancerz){
    koniec = false;
    warunek =false;

    do{
            
            
            char wybor;
            do{
                printf("CZY TA POSTAC ZYJE? %d\n", p->czyZyje);
                if(!p->czyZyje){
                    goto KONIEC;
                    warunek = true;
                    koniec = true;
                }
                else{
                    if(p->czyZyje){
                        if(p->czyZyje){
                            printf("-------------- %s znajdujesz się w %s -------------\n", p->nazwa, (*al)->nazwa);
                            printf("%s\n", (*al)->opis);
                            PrzejdzDalej();
                            puts("Co robisz?. Dokonaj wyboru:\n1) Przejdz do innego pomieszczenia  \n2) Podnies przedmiot \n3) Uzyj przedmiotu\n4)Twój ekwipunek\n5)Twoja Postać\n6)Zakończ grę");
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
                                    Podnies(&p, &al);
                                    warunek = true;
                                    tura++; zagrozenie++;
                                    break;  
                                case '3':
                                    Uzyj(&p,&al, &l);
                                    warunek = true;
                                    tura++; zagrozenie++;
                                    printf("CIEKAWA SPRAWA CO TU SIE DZIEJE:");
                                    if( l[11]->zamekotwarty1 == true){
                                        puts("ZWYCIESTWO");
                                        goto ZWYCIESTWO;
                                    }
                                    break;  
                                case '4':
                                    Ekwipunek(&p);
                                    warunek = true;
                                    break;  
                                case '5':
                                    system("clear");
                                    Postac(&p);
                                    warunek = false; //true
                                    break;  
                                case '6':
                                    goto KONIEC;
                                    puts("WYBRANO 7");
                                    warunek = true;
                                    koniec = true;
                                    break;                    
                                default:
                                    puts("\nZmęczenie i strach rozproszył cię na chwilę\n");
                                    puts("Lecz taka dezorientacja może cię kosztować życię.");
                                    break;
                                }
                            }
                        }
                        ryzyko = k100();
                        if(ryzyko < zagrozenie) wrog = true;
                        else wrog = false;
                        if( wrog && wybor != '5' && !koniec){
  
                            printf("%d WALKA; zagrozenie=%d \n", wrog, zagrozenie);
                            jakiprzeciwnik = k100();
                            
                            if(jakiprzeciwnik < 51){
                                printf("Wynik testu na przeciwnika: %d\n", jakiprzeciwnik);
                                Walka(&p,&potwory[0], bron, tarcze, pancerz);
                            }
                            else if (jakiprzeciwnik >50 && jakiprzeciwnik < 95)
                            {
                                printf("%s Wynik testu na przeciwnika: %d\n",potwory[1]->nazwa, jakiprzeciwnik);
                                Walka(&p,&potwory[1], bron, tarcze, pancerz);
                            }
                            else{
                                printf("Wynik testu na przeciwnika: %d\n", jakiprzeciwnik);
                                Walka(&p,&potwory[2], bron, tarcze, pancerz);
                            }
                            
                            PrzejdzDalej();
                        }

                    }
                }
            }while(!warunek);


        
        
    }while(!koniec);
    ZWYCIESTWO:
        puts("ZWYCIĘSTWO!!");
    KONIEC:
        puts("KONIEC");


}