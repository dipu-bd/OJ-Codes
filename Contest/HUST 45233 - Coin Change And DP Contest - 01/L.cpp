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
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define loop(type, it, cont) for(type::iterator it = cont.begin(); it != cont.end(); ++it)
#define rloop(type, it, cont) for(type::reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)

#define MOD 100000007

int main()
{
   int test, cas = 1;
   int n, K;
   int coin[55];
   int avail[55];
   int ways[1010];

   cin >> test;
   while(test--)
   {
       scanf("%d %d", &n, &K);
       REP(i, 0, n) scanf("%d", coin + i);
       REP(i, 0, n) scanf("%d", avail + i);

       clr(ways);
       ways[0] = 1;
       REP(i, 0, n)
       {
           RREPE(j, K, 0)
           {
               if(ways[j])
               {
                   for(int c = 0, p = j + coin[i];
                           c < avail[i] && p <= K;
                           ++c, p += coin[i])
                       ways[p] = (ways[j] + ways[p]) % MOD;
               }
           }
       }

       printf("Case %d: %d\n", cas++, ways[K]);
   }


   return 0;
}
