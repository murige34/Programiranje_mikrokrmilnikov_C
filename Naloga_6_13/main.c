/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.13: funkcija dopise p2 na konec p1
*/

#include <stdio.h>
#include <stdlib.h>

char *prilepiNiz(char *p1, char *p2){
    char *start = p1;

    // najdes konec vhodnega stringa p1
    for(;*p1 != '\0'; p1++);
    // stringu p1 pripnes ali pripises p2
    for(;*p2 != '\0';) *(p1++) = *(p2++);
    // niz zakljucis z null characterjem
    *p1 = '\0';

    // vrnes kazalec na zacetek stringa p1
    return start;
}

int main()
{
    char pregovor[100] = "Tudi slepa kura";
    prilepiNiz(prilepiNiz(pregovor, " zrno"), " najde.");
    printf(pregovor); //izpise: Tudi slepa kura zrno najde.

    return 0;
}
