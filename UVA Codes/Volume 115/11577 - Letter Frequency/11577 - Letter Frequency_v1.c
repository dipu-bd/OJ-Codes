#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int freq[26];
char inp[250];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11577.inp", "r", stdin);
#endif

    int n, i, m;
    char c;
    scanf("%d", &n);

    while(n--)
    {
        scanf(" %[^\n]", inp);
        memset(freq, 0, sizeof(freq));
        for(i = m = 0; c = *(inp + i); ++i)
        {
            if(isalpha(c))
            {
                c = tolower(c) - 'a';
                if(++freq[c] > m)
                    m = *(freq + c);
            }
        }

        for(i=0; i<26; ++i)
            if(freq[i]==m)
                putchar(i+'a');
        putchar('\n');
    }

    return 0;
}
