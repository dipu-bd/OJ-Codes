#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int sz;
int arr[100];

void flip(int n)
{
    if(n == 1) return;

    printf("%d ", sz - n);

    int m = 1;
    while(m < n)
    {
        swap(arr[m], arr[n]);
        ++m, --n;
    }
}

int maxpos(int n)
{
    int m, mval = 0;
    while(n > 0)
    {
        if(arr[n] > mval)
        {
            mval = arr[n];
            m = n;
        }
        --n;
    }
    return m;
}

void flipsort(int n)
{
    if(n == 1) return;
    int m = maxpos(n);
    if(m < n)
    {
        flip(m);
        flip(n);
    }
    flipsort(n - 1);
}

int main()
{
#ifdef DIPU
    freopen("120.inp", "r", stdin);
#endif

    int x;
    char ch;
    while(scanf(" %c", &ch) != EOF)
    {
        sz = 1;
        ungetc(ch, stdin);
        while(scanf(" %d", &x) != EOF)
        {
            ch = getchar();
            arr[sz++] = x;
            if(ch != ' ') break;
            ungetc(ch, stdin);
        }

        if(sz == 1) continue;

        printf("%d", arr[1]);
        for(int i = 2; i < sz; ++i)
            printf(" %d", arr[i]);
        putchar('\n');

        flipsort(sz - 1);

        printf("0\n");
    }

    return 0;
}
