/* =================================
@AUTHOR : Sudipto Chandra Das DIPU
@UNIV : SUST [2012-331-019]
@COUNTRY : Bangladesh
================================= */
// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

void INPUTFILE()
{
#ifndef ONLINE_JUDGE
#ifdef DIPU
    freopen("624.inp", "r", stdin);
#endif
#endif
}

//#define ENABLE_FUNCTIONS

const double PI = acos(-1);
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
//typedefs
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
//risk-free macros
#define gcd(a,b) __gcd(a,b)
#define logab(a,b) (log(a) / lob(b))
#define mem(a,v) memset(a, v, sizeof(a))
#define _IT ::iterator
#define pb push_back
#define pp pop_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define loop(type, v, it) for(type::iterator it = v.begin(); it != v.end(); ++it)
//pre-functions
#ifdef ENABLE_FUNCTIONS
template<class T> inline T SQR(T num) { return num * num; } //returns square of two nums
template<class T> inline T ABS(T num) { return (num < 0) ? -num : num; }    //returns absolute value of num
template<class T> inline T PMOD(T A, T M) { return (A >= 0) ? (A % M) : (A % M) + ABS(M); } //returns positive modulus
template<class T> T POW(const T& n, const int& b) //calculate [n^p] in log(p)
{
    if(b < 0) return 1 / POW(n, -b);
    if (b & 1) return n * SQR(POW(n, b >> 1)) ;
    else return (b == 0) ? 1 : SQR(POW(n, b >> 1));
}
ll bigmod(const ll& n, const ll& b, const ll& m) //calculate [(n^p) % m] in O(log(p))
{
    if (b & 1) return (n * (SQR(POW(n, b >> 1)) % m)) % m ;
    else return (b == 0 ? 1 : SQR(POW(n, b >> 1))) % m;
}
#endif

//other macros
const int MAX = 0;
const int LIM = 0;

int N, K, msum;
vector<int> seq;

int num[25];
bool check[25];
vector<int> tmp;

void backtrack(int p, int sum = 0)
{
    if(msum == N) return;

    //base conditions
    if(sum > N) return;
    if(msum < sum)
    {
        msum = sum;
        seq = tmp;
    }

    //works
    for(int i = p + 1; i < K; ++i)
    {
        if(!check[i])
        {
            check[i] = true;
            tmp.pb(num[i]);

            backtrack(i, sum + num[i]);

            tmp.pp();
            check[i] = false;
        }
    }
}

//main function
int main()
{
    INPUTFILE();

    while(scanf("%d %d", &N, &K) != EOF)
    {
        for(int i = 0; i < K; ++i)
            scanf("%d", num + i);

        msum = 0;
        backtrack(-1);

        for(int i = 0; i < seq.size(); ++i)
            printf("%d ", seq[i]);
        printf("sum:%d\n", msum);
    }


    return 0;
}
