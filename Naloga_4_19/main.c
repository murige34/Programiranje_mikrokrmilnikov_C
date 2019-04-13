/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.19: Kako je v ramu zapisan float
//
//    Z uporabo naslovnega operatorja, operatorja za pretvorbo tipa in operatorja
//    posredovanja lahko iz pomnilnika preberemo zapis realnega stevila s plavajoco
//    vejico in ga izpisemo v sestnajstiski obliki na naslednji nacin:
//
//        float x = 12.9;
//        //Predpostavimo, da sta int in float oba 32-bitna
//        printf("%X", *(unsigned int *) &x);
//
//    Razlaga: Nad spremenljivko x smo izvedli tri operacije: Naslovni operator (&)
//    najprej vrne naslov spremenljivke x, katerega sklicevani tip je float. Potem z operatorjem
//    za pretvorbo tipa ta sklicevani tip pretvorimo v unsigned int. Zvezdica,
//    ki je v paru oklepajev za imenom tipa, pomeni, da zahtevamo pretvorbo v kazalec
//    na unsigned int in ne unsigned int. Na koncu z operatorjem posredovanja
//    (*) z naslova &x preberemo stiri bajte podatkov in jih tolmacimo kot podatek tipa
//    unsigned int. Tak je namrec zdaj sklicevani tip kazalca &x. To seveda deluje
//    samo ob predpostavki, da sta tipa float in int oba dolga 32 bitov.
//
//    Napisite program, ki bo s tipkovnice prebral realno vrednost in v dvojiskem zapisu
//    izpisal predznak, eksponent in decimalni del stevila, kakor je zapisano v zapisu z
//    32-bitno plavajoco vejico.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float x;
    unsigned int y;

    // Nas program je pisan z predpostavko, da sta int in float 32-bitna
    // ce predpostavka ne drzi je izvajanje programa nesmiselno
    if(sizeof(int) != 4 || sizeof(float) != 4){
        printf("Napaka: int in float nista 32-bitna\n");
        return 0;
    }

    printf("Vnesi realno vrednost: ");
    scanf("%f", &x);

    // prepisemo dvojisko vrednost v nepredznacen celostevilski tip
    y = *(unsigned int *) &x;

    // MSB bit je predznak (- je 1  in + je 0)
    printf("Predznak:   %d\n", ((1<<31) & y) > 0);

    // naslednjih 8 bitov sestavlja eksponent
    printf("Eksponent:  ");
    for(i=1; i <=8; i++)    printf("%d", ((1<<31) & y<<i) > 0);

    // zadnji biti pripadajo mantisi
    printf("\nMantisa:    ");
    for(; i <32; i++)       printf("%d", ((1<<31) & y<<i) > 0);

    // izpis sestnajstiske vrednost
    printf("\n\nSestnajstisko: %x\n", y);
    // izpis binarne vrednosti razdeljene na bajte
    printf("Binarno: ");
    for(i = 0; i < 32; i++){
        printf("%d", ((1<<31) & y<<i) > 0);
        if((i+1) % 8 == 0) printf(" ");
    }

    return 0;
}
