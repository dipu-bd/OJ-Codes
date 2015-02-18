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
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define IT iterator
#define RIT reverse_iterator
#define CIT const_iterator
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define loop(type, it, cont) for(type::iterator it = cont.begin(); it != cont.end(); ++it)
#define rloop(type, it, cont) for(type::reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)

ll ways[10010];

int main()
{
    //count ways
    ways[0] = 1;
    REPE(i, 1, 21)
    {
        int coin = i * i * i;
        REPE(j, coin, 10000)
        {
            ways[j] += ways[j - coin];
        }
    }

    //program
    int n;
    while(cin >> n)
        cout << ways[n] << endl;

    return 0;
}