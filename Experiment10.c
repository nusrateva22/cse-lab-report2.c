#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    printf("Size of union Data = %d bytes\n\n", (int) sizeof(union Data));

    d.i = 65;
    printf("Assigned integer : i = %d\n", d.i);

    d.f = 3.5;
    printf("Assigned float   : f = %f\n", d.f);

    d.c = 'A';
    printf("Assigned char    : c = %c\n", d.c);

    printf("\nValues after the last assignment (d.c = 'A'):\n");
    printf("i = %d\n", d.i);
    printf("f = %f\n", d.f);
    printf("c = %c\n", d.c);

    return 0;
}