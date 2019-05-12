/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

int prestejEnke(unsigned short x){
    int n = 0, i;
    for(i=0; i<16; i++)
        if(((x>>i) & 0x1) != 0) n++;

    return n;
}
int main()
{
    unsigned short a = 0x06f1;
    printf("St. enk v %u = %d", a, prestejEnke(a));
    return 0;
}
