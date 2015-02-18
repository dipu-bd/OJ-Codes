#include <bits/stdc++.h>
using namespace std;

//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)

vector<int>vec;
int par[1001000];
bool vis[1000100];
set<int> graph[100005];

void BFS(int source, int target)
{
    queue<int>q;
    q.push(source);
    vis[source] = 1;
    par[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == target) break;
        loop(it, graph[u])
        {
            int  v = *it;
            if(!vis[v])
            {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    vec.clear();
    int u = target;
    while(u != -1)
    {
        vec.push_back(u);
        u = par[u];
    }


    bool sp = false;
    rloop(it, vec)
    {
        if(sp) putchar(' ');
        else sp = true;
        printf("%d", *it);
    }
    putchar('\n');

    return ;
}

int main()
{
    int N, pre, a;

    scanf("%d", &N);
    scanf("%d", &pre);

    int source = pre;
    int target = pre;
    for(int i = 1; i < N; i++)
    {
        scanf("%d", &a);
        graph[pre].insert(a);
        pre = a;
        target = a;
    }

    BFS(source, target);

    return 0;
}
