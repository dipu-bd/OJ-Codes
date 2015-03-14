/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//#include <bits/stdc++.h>
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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct node
{
    char x, y;
    char mat[5][5];

    node()
    {
        REP(i, 0, 5)
        REP(j, 0, 5)
        mat[i][j] = (i < j);
        mat[0][0] = 1;
        mat[1][1] = 1;
        x = y = 2;
    }

    int hash() const
    {
        int v = x + (x << 2) + y; //x * 5 + y
        REP(i, 0, 5)
        REP(j, 0, 5)
        v = (v << 1) | mat[i][j];
        return v;
    }

    bool move(char p, char q)
    {
        p += x, q += y;
        if(p < 0 || q < 0 || p > 4 || q > 4) return false;
        swap(mat[p][q], mat[x][y]);
        x = p, y = q;
        return true;
    }

    void show()
    {
        uint v = hash();
        cout << v << " = ";
        string str = "";
        for( ; v > 0; v >>= 1)
            str.pb((v & 1) + '0');
        reverse(all(str));
        cout << str << endl;

        REP(i, 0, 5)
        {
            REP(j, 0, 5)
            printf("%d ", mat[i][j]);
            putchar('\n');
        }
    }

    bool operator < (const node& r) const
    {
        return hash() < r.hash();
    }
};

//knight move
map<int, int> dis;
char X[] = { -2, -2, -1, -1, 1, 1, 2, 2};
char Y[] = { -1, 1, -2,  2, -2, 2, -1, 1};

void precalc()
{
    node n, m;
    queue<node> q;
    q.push(n);
    dis[n.hash()] = 0;
    while(!q.empty())
    {
        n = q.front();
        q.pop();

        int d = dis[n.hash()] + 1;

        REP(i, 0, 8)
        {
            m = n;
            if(m.move(X[i], Y[i]))
            {
                if(!dis.count(m.hash()))
                {
                    dis[m.hash()] = d;
                    if(d < 10) q.push(m);
                }
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    precalc();
    
    node n;
    char inp[10];
    
    sscanf(gets(inp), "%d ", &test);
    while(test--)
    {
        REP(i, 0, 5)
        {
            gets(inp);
            REP(j, 0, 5)
            { 
                if(inp[j] == ' ')
                {
                    n.x = i;
                    n.y = j; 
                    n.mat[i][j] = 0;
                }
                else 
                {
                    n.mat[i][j] = inp[j] - '0';
                }
            }
        }
        
        if(!dis.count(n.hash())) 
            printf("Unsolvable in less than 11 move(s).\n");
        else 
            printf("Solvable in %d move(s).\n", dis[n.hash()]);
    }


    return 0;
}
