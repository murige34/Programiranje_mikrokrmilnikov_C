/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

#define ST_ZNAKOV 20

typedef struct{
    char ime[ST_ZNAKOV + 1];
    unsigned long tel;
}vnos;

vnos imenik[] = {{"Janez",      41555666},
                 {"Tristan",    30652853},
                 {"Jasminka",   40761845},
                 {"Janko",      51764981},
                 {"Terezija",   41888656}};

int main()
{
    char vnos[ST_ZNAKOV + 1];
    int i, j, dolzina;
    dolzina = sizeof(imenik)/sizeof(imenik[0]);

    while(1){
        printf("Isci (0 konca): ");
        gets(vnos);

        if(vnos[0] == '0')    break;

        for(i = 0; i < dolzina; i++){
            for(j = 0; imenik[i].ime[j] == vnos[j] && vnos[j] != '\0'; j++);

            if(vnos[j] == '\0'){
                printf("   %s\t%ld\n", imenik[i].ime, imenik[i].tel);
            }
        }
    }

    printf("Nasvidenje!");
    return 0;
}
