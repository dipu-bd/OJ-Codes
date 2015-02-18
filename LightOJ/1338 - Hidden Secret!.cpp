#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int test, cas = 1;

    int freq[150];
    char str1[150];
    char str2[150];

    cin >> test;
    while(test--)
    {
        scanf(" %[^\n] %[^\n]", str1, str2);

        memset(freq, 0, sizeof(freq));
        for(int i = 0; str1[i]; ++i)
            if(isalpha(str1[i]))
                ++freq[toupper(str1[i])];

        bool pos = true;
        for(int i = 0; pos && str2[i]; ++i)
            if(isalpha(str2[i]))
            {
                int& p = freq[toupper(str2[i])];
                if(p > 0) p--;
                else pos = false;
            }

        printf("Case %d: ", cas++);
        if(pos) puts("Yes");
        else puts("No");
    }

    return 0;
}
