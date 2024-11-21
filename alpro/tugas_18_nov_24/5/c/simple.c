#include <stdio.h>
int main() {
    int gajiBersih, gajiPokok, jumlahAnak;
    int tunjanganAnak = 100000;
    int tunjanganIstri = 300000;
    printf("input gaji pokok : ");
    scanf("%d", &gajiPokok);
    printf("input jumlah anak : ");
    scanf("%d", &jumlahAnak);
    gajiBersih = gajiPokok + (tunjanganAnak * jumlahAnak) + tunjanganIstri;
    printf("gaji bersih : %d\n", gajiBersih);
    return 0;
}