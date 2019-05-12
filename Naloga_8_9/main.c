/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IME_SIZE 20

// linked list struktura
struct kontakt{
    char ime[IME_SIZE + 1];
    long stev;
    struct kontakt *naslednji;
};

struct kontakt *dodajKontakt(struct kontakt *seznam, char *ime, long stev){
    struct kontakt *novKontakt = malloc(sizeof(struct kontakt));
    if (novKontakt == NULL) {
        printf("NAPAKA: pomnilnik");
        exit(EXIT_FAILURE);
    }
    strcpy(novKontakt->ime, ime);
    novKontakt->stev = stev;
    novKontakt->naslednji = seznam;

    return novKontakt;
};

// vrne NULL ptr, ce kontakta s tem imenom ne najde
struct kontakt *isciKontakt(struct kontakt *seznam, char *ime){
    struct kontakt *kont = seznam;

    while( kont != NULL ){
        if( strcmp(kont->ime, ime) == 0 ){
            break;
        }
        kont = kont->naslednji;
    }
    return kont;
};

void izpisiKontakte(struct kontakt *seznam){
    struct kontakt *kont = seznam;

    while( kont != NULL ){
        printf("%s: %ld\n", kont->ime, kont->stev);
        kont = kont->naslednji;
    }
};

int main()
{
    int izbira;
    char buff[IME_SIZE + 1];
    long stev;
    struct kontakt *prvi = NULL, *tmp;

    while(1){
        printf("Ukaz (1-isci, 2-dodaj/spremeni, 3-izpisi vse, 4-izhod): ");
        scanf("%d", &izbira);

        while ( getchar() != '\n' );

        if(izbira < 1 || izbira > 4){
            printf("Napacen vnos.\n");
        }else if(izbira == 4){
            break;
        }else if(izbira == 3){
            izpisiKontakte(prvi);
        }else if(izbira == 2){
            // dodaj/spremeni
            printf("Vnesi ime: ");
            scanf("%s", buff);

            if( (tmp = isciKontakt(prvi, buff)) != NULL){
                printf("Trenutna stevilka: %ld\n", tmp->stev);
            }

            printf("Vnesi novo stevilko: ");
            scanf("%ld", &stev);

            if(getchar() != '\n'){
                // pocistic input buffer, ce uporabnik vnesel besedilo namesto stevilk
                while ( getchar() != '\n' );

                printf("Err. napacen vnos.\n");
            }else{
                // veljaven vnos stevilke
                if( tmp != NULL){
                    // kontakt ze obstaja, spremenis
                    tmp->stev = stev;
                }else{
                    // kontakt ne obstaja, dodas
                    prvi = dodajKontakt(prvi, buff, stev);
                }
            }
        }else if(izbira == 1){
            // isci
            printf("Vnesi ime: ");
            scanf("%s", buff);
            if( (tmp = isciKontakt(prvi, buff)) != NULL){
                printf("%09ld\n", tmp->stev);
            }else{
                printf("Kontakt s tem imenom ne obstaja.\n");
            }
        }
    }

    printf("Nasvidenje!\n");

    return 0;
}
