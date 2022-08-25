#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if there are 2 arguments in command line ( including file name)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check if argv[1] only has digits
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert string argv into int
    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    //string ciphertext = "";

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // For small alphabets
        if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 97 + k) % 26) + 97);
        }
        // For capital alphabets
        else if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 65 + k) % 26) + 65);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}
