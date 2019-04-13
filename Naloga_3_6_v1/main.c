/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.6: Izpis stevilk z besedo
//
//   Napisite program, ki prebere celostevilsko vrednost med vkljucno 1 in
//   99 ter prebrano vrednost izpise z besedo.
//   (program lahko razsiris na obmocje -99 do 99)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Deklaracija spremenljivk:
    int n;

    printf("Vpisi celo stevilo med -99 in 99: ");
    // Preberemo celostevilsko vrednost
    // scanf potrebuje naslov spremenljivke, v katero zelimo shraniti vrednost
    // do naslova spremenljivke pridemo z "&" pred imenom spremenljivke
    // npr. spremenljivka n se nahaja v spominu(RAM) na naslovu &n
    scanf("%d", &n);


    if(n < -99 || n > 99){
        // lovljenje napak, ce uporabnik vnese stevilo izven predvidenega obmocja
        printf("Vnesli ste neveljavno stevilo");
    }else{
        printf("Vpisal/a si stevilo ");

        if(n == 0){
            // poseben primer: 0
            printf("nic");
        }else{
            if(n < 0){
                // stevila z negativnim predznakom breremo z minus
                printf("minus ");
                // hocemo samo pozitivne vrednosti stevila n
                n *= -1;
            }
            // izpis enic (enice so ostanek pri deljenju z 10 .. % modulo operator)
            switch(n%10){
                case 1: printf("ena"); break;
                case 2: printf("dva"); break;
                case 3: printf("tri"); break;
                case 4: printf("stiri"); break;
                case 5: printf("pet"); break;
                case 6: printf("sest"); break;
                case 7: printf("sedem"); break;
                case 8: printf("osem"); break;
                case 9: printf("devet"); break;
            }
            // lovljenje izjem 10 do 19
            if(n == 10){
                printf("deset");
            }else if(n == 11){
                printf("jst");
            }else if (n >= 12 && n <=19){
                printf("najst");
            }else{
                if(n%10 != 0 && n >= 20){
                    // desetice in enice locene z "in", razen kadar so enice 0
                    printf("in");
                }
                // Izpis desetic (do desetic pridemo s celostevilskim deljenjem int z 10)
                switch(n/10){
                    case 2: printf("dvajset"); break;
                    case 3: printf("tri"); break;
                    case 4: printf("stiri"); break;
                    case 5: printf("pet"); break;
                    case 6: printf("sest"); break;
                    case 7: printf("sedem"); break;
                    case 8: printf("osem"); break;
                    case 9: printf("devet"); break;
                }
                // Deseticam nad 20 pripnemo 10, lahko bi vnesli ze v printf znotraj switch
                if(n>=30){
                    printf("deset");
                }
            }
        }
    }
    // Poved zakljucimo s piko
    printf(".\n");

    return 0;
}
