//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h> 
//cpp headers
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std;
//typedefs
typedef long long ll; 
//always useful   
#define REP(i, a, n) for(int i = a; i < n; ++i) 
#define fr first
#define sc second
#define sf1(a) scanf("%d", &a) 
#define pb push_back
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)

int test, cas = 1;

struct node
{
    int n; 
    map<char, int> next;
    
    node() 
    { 
        n = 0;  
        next.clear(); 
    }
    
    int& operator [] (char ch)
    {
        return next[ch];
    }
     
};

char inp[1000006];
vector<node> tree;

void insert_trie()
{
    int p = 0;
    tree[0].n++;
    
    for(int i = 0; inp[i]; ++i)
    {
        int& n = tree[p][inp[i]];
        if(!n)
        {
            n = tree.size();
            tree.pb(node());
        }
        p = n;
        tree[p].n++;
    }
}

ll recur(int pos = 0, int len = 0)
{
    if(tree[pos].n <= 1) return len;
    
    ll cnt = 0;
    loop(it, tree[pos].next)
    {
        if(it->sc)
            cnt += recur(it->sc, len + 1);
    }
    
    return cnt;
}

int main()
{
    int n;
    sf1(test);
    REP(i, 0, test)
    {
        tree.clear();
        tree.pb(node());
        
        sf1(n);
        REP(i, 0, n)
        {
            scanf(" %s", inp);
            insert_trie();
        }
        
        ll res = recur();
        if(!res) res = 1;
        printf("%lld\n", res);
    }
    
    return 0;
}
