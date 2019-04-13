/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.9: funkcija tabeliraj
//
//    Napisite in preizkusite definicijo funkcije  tabeliraj. Funkcija naj
//    kot argument sprejme poljubno funkcijo f, ki sprejme in vrne vrednost tipa double
//    ter se tri parametre  a, b in dx, prav tako tipa double. Funkcija tabeliraj naj
//    izpise tabelo vrednosti podane funkcije  f za vrednosti parametrov od a do b s korakom dx.
//
//      Na primer, klic:
//
//        tabeliraj(log, 1, 3, .5);
//
//      naj izpise naslednjo tabelo:
//
//          x    f(x)
//        ----- -------
//        1.000 0.00000
//        1.500 0.40547
//        2.000 0.69315
//        2.500 0.91629
//        3.000 1.09861
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void tabeliraj(double (*f)(double), double a, double b, double dx){
    double x;
    printf("   x      f(x)\n");
    printf("------  --------\n");
    for(x = a; x <= b; x += dx){
        printf("%6.3lf  %8.5lf\n", x, f(x));
    }
}
int main()
{
    tabeliraj(log, 1, 3, .5);
    return 0;
}
