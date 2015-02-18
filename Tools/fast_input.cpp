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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

const int maxbufsize = 1 << 20;

struct Input  //this won't work for system stdin. have to be a binary input file
{
    int bufsize, bufend, pos;
    char buffer[maxbufsize];

    void grab()
    {
        pos = 0;
        bufsize = maxbufsize;
        bufend = fread(buffer, sizeof(char), bufsize, stdin);
        buffer[bufend] = '\0';
    }

    bool eof()
    {
        return pos == bufend;
    }

    void skipws()
    {
        while(isspace(buffer[pos])) ++pos;
    }

    int getchar()
    {
        return buffer[pos++];
    }

    char readchar()
    {
        skipws();
        return getchar();
    }

    int getint() //read next integer
    {
        skipws();

        int n = 0, x;
        bool neg = false;
        if ((x = getchar()) == '-')
        {
            neg = true;
            x = getchar();
        }

        while(isdigit(x))
        {
            n = (n << 3) + (n << 1) + (x - '0');
            x = getchar();
        }

        if(neg) return -n;
        else return n;
    }

    char* getstring(char* inp) //read next string
    {
        skipws();
        char* tmp = inp;
        while(!isspace(*tmp = getchar())) ++tmp;
        *tmp = 0;
        return inp;
    }

    char* getuntil(char* inp, char ch) //read until ch found
    {
        char* tmp = inp;
        while((*tmp = getchar()) != ch) ++tmp;
        *tmp = 0;
        return inp;
    }

    char* getline(char* inp) //read next line
    {
        return getuntil(inp, '\n');
    }

} input;

int main()
{
    //freopen("", "r", stdin);
    input.grab();

    return 0;
}
