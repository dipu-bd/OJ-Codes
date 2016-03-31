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
typedef long long ll;
typedef pair<ll, ll> pii;

int test, cas = 1;

int n;
char line[2][1010];
int num[2][1010];
map<int, vector<int>> pos;

int main()
{
    freopen("high_security_in.txt", "r", stdin);
    freopen("high_security_output_dipu.txt", "w", stdout);

    scanf("%d", &test);
    while(test--)
    {
        pos.clear();

        scanf("%d", &n);
        scanf(" %s %s", line[0], line[1]);

        int last1 = 1, last2 = n + 10;
        for(int i = 0; i < n; ++i)
        {
            if(line[0][i] == '.')
            {
                num[0][i] = last1;
                pos[last1].push_back(i);
            }
            else
            {
                last1++;
            }

            if(line[1][i] == '.')
            {
                num[1][i] = last2;
                pos[last2].push_back(n + i);
            }
            else
            {
                last2++;
            }
        }

        int ans = pos.size();

        loop(it, pos)
        {
            if(it->second.size() == 1)
            {
                int i = it->second[0], j = 1;
                if(i >= n) i -= n, j = 0;
                if(pos[num[j][i]].size())
                {
                    pos[num[j][i]].clear();
                    ans--;
                }
            }
        }

        printf("Case #%d: %d\n", cas++, ans);
    }

    return 0;
}


