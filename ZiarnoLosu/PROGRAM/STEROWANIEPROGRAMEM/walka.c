#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../STRUKTURY/struktura.h"
#include "kosci.h"
#include "sterowanie.h"
#include "../STRUKTURY/funkcjestruktur.h"

postac_t przyklad;
postac_t *wsk_przykl;
postac_t **wsk_przykl2;

void Walka(postac_t **p, postac_t **potw){
    /*
    int w[3]= {20,25,30};
    int z[3] = {10, 15, 20};
    */
    przyklad = **potw;
    wsk_przykl = &przyklad;
    wsk_przykl2 = &wsk_przykl;



    (**wsk_przykl2).walka += k10();
    (**wsk_przykl2).zywotnosc += k10();
    (**wsk_przykl2).czyZyje = true;


    printf("\n----------------PRZYKŁAD: %s [%d]\n", przyklad.nazwa, przyklad.walka);
    printf("\n-------WSKAZNIK PRZYKŁAD: %s [%d]\n", (*wsk_przykl2)->nazwa, (*wsk_przykl2)->walka);
/*
    if (strcmp((*potw)->nazwa, "Ungor") == 0){
        printf("Sprawdzamy czy ungor: %s",(*potw)->nazwa );
        (*potw)->walka = w[0] + k10();
        (*potw)->zywotnosc = z[0] + k10();
    }
    else if (strcmp((*potw)->nazwa, "Gor") == 0)
    {
        
        (*potw)->walka = w[1] + k10();
        (*potw)->zywotnosc = z[1] + k10();
    }
    else if (strcmp((*potw)->nazwa, "Bestigor") == 0)
    {
        (*potw)->walka = w[2] + k10();
        (*potw)->zywotnosc = z[2] + k10();
    }
    
*/
    (*potw)->czyZyje = true;
    printf("%s walka %d zywotnosc %d\n", (*potw)->nazwa, (*potw)->walka, (*potw)->zywotnosc);
    
    puts("WALKA WALKA WALKA WALKA WALKA");
    while((*wsk_przykl2)->czyZyje && (*p)->czyZyje){
        printf("\n\t zywotnosc: %d", (*wsk_przykl2)->zywotnosc);
        if((*p)->czyZyje) (*p)->atakuj(&p, &wsk_przykl2); //wywołanie funkcji przypisanej do struktury
        PrzejdzDalej();

        if((*wsk_przykl2)->czyZyje) (*wsk_przykl2)->atakuj(&wsk_przykl2, &p);
        PrzejdzDalej();
    }

/*
    while((*potw)->czyZyje && (*p)->czyZyje){
        printf("\n\t zywotnosc: %d", (*potw)->zywotnosc);
        if((*p)->czyZyje) (*p)->atakuj(&p, &potw); //wywołanie funkcji przypisanej do struktury
        PrzejdzDalej();

        if((*potw)->czyZyje) (*potw)->atakuj(&potw, &p);
        PrzejdzDalej();
    }
*/
    puts("\n========================");

    
    puts("WALKA WALKA WALKA WALKA WALKA");
}