// Run at your own risk!!!

#include <stdio.h>

int main(void)
{
    printf("Created an integer a:\n");
    int a = 50;
    printf(" a = %i \n&a = %p \n*a = invalid operation\n", a, &a);

    printf("\n");

    printf("Created a pointer p based on integer a:\n");
    int *p = &a;
    printf(" p = %p \n*p = %i \n&p = %p \n", p, *p, &p);

    printf("\n");

    printf("Created another pointer k and assigned it a random value using type casting:\n");
    int *k = (int *) 0x7ffe488e087c;
    printf(" k = %p \n*k = %i \n&k = %p \n", k, *k, &k);
}
