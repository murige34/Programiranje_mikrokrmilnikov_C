/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.1: Izpis deljiteljev naravnega stevila
//
//    Za vajo napisite program, ki izpisuje vse pozitivne delitelje vsakokrat
//    vnesenega naravnega stevila. Program naj med izpisane delitelje postavi vejice.
//
//      Primer delovanja programa:
//        Vnesi naravno stevilo (0 konca): 15
//        1, 3, 5, 15
//        Vnesi naravno stevilo (0 konca): 16
//        1, 2, 4, 8, 16
//        Vnesi naravno stevilo (0 konca): 0
//        Nasvidenje!

//    Nalogo resite tako, da napi  site in v programu uporabite funkcijo  dodajStevilo,
//    ki naj na izhod izpise stevilsko vrednost, ki ji jo podamo kot argument. Ko funkcijo
//    klicemo prvi  c, naj izpi  se zgolj podano vrednost, ob vsakem naslednjem klicu pa naj
//    pred izpis vrednosti doda se vejico.  Ce funkciji podamo argument z vrednostjo  0, naj
//    se ponastavi – njen naslednji klic naj spet izpise zgolj  stevilko brez vejice.
//
//      Primeri klicev funkcije:
//        dodajStevilo(4); //izpise: 4
//        dodajStevilo(51); //izpise: , 51
//        dodajStevilo(5); //izpise: , 5
//        dodajStevilo(0); //Ne izpise nicesar, temvec ponastavi funkcijo.
//        dodajStevilo(19); //izpise: 19
*/
#include <stdio.h>
#include <stdlib.h>


// funkcija za izpis stevila tipa void -> ne vraca nicesar
void dodajStevilo(int st){
    static int old = 0;
    if(st != 0){ // kadar je 0 ne izpisemo nicesar
        // ce je bilo zadnje st. razlicno od nic dodamo spredaj vejico
        if(old){
            printf(", %d", st);
        }else{
            printf("%d", st);
        }
    }

    // zapomnimo (static) si zadnje vneseno stevilo
    old = st;
}

int main()
{
    int st, i;

    while(1){
        do{
            printf("Vnesi naravno stevilo (0 konca): ");
            scanf("%d", &st);
            // izpolnjen pogoj za koncanje programa
            if(st == 0){
                printf("Nasvidenje!\n");
                return 0;
            }
            // sporocilo uporabniku, ob napacnem vnosu
            if(st < 0){
                printf("Napaka: %d NI naravno stevilo.\n", st);
            }

            // pocisti standard input (da se ne sesuje, ce vneses crko)
            while ((getchar()) != '\n');
        }while(st <= 0);

        dodajStevilo(0); // naslednje stevilo naj se izpise brez ,
        for(i = 1; i <= st; i++){
            if(st % i == 0){
                // izpis deljiteljev
                dodajStevilo(i);
            }
        }
        printf("\n");
    }
    return 0;
}
