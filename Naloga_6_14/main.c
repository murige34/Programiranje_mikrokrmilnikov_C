/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.14:
//
//    Funkcija v podanem nizu poisce prvi znak, ki je enak podanemu znaku in
//    ga nadomesti z nicelnim znakom. Funkcija naj zacne iskati od zacetka podanega niza.
//    Ce funkcijo klicemo z argumentom z vrednostjo  NULL, potem naj isce od tam, kjer je
//    koncala v prej  snjem klicu. Funkcija naj vsakokrat vrne naslov znaka, pri katerem je
//    zacela iskati.
//    Taksno funkcijo lahko na primer uporabimo, da iz seznama besed, locenega z ve-
//    jicami, izlocimo posamezne besede.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *odlomiNiz(char *niz, char znak){
    static char *last;
    char *start;

    if(niz == NULL) niz = last;

    for(start = niz;; niz++){
        if(*niz == znak){
            *niz = '\0';
            last = niz + 1;
            break;
        }
        else if(*niz == '\0') return NULL;
    }
    return start;
}

int main()
{
    char seznam[] = "ena,dve,tri,stiri,pet,";
    char *k;

    k = odlomiNiz(seznam, ',');
    //k = strtok(seznam, ",");
    while (k) {
        printf("%s\n", k); //Vsakokrat izpise eno besedo iz seznama
        k = odlomiNiz(NULL, ',');
        //k = strtok(NULL, ",");
    }
    return 0;
}
