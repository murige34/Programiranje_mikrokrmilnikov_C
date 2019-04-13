/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.8: funkcija vraca naslov prvega elementa,ki ima
//      vrednost vecjo od srednje vrednosti vseh elementov tabele
*/

#include <stdio.h>
#include <stdlib.h>
#define N 6

double *prviVecjiOdSred(double t[], int N){
    int i;
    double mean = 0.0;

    // Poiscemo srednjo vrednost
    for(i = 0; i < N; i++){
        mean += t[i];
    }
    mean /= N;

    // Prestejemo, koliko elementov je vecjih od povprecja
    for(i = 0; i < N; i++){
        if(t[i] > mean) return &t[i];
    }

    return NULL;
}

int main()
{
    double *k, t[N] = {1.5, 7.1, 1.8, 2.3, 16.9, 0.9};

    k = prviVecjiOdSred(t, N);
    printf("%lf\n", *k); // izpise 7.1

    return 0;
}
