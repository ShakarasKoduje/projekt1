//#include <stdio.h>
//#include <stdlib.h>

#include <stdbool.h>

#include "STRUKTURY/struktura.h"

#include "STEROWANIEPROGRAMEM/sterowanie.h"
#include "STEROWANIEPROGRAMEM/sterowaniepostacia.h"
#include "STEROWANIEPROGRAMEM/kosci.h"

bool wrog, warunek, koniec;
int ryzyko;
int tura;
int zagrozenie, jakiprzeciwnik;

void ProwadzGre(postac_t *, lokalizacja_t **, lokalizacja_t const **, postac_t**);


void PetlaGry(postac_t **p,lokalizacja_t ***l, lokalizacja_t **startowalokalizacja, postac_t ***potwory){

    tura = 1; zagrozenie = 65;
    char ch;
    //(*p)->zywotnosc -= 7;
    ProwadzGre(*p, startowalokalizacja, *l, *potwory);
    PrzejdzDalejCzyscEkran();
}

void ProwadzGre(postac_t *p, lokalizacja_t **al, lokalizacja_t const **l, postac_t **potwory){
    koniec = false;
    warunek =false;
    
    do{
            
            
            char wybor;
            do{
                printf("CZY TA POSTAC ZYJE? %d\n", p->czyZyje);
                if(!p->czyZyje){
                    warunek = true;
                    koniec = true;
                }
                else{
                    if(p->czyZyje){
                        ryzyko = k100();
                        if(ryzyko < zagrozenie) wrog = true;
                        else wrog = false;
                        if(wrog && wybor != '6'){
                            printf("%d WALKA; zagrozenie=%d \n", wrog, zagrozenie);
                            jakiprzeciwnik = k100();
                            
                            if(jakiprzeciwnik < 51){
                                printf("Wynik testu na przeciwnika: %d\n", jakiprzeciwnik);
                                Walka(&p,&potwory[0]);
                            }
                            else if (jakiprzeciwnik >50 && jakiprzeciwnik < 95)
                            {
                                printf("%s Wynik testu na przeciwnika: %d\n",potwory[1]->nazwa, jakiprzeciwnik);
                                Walka(&p,&potwory[1]);
                            }
                            else{
                                printf("Wynik testu na przeciwnika: %d\n", jakiprzeciwnik);
                                Walka(&p,&potwory[2]);
                            }
                            
                            PrzejdzDalej();
                        }
                        if(p->czyZyje){
                            printf("-------------- %s znajdujesz się w %s -------------\n", p->nazwa, (*al)->nazwa);
                            printf("%s\n", (*al)->opis);
                            PrzejdzDalej();
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
                                    puts("\nZmęczenie i strach rozproszył cię na chwilę\n");
                                    puts("Lecz taka dezorientacja może cię kosztować życię.");
                                    break;
                                }
                            }
                        }
                    }
                }
            }while(!warunek);


        
        
    }while(!koniec);
}