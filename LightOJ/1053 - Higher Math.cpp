#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 40000
int sqr[MAX + 10];

void precalc()
{
    for(int i = 1; i <= MAX; ++i)
        sqr[i] = i * i;
}

int main()
{
    precalc();

    int test, cas = 1;
    int a, b, c;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", cas++);

        if(sqr[a] + sqr[b] == sqr[c] ||
                sqr[b] + sqr[c] == sqr[a] ||
                sqr[c] + sqr[a] == sqr[b])
            puts("yes");
        else puts("no");
    }

    return 0;
}
