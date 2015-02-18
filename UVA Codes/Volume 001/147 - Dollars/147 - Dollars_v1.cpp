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

#define MAX 30000

ll ways[MAX + 10];
const int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main()
{
    //pre-calc
    ways[0] = 1;
    REP(i, 0, 11)
    {
        REPE(j, coin[i], MAX)
        {
            ways[j] += ways[j - coin[i]];
        }
    }

    //program
    int a, b, n;
    while(scanf("%d.%d", &a, &b) != EOF)
    {
        n = a * 100 + b;
        if(n == 0) break;
        printf("%3d.%.2d%17lld\n", a, b, ways[n]);
    }

    return 0;
}

