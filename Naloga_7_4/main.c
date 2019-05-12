/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>

#define M 3
#define N 4

int maks(int *t, int dolzina){
    int i, max = *t;
    for(i = 0; i < dolzina; i++){
        if( t[i] > max){
            max = t[i];
        }
    }
    return max;
}

int main(void){
    int a[M][N] = {{ 1, 8, 11},
                   { 9, -34},
                   { 55, 92, 1, 13}};
    printf("%d", maks( (int *)&a, M*N)); //izpise: 92

    return 0;
}
