/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.4: Koliko prostora zasedejo spremenljivke v RAMu?
//
//    Brez uporabe operatorja sizeof napisite program, ki izpise stevilo bitov,
//    ki jih zaseda vsak od treh nepredznacenih celostevilskih tipov, ki smo jih spoznali.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main()
{
    // Nacin 1: st. bitov s pomocjo maks. vrednosti
    // delis z 2, pomaknes bite za 1 mesto v desno (a/2  a>>1)
    int i;
    unsigned char a = - 1; // maks. vrednost (preliv, nepredznaceno stevilo)
    unsigned int b = -1;
    unsigned long c = -1;

    for(i = 0; a > 0; i++) a /= 2; // stejemo st. bitov i
    printf("Char zasede %d bitov.\n", i);

    for(i = 0; b > 0; i++) b /= 2;
    printf("Int zasede %d bitov.\n", i);

    for(i = 0; c > 0; i++) c /= 2;
    printf("Long zasede %d bitov.\n", i);

    printf("---------------------\n");

    // Nacin 2: st. bitov z pointerji (1 bajt = 8 bitov)
    unsigned char *ptr_char;
    unsigned int *ptr_int;
    unsigned long *ptr_long;

    printf("Char zasede %ld bajtov.\n", (long)(ptr_char + 1) - (long)ptr_char);
    printf("Int zasede %ld bajtov.\n", (long)(ptr_int + 1) - (long)ptr_int);
    printf("Long zasede %ld bajtov.\n", (long)(ptr_long + 1) - (long)ptr_long);
    printf("---------------------\n");

    // Nacin 3:  st. bitov z naslovi arrajev (1 bajt = 8 bitov)
    unsigned char var_char[2];
    unsigned int var_int[2];
    unsigned long var_long[2];

    printf("Char zasede %ld bajtov.\n", (long)&var_char[1] - (long)&var_char[0]);
    printf("Int zasede %ld bajtov.\n", (long)&var_int[1] - (long)&var_int[0]);
    printf("Long zasede %ld bajtov.\n", (long)&var_long[1] - (long)&var_long[0]);
    printf("---------------------\n");

    // Nacin 4:  st. bitov z Makrojem (1 bajt = 8 bitov)
    unsigned char x_char;
    unsigned int x_int;
    unsigned long x_long;

    printf("Char zasede %d bajtov.\n", my_sizeof(x_char));
    printf("Int zasede %d bajtov.\n", my_sizeof(x_int));
    printf("Long zasede %u bajtov.\n", my_sizeof(x_long));
    printf("---------------------\n");

    return 0;
}
