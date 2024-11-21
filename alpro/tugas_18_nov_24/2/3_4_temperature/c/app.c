#include <stdio.h>
#include <stdbool.h>

void exitOpt (bool *isExit) {
    char opt;
option:
    fflush(stdin);
    printf("kembali ke utama? [Y/N] \n=> ");
    scanf("%c", &opt);
    switch (opt) {
    case 'Y':
        *isExit = true;
        break;
    case 'N':
        *isExit = false;
        break;
    default:
        printf("cannot read %c\n", opt);
        goto option;
        break;
    }
}
void getFloatInput(char *prompt, float *store) {
    int scanResult;
    char nextCharInput;
input:
    printf("%s : ", prompt);
    fflush(stdin);
    scanResult = scanf("%f%c", store, &nextCharInput);
    if (scanResult == 0 || nextCharInput != '\n') {
        puts("please input a valid number!");
        goto input;
    }
}
float F(float *c) {
    return ((5/9) * *c) + 32;
}
void CtoF() {
    bool isExit = false;
    do {
        float c;
        getFloatInput("C", &c);
        printf("=> %fF\n", F(&c));
        exitOpt(&isExit);
    } while (!isExit);
}
float C(float *f) {
    return (9/5) * (*f - 32);
}
void FtoC() {
    bool isExit = false;
    do {
        float f;
        getFloatInput("F", &f);
        printf("=> %fF\n", C(&f));
        exitOpt(&isExit);
    } while (!isExit);
}
int main() {
    bool isExit = false;
    do {
        int opt;
        puts("Pilih :");
        puts("1. Konversi Celcius ke Fahrenheit");
        puts("2. Konversi Fahrenheit ke Celcius");
        puts("3. Keluar");
    option:
        printf("=> ");
        fflush(stdin);
        scanf("%d", &opt);
        switch (opt){
        case 1:
            CtoF();
            break;
        case 2:
            FtoC();
            break;
        case 3:
            isExit = true;
            break;
        default:
            printf("cannot read %d\n", opt);
            goto option;
            break;
        }
    } while (!isExit);
    return 0;
}