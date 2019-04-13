/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.20: Kako vrednost float predstavlja neslednja heksadecimala vrednost?
//
//    Za pomoc glej vajo 4.19
//
//    Napisite
//    program, ki bo s tipkovnice prebral realno vrednost neposredno v zapisu z 32-bitno
//    plavajoco vejico (v sestnajstiskem zapisu) in na zaslon izpisal ustrezno realno vrednost.
//    Za izpis vrednosti uporabite formatno dolocilo %g, ki povzroci, da se bo funkcija
//    printf sama odlocila, ali bo vrednost izpisala v obicajni ali v eksponentni obliki.
//
//    Primer: 33D6BF95 --> 1e-007
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float y;
    unsigned int x;

    // Nas program je pisan z predpostavko, da sta int in float 32-bitna
    // ce predpostavka ne drzi je izvajanje programa nesmiselno
    if(sizeof(int) != 4 || sizeof(float) != 4){
        printf("Napaka: int in float nista 32-bitna\n");
        return 0;
    }

    printf("Vnesi realno vrednost v 32-bitnem\n");
    printf("zapisu s plavajoco vejico: ");

    scanf("%x", &x);

    // prepisemo dvojisko vrednost (bite) v tip float
    y = *(float *)&x;

    printf("Vneseni zapis predstavlja vrednost: %g", y);
    return 0;
}
