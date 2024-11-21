#include <stdio.h>

typedef struct{
    int r;
    float circumference;
} Circle;
void calculateCircumference(Circle *c) {
    const float pi = 3.14;
    puts("------- Calculating... ------");
    printf("r: %d \n", c->r);
    printf("pi: %f \n", pi);
    c->circumference = pi * c->r * c->r;
}
void getInput(char *prompt, int *store) {
    printf("%s :", prompt);
    scanf("%d", store);
}
int main() {
    Circle circle;
    puts("Calculate the circumference of circle");
    getInput("r", &circle.r);
    calculateCircumference(&circle);
    printf("circumference: %f cm^2 \n", circle.circumference);
    return 0;
}