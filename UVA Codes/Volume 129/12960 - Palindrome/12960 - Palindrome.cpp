/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
template<typename T> inline T sqr(T n) { return n * n; }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 2020
char inp[SIZ];
char pos[SIZ];

int main()
{
    int n, x;
    int szc, posc, maxpos, maxsiz;

    while(scanf(" %s", inp) == 1)
    {
        mem(pos, 0);

        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            pos[x - 1] = 1;
        }

        n = strlen(inp);
        maxpos = maxsiz = 0;
        for(int i = 0; i < n; ++i)
        {
            //check odd
            szc = 0;
            posc = pos[i];
            for(int p = 1; p < n; ++p)
            {
                if(i - p < 0 || i + p >= n) break;
                if(inp[i - p] != inp[i + p]) break;
                posc += pos[i - p] + pos[i + p];
                szc = p;
            }
            printf("%d | %d %d |", i, szc, posc);
            if(maxpos < posc)
            {
                maxpos = posc;
                maxsiz = szc + szc + 1;
            }
            else if(maxpos == posc)
            {
                maxsiz = max(maxsiz, szc + szc + 1);
            }

            //check even
            szc = 0;
            posc = 0;
            for(int p = 0; p < n; ++p)
            {
                if(i - p - 1 < 0 || i + p >= n) break;
                if(inp[i - p - 1] != inp[i + p]) break;
                posc += pos[i - p - 1] + pos[i + p];
                szc = p;
            }
            printf(" %d %d\n", szc, posc);
            if(maxpos == posc)
            {
                maxpos = posc;
                maxsiz = szc + szc;
            }
            else if(maxpos == posc)
            {
                maxsiz = max(maxsiz, szc + szc);
            }
        }

        printf("%d\n", maxsiz);
    }

    return 0;
}

/*
BANANAS
0
BANANAS
1 7
ACDAAACX
3 2 3 8
MARATONA
4 3 1 5 2
*/
