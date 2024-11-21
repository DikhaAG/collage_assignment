#include <stdio.h>

int main() {
    int r;
    const float pi = 3.14;
    printf("input r : ");
    scanf("%d", &r);
    printf("keliling : %f\n", (pi * r * r));
    return 0;
}