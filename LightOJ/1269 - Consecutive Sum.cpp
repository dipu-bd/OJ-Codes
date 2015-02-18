/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
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
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline int extract(const string& s, T ret) { stringstream ss(s); return (ss >> ret); }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct node
{
    int pos[2];
    node() { clr(pos); }
    int& operator [] (int i) { return pos[i]; }
};

#define SIZ 50010
int n;
uint arr[SIZ];
uint cum[SIZ];
vector<node> trie;

void insert_trie(uint val)
{
    int pos = 0;
    RREPE(i, 31, 0)
    {
        bool d = (val & (1U << i));
        if(trie[pos][d] == 0)
        {
            trie[pos][d] = trie.size();
            trie.pb(node());
        }
        pos = trie[pos][d];
    }
}

uint findMax(uint val)
{
    uint ans = 0;
    //try to find a number as close as possible to reverse of val in the trie
    int pos = 0;
    RREPE(i, 31, 0)
    {
        int d = (val & (1U << i)) ? 0 : 1;

        if(trie[pos][d] == 0)
        {
            pos = trie[pos][1 ^ d];
        }
        else
        {
            ans |= (1U << i);
            pos = trie[pos][d];
        }
    }

    return ans;
}

uint findMin(uint val)
{
    uint ans = 0;
    //try to find a number as close as possible to val in the trie
    int pos = 0;
    RREPE(i, 31, 0)
    {
        int d = (val & (1U << i)) ? 1 : 0;
        if(trie[pos][d] == 0)
        {
            ans |= (1U << i);
            pos = trie[pos][1 ^ d];
        }
        else
        {
            pos = trie[pos][d];
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        trie.clear();
        trie.pb(node());

        sf1(n);
        REP(i, 0, n)
        {
            scanf("%u", &arr[i]);
            if(i == 0) cum[i] = arr[i];
            else cum[i] = cum[i - 1] ^ arr[i];
        }

        uint maxi = cum[0];
        uint mini = cum[0];
        REP(i, 1, n)
        {
            maxi = max(maxi, cum[i]);
            mini = min(mini, cum[i]);
            maxi = max(maxi, findMax(cum[i]));
            mini = min(mini, findMin(cum[i]));
            insert_trie(cum[i]);
        }

        printf("Case %d: %u %u\n", cas++, maxi, mini);
    }

    return 0;
}



