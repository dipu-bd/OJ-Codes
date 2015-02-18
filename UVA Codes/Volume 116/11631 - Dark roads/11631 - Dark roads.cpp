// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

//predefined macros
#define mp make_pair
#define pb push_back
#define _a first
#define _b second
#define _IT ::iterator
#define gcd(a,b) __gcd(a,b)

#define PI acos(-1)

//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//other macros
#define LIMIT
#define MOD
#define MAX 200000

//structures
struct edge
{
    int u;
    int v;
    int w;
    edge(int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) { }

    bool operator < (const edge& rhs) const
    {
        return w < rhs.w;
    }
};

//global variables, constants


//functions

int par[MAX + 10];

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        par[i] = i;
    }
}

int getpar(int u)
{
    if(par[u] == u) return u;
    return par[u] = getpar(par[u]);
}

bool connect(int u, int v)
{
    int p = getpar(u);
    int q = getpar(v);
    if(p == q) return false;
    par[p] = q;
    return true;
}


//main function
int main()
{
#ifdef DIPU
    //freopen("inp.txt", "r", stdin);
#endif // DIPU

    int n, m;
    int u, v, w;

    while(scanf("%d %d", &n, &m) == 2 && n)
    {
        init(n);
        vector<edge> ve;

        int tot = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            ve.pb(edge(u, v, w));
            tot += w;
        }

        sort(ve.begin(), ve.end());

        int sum = 0, cnt = 0;
        vector<edge>_IT i;
        for(i = ve.begin(); i != ve.end(); ++i)
        {
            edge& e = *i;
            if(connect(e.u, e.v))
            {
                ++cnt;
                sum += e.w;
                if(cnt == n) break;
            }
        }

        printf("%d\n", tot - sum);
    }


    return 0;
}
