#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Number of rows
    int n;

   do
   {
    // Take input from user
      n = get_int("Height: ");
   } while (n < 1 || n > 8);

    // For n rows
    for (int i = 1; i <= n; i++)
    {
     // For spaces triangle
        for (int j = 1; j <= n-i ; j++)
        {
            printf(" ");
        }

        // For # triangle
        for (int j = n; j >= n-i+1 ; j--)
        {
            printf("#");
        }

       //For a blank gap betwn 2 triangles
       printf("  ");

       // For 2nd # triangle
       for (int j = 1; j <= i ; j++)
       {
           printf("#");
       }
       printf("\n");
    }
}
