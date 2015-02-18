#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool ispalin(map<char, int>& mp)
{
    bool odd = false;
    map<char, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it)
        if((it->second) & 1)
        {
            if(odd) return false;
            odd = true;
        }

    return true;
}

int main()
{
    int test, cas = 1;

    char inp[1010];
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp);

        int cnt = 0;
        map<char, int> freq, temp;
        for(int i = 0; inp[i]; ++i)
        {
            ++freq[inp[i]];
            temp = freq;
            for(int j = 0; j <= i; ++j)
            {
                if(ispalin(temp)) ++cnt;
                --temp[inp[j]];
            }
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
