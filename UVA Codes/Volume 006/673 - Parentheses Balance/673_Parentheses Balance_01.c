#include <stdio.h>
#include <string.h>

char str[150];

int isvalid(void)
{
    char c, d;
    int i, j, l;
    j = l = strlen(str);

    while(l--)
    {
        c = str[l];
        if(c == '(' || c == '[')
        {
            d = (c == '(') ? ')' : ']';

            for(i = l + 1; str[i]; ++i)
                if(str[i] != ' ')
                {
                    if(str[i] == d)
                    {
                        str[i] = ' ';
                        break;
                    }
                    else return 0;
                }
            if(!str[i]) return 0;

            str[l] = ' ';
        }
    }

    while(j--)
        if(str[j] != ' ') return 0;
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
