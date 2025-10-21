#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage. Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");

    // Check if file exists
    if (file == NULL)
    {
        printf("No such file found\n");
        return 1;
    }

    // Read buffer and get JPEG Signature

    unsigned char buffer[512];
    int contador = 0;

    FILE *output = NULL;
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, file) == 512)
    {
        // Read buffer and get JPEG Signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (contador > 0)
            {
                fclose(output);
            }

            // Write the JPEG filenames
            sprintf(filename, "%03i.jpg", contador);

            // Open output_file for writing
            output = fopen(filename, "w");

            // count number of image found
            contador++;
        }
        // Check if output have been used for valid input
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }

    // close and free memory :D 
    fclose(file);
    fclose(output);
    free(filename);



}