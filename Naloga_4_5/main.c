/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
// Lab. vaja 4.5: Logisticna preslikava
//
//
// Enacba logisticne preslikave:
// x(n+1) = r * x(n) * (1 - x(n))
//
// r med 0 in 1: populacija izumre
// r med 1 in 2: populacija se hitro ustali pri (r-1)/r
// r med 2 in 3: populacija zaniha, nato se hitro ustali pri (r-1)/r
// r med 3 in 1+sqrt(6) = 3.44949: populacija niha med dvema vrednostima
// r med 1+sqrt(6) in 3.54409: populacija niha med 4. vrednostmi
// r preko 3.54409: populacija zacne nihati med 8, 16, 32 itd. vrednostmi
// r preko 3.56995: populacija se ne ustali ali niha s periodo (sistem je kaoticen)
//
//    Kadar je sistem kaoticen, zaradi napak pri kodiranju in racunanju nikoli
//    ne moremo dobiti pravih rezultatov. Ce pa je sistem stabilen ali ce niha s stabilno amplitudo
//    in frekvenco, majhne napake v natancnosti niso usodne. Predelajte program
//    za racunanje logisticne preslikave s strani 53 tako, da bo zaznal stabilno stanje ali
//    stabilna nihanja s periodami do na primer 64. Ko boste zaznali periodo (t.j. ponovitev
//    dolocene vrednosti po dolocenem stevilu iteracij), pustite program se nekaj casa teci,
//    da se prepricate, ce se ta vrednost res ponavlja periodicno.
//
// Opomba: program ne najde vedno najmanjse periode (pri r = 3.54 vrne T=8 namesto T=4)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const int hist_size = 101; // dolocimo velikost spomina (omejimo najvisjo periodo, ki jo iscemo)
    unsigned long i, j;
    double x = 0.5, r; // zacetni x mora biti med 0 in 1
    double history[hist_size]; // spomin nekaj preteklih vrednosti
    int changed_T = 0, same_T = 0, T = 0; // stevec period (spremenjenih in ponovljenih)

    // Inicializacija zgodovine z niclami
    for(i = 0; i < hist_size; i++) history[i] = 0;

    printf("Vnesi r: ");
    scanf("%lf", &r);
    for (i = 0; i <= 20000; i++){
        x = r * x * (1 - x);
        printf("%.8lf\n", x);

        // zamaknes podatke za eno mesto, tako da imas na indeksu 0 zadnji podatek, na 1 predzadnjega...
        for(j = hist_size - 1; j > 0; j--) history[j] = history[j - 1];
        history[0] = x; // zapises trenutno vrednost na prvo mesto

        // Preverjanje, ce se pri kateri vrednosti ustali
        if(fabs(history[0] - history[1]) <= 1e-6*history[0]){
            printf("Stabilno stanje pri vrednosti %.10lf", x);
            return 0;
        }

        // Pregled preteklih vrednosti, iskanje periode, ce se vrednosti ponavljajo
        for(j = 2; j < hist_size; j++){
            // Iscemo ujemanje
            if(x == history[j]){
                // perioda je enaka, kot v prejsnjem koraku
                if(T == j){
                    printf("*\n"); // oznacimo ujemanje
                    if(++same_T > 2*T){ // Poiscemo zadostno stevilo ujemanj
                        printf("Stabilno nihanje s periodo %d", T);
                        return 0;
                    }
                }else if(changed_T++ > 2*hist_size){
                    // tukaj se ustavimo program, da se ne zacikla, ker ob ujemanju zmanjsamo i
                    // ce bi se T spreminjal, bi imeli neskoncno zanko
                    // NISEM preprican, ce je za dan sistem tak primer mozen(da bi se T spreminjal)
                    printf("Tezave pri dolocanju periode T");
                    return 0;
                }
                if(i > j) i -= j; // Preveris se nekaj period nihanja
                T = j;
                break; // ce smo nasli ujemanje, prekinemo nadaljne iskanje po zgodovini
            }
        }
    }

    printf("Sistem je kaoticen ali pa ima periodo nihanja vecjo od %d", hist_size);
    return 0;
}
