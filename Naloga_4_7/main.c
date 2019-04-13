/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.7: Tekst brez presledkov in locil
//
//    Za vajo napisite program, ki s tipkovnice prebere poljubno besedilo (zakljuceno
//    s tipko za potrditev) in izpise vneseno besedilo brez presledkov in locil.
//    Pri pisanju programa si pomagajte s funkcijama isspace() in ispunct(). Obe funkciji
//    kot argument sprejmeta en znak. Prva funkcija vrne nenicelno vrednost, ce je znak
//    presledek (angl. space) ali katerikoli drug znak, ki se prikaze kot prazen prostor.
//    Druga funkcija vrne neni¡celno vrednost, ce je znak locilo (angl. punctuation).
//    Funkciji se nahajata v knjiznici <ctype.h>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char znak;
    printf("Vnesi nekaj besedila: ");
    while (1){
        scanf("%c", &znak);
        if (znak == '\n') break;
        // Izpis znaka, ce ni presledek ali locilo
        if(!isspace(znak) && !ispunct(znak)){
            printf("%c", znak);
        }
    }
    return 0;
}
