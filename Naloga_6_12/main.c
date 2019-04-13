/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.12: funkcija vrne naslov znaka v tabeli ali
//                  NULL, èe ga ne najde
*/

#include <stdio.h>
#include <stdlib.h>

char *poisciZnak(char *p, char znak){
    for(;; p++){
        if(*p == znak) return p;
        if(*p == '\0')return NULL;
    }
}

int main()
{
    char niz[] = "Kdor isce, ta najde.";
    char *k = poisciZnak(niz, 'n');
    printf("%c %s\n", *k, k); //izpise: n najde.
    k = poisciZnak(niz, '\0');
    printf("%d\n", k - niz); //izpise 20 (stevilo znakov v nizu)

    return 0;
}
