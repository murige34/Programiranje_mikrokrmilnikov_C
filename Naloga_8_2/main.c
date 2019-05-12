/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

struct vozlisce {
    int podatek;
    struct vozlisce *naslednji;
};

struct vozlisce *dodajVozlisce(struct vozlisce *seznam, int n){
    struct vozlisce *novoVozlisce = malloc(sizeof(struct vozlisce));
    if (novoVozlisce == NULL) {
        printf("NAPAKA: pomnilnik");
        exit(EXIT_FAILURE);
    }
    novoVozlisce->podatek = n;
    novoVozlisce->naslednji = seznam;
    return novoVozlisce;
}

struct vozlisce *brisiVozlisce(struct vozlisce *seznam, int *n){
    if( seznam == NULL){
        return NULL;
    }else{
        struct vozlisce *prvi = seznam->naslednji;
        *n = seznam->podatek;
        free(seznam);
        return prvi;
    }
}

int main()
{
    struct vozlisce *prvi = NULL, *tmp;
    int i, n;

    for (i = 0; i < 5; i++){
        prvi = dodajVozlisce(prvi, i + 1);
    }

    prvi = brisiVozlisce(prvi, &n); //n zdaj hrani vrednost, ki je


    // ker nocemo spreminjati originalne strukture, naredimo kopijo kazalca
    tmp = prvi;
    for(; tmp != NULL;){
        printf("%d\n", tmp->podatek);
        tmp = tmp->naslednji;
    }

    return 0;
}
