/*============================
/\u7h0r : 5ud!p70 ch@ndr@ d@5
=============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct word
{
    int sum;
    int freq[30];
    char text[100];
    
    word() { }

    void operator = (const char* ing)
    {
        strcpy(text, ing);
        process();
    }
    
    void process()
    {
        clr(freq);
        for(int i = 0; text[i]; ++i)
        {
            if(isupper(text[i])) ++freq[text[i] - 'A'];
        }
        sum = 0;
        REP(i, 0, 26) sum += freq[i];
    }

    bool cantake(const word& other)
    {
        if(sum < other.sum) return false;
        REP(i, 0, 26) 
        if(freq[i] < other.freq[i]) return false;
        return true;
    }

    void take(const word& other)
    {
        sum -= other.sum;
        REP(i, 0, 26) 
        freq[i] -= other.freq[i];
    }

    void put(const word& other)
    {
        sum += other.sum;
        REP(i, 0, 26) 
        freq[i] += other.freq[i];
    }
};

int len;
vii took;
word phrase;
word dic[2004];
vector<string> text;
vector<string> part;

void split(const char* str, vector<string>& v)
{
    string s;
    v.clear();
    for(int i = 0; str[i]; ++i)
    {
        if(isupper(str[i]))
        {
            s.pb(str[i]);
        }
        else
        {
            if(s.size()) v.pb(s);
            s.clear();
        }
    }
    if(s.size()) v.pb(s);
    ssort(v);
}

bool ismatch()
{
    int sz = took.size();
    if(sz != (int)part.size()) return false;

    text.clear();
    loop(i, took)
    text.pb(dic[*i].text);
    ssort(text);

    REP(i, 0, sz)
    if(text[i] != part[i]) return false;

    return true;
}

void backtrack(int p = 0)
{
    if(phrase.sum == 0)
    {
        if(ismatch()) return;
        printf("%s =", phrase.text);
        loop(i, took) printf(" %s", dic[*i].text);
        putchar('\n');
        return;
    }
    if(p == len) return;

    //take
    if(phrase.cantake(dic[p]))
    {
        took.pb(p);
        phrase.take(dic[p]);
        backtrack(p);
        phrase.put(dic[p]);
        took.pp();
    }

    //don't take
    backtrack(p + 1);
}

int main()
{
    char inp[25];
    while(gets(inp))
    {
        if(inp[0] == '#') break;
        text.pb(inp);
    }

    len = 0;
    ssort(text);
    loop(i, text)
    {
        if(i->size()) 
            dic[len++] = i->data();
    }

    while(gets(phrase.text))
    {
        if(phrase.text[0] == '#') break;
        split(phrase.text, part);
        phrase.process();
        backtrack();
    }

    return 0;
}