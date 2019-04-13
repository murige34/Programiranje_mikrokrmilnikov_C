/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.6: funkcija za branje celega stevila
//
//    Napisite funkcijo  beriCelo, ki z vhoda prebere celostevilsko vred-
//    nost in jo vrne v parametru, ki ji ga podamo po sklicu. S stavkom return naj
//    funkcija vrne podatek o izidu operacije kot eno od naslednjih treh vrednosti:
//        0: operacija je uspela,
//        1: opozorilo – vneseni celo  stevilski vrednosti sledijo znaki, ki jih ni mogoce
//           tolmaciti kot del celo  stevilske vrednosti in
//        2: napaka – vhodnega podatka ni mogoce tolma  citi kot celo  stevilo.

//    V prvih dveh primerih naj funkcija v parameter zapise vrednost, ki jo je prebrala, v
//    tretjem primeru pa naj vanj vpise vrednost  0. Za branje vrednosti uporabite funkcijo
//    scanf. Dodajte tudi ciscenje vhodnega toka podatkov, da odstranite vse neprebrane
//    znake, ki jih funkcija scanf pusti za sabo
*/
#include <stdio.h>
#include <stdlib.h>

int beriCelo(int *x){
    int n = scanf("%d", x);

    // pricakovan vnos stevilo in potem enter
    if(n > 0 && getchar() == '\n'){
        return 0;
    }

    // ciscenje vhodnega toka podatkov
    while(getchar() != '\n');

    if(n > 0){
        // veljavno stevilo, ki mu sledijo znaki
        return 1;
    }else{
        // niz znakov brez stevila
        *x = 0;
        return 2;
    }

    // Error: nepredvidena situacija
    return -1;
}

int main()
{
    int x;
    while (1) {
        printf("Vnesi celo stevilo (-1 konca): ");
        switch (beriCelo(&x)) {
            case 1: printf("Branje delno uspelo. ");
            case 0: printf("Prebrana vrednost: %d\n", x);
                    if (x == -1) {
                        printf("Nasvidenje!");
                        exit(0);
                    }
                    break;
            case 2: printf("Napacen vnos.\n"); break;
        }
    }

    return 0;
}
