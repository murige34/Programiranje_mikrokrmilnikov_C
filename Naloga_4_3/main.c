/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.3: Fibonaccijevo zaporedje
//
//    Za vajo napisite program, ki izpise toliko clenov Fibonaccijevega zaporedja,
//    kolikor je to mogoce. Razmislite, kako bi program sam zaznal, kdaj v
//    postopku racunanja je prislo do preliva.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    unsigned long f1 = 0, f2 = 1, next;

    for(i = 1; f2 >= f1; i++){
        next = f1 + f2;
        f1 = f2;
        f2 = next;
        printf("F%d: %lu\n", i, f1);
    }

    return 0;
}
