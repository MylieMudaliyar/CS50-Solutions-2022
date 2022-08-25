#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get card number
    long num = get_long("Number: ");

    // Checking length of card
    int count = 0;
    do
    {
        num = num / 10;
        count++;
    }

    while (num != 0);

    if (count != 13 && count != 14 && count != 16)
    {
        printf("INVALID\n");
    }

    else
    {

        // Main Checksum

        int mod1;
        int mod2;
        int d1;
        int d2;
        long n = num;
        int sum1 = 0;
        int sum2 = 0;
        int total = 0;

        do
        {
            // Extracting and Adding digits which weren't multiplied by 2 to sum

            // Eliminating last digit
            mod1 = n % 10;
            n = n / 10;
            sum1 = sum1 + mod1;

            // Eliminating 2nd last digit
            mod2 = n % 10;
            n = n / 10;

            // Extracting 2nd last digits and adding product digits to sum

            // Multiplying 2nd last digit by 2
            mod2 = mod2 * 2;

            // Taking individual digits of product
            // Suppose 12 -> d1 = 2 , d2 = 1
            d1 = mod2 % 10;
            d2 = mod2 / 10;
            sum2 = sum2 + d1 + d2;

        } while (n > 0);

        total = sum1 + sum2;
        printf("%li\n", total);

        // // Checking Luhn Algorithm
        // if (total % 10 != 0)
        // {
        //     printf("INVALID\n");
        //     return 0;
        // }

        // // Getting first 2 digits

        // long card = n;
        // do
        // {
        //    card = card / 10;
        // }
        // while (card > 100);

        // printf("%li\n", card);

        // // Checking card type
        // if ( card <= 55 && card >= 51)
        // {
        //     printf("MASTERCARD\n");
        // }

        // else if ( card == 34 || card == 37)
        // {
        //     printf("AMEX\n");
        // }

        // else if ( card / 10 == 4)
        // {
        //     printf("VISA\n");
        // }

        // else
        // {
        //     printf("INVALID\n");
        // }
    }
}