#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checking if 2 command line arguments present
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        // Check if argv[1] has digits
        if (!isalpha(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        for (int i = j + 1; i < strlen(argv[1]); i++)
        {
            // Checking if any duplicates in key
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    // Chexking if key length is more than 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string k = argv[1];

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // For small alphabets
        if (islower(plaintext[i]))
        {
            // If plaintext is in lower then cipher should also be even if key is upper
            printf("%c",tolower(k[(plaintext[i] - 'a') ]));
        }
        // For capital alphabets
        else if (isupper(plaintext[i]))
        {
            // If plaintext is in upper then cipher should also be even if key is upper
            printf("%c", toupper(k[(plaintext[i] - 'A')]));
        }
        else
        {
            // All other characters apart from alphabets to be printed as it is
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}