/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>

#define MSG_LEN 100
int main()
{
    int i, mode;
    char msg[3*MSG_LEN], key[3*MSG_LEN], *ptr_key, * ptr_msg;
    unsigned char key_val[MSG_LEN], msg_val[MSG_LEN];

    printf("Izberi nacin:\n 1 - sifriraj\n 2 - desifriraj\n");
    scanf("%d", &mode);
    while( getchar() != '\n' );

    printf("Vnesi sporocilo:\n");
    gets((char *)msg);
    printf("Vnesi kljuc (enake dolzine kot sporocilo):\n");
    gets((char *)key);

    if(mode == 1){
        printf("Sifrirano sporocilo:\n");
        for(i = 0, ptr_key = key; *ptr_key != '\0' && msg[i] != '\0'; i++){
            key_val[i] = strtol(ptr_key, &ptr_key, 16);
            printf("%X ", key_val[i] ^ msg[i]);
        }
    }else if(mode == 2){
        printf("Desifrirano sporocilo:\n");
        for(i = 0, ptr_msg = msg, ptr_key = key; *ptr_msg != '\0' && ptr_key != '\0'; i++){
            msg_val[i] = strtol(ptr_msg, &ptr_msg, 16);
            key_val[i] = strtol(ptr_key, &ptr_key, 16);
            printf("%c", key_val[i] ^ msg_val[i]);
        }
    }

    return 0;
}
