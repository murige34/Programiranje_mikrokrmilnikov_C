/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.9: Kalkulator za resevanje trikotnika
//
//    Izdelajte kalkulator za razresevanje trikotnika. Program naj prek
//    stevilskih ukazov omogoca uporabniku naslednje operacije:
//     - Vnos dolzin stranic a, b in c,
//     - Izracun ploscine,
//     - Izracun obsega in
//     - Izracun kotov A, B in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ukaz = -1;
    float a = 0, b = 0, c = 0; // stranice trikotnika
    float s;

    printf("Dobrodosel/la v programu za resevanje trikotnikov.");
    printf("Uporabis lahko naslednje ukaze:\n");
    printf("(0) Vnos stranic, (1) Ploscina, (2) Obseg, (3) Koti, (4) Izhod\n");

    // neskoncna zanka, potrebuje pogoj za izhod (vneses 4)
    while(1){
        // Najprej preberes ukaz uporabnika, kaj naj se racuna
        printf("Vnesi ukaz: ");
        scanf("%d", &ukaz);

        if(a*b*c == 0 && ukaz >= 1 && ukaz <= 3){
            // dokler vsaj ena stranica 0, se steje, kot da podatki niso vneseni
            printf("Najprej vnesi dolzine stranic.\n");
        }else if((a>b+c || b>a+c || c>a+b) && ukaz >= 1 && ukaz <= 3){
            // lovljenje nemogocih trikotnikov (trikotniska neenakost)
            printf("Tak trikotnik ni mogoc.\n");
        }else{
            // obdelava ukaza
            switch(ukaz){
                case 0:
                    // vnos dolzin stranic a, b in c
                    printf("Vpisi stranice (a b c): ");
                    scanf("%f %f %f", &a, &b, &c);
                    break;
                case 1:
                    // izracun ploscine
                    s = (a+b+c)/2;
                    printf("ploscina trikotnika je %.2f\n", sqrt(s*(s-a)*(s-b)*(s-c)));
                    break;
                case 2:
                    // izracun obsega
                    printf("Obseg trikotnika je %.2f\n", (a+b+c) );
                    break;
                case 3:
                    // izracun kotov alpha, beta, gama
                    printf("Koti trikotnika (v stopinjah) so:\n");
                    printf("alpha = %.2f\n", acos((b*b+c*c-a*a)/(2*b*c))*180/M_PI);
                    printf("beta  = %.2f\n", acos((a*a+c*c-b*b)/(2*a*c))*180/M_PI);
                    printf("gama  = %.2f\n", acos((a*a+b*b-c*c)/(2*a*b))*180/M_PI);
                    break;
                case 4:
                    // izhod iz programa
                    printf("Nasvidenje!\n");
                    return 0;
                    break;
                default:
                    // Nepredvideni vnosi, znova izpises mozne ukaze
                    printf("Neveljaven ukaz. ");
                    printf("Uporabis lahko naslednje ukaze:\n");
                    printf("(0) Vnos stranic, (1) Ploscina, (2) Obseg, (3) Koti, (4) Izhod\n");
                    break;
            }
        }
    }

    return 0;
}
