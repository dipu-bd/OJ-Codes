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
    freopen("604.inp", "r", stdin);
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

bool BT;
string word;
char board1[4][4];
char board2[4][4];
bool visit[4][4];
set<string> first;
set<string> res;

inline bool isvowel(const char& ch)
{
    return ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U' || ch == 'Y';
}

inline int vowel()
{
    int vw = 0;
    for(int i = 0; i < word.size(); ++i)
        if(isvowel(word[i])) ++vw;
    return vw;
}

inline int conso()
{
    int cs = 0;
    for(int i = 0; i < word.size(); ++i)
        if(!isvowel(word[i])) ++cs;
    return cs;
}

void backtrack(int i, int j, int p = 0)
{
    if(word.size() == 4)
    {
        if(BT) first.insert(word);
        else if(first.count(word))
            res.insert(word);
        return;
    }

    const char (*b)[4] = BT ? board1 : board2;
    if(i < 0 || j < 0 || i > 3 || j > 3 || visit[i][j]) return;
    if(isvowel(b[i][j])) { if(vowel() == 2) return; }
    else { if(conso() == 2) return; }

    visit[i][j] = true;
    word.push_back(b[i][j]);

    backtrack(i, j + 1);
    backtrack(i, j - 1);
    backtrack(i + 1, j + 1);
    backtrack(i + 1, j);
    backtrack(i + 1, j - 1);
    backtrack(i - 1, j + 1);
    backtrack(i - 1, j);
    backtrack(i - 1, j - 1);

    word.erase(word.end() - 1);
    visit[i][j] = false;
}

//main function
int main()
{
    INPUTFILE();

    char ch;
    bool nl = false;
    while(scanf(" %c", &ch) != EOF)
    {
        res.clear();
        first.clear();

        if(ch == '#') break;
        else ungetc(ch, stdin);

        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
                scanf(" %c", board1[i] + j);
            for(int j = 0; j < 4; ++j)
                scanf(" %c", board2[i] + j);
        }

        BT = true;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                backtrack(i, j);

        BT = false;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                backtrack(i, j);

        if(nl) putchar('\n');
        else nl = true;

        if(res.size() == 0)
            puts("There are no common words for this pair of boggle boards.");
        else
        {
            loop(set<string>, res, it)
            cout << *it << endl;
        }
    }

    return 0;
}
