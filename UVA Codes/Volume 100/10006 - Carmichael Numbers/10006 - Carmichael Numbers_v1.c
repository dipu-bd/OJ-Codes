#include <stdio.h>
#include <stdlib.h>

int car[] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

int main()
{
    int n, i;

    while(scanf("%d", &n) != EOF && n)
    {
        for(i = 0; i<15; ++i)
            if(car[i]==n) goto print_car;
            else if(car[i]>n) goto print_not;

        print_not : { printf("%d is normal.\n", n); continue; }
        print_car : { printf("The number %d is a Carmichael number.\n", n); }
    }

    return 0;
}
