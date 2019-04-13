
// definicije funkcij se nahajajo v .c datoteki

int sestej(int *st1, int *im1, int st2, int im2){
    int im1_cpy = *im1;
    *st1 = *st1 * im2 + st2 * *im1;
    *im1 = im1_cpy * im2;
    return 0;
}

int zmnozi(int *st1, int *im1, int st2, int im2){
    *st1 = *st1 * st2;
    *im1 = *im1 * im2;
    return 0;
}

int krajsaj(int *st, int *im){
    int i;
    for(i = 2; i <= *im; i++){
        while(*st%i == 0 && *im%i == 0){
            *st /= i;
            *im /= i;
        }
    }
    return 0;
}
