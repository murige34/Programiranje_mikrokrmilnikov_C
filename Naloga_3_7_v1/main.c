/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.7: Koledar
//
//    Napisite program, ki z vhoda prebere, koliko dni ima mesec in s katerim
//    dnem v tednu se zacne (1 za ponedeljek, 2 za torek itd, do 7 za nedeljo).
//    Nato naj program izpise koledar za podani mesec.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, st_dni, prvi_dan;
    printf("Program za izpis koledarja v1.\n");
    printf("Stevilo dni v mesecu: ");
    scanf("%d", &st_dni);
    printf("Prvi dan v mesecu (1-pon, 2-tor ... 7-ned): ");
    scanf("%d", &prvi_dan);

    // lovljenje napak
    if(prvi_dan < 1 || prvi_dan > 7 || st_dni < 1){
        printf("Vnesli ste neveljavne podatke.\n");
        return 1;
    }
    // Izpis imen dneva
    printf("\n  Po  To  Sr  Ce  Pe  So  Ne\n");

    // Ustrezen zamik, kadar se mesec ne zacne s ponedeljkom
    for(i = 1; i < prvi_dan; i++){
        printf("    ");
    }
    // Izpis datumov (stevilk)
    for(i = 1; i <= st_dni; i++){
        printf("%4d", i);
        // Za vsakih 7 izpisanih st. gremo v novo vrstico
        if((prvi_dan + i) % 7 == 1){
            printf("\n");
        }
    }

    return 0;
}
