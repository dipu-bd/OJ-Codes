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
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//cpp headers
#include <iostream>
#include <algorithm>
#include <vector>
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
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int row[10];
int col[10];
int box[10];
vpii gpoint[30];
char group[10][10];
char sudoku[10][10];
vpii peers[10][10][3];

const char BLANK = '0';

inline int bi(int i, int j)
{
    return 3 * (i / 3) + (j / 3);
}
inline void setv(int& n, int p)
{
    n |= (1 << p);
}
inline void clearv(int& n, int p)
{
    n &= ~(1 << p);
}
inline bool getv(int n, int p)
{
    return (n & (1 << p));
}

void init()
{
    REP(i, 0, 9)
    REP(j, 0, 9)
    {
        REP(k, 0, 9)
        {
            if(k != j) peers[i][j][0].pb(mp(i, k));
            if(k != i) peers[i][j][1].pb(mp(k, j));
        }

        int b = bi(i, j);
        pii beg = mp(3 * (b / 3), 3 * (b % 3));
        pii end = mp(3 * (b / 3 + 1), 3 * (b % 3 + 1));

        REP(x, beg.fr, end.fr)
        REP(y, beg.sc, end.sc)
        if(!(x == i && y == j))
        {
            peers[i][j][2].pb(mp(x, y));
        }
    }
}

string calculate(int r, int c)
{
    string res = "";
    int bit = row[r] | col[c] | box[bi(r, c)];

    //check single
    REPE(d, 1, 9)
    if(!getv(bit, d)) res.pb(d);
    if(res.size() <= 1) return res;

    //discover hidden single
    REPE(d, 1, 9)
    if(!getv(bit, d))
    {
        REP(k, 0, 3)
        {
            bool ok = true;
            loop(p, peers[r][c][k])
            if(sudoku[p->fr][p->sc] == BLANK)
            {
                int q = row[p->fr] | col[p->sc] | box[bi(p->fr, p->sc)];
                if(!getv(q, d)) { ok = false; break; }
            }
            if(ok)
            {
                res.clear();
                res.pb(d);
                return res;
            }
        }
    }

    return res;
}

void color(int r, int c, int d)
{
    sudoku[r][c] = d + '0';
    setv(row[r], d);
    setv(col[c], d);
    setv(box[bi(r, c)], d);
    if(group[i][j] != BLANK)
    {
        loop(p, gpoint[group[i][j]])
        {
            sudoku[r][c] = d + '0';

        }
    }
}

void uncolor(int r, int c, int d)
{
    clearv(row[r], d);
    clearv(col[c], d);
    clearv(box[bi(r, c)], d);
    if(group[i][j] != BLANK)
    {
        loop(p, gpoint[group[i][j]])
        {
            clearv(row[p->fr], d);
            clearv(col[p->sc], d);
            clearv(box[bi(p->fr, p->sc)], d);
        }
    }
}

bool issolved()
{
    REP(i, 0, 9)
    REP(j, 0, 9)
    if(sudoku[i][j] == BLANK)
        return false;
    return true;
}

bool solve()
{
    if(issolved()) return 1;

    //find next best string
    int r, c;
    string best;
    REP(i, 0, 9)
    REP(j, 0, 9)
    if(sudoku[i][j] == BLANK)
    {
        string num = calculate(i, j);
        if(num.empty()) return 0;

        if(best.empty() || num.size() < best.size())
        { r = i; c = j; best = num; }

        if(best.size() == 1) break;
    }

    //recursive call
    int cnt = 0;
    REP(i, 0, best.size())
    {
        color(r, c, best[i]);
        cnt += solve();
        uncolor(r, c, best[i]);
    }

    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("1397.inp", "r", stdin);
#endif // LOCAL

    init();

    scanf("%d", &test);
    while(test--)
    {
        clr(row);
        clr(col);
        clr(box);
        clr(gpoint);

        REP(i, 0, 9)
        {
            scanf(" %s", sudoku[i]);
            REP(j, 0, 9)
            {
                group[i][j] = BLANK;
                if('1' <= sudoku[i][j] && sudoku[i][j] <= '9')
                {
                    color(i, j, sudoku[i][j] - '0');
                }
                else if(sudoku[i][j] == 'e')
                {
                    for(int d = 2; d < 9; d += 2) color(i, j, i);
                    sudoku[i][j] = BLANK;
                }
                else if(sudoku[i][j] == 'o')
                {
                    for(int d = 1; d < 9; d += 2) color(i, j, i);
                    sudoku[i][j] = BLANK;
                }
                else if('a' <= sudoku[i][j] && sudoku[i][j] <= 'z')
                {
                    int ch = sudoku[i][j] - 'a';
                    group[i][j] = ch;
                    gpoint[ch].pb(mp(i, j));
                    sudoku[i][j] = BLANK;
                }
            }
        }

        int res = solve();
        printf("%d\n", res);
    }

    return 0;
}
