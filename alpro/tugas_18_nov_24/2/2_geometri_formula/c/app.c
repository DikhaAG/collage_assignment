#include <stdio.h>
#include <stdbool.h>

void getIntInput(char *prompt, int *store) {
    int scanResult;
    char nextCharInput;
input:
    printf("%s : ", prompt);
    scanResult = scanf("%d%c", store, &nextCharInput);
    if (scanResult == 0 || nextCharInput != '\n')
    {
        puts("please input a valid number!");
        fflush(stdin);
        goto input;
    }
    
    fflush(stdin);
}
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

typedef struct {
    int side;
    int area;
} BujurSangkar;
void calculateBujurSangkarArea() {
    bool isExit = false;
    do {
        BujurSangkar bs;
        puts("------BUJUR SANGKAR------");
        getIntInput("sisi", &bs.side);
        bs.area = bs.side * bs.side;
        printf("Area : %d cm^2\n", bs.area);
        exitOpt(&isExit);
    } while (!isExit);
}
typedef struct {
    int bottom, height;
    float area;
} Triangle;
void calculateTriangleArea() {
    bool isExit = false;
    do {
        Triangle t;
        puts("------Segitiga------");
        getIntInput("alas", &t.bottom);
        getIntInput("tinggi", &t.height);
        t.area = (t.bottom * t.height) / 2;
        printf("Area : %f cm^2\n", t.area);
        exitOpt(&isExit);
    } while (!isExit);
}
typedef struct {
    int longBase, shortBase, height;
    float area;
} Trapezoid;
void calculateTrapezoidArea() {
    bool isExit = false;
    do {
        Trapezoid t;
        puts("------Trapesium------");
        getIntInput("basis panjang", &t.longBase);
        getIntInput("basis pendek", &t.shortBase);
        getIntInput("tinggi", &t.height);
        t.area = ((t.longBase + t.shortBase) / 2) * t.height;
        printf("Area : %f cm^2\n", t.area);
        exitOpt(&isExit);
    } while (!isExit);
}

int main() {
    bool isExit = true;
    do {
        int opt;
        puts("Pilih : ");
        puts("1. Bujur sangkar");
        puts("2. Segitiga");
        puts("3. Trapesium");
        puts("4. Keluar");
        printf("=> ");
        fflush(stdin);
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            calculateBujurSangkarArea();
            break;
        case 2:
            calculateTriangleArea();
            break;
        case 3:
            calculateTrapezoidArea();
            break;
        case 4:
            isExit = false;
            break;
        default:
            puts("choose a valid option");
            break;
        }
    } while (isExit);
}