/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 5.8: Ugotovite, kaj pocne naslednji program
*/
#include <stdio.h>
#include <stdlib.h>

double minus(double a, double b) {
    return a - b;
}
double plus(double a, double b) {
    return a + b;
}
double g(double (*f)(double, double), double x, double y) {
    return f(x, y) * f(x, y);
}
int main(void) {
    double a = g(minus, 30, 25); // vrne kvadrat razlike
    double b = g(plus, 30, 25); // vrne kvadrat vsote

    printf("a = %lf\nb = %lf\n", a, b);
    return 0;
}

