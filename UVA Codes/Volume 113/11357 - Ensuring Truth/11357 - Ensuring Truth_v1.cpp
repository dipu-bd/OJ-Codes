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

struct btree
{
    int dat;
    btree* left;
    btree* right;

    btree(int d = 0) : dat(d), left(0), right(0) { }

    bool isop()
    {
        return dat == '~' || dat == '|' || dat == '&';
    }
};

char inp[1000];
map<char, int> vars;

void popout(stack<char>& op, stack<btree*>& val)
{
    while(op.size())
    {
        char p = op.top();
        op.pop();
        if(p == '(') break;

        btree* nod = new btree(p);
        nod->right = val.top();
        val.pop();
        nod->left = val.top();
        val.pop();
        val.push(nod);
    }
}

btree* maketree()
{
    stack<char> op;
    stack<btree*> val;

    for(int i = 0; inp[i]; ++i)
    {
        switch(inp[i])
        {
        case '(':
            op.push(inp[i]);
            break;

        case '&' :
        case '|' :
        case ')':
            popout(op, val);
            if(inp[i] != ')') op.push(inp[i]);
            break;

        case '~':
            val.push(new btree(inp[i]));
            break;

        default:
            if(isalpha(inp[i]))
            {
                int indx = vars[inp[i]];
                if(!indx) indx = 1 << (vars.size() - 1);

                btree* nod = new btree(indx);
                if(val.empty()) val.push(nod);
                else
                {
                    if(val.top()->dat == '~')
                    {
                        val.top()->left = nod;
                        val.top()->right = nod;
                    }
                    else
                    {
                        val.push(nod);
                    }
                }
            }
            break;
        }
    }

    popout(op, val);

    return val.top();
}

bool evaluate(btree* nod, int val)
{
    if(!nod) return false; //this case should never occur
    if(!nod->isop()) return (val & nod->dat);

    if(nod->dat == '~') return !evaluate(nod->left, val);
    if(nod->dat == '|') return evaluate(nod->left, val) || evaluate(nod->right, val);
    if(nod->dat == '&') return evaluate(nod->left, val) && evaluate(nod->right, val);
}

bool istrue(btree* nod)
{
    int p = 1 << vars.size();
    REP(i, 0, p) if(evaluate(nod, i)) return true;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("11357.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %[^\n]", inp);

        vars.clear();
        btree* bt = maketree();
        istrue(bt) ? puts("YES") : puts("NO");
    }

    return 0;
}
