#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

#define SIZ 1000000

char flag[SIZ];
vector<int> factor[SIZ];

void push(int n, int p)
{
    for(int q = n; q % p == 0; q /= p)
    {
        factor[n].push_back(p);
    }
}

void mark(int p)
{
    for(int i = p; i <= SIZ; i += p)
    {
        flag[i] = 1;
        push(i, p);
    }
}

void factosieve()
{
    mark(2);
    for(int i = 3; i <= SIZ; i += 2)
        if(!flag[i]) mark(i);
}

int main()
{
    time_t t1, t2;
    t1 = clock();
    factosieve();
    t2 = clock();
    printf("Pregenerated all. Time %.3lf seconds\n\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    int n;
    while(true)
    {
        printf("Give a number ( < %d ) : ", SIZ);
        scanf("%d", &n);

        printf("Factors of %d = ", n);
        for(int i = 0; i < factor[n].size(); ++i)
        {
            if(i > 0) putchar('*');
            printf("%d", factor[n][i]);
        }
        printf("\n\n");
    }

    return 0;
}
