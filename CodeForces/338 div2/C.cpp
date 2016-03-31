/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(), v.end()
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

#define SIZ 2500
const int MAX = 1<<28;

int n, m;
char s[SIZ];
char f[SIZ];
char t[SIZ];
int len[SIZ];
int pi[SIZ][SIZ];
int bi[SIZ][SIZ];
int save[SIZ];
bool _save[SIZ];

void build()
{
    n = strlen(s + 1);
    m = strlen(t + 1);

    //calculate pi
    for(int i = 1; i <= m; ++i)
    {
        pi[i][1] = 0;
        len[i] = m - i + 1;
        char* pat = t + i - 1;
        for(int q = 2, k = 0; q <= len[i]; ++q)
        {
            while(k > 0 && pat[k + 1] != pat[q]) k = pi[i][k];
            if(pat[k + 1] == pat[q]) k++;
            pi[i][q] = k;
        }
    }

    //flip block
    for(int i = 1; i <= n; ++i)
    {
        f[i] = s[n - i + 1];
    }
}

int recur(int p)
{
    int& dp = save[p];
    if(_save[p]) return dp;
    _save[p] = 1;
    dp = MAX;

    char* pat = t + p - 1;

    //forward check
    for(int i = 1, q = 0; i <= n; ++i)
    {
        while(q > 0 && pat[q + 1] != s[i]) q = pi[p][q];
        if(pat[q + 1] == s[i]) q++;
        if(q == len[p])
        {
            dp = 1;
            return 1;
        }
        if(q > 0)
        {
            dp = min(dp, 1 + recur(p + q));
        }
    }

    //backward check
    for(int i = 1, q = 0; i <= n; ++i)
    {
        while(q > 0 && pat[q + 1] != f[i]) q = pi[p][q];
        if(pat[q + 1] == f[i]) q++;
        if(q == len[p])
        {
            dp = 1;
            return 1;
        }
        if(q > 0)
        {
            dp = min(dp, 1 + recur(p + q));
        }
    }

    return dp;
}

void printpath(int p)
{
    int dp = recur(p);
    char* pat = t + p - 1;

    //forward check
    for(int i = 1, q = 0; i <= n; ++i)
    {
        while(q > 0 && pat[q + 1] != s[i]) q = pi[p][q];
        if(pat[q + 1] == s[i]) q++;
        if(q == len[p])
        {
            printf("%d %d\n", i - q + 1, i);
            return;
        }
        if(q > 0)
        {
            if(dp == recur(p + q) + 1)
            {
                printf("%d %d\n", i - q + 1, i);
                printpath(p + q);
                return;
            }
        }
    }

    //backward check
    for(int i = 1, q = 0; i <= n; ++i)
    {
        while(q > 0 && pat[q + 1] != f[i]) q = pi[p][q];
        if(pat[q + 1] == f[i]) q++;
        if(q == len[p])
        {
            printf("%d %d\n", n - i + q, n - i + 1);
            return;
        }
        if(q > 0)
        {
            if(dp == recur(p + q) + 1)
            {
                printf("%d %d\n", n - i + q, n - i + 1);
                printpath(p + q);
                return;
            }
        }
    }

}

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf(" %s %s", s + 1, t + 1);

    build();

    int res = recur(1);
    if(res >= MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << res << endl;
        printpath(1);
    }

    return 0;
}


