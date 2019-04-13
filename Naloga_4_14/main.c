/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.14: Priimek in ime
//
// Napisite program, ki z vhoda prebere ime in priimek ter izpise najprej
// priimek, potem vejico in na koncu zacetnico imena s piko.
// Primer: "Julio Iglesias" -> "Iglesias, J."
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char znak, prva_crka;

    printf("Vnesi ime in priimek: ");
    scanf("%c", &prva_crka);

    do{
        scanf("%c", &znak);
    }while( znak != ' ');

    do{
        scanf("%c", &znak);
        if(znak != '\n') printf("%c", znak);
    }while( znak != '\n');

    printf(", %c.\n", prva_crka);

    return 0;
}
