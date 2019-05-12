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

kompl sestej(kompl x, kompl y) {
    kompl pom;
    pom.re = x.re + y.re;
    pom.im = x.im + y.im;
    return pom;
}

kompl odstej(kompl x, kompl y) {
    kompl pom;
    pom.re = x.re - y.re;
    pom.im = x.im - y.im;
    return pom;
}

kompl mnozi(kompl x, kompl y) {
    kompl pom;
    pom.re = x.re * y.re - x.im * y.im;
    pom.im = x.re * y.im + x.im * y.re;
    return pom;
}

kompl deli(kompl x, kompl y) {
    kompl pom;
    pom.re = (x.re*y.re + x.im*y.im) / (y.re*y.re + y.im*y.im);
    pom.im = (x.im*y.re - x.re*y.im) / ( y.re*y.re + y.im*y.im );
    return pom;
}

kompl konjugiraj(kompl x) {
    kompl pom;
    pom.re = x.re;
    pom.im = -x.im;
    return pom;
}

double absKompl(kompl x){
    return sqrt( x.re*x.re + x.im*x.im);
}

int main()
{
    kompl a = {1, 4};
    kompl b = {2, -1};

    kompl rez;

    printf("a = %.2lf %+.2lfi\n", a.re, a.im);
    printf("b = %.2lf %+.2lfi\n", b.re, b.im);

    rez = mnozi(a, b);
    printf("a*b = %.2lf %+.2lfi\n", rez.re, rez.im);

    rez = deli(a, b);
    printf("a/b = %.2lf %+.2lfi\n", rez.re, rez.im);
    return 0;
}
