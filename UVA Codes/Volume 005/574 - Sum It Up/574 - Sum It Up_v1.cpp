#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vii;
const double PI = 2.0 * acos(0.0);

#define mp make_pair
#define pb push_back
#define pp pop_back
#define IT iterator
#define gcd(a, b) __gcd(a, b)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define loop(type, it, cont) for(type::iterator it = cont.begin(); it != cont.end(); ++it)
#define rloop(type, it, cont) for(type::reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)
#define all(v) v.begin(), v.end()

int t, n;
int num[20];
set<string> res;

string getstr(int bit)
{
    stringstream out;

    bool sp = false;
    for(int i = 0; i < n; ++i)
        if(bit & (1 << i))
        {
            if(sp) out << '+';
            else sp = true;

            out << num[i];
        }

    return out.str();
}

void find_sum(int p = 0, int s = 0, int bit = 0)
{
    if(s > t) return;
    if(s == t)
    {
        res.insert(getstr(bit));
        return;
    }

    for(int i = p, m = 1 << p; i < n; ++i, m <<= 1)
    {
        if(!(bit & m)) find_sum(i + 1, s + num[i], bit | m);
    }
}

int main()
{
    while(cin >> t >> n)
    {
        if(n == 0) break;

        REP(i, 0, n) scanf("%d", num + i);

        printf("Sums of %d:\n", t);

        res.clear();
        find_sum();

        if(res.empty()) puts("NONE");
        else
        {
            rloop(set<string>, it, res)
            cout << *it << endl;
        }
    }

    return 0;
}