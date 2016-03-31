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

struct node
{
    int siz;
    bool last;
    map<char, int> next;

    node()
    {
        siz = 0;
        last = false;
        next.clear();
    }

    int& operator [] (char c)
    {
        return next[c];
    }

    bool has(char c)
    {
        return next.count(c);
    }

};

int n, k;
char inp[100005];
vector<node> tree;
int len[310];
ll overlap[310][310];
ll save[310][310][310];
int _save[310][310][310];

void insert()
{
    int cur = 0;
    int len = strlen(inp);

    tree[cur].siz++;
    for(int i = 0; i < len; ++i)
    {
        if(!tree[cur].has(inp[i]))
        {
            tree[cur][inp[i]] = tree.size();
            tree.push_back(node());
        }

        cur = tree[cur][inp[i]];
        tree[cur].siz++;
    }
    tree[cur].last = true;
}

void calc_overlap(int cur = 0, int base = 0, int high = 0)
{
    int pos = base;
    int si = base + tree[cur].siz;
    loop(it, tree[cur].next)
    {
        int nxt = it->second;
        int sj = pos + tree[nxt].siz;
        for(int i = base + 1; i <= si; ++i)
            for(int j = pos + 1; j <= sj; ++j)
                if(i != j)
                    overlap[i][j] = overlap[j][i] = high;

        calc_overlap(nxt, pos, high + 1);
        pos += tree[nxt].siz;
    }
    if(tree[cur].last)
    {
        len[si] = high;
    }
}

ll recur(int t = 0, int p = 1, int q = 0)
{
    if(t >= k) return len[q];
    if(p > n) return 1LL << 62;

    ll& dp = save[t][p][q];
    int& dpc = _save[t][p][q];
    if(dpc == cas) return dp;
    dpc = cas;

    dp = recur(t, p + 1, q);
    if(q == 0)
    {
        ll cost = len[p];
        dp = min(dp, recur(t + 1, p + 1, p) + cost);
    }
    else
    {
        ll cost = len[p] + len[q] - 2 * overlap[p][q];
        dp = min(dp, recur(t + 1, p + 1, p) + cost);
    }

    return dp;
}


int main()
{
    freopen("text_editor.txt", "r", stdin);
    freopen("text_editor_output.txt", "w", stdout);

    scanf("%d", &test);
    while(test--)
    {
        tree.clear();
        tree.push_back(node());

        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i)
        {
            scanf(" %s", inp);
            insert();
        }

        mem(overlap, 0);
        calc_overlap();

        ll ans = k + recur();
        printf("Case #%d: %lld\n", cas++, ans);
    }

    return 0;
}


