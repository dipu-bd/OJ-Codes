#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num1[230];
char num2[230];
char res[230];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("713.inp", "r", stdin);
#endif

    int N;
    register int k, l;
    scanf("%d", &N);

    while(N--)
    {
        scanf(" %s %s", num1, num2);
        l = 0;
        for(int l1 = strlen(num1), l2 = strlen(num2),
                i = 0, j = 0, carry = 0; i < l1 || j < l2 || carry; ++i, ++j, ++l)
        {
            carry += (i < l1 ? num1[i] - '0' : 0) + (j < l2 ? num2[j] - '0' : 0);
            res[l] = carry % 10  + '0';
            carry /= 10;
        }

        k = res[l] = 0;
        while(*(res + k) == '0') ++k;
        puts(res + k);
    }

    return 0;
}
