/*
    Poniewaz struktura.h jest definiowana przedprocesorowo i jest zamieszczona w funkcje.h
    to tu nic nie trzeba dopisywac w include, samo lapie postac_t
    przynajmniej na linuxie :D

*/

postac_t postac = {0};
postac_t *orki;
//postac_t bohater={0};

int pododawaj(int a, int b, postac_t p){
    printf("Pododawajmy %d do %d, i da nam to %d, dodawal %s\n", a,b,a+b, p.nazwa);
    return a+b;
}
void podniespzedmiot(postac_t *p, przedmiot_t *b){
    przedmiot_t nowy = *b; // trzeba utworzyc nowy egzemplarz przedmiotu
    p->bron = &nowy;
}

void Krzyk(postac_t p){    
    printf("%s: WRRRRRRRRRRRRRRRRRRRRRRRRRRRRR.\n", p.nazwa);
}

void UtworzOrki(){
    orki = (postac_t*)malloc(20*sizeof(postac_t));
    for(int i = 0 ; i <20; i++){
        postac_t p={.nazwa="Ork"};
        p.okrzyk = &Krzyk;
        orki[i] = p;
    }
}
void FreeOrki(){
    free(orki);
}