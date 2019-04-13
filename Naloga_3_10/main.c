/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.10: Igra jemanja zetonov
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int st_zetonov, izbira, n, n_best, racNaPotezi = 0, tezavnost, meja;
    int ponoviIgro = 1;
    printf("Igra jemanja zetonov. v1\n");

    // za seme generatornja nakljucnih stevil uporabimo trenutni cas
    srand(time(NULL));

    // neskoncna zanka, ki generira nove igre, dokler se nam da igrati
    do{
        printf("---------------------------------\n");
        // vnos st. zetonov, ki mora biti pozitivno stevilo
        do{
            printf("Vnesi zacetno stevilo zetonov: ");
            scanf("%d", &st_zetonov);
        }while(st_zetonov <= 0);

        // izbira tezavnosti
        do{
            printf("Izberi tezavnost (1-lahko, 2-srednje, 3-tezko): ");
            scanf("%d", &tezavnost);
        }while(tezavnost < 1 || tezavnost > 3);
        // glede na tezavnost, dolocimo mejo(1-100) v koliko % se rac. NE zmoti
        switch(tezavnost){
            case 1: meja = 50; break;
            case 2: meja = 70; break;
            case 3: meja = 90; break;
            default: meja = 70; break;
        }

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
                //if(!(n = (st_zetonov - 1)%4)) n = 1; // najboljsa mozna izbira

                if(!(n = (st_zetonov - 1)%4)) n = 1; // najboljsa mozna izbira
                // racunalnik se vcasih tudi zmoti (ne odigra optimalne poteze)
                // koliko se racunalnik moti je odvisno od spr. "meja", meja dolocena glede na tezavnost
                if(rand()%100 >= meja){
                    n_best = n; // si shranis optimalno vrednost
                    do{
                        n = rand()%3 + 1;
                    }while(n_best == n || n >= st_zetonov);
                }
                st_zetonov -= n;
                printf("Racunalnik vzame %d zetonov.\n", n);

            }

            racNaPotezi = !racNaPotezi; // zamenjava, kdo je na potezi
        }

        printf("Zelite igro ponoviti? 1-da, 0-ne: ");
        scanf("%d", &ponoviIgro);
    }while(ponoviIgro == 1);

    printf("Hvala, da ste igrali.");

    return 0;
}
