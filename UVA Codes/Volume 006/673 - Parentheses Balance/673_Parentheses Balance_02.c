#include <stdio.h>
#include <string.h>

char str[150];

int isvalid(void)
{
    char c, d;
    int i, j, l;
    j = l = strlen(str);

    while(j--)
    {
        c = str[j];
        if(c == '(' || c == '[')
        {
            d = (c == '(') ? ')' : ']';

            i = j + 1;
            while(str[i] == ' ') ++i;

            if(str[i] == d) str[i] = ' ';
            else return 0;

            str[j] = ' ';
        }
    }

    while(l--)
        if(str[l] != ' ') return 0;

    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("673_Parentheses Balance_01.inp", "r", stdin);
#endif

    int n;
    sscanf(gets(str), "%d", &n);
    while(n--)
    {
        gets(str);
        if(isvalid()) puts("Yes");
        else puts("No");
    }

    return 0;
}
