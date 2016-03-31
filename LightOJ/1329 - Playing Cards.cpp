/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//useful definitions
#define gcd(a,b) __gcd(a,b)
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
template<typename T> inline T sqr(T n) { return n * n; }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, long long p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod(T n,  long long p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/
//typedefs
typedef unsigned long long ull;

int test, cas = 1;

#define SIZ 14

ull save[SIZ][SIZ][SIZ][SIZ][5];
bool _save[SIZ][SIZ][SIZ][SIZ][5];

ull recur(int t4, int t3, int t2, int t1, int prev)
{
    if(t4 < 0 || t3 < 0 || t2 < 0 || t1 < 0) return 0;
    if(t4 + t3 + t2 + t1 == 0) return 1;

    ull& dp = save[t4][t3][t2][t1][prev];
    bool& dpc = _save[t4][t3][t2][t1][prev];
    if(dpc) return dp;
    dpc = true;
    dp = 0;

    dp += 4 * t4 * recur(t4 - 1, t3 + 1, t2, t1, 4);

    if(prev == 4)
        dp += 3 * (t3 - 1) * recur(t4, t3 - 1, t2 + 1, t1, 3);
    else
        dp += 3 * t3 * recur(t4, t3 - 1, t2 + 1, t1, 3);

    if(prev == 3)
        dp += 2 * (t2 - 1) * recur(t4, t3, t2 - 1, t1 + 1, 2);
    else
        dp += 2 * t2 * recur(t4, t3, t2 - 1, t1 + 1, 2);

    if(prev == 2)
        dp += (t1 - 1) * recur(t4, t3, t2, t1 - 1, 1);
    else
        dp += t1 * recur(t4, t3, t2, t1 - 1, 1);

    return dp;
}


int getValue(char c)
{
    if(isdigit(c))
        return c - '2';
    else if(c == 'T')
        return 8;
    else if(c == 'J')
        return 9;
    else if(c == 'Q')
        return 10;
    else if(c == 'K')
        return 11;
    else if(c == 'A')
        return 12;
    return 0;
}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n;
    char card[5];
    int valFreq[15];
    int valueClass[5];

    scanf("%d", &test);
    while(test--)
    {
        mem(valFreq, 0);
        mem(valueClass, 0);

        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf(" %s", card);
            valFreq[getValue(card[0])]++;
        }
        for(int i = 0; i < 13; ++i)
        {
            valueClass[valFreq[i]]++;
        }

        ull res = recur(valueClass[4], valueClass[3], valueClass[2], valueClass[1], 0);
        printf("Case %d: %llu\n", cas++, res);
    }

    return 0;
}

