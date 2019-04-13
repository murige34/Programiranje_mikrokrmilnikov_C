#include <stdio.h>
#include <stdlib.h>

int main()
{
    char znak;
    int z = 0, pz = 0, ppz = 0; // zadnja, predzadnja in predpredzadnja cifra
    unsigned long vsota = 0;

    printf("Vnesi naravno stevilo: ");

    while(1){
        scanf("%c", &znak);
        if(znak == '\n'){   break;
        }else if(znak >= '0' && znak <= '9'){
            ppz = pz;
            pz = z;
            z = znak - '0';

            vsota += z;
        }else{
            printf("Neveljaven vnos!\n");
            return 0;
        }
    }

    if(z % 2 == 0)  printf("... je deljivo z 2.\n");
    else    printf("... ni deljivo z 2.\n");

    if(vsota % 3 == 0)  printf("... je deljivo z 3.\n");
    else    printf("... ni deljivo z 3.\n");

    if((pz*10+z) % 4 == 0)  printf("... je deljivo z 4.\n");
    else printf("... ni deljivo z 4.\n");

    if(z % 5 == 0)  printf("... je deljivo z 5.\n");
    else    printf("... ni deljivo z 5.\n");

    if(vsota % 3 == 0 && z % 2 == 0)  printf("... je deljivo z 6.\n");
    else    printf("... ni deljivo z 6.\n");

    if((ppz*100 + pz*10 + z) % 8 == 0)  printf("... je deljivo z 8.\n");
    else printf("... ni deljivo z 8.\n");

    if(vsota % 9 == 0)  printf("... je deljivo z 9.\n");
    else    printf("... ni deljivo z 9.\n");

    if(z == 0)  printf("... je deljivo z 10.\n");
    else    printf("... ni deljivo z 10.\n");

    if((pz*10+z) % 25 == 0)  printf("... je deljivo z 25.\n");
    else printf("... ni deljivo z 25.\n");

    return 0;
}
