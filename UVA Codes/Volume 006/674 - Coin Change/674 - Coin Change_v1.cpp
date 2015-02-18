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

#define MAX 7489

ll ways[MAX + 10];
const int coin[] = {1, 5, 10, 25, 50};

int main()
{
    //pre-calc
    ways[0] = 1;
    REP(i, 0, 5)
    {
        REPE(j, coin[i], MAX)
        {
            ways[j] += ways[j - coin[i]];
        }
    }

    //program
    int n;
    while(cin >> n) cout << ways[n] << endl;

    return 0;
}
