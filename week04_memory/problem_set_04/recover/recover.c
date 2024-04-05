// Recovers JPEG images from a forensic image

// Includes
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Constants
// JPEG block size in bytes
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check the provided arguments
    if (argc != 2)
    {
        printf("Usage: ./recover <forensic_image>\n");
        return 1;
    }

    // Open the forensic image
    FILE *source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("Could not open image %s\n", argv[1]);
        return 1;
    }

    // Open a new image
    int image_count = 0;
    char *new_file = malloc(8);
    sprintf(new_file, "%03i.jpg", image_count);

    FILE *output = fopen(new_file, "w");
    if (output == NULL)
    {
        printf("Could not open image %s\n", new_file);
        return 1;
    }

    // Loop over blocks of 512 bytes of the image
    // Create a buffer
    uint8_t *buffer = malloc(BLOCK_SIZE);
    if (buffer == NULL)
    {
        printf("Could not create buffer.\n");
        return 2;
    }

    while (fread(buffer, 1, BLOCK_SIZE, source))
    {
        // Look for a signatue in the first four bytes (0xff 0xd8 0xff 0xe0 <= x <= 0xef)
        // If found
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] >= 224 &&
            buffer[3] <= 239)
        {
            // Stop writing the previous image
            fclose(output);

            // Start writing a new image
            sprintf(new_file, "%03i.jpg", image_count);
            output = fopen(new_file, "w");
            if (output == NULL)
            {
                printf("Could not open image %s\n", new_file);
                return 1;
            }
            fwrite(buffer, 1, BLOCK_SIZE, output);
            image_count++;
        }
        // If not found
        else
        {
            // Either continue looking
            // Or append to the started image
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    // Close files
    fclose(source);
    fclose(output);

    // Release memory
    free(new_file);
    free(buffer);
}
