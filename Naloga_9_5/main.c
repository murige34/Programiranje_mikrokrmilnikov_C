/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

#define LEVO -1
#define DESNO 1

unsigned short zasukaj(unsigned short x, int n, int smer){
    int i;

    for(i = 0; i< n; i++){
        if(smer == LEVO){
            x = (x<<1) | (x>>15);
        }else if(smer == DESNO){
            x = (x>>1) | (x<<15);
        }
    }
    return x;
}

int main()
{
    unsigned short x = zasukaj(0xf824, 2, LEVO);
    printf("%x\n", x);  // izpise: e093
    x = zasukaj(0x1a6d, 4, DESNO);
    printf("%x\n", x);  // izpise: d1a6
    return 0;
}
