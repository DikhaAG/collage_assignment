#include <stdio.h>

int main() {
    char name[20];
    puts("Enter your name :");
    scanf("%19s", name);
    printf("Hello, %s \n", name);
    return 0;
}