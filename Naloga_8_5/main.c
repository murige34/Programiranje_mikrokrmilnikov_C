/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double re, im;
} kompl;

kompl mnozi(kompl x, kompl y) {
    kompl pom;
    pom.re = x.re * y.re - x.im * y.im;
    pom.im = x.re * y.im + x.im * y.re;
    return pom;
}

double absKompl(kompl x){
    return sqrt( x.re*x.re + x.im*x.im);
}

int main()
{
    kompl a = {1, -3};
    printf("%.2lf", absKompl(a));
    return 0;
}
