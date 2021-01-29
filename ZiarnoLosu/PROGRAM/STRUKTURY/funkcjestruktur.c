#include "struktura.h"
#include <stdio.h>
#include <stdlib.h>
#include "../STEROWANIEPROGRAMEM/kosci.h"

void WyswietlPlecak(postac_t ***);
void UsunZPLecaka(int index, postac_t ***plecak);

void atak(postac_t ***a, postac_t *** o){
    printf("%s uzbrojony w %s atakuje %s.\n ", (**a)->nazwa, (**a)->bron->nazwa , (**o)->nazwa);
    printf("Obrońca %s chroni się %s nosi %s.\n ", (**o)->nazwa, (**o)->tarcza->nazwa , (**o)->pancerz->nazwa);

    (**a)->okrzyk(a);
    int rzut = k100();
    
    if(rzut <= (**a)->walka + (**a)->bron->premia -(**o)->tarcza->cecha ) {
        puts("Trafienie!");
        int obrazenia = (**a)->walka/10 + (**a)->bron->cecha + rand()%6 - (**o)->pancerz->cecha;
        (**o)->zywotnosc -= obrazenia;
        printf("Atak zadał %d obrażeń walczy %s, pozostało %d żywotności\n",
        obrazenia, (**a)->bron->nazwa ,(**o)->zywotnosc);
    }
    else{
        puts("Pudło.");
    }
    
    if((**o)->zywotnosc < 1) {
            puts("Poniżej 0");
            (**o)->czyZyje = false;
        }
}

void okrzykbojowy(postac_t const ***p){
    printf("[%s]: wrzeszczy \n", (**p)->nazwa );
}

void PodniesPrzedmiot(int * u, przedmiot_t ***plecak, przedmiot_t ** przed){
    int nowyudzwig = *u+1;


    przedmiot_t ** tmp = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*nowyudzwig);
    for(int i = 0 ; i < *u; i++){
        tmp[i] = (*plecak)[i];
    }
    tmp[*u] =(przedmiot_t*)malloc(sizeof(przedmiot_t));
    tmp[*u] = przed;
    printf("Podnosisz przedmiot %s\n", tmp[*u]->nazwa);

    free(*plecak);
    *plecak = tmp;
    ++(*u);
    printf("NOWY UDZWIG %d/%d" , nowyudzwig, *u);
}

void UzyjPrzedmiotNaSobie(postac_t ***p){
    char wybor;
    int index;
    printf("Używam przedmiotu na sobie. A imię moje %s\n", (**p)->nazwa );
    WyswietlPlecak(p);
    scanf("%c", &wybor);
    getchar();

    index = (int)wybor - 48;

            
    if(isdigit(wybor) && index < (**p)->udzwig){
        if((**p)->plecak[index]->rodzaj == 4){
            puts("JEDZENIE i MEDYKAMENTY PRZYWRÓCI CI ŻYWOTNOŚĆ");
            (**p)->zywotnosc += (**p)->plecak[index]->cecha;
            (**p)->zywotnosc += rand()%6+1;
            if((**p)->zywotnosc > 30) (**p)->zywotnosc = 30;
            UsunZPLecaka(index, p);
        }
        else if ((**p)->plecak[index]->rodzaj == 3)
        {
            puts("NARZĘDZIE Chyba trzeba go gdzieś użyć");
        }
        else{
            puts("Dziwny rodzaj przedmiotu.");
        }
        

    }

}

void UzyjPrzedmiotLokalizacja(postac_t ***p, lokalizacja_t ****l,lokalizacja_t const ****war){
    char wybor;
    int index;


    puts("Używam przedmiotu w lokalizacji");
    if(strcmp((***l)->nazwa, "Mechanizm Sygnałowy") == 0){                    
        puts("Jesteś w Mechanizmie sygnałowym");
        printf("Używam przedmiotu w lokalizacji %s. ||  %s\n", (***l)->nazwa ,(**p)->nazwa );
        if((***l)->zamekotwarty1 == false){
            puts("Mechanizm sygnałowy jest niekompletny, jakim przedmiotem chcesz uzupełnić braki?");
            WyswietlPlecak(p);
            scanf("%c", &wybor);
            getchar();

            index = (int)wybor - 48;

            
            if(isdigit(wybor) && index < (**p)->udzwig){      
                
                if((**p)->plecak[index]->cecha == (***l)->zamek1) {
                    (***l)->zamekotwarty1 = true;

                    //usuwanie przedmiotu
                    UsunZPLecaka(index, p);
                    puts("Trybiki na swoim miejscu!");
                }
            }
            
        }
        if((***l)->zamekotwarty2 == false && (***l)->zamekotwarty1 == true ){
            puts("Części są na swoim miejscu. Ale trzeba to jeszcze podokręcać. Czym chcesz to zrobić?");
            WyswietlPlecak(p);
            scanf("%c", &wybor);
            getchar();

            index = (int)wybor - 48;

            
            if(isdigit(wybor) && index < (**p)->udzwig){        
                
                if((**p)->plecak[index]->cecha == (***l)->zamek2) {
                    (***l)->zamekotwarty2 = true;

                    //usuwanie przedmiotu
                    UsunZPLecaka(index, p);
                    puts("Mechanizm naprawiony!");
                }
            }            
        }

    }
    else if(strcmp((***l)->nazwa, "Platforma Obserwacyjna") == 0){
        puts("Jesteś w Platforma Obserwacyjna");
        printf("Używam przedmiotu w lokalizacji %s. ||  %s\n", (***l)->nazwa ,(**p)->nazwa );

        /*
        NO TO SPRADZAMY CZY MOZLIWY JEST FINAL;
        */
       if((**war)[10]->zamekotwarty1 == true &&  (**war)[10]->zamekotwarty2 == true){
           puts("MOŻNA NADAĆ SYGNAŁ, CZY ZNASZ SZYFR?");
           WyswietlPlecak(p);
            scanf("%c", &wybor);
            getchar();
            index = (int)wybor - 48;
            if(isdigit(wybor) && index < (**p)->udzwig){                     
                if((**p)->plecak[index]->cecha == (***l)->zamek1) {
                    (***l)->zamekotwarty1 = true;
                    //Usuwanie przedmiotu
                    UsunZPLecaka(index, p);
 

                    puts("SYGNAŁ ZOSTAŁ NADANY!!!!!!!!!!!!!!!!");
                }
            }
           
       }



    }
    else{
        puts("Wydaje się, że w tym pomieszczeniu nie można zrobić niczego ciekawego.");
    }
    
    
}


void WyswietlPlecak(postac_t ***p){
    puts("Którego przedmiotu używasz?: ");
    for(int i = 0 ; i < (**p)->udzwig; i++){

        printf("\t%d) %s %s\n", i ,(**p)->plecak[i]->nazwa, (**p)->plecak[i]->opis);
    }
    //PrzejdzDalej();
}


/*

    USUWANIE PRZEDMIOTU Z PLECAKA PO UŻYCIU.
*/

void UsunZPLecaka(int index, postac_t ***plecak){
    puts("USUWANIE Z PLECAKA");
    int nowyudzwig = (**plecak)->udzwig -1;
    printf("NOWY UDZWIG: %d || STARY UDZWIG: %d\n", nowyudzwig, (**plecak)->udzwig );

    przedmiot_t **tmp = (przedmiot_t**)malloc(sizeof(przedmiot_t*)*nowyudzwig);
    for(int i = 0, j = 0; i < (**plecak)->udzwig; i++){
        if(i == index){
            puts("Ten przedmiot zostanie usunięty z plecaka.");
            continue;
        }
        else{
            tmp[j] = (**plecak)->plecak[i];
            j++;            
        }

    }
    free((**plecak)->plecak);
    (**plecak)->plecak = tmp;
    --(**plecak)->udzwig;

}