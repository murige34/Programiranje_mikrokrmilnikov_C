/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.11: Racunanje kvadratnega korena po Newtonovem postopku
//
//    Napisite program, ki z uporabo Newtonovega postopka izracuna kvadratni
//    koren pozitivnega realnega stevila.
//       Pomoc: Predpostavimo, da je uporabnik vnesel vrednost x. Newtonov postopek
//    potrebuje zacetno vrednost, iz katere zacne racunati. Naj bo ta vrednost y = 1.
//    Postopek v vsakem koraku izracuna povprecje vrednosti y in x=y. Dobljeno vrednost
//    priredi spremenljivki y in postopek se nadaljuje.
//       Program naj preneha z racunanjem takrat, ko bo absolutna vrednost razlike dveh
//    zaporednih vrednosti spremenljivke y manjsa od produkta 0;00001 in y. Za racunanje
//    uporabite spremenljivke z dvojno natancnostjo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y_old = 0, y = 1;

    printf("Vnesi pozitivno realno stevilo: ");
    scanf("%lf", &x);
    do{
        y_old = y;
        y = (y + x/y)/2;
    }while(fabs(y - y_old) > 1e-6*y);

    printf("Kvadratni koren: %lf", y);
    return 0;
}
