/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *prilepiNiz(char *p1, char *p2){
    char *start, *p, *p1_c = p1;

    // rezerviras vecji prostor za oba stringa
    start = p = malloc(strlen(p1) + strlen(p2) + 1);

    // prepises p1 v p
    for(;*p1_c != '\0';) *(p++) = *(p1_c++);
    // stringu p1 pripnes/pripises p2
    for(;*p2 != '\0';) *(p++) = *(p2++);
    // niz zakljucis z null characterjem
    *p = '\0';

    // sprostis prostor od *p1, ki ga ne uporabljas vec
    free(p1);

    // vrnes kazalec na zacetek stringa p
    return start;
}

int main()
{
    char *pregovor = "Kdor prej pride,";
    pregovor = prilepiNiz(pregovor, " prej melje.");
    printf(pregovor); //izpise: Kdor prej pride, prej melje.

    return 0;
}
