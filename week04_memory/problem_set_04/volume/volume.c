// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
// Size of samples in .wav file
const int SAMPLE_SIZE = 2;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Create a buffer for copying the header
    uint8_t *header_buffer = malloc(HEADER_SIZE);
    if (header_buffer == NULL)
    {
        printf("Could not create buffer.\n");
        return 2;
    }

    // Copy
    fread(header_buffer, HEADER_SIZE, 1, input);
    fwrite(header_buffer, HEADER_SIZE, 1, output);

    // Release memory
    free(header_buffer);

    // TODO: Read samples from input file and write updated data to output file
    // Create a buffer for samples
    int16_t *sample_buffer = malloc(SAMPLE_SIZE);
    if (sample_buffer == NULL)
    {
        printf("Could not create buffer.\n");
        return 2;
    }

    // Keep reading the file while there is still data
    while (fread(sample_buffer, SAMPLE_SIZE, 1, input))
    {
        // Scale the sample
        *sample_buffer *= factor;

        // Write the scaled sample
        fwrite(sample_buffer, SAMPLE_SIZE, 1, output);
    }

    // Release memory
    free(sample_buffer);

    // Close files
    fclose(input);
    fclose(output);
}
