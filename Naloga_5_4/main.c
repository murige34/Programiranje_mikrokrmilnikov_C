/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.4: Popravi program, da izpise tabelo
//
// komentar: Popravljene stvari so oznacene s komentarjem
*/
#include <stdio.h>
#include <stdlib.h>


// napaka : i je bila globalna spr.
// resitev je bila sprememba v lokalne spr.
//int i;

void pisi(int x, int y) {
    int i; // lokalna spr.
    for (i = x; i <= y; i++) {
        printf("%3d", i);
    }
    printf("\n");
}
int main(void) {
    int i; // lokalna spr.
    for (i = 0; i < 5; i++) {
        pisi(i, i + 5);
    }

    return 0;
}
