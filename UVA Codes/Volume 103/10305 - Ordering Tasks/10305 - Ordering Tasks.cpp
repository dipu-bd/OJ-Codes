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
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

//predefined macros
#define mp make_pair
#define pb push_back
#define _a first
#define _b second
#define _IT ::iterator
#define gcd(a,b) __gcd(a,b)

#define PI acos(-1)

//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//other macros
#define LIMIT
#define MOD
#define MAX

//structures
struct node
{
    int u;
    int w;
    node(int a = 0, int c = 0) : u(a), w(c) { }

    bool operator < (const node& b) const
    {
        if(w == b.w)
            return u < b.u;
        return w > b.w;
    }
};


//global variables, constants

stack<int> st;
bool check[150];
vector<int> graph[150];

//functions

void dfs(int u)
{
    vector<int>_IT it;
    for(it = graph[u].begin(); it != graph[u].end(); ++it)
    {
        int& v = *it;
        if(!check[v])
        {
            dfs(v);
            check[v] = true;
            st.push(v);
        }
    }
}

//main function
int main()
{
    int n, m, u, v;

    while(scanf("%d %d", &n, &m) == 2 && n)
    {
        for(int i = 1; i <= n; ++i)
            graph[i].clear();


        while(m--)
        {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
        }

        memset(check, 0, sizeof(check));
        for(int i = 1; i <= n; ++i)
            if(!check[i])
            {
                dfs(i);
                check[i] = true;
                st.push(i);
            }


        bool ns = false;
        while(st.size())
        {
            if(ns) printf(" ");
            ns = true;
            printf("%d", st.top());
            st.pop();
        }

        putchar('\n');
    }

    return 0;
}

