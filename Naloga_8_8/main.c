/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ST_ZNAKOV 20
#define MAX_BESED 10

int compare(const void *a, const void *b){
    return strcmp(a, b);
}

int main()
{
    char vnos[MAX_BESED][ST_ZNAKOV + 1];
    int st_besed, i;

    printf("Vnesi do 10 angleskih besed: (0 - konca vnos)\n");
    for(st_besed = 0; st_besed < MAX_BESED; st_besed++){
        printf("%2d: ", st_besed + 1);
        gets(vnos[st_besed]);
        if(vnos[st_besed][0] == '0')    break;
    }

    qsort(vnos, st_besed, sizeof(vnos[0]), compare);

    printf("Urejeni po abecedi:\n");
    for(i = 0; i < st_besed; i++){
        printf("%2d: %s\n", i + 1, vnos[i]);
    }
    return 0;
}
