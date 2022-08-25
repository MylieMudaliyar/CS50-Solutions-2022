#include<stdio.h>
int main(void)
{
   int collatz(int n , int count)
   {
    if(n == 1)
    {
        return count;
    }
    else if((n % 2 ) == 0)
    {
        return collatz(n / 2 , count + 1);
    }

    else
    {
        return collatz((3*n) + 1 , count + 1);
    }
   }
   printf("%i\n",collatz(6 , 0));
}

