/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.7: Knjiznica za racunanje z ulomki
//
//    Sestavite knjiznico funkcij za racunanje z ulomki. Knjiznica naj vsebuje
//    funkcije za sestevanje, mnozenje in krajsanje ulomkov.
*/
#include <stdio.h>
#include <stdlib.h>
#include "ulomki.h" //knjiznica funkcij za racunanje z ulomki

int main(void) {
    int st1 = 3, im1 = 4, st2 = 9, im2 = 6;
    printf("%d / %d + %d / %d = ", st1, im1, st2, im2);
    sestej(&st1, &im1, st2, im2); //Vsota se nahaja v st1 in im1
    printf("%d / %d = ", st1, im1); //izpise: 54 / 24
    krajsaj(&st1, &im1);
    printf("%d / %d\n", st1, im1); //izpise: 9 / 4

    st1 = 3, im1 = 4, st2 = 9, im2 = 6;
    printf("%d / %d * %d / %d = ", st1, im1, st2, im2);
    zmnozi(&st1, &im1, st2, im2); //Vsota se nahaja v st1 in im1
    printf("%d / %d = ", st1, im1); //izpise: 27 / 24
    krajsaj(&st1, &im1);
    printf("%d / %d\n", st1, im1); //izpise: 9 / 8
    return 0;
}
