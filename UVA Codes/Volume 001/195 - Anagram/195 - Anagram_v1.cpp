#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const char& a, const char& b)
{
    if(toupper(a) == toupper(b)) return a < b;
    return toupper(a) < toupper(b);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("195.inp", "r", stdin);
#endif

    int n;
    string s;
    scanf("%d ", &n);
    while(n--)
    {
        cin >> s;
        sort(s.begin(), s.end(), comp);

        do puts(s.c_str());
        while(next_permutation(s.begin(), s.end(), comp));
    }

    return 0;
}
