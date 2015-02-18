//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
//cpp headers
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
using namespace std;

const double EPS = 1E-12;
const double E = exp(1.0);
const double PI = 2.0 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define ssort(v) stable_sort(v.begin(), v.end())
#define all(v) (v.begin(), v.end())
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define LB lower_bound
#define UB upper_bound

int test, cas = 1;
double W, H, x, xe, ye, miu;

double getmid(double h)
{
    return W + (h - H) * (W - xe) / (H - ye);
}

double getmiu(double m, double h)
{
    double p = m - x;
    double q = xe - m;
    double l = ye - h;
    return (q * sqrt(h * h + p * p)) / (p * sqrt(q * q + l * l));
}

//returns true if it is possible
bool ispossible(double h)
{
    double m = getmid(h);
    if(m + EPS < x - EPS) return false;
    double tmp = getmiu(m, h);
    return (tmp - miu) < EPS;
}

double hisearch()
{
    double low = 0;
    double high = H;
    while ((high - low) > EPS)
    {
        double h = (low + high) / 2;
        if (ispossible(h))
        {
            high = h - 1E-9;
        }
        else
        {
            low = h + 1E-9;
        }
    }
    return high + 1E-9;
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &W, &H, &x, &xe, &ye, &miu);
        if(ispossible(H))
        {
            double res = fabs(hisearch()) + EPS;
            printf("%.4lf\n", res);
        }
        else
        {
            printf("Impossible\n");
        }
    }


    return 0;
}