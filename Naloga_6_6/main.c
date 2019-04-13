/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.6: izracun drsecega povprecja
*/

#include <stdio.h>
#include <stdlib.h>

#define N 7

// funkcija za izracun drsecega povprecja
// param:   dp[] .. tabela, v katero se shrani rezultat (drs. povprecje)
//          t[]  .. tabela z originalnim zaporedjem
//          dolz .. dolzina tabele t
//          n   ... velikost okna (st. vzorcev, ki jih vzamemo za povprecje)
// vrne:    dolzino tabele dp
int drsPovp(double dp[], double t[], int dolz, int n){
    int i, j;
    for(i = 0; i <= dolz-n; i++){
        dp[i] = 0;
        for(j = 0; j < n; j++){
            dp[i] += t[i+j];
        }
        dp[i] /= n;
    }
    return i;
}

int main()
{
    int i, length;
    double dp[N], t[N] = {1, 2, 3, 5, 9, 14, 66};

    length = drsPovp(dp, t, N, 3);
    for(i = 0; i < length; i++)
        printf("%.1lf, ", dp[i]);

    return 0;
}
