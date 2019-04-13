/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.10: Igra jemanja zetonov
//
//    Izdelajte program, ki proti cloveskemu igralcu igra igro jemanja zetonov
//    s kupa. Igra poteka tako, da igralca s kupa izmenicno vzemata enega, dva
//    ali tri zetone. Izgubi tisti, ki s kupa vzame zadnji zeton.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int st_zetonov, izbira, n, racNaPotezi = 0;
    int ponoviIgro = 1;
    printf("Igra jemanja zetonov. v1\n");
    // neskoncna zanka, ki generira nove igre, dokler se nam da igrati
    do{
        printf("---------------------------------\n");
        // vnos st. zetonov, ki mora biti pozitivno stevilo
        do{
            printf("Vnesi zacetno stevilo zetonov: ");
            scanf("%d", &st_zetonov);
        }while(st_zetonov <= 0);

        // izbira ali zacne igro igralec ali racunalnik
        do{
            printf("Kdo bo prvi na potezi (0-clovek, 1-racunalnik): ");
            scanf("%d", &izbira);
        }while(izbira < 0 || izbira > 1);
        racNaPotezi = izbira;

        // neskoncna zanka ene igre
        while(1){
            if(!racNaPotezi){ // igralec je na potezi

                printf("Na kupu je %d zetonov. ", st_zetonov);
                // Izgubis, ce moras vzeti zadnji zeton
                if(st_zetonov <= 1){
                    printf("Izgubil si!\n"); break;
                }
                // Izbiras, dokler ne izberes veljavnega st. zetonov
                while(1){
                    printf("Tvoja poteza: ");
                    scanf("%d", &n);
                    if(n < 1 || n > 3){
                        printf("Ne goljufaj! Vzames lahko en, dva ali tri zetone!\n");
                    }else if(n > st_zetonov){
                        printf("Ne mores vzeti vec zetonov, kot jih je na mizi!\n");
                        //printf("Na mizi sta samo se 2 zetona, ne mores vzeti treh.\n");
                    }else{
                        st_zetonov -= n;
                        break;
                    }
                }
                if(st_zetonov <= 0){
                    // Ce si z mize vzel vse preostale zetone si izgubil
                    printf("Vzel si zadnji zeton in izgubil!\n");
                    break;
                }

            }else{ // racunalnik je na potezi
                if(st_zetonov <= 1){
                    // Ce je racunalniku ostal zadnji zeton si zmagal
                    printf("Cestitke premagal si racunalnik, ki je vzel zadnji zeton\n");
                    break;
                }
                //n = 1; // najenostavnejsa resitev
                if(!(n = (st_zetonov - 1)%4)) n = 1; // najboljsa mozna izbira
                st_zetonov -= n;
                printf("Racunalnik vzame %d zetonov.\n", n);

            }

            racNaPotezi = !racNaPotezi; // zamenjava, kdo je na potezi
        }

        printf("Zelite igro ponoviti? 1-da, 0-ne: ");
        scanf("%d", &ponoviIgro);
    }while(ponoviIgro == 1);

    return 0;
}
