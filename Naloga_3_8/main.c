/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 3.8: Koledar, nadgradnja
//
//    Dopolnite program iz naloge 3.7 tako, da bo kot vhodne podatke sprejel
//    leto in mesec gregorijanskega koledarja ter podatek o tem, kateri dan v tednu je 1:
//    januar vnesenega leta. Program naj potem izpise koledar za vneseni mesec. Program
//    naj nalogo ponavlja toliko casa, dokler za leto ne vpisemo vrednosti -1.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, prestopno, leto, mesec, st_dni, prvi_dan;
    printf("Program za izpis koledarja v1.\n");

    while(1){
        printf("Vpisi leto(-1 za izhod): ");
        // VNOS leta
        scanf("%d", &leto);
        if(leto < 0){
            printf("Hvala, ker ste uporabili nas program.");
            return 0;
        }
        // VNOS meseca
        do{
            printf("Vpisi mesec (1-12): ");
            scanf("%d", &mesec);
            if(mesec < 1 || mesec >12){
                printf("Vnesli ste neveljavno vrednost.\n");
            }
        }while(mesec < 1 || mesec >12);

        // VNOS kateri dan je 1. januar
        do{
            printf("1. januar %d (1-pon, 2-tor ... 7-ned): ", leto);
            scanf("%d", &prvi_dan);
            // Izhod iz neskoncne zanke: while(1) je vnesen veljaven dan
            if(prvi_dan >= 1 && prvi_dan <= 7) break;
            printf("Vnesli ste neveljavno vrednost.\n");
        }while(1);

        // ugotavljanje, ce je leto prestopno  1..ce je prestopno
        prestopno = (leto%400 == 0 || (leto%4==0 && leto%100 !=0));
        // dolocis stevilo dni
        switch(mesec){
            case 2:
                st_dni = (prestopno) ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11: st_dni = 30; break;
            default: st_dni = 31; break;
        }
        // dolocis zacetni dan v danem mesecu
        // (breaki ne manjkajo!!), upostevati moramo vse ze pretekle mesece v letu
        switch(mesec){
            case 12: prvi_dan = (prvi_dan + 30)%7;
            case 11: prvi_dan = (prvi_dan + 31)%7;
            case 10: prvi_dan = (prvi_dan + 30)%7;
            case 9:  prvi_dan = (prvi_dan + 31)%7;
            case 8:  prvi_dan = (prvi_dan + 31)%7;
            case 7:  prvi_dan = (prvi_dan + 30)%7;
            case 6:  prvi_dan = (prvi_dan + 31)%7;
            case 5:  prvi_dan = (prvi_dan + 30)%7;
            case 4:  prvi_dan = (prvi_dan + 31)%7;
            case 3:  prvi_dan = (prvi_dan + (prestopno?29:28))%7;
            case 2:  prvi_dan = (prvi_dan + 31)%7; break;
        }
        // popravek: %7 nam obmocje 1-7 preslika v 0-6, kjer je 0 prejsnja 7
        if(prvi_dan == 0) prvi_dan = 7;

        /* ****Izpis koledarja *************************************/
        // Izpis imen dneva
        printf("\n  Po  To  Sr  Ce  Pe  So  Ne\n");

        // Ustrezen zamik, kadar se mesec ne zacne s ponedeljkom
        for(i = 1; i < prvi_dan; i++){
            printf("    ");
        }
        // Izpis datumov (stevilk)
        for(i = 1; i <= st_dni; i++){
            printf("%4d", i);
            // Za vsakih 7 izpisanih st. gremo v novo vrstico
            if((prvi_dan + i) % 7 == 1){
                printf("\n");
            }
        }
        printf("\n\n");
    }

    return 0;
}
