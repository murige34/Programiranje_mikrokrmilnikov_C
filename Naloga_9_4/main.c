/* ---------------- Programiranje C ---------------------
// Programiranje mikrokrmilnikov, demonstrator 2018/2019
// Programiranje II, demonstrator 2018/2019
// Martin Urigelj
*/

#include <stdio.h>
#include <stdlib.h>


unsigned short f(unsigned short x, int m, int n){
    return (x >> m) & ~(~0 << (n - m + 1));
}
int main()
{
    printf("%u", f(8,1,1));
    return 0;
}
