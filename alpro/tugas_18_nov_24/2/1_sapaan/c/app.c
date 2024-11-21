#include <stdio.h>

typedef struct {
    char name[20], city[20];
} Person;
void greeting(Person *person) {
    printf("Senang bertemu dengan mu, %s, dikota %s\n", person->name, person->city);
}
int main() {
    Person person;
    puts("Hola, siapa nama-mu?");
    scanf("%19s", person.name);
    fflush(stdin);
    puts("Dikota apa kamu sekarang?");
    scanf("%19s", person.city);
    fflush(stdin);
    greeting(&person);
    return 0;
}