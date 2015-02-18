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

int n, k;
char ciphertext[100];
char ciphercode[100];
char plaincode[100];
char plaintext[100];

void convert(char* text, char* code)
{
    REP(i, 0, n)
    {
        code[i] = text[i] - 'a' + 1;
        if(text[i] == '_') code[i] = 0;
        if(text[i] == '.') code[i] = 27;
    }
}

void revert(char *code, char* text)
{
    REP(i, 0, n)
    {
        text[i] = code[i] + 'a' - 1;
        if(code[i] == 0) text[i] = '_';
        if(code[i] == 27) text[i] = '.';
    }
    text[n] = 0;
}

void decrypt(char* plain, char* cipher)
{
    REP(i, 0, n)
    {
        plain[(k * i % n)] = (cipher[i] + i) % 28;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("641.inp", "r", stdin);
    #endif // LOCAL

    while(scanf("%d %s", &k, ciphertext) != EOF)
    {
        if(k == 0) break;
        n = strlen(ciphertext);
        convert(ciphertext, ciphercode);
        decrypt(plaincode, ciphercode);
        revert(plaincode, plaintext);
        puts(plaintext);
    }

    return 0;
}
