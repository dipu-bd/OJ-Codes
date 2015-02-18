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

//risk-free macros
#define gcd(a,b) __gcd(a,b)
#define logab(a,b) (log(a) / lob(b))
#define mem(a,v) memset(a, v, sizeof(a))
#define _IT ::iterator
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define loop(type, v, it) for(type::iterator it = v.begin(); it != v.end(); ++it)

int num, sqn;
bool solved;
int sudoku[10][10];

int bi[10][10];
bool row[10][10];
bool col[10][10];
bool box[10][10];

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

void makebox()
{
    for(int i = 0; i < sqn; ++i)
        for(int j = 0; j < sqn; ++j)
            bi[i][j] = (i / num) * num + (j / num);
}

bool canput(const int& p, const int&r, const int& c)
{
    return (!(row[r][p] || col[c][p] || box[bi[r][c]][p]));
}

void color(const int& p, const int&r, const int& c)
{
    sudoku[r][c] = p;
    row[r][p] = 1 ;
    col[c][p] = 1;
    box[bi[r][c]][p] = 1;

}

void uncolor(const int& p, const int&r, const int& c)
{
    sudoku[r][c] = 0;
    row[r][p] = 0;
    col[c][p] = 0;
    box[bi[r][c]][p] = 0;
}

void backtrack(int r, int c)
{
    if(solved) return;
    if(r == sqn) { solved = true; return; }
    if(c == sqn) { backtrack(r + 1, 0); return; }
    if(sudoku[r][c] > 0) { backtrack(r, c + 1);  return; }

    for(int p = 1; p <= sqn; ++p)
        if(canput(p, r, c))
        {
            color(p, r, c);

            backtrack(r, c + 1);
            if(solved) return;

            uncolor(p, r, c);
        }
}

//main function
int main()
{
    INPUTFILE();

    int x;
    bool bl = false;

    while(scanf("%d", &num) != EOF)
    {
        if(bl) putchar('\n');
        else bl = true;

        //for special test case
        if(num == 1)
        {
            printf("1");
            continue;
        }

        //precalc
        sqn = num * num;
        makebox();
        mem(box, 0);
        mem(row, 0);
        mem(col, 0);

        //get input
        for(int i = 0; i < sqn; ++i)
            for(int j = 0; j < sqn; ++j)
            {
                scanf("%d", &x);    //take input
                sudoku[i][j] = x;
                row[i][x] = 1;
                col[j][x] = 1;
                box[bi[i][j]][x] = 1;
            }

        //solve sudoku
        solved = false;
        backtrack(0, 0);

        //show result
        if(solved) printsud();
        else puts("NO SOLUTION");
    }

    return 0;
}
