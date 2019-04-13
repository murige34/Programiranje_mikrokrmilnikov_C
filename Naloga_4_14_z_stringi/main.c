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
    char ime[101], priimek[101];

    printf("Vnesi ime in priimek: ");
    scanf("%s %s", ime, priimek);
    printf("%s, %c.\n", priimek, ime[0]);

    return 0;
}
