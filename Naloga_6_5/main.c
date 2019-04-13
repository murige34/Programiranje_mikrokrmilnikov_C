/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.5: funkcija vraca stevilo elementov z vrednostjo
//                vecjo od srednje vrednosti vseh elementov
*/

#include <stdio.h>
#include <stdlib.h>

#define N 6

int stVecjihOdSred(double t[], int N){
    int i, st = 0;
    double mean = 0.0;

    // Poiscemo srednjo vrednost
    for(i = 0; i < N; i++){
        mean += t[i];
    }
    mean /= N;

    // Prestejemo, koliko elementov je vecjih od povprecja
    for(i = 0; i < N; i++){
        if(t[i] > mean) st++;
    }

    return st;
}

int main()
{
    double t[N] = {1.5, 2.1, 1.8, 2.3, 16.9, 0.9};
    printf("%d\n", stVecjihOdSred(t, N)); //izpise: 1

    return 0;
}
