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
    freopen("989.inp", "r", stdin);
#endif
#endif
}

#define ENABLE_FUNCTIONS

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

/// SUDOKU DATA
int num, sqn;
bool solved;
int cellcount;
int sudoku[10][10];

/// SOLUTION CHECKING FUNC
bool issolved()
{
    int tot = sqn * (sqn + 1) / 2;
    for(int i = 0; i < sqn; ++i)
    {
        int sum = 0;
        for(int j = 0; j < sqn; ++j)
            if(sudoku[i][j] == 0) return false;
            else sum += sudoku[i][j];
        if(sum != tot) return false;
    }

    return true;
}

/// PRINT SUDOKU FUNC
void printsud()
{
    for(int i = 0; i < sqn; ++i)
    {
        printf("%d", sudoku[i][0]);
        for(int j = 1; j < sqn; ++j)
            printf(" %d", sudoku[i][j]);
        putchar('\n');
    }
}

/// BACKTRACKING
inline bool canput(const int& p, const int&r, const int& c)
{
    for(int i = 0; i < sqn; ++i)
    {
        if(sudoku[r][i] == p) return false;
        if(sudoku[i][c] == p) return false;
    }

    int bi = (r / num) * num, ei = bi + num;
    int bj = (c / num) * num, ej = bj + num;
    for(int i = bi; i < ei; ++i)
        for(int j = bj; j < ej; ++j)
            if(sudoku[i][j] == p) return false;

    return true;
}

void backtrack()
{
    for(int i = 0; i < sqn; ++i)
    {
        for(int j = 0; j < sqn; ++j)
        {
            if(sudoku[i][j] == 0)
            {
                for(int k = 1; k <= sqn; ++k)
                {
                    if(canput(k, i, j))
                    {
                        sudoku[i][j] = k;
                        backtrack();
                        if(solved) return;
                        sudoku[i][j] = 0;
                    }
                }

                if(sudoku[i][j] == 0) return;
                ++cellcount;
            }
        }
    }

    solved = issolved();
}



///
/// MAIN FUNCTION
///
int main()
{
    INPUTFILE();

    int x;
    bool bl = false;

    while(scanf("%d", &num) != EOF)
    {
        if(bl) putchar('\n');
        else bl = true;

        if(num == 1)  //for special test case
        {
            printf("1");
            continue;
        }

        sqn = SQR(num);   //get size of sudoku matrix
        for(int i = 0; i < sqn; ++i)
            for(int j = 0; j < sqn; ++j)
                scanf("%d", &sudoku[i][j]);    //take input

        //solve sudoku
        solved = false;
        backtrack();

        if(solved) printsud();
        else puts("NO SOLUTION");
    }

    return 0;
}
