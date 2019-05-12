/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

char *prviPoAbecedi(char *besede[]){
    int i;
    char prva_crka = *besede[0], *p = besede[0];

    for(i = 1; besede[i] != NULL; i++){
        if(prva_crka > *besede[i]){
            prva_crka = *besede[i];
            p = besede[i];
        }

    }

    return p;
}

int main()
{
    char *besede[] = {"cow", "pig", "dragon", "auto", NULL};
    printf(prviPoAbecedi(besede)); //izpise: auto

    return 0;
}
