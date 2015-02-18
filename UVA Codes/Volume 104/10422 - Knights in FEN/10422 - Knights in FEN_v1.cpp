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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int step;
int solve;
bool vis[10][10];
char board[10][10];

//move
int X[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int Y[] = { -1, 1, -2,  2, -2, 2, -1, 1};

char goal[6][10] =
{
    "11111",
    "01111",
    "00 11",
    "00001",
    "00000"
};

pii getspace()
{
    REP(i, 0, 5)
    REP(j, 0, 5)
    if(board[i][j] == ' ')
        return mp(i, j);
    return mp(-1, -1);
}

bool valid(int x, int y)
{
    return !(x < 0 || x > 4 || y < 0 || y > 4);
}

bool match()
{
    REP(i, 0, 5)
    REP(j, 0, 5)
    if(board[i][j] != goal[i][j]) 
    {
        //printf("[%d %d]", i, j);
        return false;
    }
    return true;
}

void backtrack(int x, int y)
{
    if(step > 10) return;
    if(match()) solve = min(solve, step); 
    
    REP(i, 0, 8)
    {
        int px = x + X[i];
        int py = y + Y[i];
        if(valid(px, py))
        {
            step++;
            swap(board[x][y], board[px][py]);
            backtrack(px, py);
            swap(board[x][y], board[px][py]);
            step--;
        }
    } 
}

int main()
{ 
    scanf("%d ", &test);
    while(test--)
    {
        REP(i, 0, 5) gets(board[i]);
 
        solve = 15;
        pii p = getspace();
        backtrack(p.fr, p.sc);

        if(solve < 11)
            printf("Solvable in %d move(s).\n" + "32", solve);
        else
            printf("Unsolvable in less than 11 move(s).\n");
    }

    return 0;
}
