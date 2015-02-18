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

char inp[1000];
double save[30];

void store(char ch, double value)
{
    save[ch - 'a'] = value;
}

double get(char ch)
{
    return save[ch - 'a'];
}

double parse(int i, int j)
{
    //if a variable
    if(isalpha(inp[i])) return get(inp[i]);
    //otherwise value
    double val;
    char ch = inp[j + 1];
    inp[j + 1] = 0;
    sscanf(inp + i, "%lf", &val);
    inp[j + 1] = ch;
    return val;
}

bool isop(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

int opval(char ch)
{
    if(ch == '(' || ch == ')') return 0;
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 3;
}

double calc(double a, double b, char& p)
{
    if(p == '+') return a + b;
    if(p == '-') return a - b;
    if(p == '*') return a * b;
    if(p == '/') return a / b;
}

double evaluate(int i, int j)
{
    stack<char> op;
    stack<double> val;

    for( ; i <= j; ++i)
    {
        if(inp[i] == '(')
        {
            op.push('(');
        }
        else if(isop(inp[i]))
        {
            int v = opval(inp[i]);
            while(op.size())
            {
                char& p = op.top();
                int t = opval(p);
                if(t < v) break;

                op.pop();
                if(p == '(') break;

                double b = val.top(); val.pop();
                double a = val.top(); val.pop();
                val.push(calc(a, b, p));
            }

            if(inp[i] != ')') op.push(inp[i]);
        }
        else
        {
            int k = i;
            while(!isop(inp[k])) ++k;
            double v = parse(i, k - 1);
            val.push(v);
            i = k - 1;
        }
    }

    return val.top();
}

int main()
{
    #ifdef LOCAL
    freopen("10932.inp", "r", stdin);
    #endif // LOCAL

    while(scanf(" %[^\n]", inp + 1) != EOF)
    {
        int len = strlen(inp + 1) + 1;
        inp[len + 1] = 0;
        inp[len] = ')';

        if(inp[2] == '=')
        {
            inp[2] = '(';
            store(inp[1], evaluate(2, len));
        }
        else
        {
            inp[0] = '(';
            double res = evaluate(0, len);
            printf("%.2lf\n", res);
        }
    }

    return 0;
}
