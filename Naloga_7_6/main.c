/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, st_znakov = 0;
    char besede[][13] = {"ena", "enajst", "enaindvajset", "konec"};

    int st_besed = sizeof(besede)/sizeof(besede[0]);

    for(i = 0; i < st_besed; i++){
        st_znakov += strlen(besede[i]);
        //printf("%d\n", st_znakov);
    }

    printf("St. znakov: %d\n", st_znakov);
    return 0;
}
