/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

void skalarnoMnozenje(double m[M][N], int k){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            m[i][j] *= k;
        }
    }
}

void prikaziMatriko(double m[M][N]){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            printf("\t%.1lf", m[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    double m[M][N] = {{2.3, 1.9, 2.0},
                      {3.1, 0.4, 11.7}};

    int k = 2;

    printf("m:\n");
    prikaziMatriko(m);

    skalarnoMnozenje(m, k);

    printf("\n%d*m:\n", k);
    prikaziMatriko(m);

    return 0;
}
