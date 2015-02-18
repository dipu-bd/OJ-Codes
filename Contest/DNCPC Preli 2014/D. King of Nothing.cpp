#include<cstdio>
#include<cmath>
#include<iostream>
#include<set>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<iterator>
#include<sstream>
#include<stack>
#include<queue>
#include<limits.h>
#include<deque>
#include<list>
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fk(a, b) for(int k=a; k<b; k++)
#define SZ(x) (int)x.size()
#define pp() pop_back()
#define pb(x) push_back(x)
#define mp make_pair
#define sf scanf
#define pf printf
#define ssf sscanf
#define rsrt(x) sort(x.rbegin(), x.rend())
#define srt(x) sort(x.begin(), x.end())
#define mem(name, value) memset(name, value, sizeof(name))
#define Max 1000
#define oo 1000000000


using namespace std;

int cases=1;

typedef pair<int, int>ii;
map<string, int>stin;
map<char, int>chin;
map<int, int>inin;
map<string, string>stst;
map<vector<string>, int>vsin;
typedef vector<int>vi;
typedef vector<string>vs;
typedef vector<char>vc;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef char C;
typedef string S;
#define fr first
#define sc second
//int dx[4] = {+0,-1,+0,+1}, dy[4] = {-1,+0,+1,+0}; /*row and column moves*/
//int dx[8] = {-1,-1,-1,+0,+1,+1,+1,+0}, dy[8] = {-1,0,+1,+1,+1,0,-1,-1};/*8-direction*/
/**
knight moves:
dx[8] = {-1,-2,-2,-1,+1,+2,+2,+1};
dy[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
*/

struct type
{
    type(){}
};

typedef vector<type> vt;
typedef vector<ii> vii;

void read(void)
{
    return ;
}

#define mod 1000000007

//#include<conio.h>

int main()
{
    int test_cases, n, x, a;
    sf("%d", &test_cases);
    while(test_cases--)
    {
        sf("%d %d", &n, &x);
        ll add = 1, den = 1;
        for(int i=0; i<n;  i++)
        {
            sf("%d", &a);
            a = x-a;
            add = (add%mod * a%mod)%mod;
            den = (den%mod * x)%mod;
        }
        if(add==0)
        {
            pf("Case %d: 0\n", cases++);
            continue;
        }
        if(add == den)
        {
            pf("Case %d: 1\n", cases++);
            continue;
        }
        ll ans = __gcd(add, den);
        pf("Case %d: %lld/%lld\n",cases++, add/ans, den/ans);
    }
    return 0;
}





















