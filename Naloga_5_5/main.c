/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.5: Varno deljenje
//
//    Napisite funkcijo  varnoDeljenje, ki ima dva celostevilska parametra
//    in en parameter tipa double. Preko slednjega naj vrne rezultat deljenja.
//    V primeru, da je deljenje uspelo, naj funkcija s stavkom return vrne
//    nenicelno vrednost, v primeru deljenja z nic pa naj vrne vrednost  0.
//
//      Primer klica funkcije:
//        if (varnoDeljenje(x, y, &rezultat)) {
//            printf("%d / %d = %.3f", x, y, rezultat);
//        }
//        else {
//            printf("Napaka: deljenje z nic.");
//        }
*/
#include <stdio.h>
#include <stdlib.h>

int varnoDeljenje(int x, int y, double *rez){
    // rez = x/y
    if(y){
        *rez = (double)x/y;
    }
    return y;
}
int main()
{
    char c;
    int x, y;
    double rezultat;

    while(1){
        printf("Vnesi dve celi stevili, za izracun kolicnika x/y (x za izhod)\n");
        printf("x: ");  scanf("%d", &x);
        printf("y: ");  scanf("%d", &y);

        // ujames, ce kdo vnese crko
        while ((c = getchar()) != '\n') if(c == 'x') return 0;

        if (varnoDeljenje(x, y, &rezultat)) {
            printf("%d / %d = %.3f", x, y, rezultat);
        }else{
            printf("Napaka: deljenje z nic.");
        }
        printf("\n");
    }

    return 0;
}
