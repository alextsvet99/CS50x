#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check the first few bytes of a file
    string filename = argv[1];
    FILE *f = fopen(filename, "r");
    uint8_t buffer[4]; // an unsigned integer of 8-bit length
    int blocks_read = fread(buffer, 1, 4, f);
    printf("Blocks read: %i\n", blocks_read);

    for (int i = 0; i < 4; i++)
    {
        printf("%i ", buffer[i]);
    }
    printf("\n");

    fclose(f);
    return 0;
}
