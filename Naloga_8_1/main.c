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

int main()
{
    struct vozlisce *prvi = NULL, *tmp;
    int i;

    for (i = 0; i < 5; i++){
        prvi = dodajVozlisce(prvi, i + 1);
    }

    // ker nocemo spreminjati originalne strukture, naredimo kopijo kazalca
    tmp = prvi;
    for(; tmp != NULL;){
        printf("%d\n", tmp->podatek);
        tmp = tmp->naslednji;
    }

    return 0;
}
