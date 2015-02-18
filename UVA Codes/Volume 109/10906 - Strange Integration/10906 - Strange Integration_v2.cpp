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

char inp[10000];
string save[100];
map<string, int> var;

char getmajor(const string& str)
{
    const char* dat = str.data();

    char major = 'd';
    for(int i = 0; dat[i]; ++i)
    {
        if(dat[i] == '(')
        {
            int cnt = 1;
            while(dat[i] && cnt)
            {
                ++i;
                if(dat[i] == '(') ++cnt;
                if(dat[i] == ')') --cnt;
            }
        }

        if(dat[i] == '+') major = '+';
        if(dat[i] == '*' && major != '+') major = '*';
    }

    return major;
}

string combine(string a, string b, char p)
{
    char ma = getmajor(a);
    char mb = getmajor(b);

    //printf("[%s]:[major = %c] %c ", a.data(), ma, p);
    //printf("[%s]:[major = %c]\n", b.data(), mb);

    if(p == '+')
    {
        if(mb == '+') b = '(' + b + ')';
    }
    else if(p == '*')
    {
        if(ma == '+') a = '(' + a + ')';
        if(mb == '+' || mb == '*') b = '(' + b + ')';
    }


    return (a + p + b);
}

void popout(stack<char>& op, stack<string>& val, char ch = 0)
{
    while(op.size())
    {
        char p = op.top();
        if(ch == '*' && p != '*') break;
        if(ch == '+' && p == '(') break;
        op.pop();
        if(ch == ')' && p == '(') break;

        string b = val.top();
        val.pop();
        string a = val.top();
        val.pop();

        val.push(combine(a, b, p));
    }
}

void simplify(string& equ)
{
    stack<char> op;
    stack<string> val;

    const char* line = equ.data();
    for(int i = 0; line[i]; ++i)
    {
        if(line[i] == '(') { op.push('('); continue; }

        if(line[i] == '*' || line[i] == '+' || line[i] == ')')
        {
            popout(op, val, line[i]);
            if(line[i] != ')') op.push(line[i]);
            continue;
        }

        if(isdigit(line[i]))
        {
            string dg;
            while(isdigit(line[i])) dg.pb(line[i++]);
            val.push(dg);
            --i;
        }
    }

    popout(op, val);

    equ = val.top();
}

void append(string& equ)
{
    string res;
    const char* line = equ.data();

    for(int i = 0; line[i]; ++i)
    {
        if(line[i] == ' ') continue;
        if(isalpha(line[i]))
        {
            string name;
            while(isalpha(line[i])) name.pb(line[i++]);
            --i;

            int& indx = var[name];
            res += '(' + save[indx] + ')';
            continue;
        }

        res.pb(line[i]);
    }

    equ = res;
}

int main()
{
#ifdef LOCAL
    freopen("10906.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        var.clear();
        int last = 0;
        int n, vs = 0;

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %[^\n]", inp);

            int i = 0;
            string name;
            while(isalpha(inp[i])) name.pb(inp[i++]);
            while(inp[i] == ' ' || inp[i] == '=') ++i;

            int& indx = var[name];
            if(indx == 0) indx = vs++;

            string equ(inp + i);
            append(equ);

            save[indx] = equ;
            last = indx;
        }

        string equ = save[last];
        simplify(equ);

        printf("Expression #%d: %s\n", cas++, equ.data());
    }

    return 0;
}
