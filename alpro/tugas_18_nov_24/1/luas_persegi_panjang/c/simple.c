#include <stdio.h>
int main() {
    int p, l;
    printf("input panjang : ");
    scanf("%d", &p);
    printf("input lebar : ");
    scanf("%d", &l);
    printf("luas : % dcm^2\n", (p*l));
    return 0;
}