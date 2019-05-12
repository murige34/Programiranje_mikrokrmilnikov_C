/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

#define N 2

void matricniProdukt(int m1[N][N], int m2[N][N]){
    int i, j, k;
    int m1_c[N][N];
    // ustvaris kopijo m1, preden m1 prepises
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            m1_c[i][j] = m1[i][j];
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            m1[i][j] = 0;
            for(k = 0; k < N; k++){
                m1[i][j] += m1_c[i][k]*m2[k][j];
            }
        }
    }

}

void prikaziMatriko(int m[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m1[N][N] = {{1, 2},
                    {5, 4}};
    int m2[N][N] = {{-3, 5},
                    {1, -2}};
    printf("m1:\n");
    prikaziMatriko(m1);
    printf("m2:\n");
    prikaziMatriko(m2);

    matricniProdukt(m1, m2);
    printf("m1*m2:\n");
    prikaziMatriko(m1);
    return 0;
}
