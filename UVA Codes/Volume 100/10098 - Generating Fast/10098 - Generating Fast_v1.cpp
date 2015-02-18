#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
//freopen("10098.inp", "r", stdin);
#endif
    int n;
    string s;

    scanf("%d", &n);
    while(n--)
    {
        cin >> s;
        sort(s.begin(), s.end());
        do
            puts(s.c_str());
        while(next_permutation(s.begin(), s.end()));
        putchar('\n');
    }

    return 0;
}
