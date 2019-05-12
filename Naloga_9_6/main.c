/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int kodirajBarvo(
    unsigned int r,
    unsigned int g,
    unsigned int b)
{
    return ( (r<<16) | (g<<8) | b );
}

unsigned int rdeca(unsigned int barva){
    return ((barva>>16) & 0x000000ff);
}
unsigned int zelena(unsigned int barva){
    return ((barva>>8) & 0x000000ff);
}
unsigned int modra(unsigned int barva){
    return (barva & 0x000000ff);
}

int main()
{
    unsigned int barva;
    barva = kodirajBarvo(12, 55, 255);
    printf("r:%4d\n", rdeca(barva)); //izpise: 12
    printf("g:%4d\n", zelena(barva)); //izpise: 55
    printf("b:%4d\n", modra(barva)); //izpise: 255
    return 0;
}
