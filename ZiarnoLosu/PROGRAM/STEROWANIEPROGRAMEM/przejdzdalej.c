//#include "../STRUKTURY/struktura.h"
#define T 116

void PrzejdzDalej(){

    puts("");
    printf("\t\tNaciśnij -> 't' <- aby kontynuować... ");
    while((getchar()) != T);
    puts("");
    getchar();
}


void PrzejdzDalejCzyscEkran(){

    puts("");
    printf("\t\tNaciśnij -> 't' <- aby kontynuować... ");
    while((getchar()) != T);
    puts("");
    getchar();
    system("clear");

}