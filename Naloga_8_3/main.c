/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>


#define D 9

typedef struct{
    char niz[D+1];
    int dolz;
} mojNiz;

/* // prof. resitev
void nastaviNiz(mojNiz *p, char *vhodniNiz){
    char *k1, *k2;
    int i;

    for( k1=vhodniNiz, k2=p->niz, i=0; *k1 != '\0' && i < D; k1++, k2++, i++){
        *k2 = *k1;
    }
    *k2 = '\0';

    p->dolz = i;
}
*/

void nastaviNiz(mojNiz *p, char *vhodniNiz){
    int i;

    for( i=0; vhodniNiz[i] != '\0' && i < D; i++){
        p->niz[i] = vhodniNiz[i];
    }
    p->niz[i] = '\0';

    p->dolz = i;
}

/* // prof. resitev
int izlociPresledke(mojNiz *p){
    char *k1, *k2;
    int i;
    for(k1=k2 = p->niz, i = 0; *k1 != '\0'; k1++){
        if(*k1 != ' ')  *k2++ = *k1;
        else i++;
    }
    *k2 = '\0';

    // dolocimo novo dolzino
    p->dolz -= i;

    // vrnemo stevilo presledkov
    return i;
}
*/

int izlociPresledke(mojNiz *p){
    char *k1, *k2;
    for(k1=k2 = p->niz; *k1 != '\0'; k1++){
        if(*k1 != ' ')  *k2++ = *k1;
    }
    *k2 = '\0';

    // dolocimo novo dolzino
    p->dolz -= k1-k2;

    // vrnemo stevilo presledkov
    return k1-k2;
}


int main()
{
    mojNiz s1;
    nastaviNiz(&s1, "a b c d e f");
    printf("%s - %d\n", s1.niz, s1.dolz); //izpi¡se: a b c d e - 9
    printf("%d\n", izlociPresledke(&s1)); //izpi¡se: 4
    printf("%s - %d\n", s1.niz, s1.dolz); //izpi¡se: abcde - 5
    return 0;
}
