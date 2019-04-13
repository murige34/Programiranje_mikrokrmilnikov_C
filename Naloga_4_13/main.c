/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.13: Preverjanje pravilnosti oklepajev in zaklepajev
//
// Napisite program, ki z vhoda bere poljubne izraze in na izhod sporoci,
// ce se oklepaji in zaklepaji v izrazu ne ujemajo. Program naj se konca, ko vnesemo
// prazen izraz (t.j. zgolj pritisnemo potrditveno tipko).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, oklepaji;
    char znak;

    while(1){
        printf("Vnesi izraz (prazen izraz konca): ");
        scanf("%c", &znak);
        if(znak == '\n') break;

        oklepaji = 0;
        for(i = 1; znak != '\n'; i++){
            if(znak == '(') oklepaji++;
            if(znak == ')') oklepaji--;

            if(oklepaji < 0){
                while(znak != '\n') scanf("%c", &znak);
                break;
            }
            scanf("%c", &znak);
        }

        if(oklepaji == 0){
            printf("Ni napak.\n");
        }else if(oklepaji < 0){
            printf("Napaka: zaklepaj na %d. tem mestu.\n", i);
        }else{
            printf("Napaka: manjka zaklepaj.\n");
        }
    }

    printf("Nasvidenje!\n");
    return 0;
}
