#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
 
int main(int argc, char *argv[])
{

    // Checks for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *memory_card = fopen(argv[1], "r");

    // Checks if memory card was accessed
    if (memory_card == NULL)
    {
        printf("Could not open memory card\n");
        return 1;
    }

    //Sets counter to control how many JPEGs were created, a buffer to read the information, sets a pointer to a place in memory for keeping the images, sets to NULL until fread finds a new JPEG file
    int jpeg_count = 0;
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8]; //###.jpg + /0

    // While there's still data to read in the memory card
    while (fread(buffer, 1, BLOCK_SIZE, memory_card) == BLOCK_SIZE)
    {
        // If it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If it's the first JPEG - Checks if there's another file openned
            if (img != NULL)
            {
                fclose(img);
                jpeg_count++;
            }

            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "w");


            // Checks if the file were created correctly
            if (img == NULL)
            {
                printf("Couldn't create image file %s\n", filename);
                fclose(memory_card);
                return 1;
            }

            // Write to the new file
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }

        // If the block of 512 bytes isn't a new JPEG header, but there's still data to read
        else if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    fclose(img);
    fclose(memory_card);

    return 0;
 
}