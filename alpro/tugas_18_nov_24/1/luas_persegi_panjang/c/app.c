#include <stdio.h>

typedef struct{
    int width, height;
    float area;
} Rectangle;
void calculateArea(Rectangle *r) {
    puts("------- Calculating... ------");
    r->area = r->width * r->height;
}
void getInput(char *prompt, int *store) {
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
int main() {
    Rectangle rectangle;
    puts("Calculate the area of Rectangle");
    getInput("width", &rectangle.width);
    getInput("height", &rectangle.height);
    calculateArea(&rectangle);
    printf("area: %f \n", rectangle.area);
    return 0;
}