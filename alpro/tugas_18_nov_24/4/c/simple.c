#include <stdio.h>
int main() {
    const int p = 2;
    double totalHarga;
    double totalBayar;
    printf("input total byr : ");
    scanf("%lf", &totalHarga);
    totalBayar = ((double)totalHarga + (((double)2/(double)100) * (double)totalHarga));
    printf("total yang harus dibayar (pajak %d persen) : \nRp %lf\n", p, totalBayar);
    return 0;
}