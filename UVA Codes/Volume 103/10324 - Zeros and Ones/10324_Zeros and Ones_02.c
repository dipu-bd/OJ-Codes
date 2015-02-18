#include <stdio.h>

#define SIZE 1000010
int array[SIZE];
char inp[SIZE];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10324_Zeros and Ones_02.inp", "r", stdin);
#endif

    char c, d;
    int i, j, m, len, cc = 1;

    while(scanf(" %[^\n]", inp) != EOF)
    {
        /* set sequence numbers */
        array[0] = i = 0;
        for(c = inp[0], len=1; inp[len]; ++len)
        {
            d = inp[len];
            if(c != d) ++i;
            array[len] = i;
            c = d;
        }

        /* get input and print */
        printf("Case %d:\n", cc++);

        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &i, &j);
            if (array[i] == array[j]) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
