/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 6.2: funkcija vraca stevilo podvojenih vr. v tabeli t
*/

#include <stdio.h>
#include <stdlib.h>

#define N 12

int prestejDuplikate(int t[], int N){
    int i, j, st_dup = 0;
    for(i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            if(t[i] == t[j]){
                st_dup++;
                break;
            }
        }
    }
    return st_dup;
}

int main()
{
    int t[N] = {5, 9, 5, 2, 6, 77, 15, 5, 5, 77, 6, 2};
    printf("St. duplikatov: %d.\n", prestejDuplikate(t, N)); //izpise: 6

    return 0;
}
