/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <string.h>
//cpp headers
#include<iostream>
//#include <bitset>
using namespace std;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
int test, cas = 1;

int m, n;
int bits[110];
int save[101][1 << 8][1 << 8];

int recur(int, int, int);
int gen(int, int, int, int, int);

int gen(int r, int c, int bit1, int bit2, int bit3)
{
    if(c == m)
        return recur(r + 1, bit2, bit3);

    int res = gen(r, c + 1, bit1, bit2, bit3);

    if(
        !(
            (c < 1) ||
            (bit1 & (0b11 << (c - 1))) ||
            (bit2 & (0b11 << (c - 1))) ||
            (bit3 & (0b11 << (c - 1)))
        )
    )
    {
        res = max(res, 1 + gen(r, c + 1,
                               bit1 | (0b11 << (c - 1)),
                               bit2 | (0b11 << (c - 1)),
                               bit3 | (0b11 << (c - 1))));
    }

    if(
        !(
            (c < 2) ||
            (bit1 & (0b111 << (c - 2))) ||
            (bit2 & (0b111 << (c - 2)))
        )
    )
    {
        res = max(res, 1 + gen(r, c + 1,
                               bit1 | (0b111 << (c - 2)),
                               bit2 | (0b111 << (c - 2)),
                               bit3));
    }

    return res;
}

int recur(int r, int bit1, int bit2)
{
    if(r == n) return 0;

    int& dp = save[r][bit1][bit2];
    if(dp != -1) return dp;

    dp = gen(r, 0, bit1, bit2, bits[r + 2]);
    return dp;
}

int main()
{
    char ch;

    sf1(test);
    while(test--)
    {
        sf2(m, n);

        clr(bits);
        REP(j, 0, m)
        REP(i, 0, n)
        {
            scanf(" %c", &ch);
            if(ch == '#')
                bits[i] |= 1 << j;
        }
        REP(i, n, n + 5)
        {
            bits[i] = (1 << m) - 1;
        }

        mem(save, -1);
        int res = recur(0, bits[0], bits[1]);

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}

/*
1
6 10
..........
########..
..........
########..
..........
########..
*/

