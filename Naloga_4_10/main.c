/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.10: 80 clenov Fibonaccijevega zaporedja
//
//    Z uporabo spremenljivk tipa unsigned long napisite program, ki izracuna in
//    izpise prvih 80 clenov Fibonaccijevega zaporedja.
//    Pomoc: Nalogo resite tako, da programsko »zlepite« po dve in dve spremenljivki
//    tipa unsigned long in tako dobite daljse spremenljivke dolzine 64 bitov. Najlazje
//    bo, ce omejite vrednosti v posameznih spremenljivkah na vrednosti med 0 in 10^9 -1.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, N = 80;
    unsigned long x1, x2, y1, y2, z1, z2; // nase sprem x, y, z
    x1 = 1; x2 = 0; // notacija x = "x2x1"
    y1 = 1; y2 = 0;

    printf("Program za izracun Fibonaccijevega zaporedja\n");

    for(i = 3; i <= N; i++){
        z1 = x1 + y1;
        z2 = x2 + y2;
        if(z1 >= 1000000000){
            z1 -= 1000000000;
            z2++;
        }

        printf("%2d : ", i);
        if(z2){
            printf("z = %u%09u\n", z2, z1);
        }else{
            printf("z = %u\n", z1);
        }

        x1 = y1, x2 = y2;
        y1 = z1, y2 = z2;
    }

    //printf("double zasede %d bajtov.\n", sizeof(double));
    return 0;
}
