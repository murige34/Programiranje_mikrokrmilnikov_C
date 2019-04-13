/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.8: Pretvorba ASCII -> znak ali obratno
//
//    Napisite program, ki uporabniku omogoca, da vnasa bodisi kode
//    ASCII bodisi znake. Program naj za vsako vne¡seno kodo prikaze ustrezen znak
//    oziroma za vsak vnesen znak izpise njegovo kodo ASCII.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int znak;

    while(1){
        printf("Vnesi ukaz (0:izhod, 1:ASCII->znak, 2:znak->ASCII): ");
        scanf("%d", &znak);

        switch(znak){
            case 0:
                printf("Nasvidenje!\n");
                return 0;
                break;
            case 1:
                printf("Vnesi kodo ASCCII: ");
                scanf("%d", &znak);
                printf("Koda %d predstavlja znak %c\n", znak, znak);
                break;
            case 2:
                printf("Vnesi znak: ");
                // Nacin 1:
                while(getchar() != '\n'); // Prebrati moras tudi enter (\n), ki ostane v bufferju od zadnjega scanf ukaza
                scanf("%c", (char *)&znak);

                // Nacin 2:
                // scanf("\n%c", &znak); // deluje tudi to, brez while zanke a ni priporocljivo

                printf("Znak %c ima kodo %d\n", znak, znak);
                break;
            default:
                printf("Neveljaven ukaz.\n");

        }
    }

    return 0;
}
