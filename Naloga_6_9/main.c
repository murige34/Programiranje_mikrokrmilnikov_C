/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.9: funkcija za izlocanje podvojenih vrednosti
*/

#include <stdio.h>
#include <stdlib.h>

#define N 12

// funkcija za izlocanje podvojenih elementov v tabeli
// prejme tabelo t in njeno dolzino N
// vraca naslov konca tabele(na tem naslovu je ze podvojena vred.)
//  isce zadnji zapis posamezne vrednosti
int *izlociDuplikate(int t[], int N){
    int i, j, k = 0;
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            if(t[i] == t[j]) break;
        }
        if(j == N) t[k++] = t[i];
    }
    return &t[k];
}

// funkcija za izlocanje podvojenih elementov v tabeli
// prejme tabelo t in njeno dolzino N
// vraca naslov konca tabele(na tem naslovu je ze podvojena vred.)
//  isce prvi zapis posamezne vrednosti
int *izlociDuplikate2(int t[], int N){
    int i, j, k = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < i; j++){
            if(t[i] == t[j]) break;
        }
        if(j == i) t[k++] = t[i];
    }
    return &t[k];
}

int main()
{
    int t[N] = {5, 9, 5, 2, 6, 77, 15, 5, 5, 77, 6, 2};
    int *k, *zadnji;
    k = t;
    zadnji = izlociDuplikate(t, N);
    for (;k < zadnji; k++) {
        printf("%d ", *k); //izpi¡se: 9 15 5 77 6 2
    }

    printf("\n");

    int t2[N] = {5, 9, 5, 2, 6, 77, 15, 5, 5, 77, 6, 2};
    k = t2;
    zadnji = izlociDuplikate2(t2, N);
    for (;k < zadnji; k++) {
        printf("%d ", *k); //izpi¡se: 9 15 5 77 6 2
    }

}
