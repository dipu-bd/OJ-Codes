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

///
/// STRUCTURES
///
struct Cell
{
    int num;
    int siz;
    set<int> has;

    Cell() { }

    bool operator == (const Cell& b) const
    {
        return has == b.has;
    }

    void init(int n, int sz)
    {
        num = n;
        siz = sz;
        has.clear();

        if(n == 0)
        {
            for(int i = 1; i <= sz; ++i)
                has.insert(i);
        }
        else
        {
            has.insert(n);
        }
    }

    bool fixed() const
    {
        return (has.size() <= 1);
    }

    void rem(int n)
    {
        if(fixed()) return;

        has.erase(n);
        if(fixed()) num = *has.begin();
    }

    void print()
    {
        printf("%d", num);

        //printf("["); loop(set<int>, has, i) printf("%d ", *i); printf("]");
    }
};

/// SUDOKU DATA
int n, sqn;
Cell sudoku[10][10];

/// SOLUTION CHECKING FUNC
bool solved()
{
    int tot = sqn * (sqn + 1) / 2;
    for(int i = 0; i < sqn; ++i)
    {
        int sum = 0;
        for(int j = 0; j < sqn; ++j)
            if(!sudoku[i][j].fixed()) return false;
            else sum += sudoku[i][j].num;
        if(sum != tot) return false;
    }

    return true;
}

/// PRINT SUDOKU FUNC
void printsud()
{
    for(int i = 0; i < sqn; ++i)
    {
        sudoku[i][0].print();
        for(int j = 1; j < sqn; ++j)
        {
            putchar(' ');
            sudoku[i][j].print();
        }
        putchar('\n');
    }
}


///
/// NORMAL CROSS CHECK
///
void eraseall(int r, int c)
{
    int& num = sudoku[r][c].num;

    //check row and cols
    for(int i = 0; i < sqn; ++i)
    {
        if(!sudoku[i][c].fixed())
        {
            sudoku[i][c].rem(num);
            if(sudoku[i][c].fixed()) eraseall(i, c);
        }

        if(!sudoku[r][i].fixed())
        {
            sudoku[r][i].rem(num);
            if(sudoku[r][i].fixed()) eraseall(r, i);
        }
    }

    //check the box
    int br = (r / n) * n, bre = br + n;
    int bc = (c / n) * n, bce = bc + n;
    for(int i = br; i < bre; ++i)
        for(int j = bc; j < bce; ++j)
            if(!sudoku[i][j].fixed())
            {
                sudoku[i][j].rem(num);
                if(sudoku[i][j].fixed()) eraseall(i, j);
            }
}

void cross_hatch()
{
    //clear all that can be
    for(int i = 0; i < sqn; ++i)
        for(int j = 0; j < sqn; ++j)
            if(sudoku[i][j].fixed())
                eraseall(i, j);
}

///
/// HIDDEN SINGLE CHECK
///

bool issingle(int r, int c, const int& x)
{
    //check row and cols
    bool hr = true, hc = true, hb = true;

    //check the box
    int br = (r / n) * n, bre = br + n;
    int bc = (c / n) * n, bce = bc + n;
    for(int i = br; i < bre; ++i)
        for(int j = bc; j < bce; ++j)
            if(i != r && j != c && sudoku[i][j].has.count(x)) hb = false;

    for(int i = 0; i < sqn; ++i)
    {
        if(i != r && sudoku[i][c].has.count(x)) hc = false;
        if(i != c && sudoku[r][i].has.count(x)) hr = false;
    }

    return (hr && hc && hb);
}

void hidden_single()
{
    //find hidden singles
    for(int i = 0; i < sqn; ++i)
        for(int j = 0; j < sqn; ++j)
            if(!sudoku[i][j].fixed())
            {
                Cell& sud = sudoku[i][j];
                loop(set<int>, sud.has, it)
                if(issingle(i, j, *it))
                {
                    sud.init(*it, sud.siz);
                    eraseall(i, j);
                    break;
                }
            }
}

///
/// DOUBLE PAIR CHECK
///
void double_pair()
{

}

///
/// MAIN FUNCTION
///
int main()
{
    INPUTFILE();

    int x;
    bool bl = false;

    while(scanf("%d", &n) != EOF)
    {
        if(bl) putchar('\n');
        else bl = true;

        if(n == 1)  //for special test case
        {
            printf("1");
            continue;
        }

        sqn = SQR(n);   //get size of sudoku matrix
        for(int i = 0; i < sqn; ++i)
        {
            for(int j = 0; j < sqn; ++j)
            {
                scanf("%d", &x);    //take input
                sudoku[i][j].init(x, sqn);
            }
        }

        //solve sudoku
        cross_hatch();
        hidden_single();
        double_pair();

        if(solved()) printsud();
        else puts("NO SOLUTION");
    }

    return 0;
}
