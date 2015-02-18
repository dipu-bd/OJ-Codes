/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct Trie
{
    int indx;
    char data;
    Trie* child[26];

    Trie(int n = 0, char ch = 0)
    {
        indx = n;
        data = ch;
        clr(child);
    }

    void clear()
    {
        REP(i, 0, 26)
        {
            if(child[i])
            {
                child[i]->clear();
                free(child[i]);
            }
        }
    }
};

Trie* head = new Trie();
vii graph[26];
bool used[26];
bool visit[26];
queue<int> st;

void insert_trie(Trie* nod, char* inp, int& n)
{
    if(!*inp) return;

    int dat = *inp - 'A';
    if(!nod->child[dat])
        nod->child[dat] = new Trie(n, dat);

    insert_trie(nod->child[dat], inp + 1, n);
}

bool comp(const pii& a, const pii& b)
{
    return a.sc < b.sc;
}

void make_graph(Trie* nod)
{
    vector<pii> v;
    REP(i, 0, 26)
    {
        Trie* t = nod->child[i];
        if(t)
        {
            make_graph(t);
            v.pb(mp(t->data, t->indx));
        }
    }

    if(v.size() < 2) return;

    sort(all(v), comp);

    char x = v[0].fr;
    used[x] = 1;
    REP(i, 1, v.size())
    {
        char y = v[i].fr;
        graph[y].pb(x);
        used[y] = 1;
        x = y;
    }
}

void dfs(int v)
{
    if(visit[v]) return;

    visit[v] = 1;
    loop(i, graph[v]) dfs(*i);

    st.push(v);
}

int main()
{
#ifdef LOCAL
    freopen("200.inp", "r", stdin);
#endif // LOCAL

    int n = 0;
    char inp[50];
    while(gets(inp) && inp[0] != '#')
    {
        insert_trie(head, inp, n);
        ++n;
    }

    make_graph(head);

    REP(i, 0, 26)
    if(used[i] && !visit[i]) dfs(i);

    while(st.size())
    {
        putchar(st.front() + 'A');
        st.pop();
    }
    putchar('\n');

    return 0;
}
