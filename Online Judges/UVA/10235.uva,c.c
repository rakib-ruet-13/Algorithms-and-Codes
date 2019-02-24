#include<stdio.h>
#include<math.h>

int main()
 {
 long int  num;
while(scanf("%ld",&num)==1 )
    {
    if (check_prime(num)!=1)
     printf ("%ld is not prime.\n", num);
  else
    {
        int  k=revers(num);
    if ( check_prime(k)==1 && k!=num)
                printf ("%ld is emirp.\n",num);

            else
                printf ("%ld is prime.\n",num);
        }
    }
    return 0;
  }

  int revers(unsigned int num)
  {
    unsigned int r = 0;
    do
        r = r * 10 + num % 10;
    while ((num /= 10) > 0);
    return r;
  }

int check_prime (long int num)
 { int i;
    for ( i = 2; i * i <= num; i++)
    {
    if (num % i == 0)
    return 0;
    }
    return 1;
   }

