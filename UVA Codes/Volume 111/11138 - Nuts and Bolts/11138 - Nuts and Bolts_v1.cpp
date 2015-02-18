#include <string.h>
#include <stdio.h>

#define MAX_BOLTS 500
#define MAX_NUTS  500

/* global copy of the input data */
int nuts, bolts;
int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void)
{
    int n, b;

    scanf("%d%d", &bolts, &nuts);
    for(b = 0; b < bolts; b++)
    {
        for(n = 0; n < nuts; n++)
        {
            scanf("%d", &fits[b][n]);
        }
    }
}

/* data used to match nuts with bolts */
int bestmatched;
int nut_parent[MAX_NUTS];
bool bolt_visited[MAX_BOLTS];


bool dfs(int u)
{
    if(bolt_visited[u]) return false;
    bolt_visited[u] = true;
    for(int n = 0; n < nuts; n++)
    {
        if(!fits[u][n]) continue;
        if(nut_parent[n] == -1 || dfs(nut_parent[n]))
        {
            nut_parent[n] = u;
            return true;
        }
    }
    return false;
}

void match_bolt()
{
    int b;
    bestmatched = 0;
    memset(nut_parent, -1, sizeof(nut_parent));
    for(b = 0; b < bolts; b++)
    {
        memset(bolt_visited, 0, sizeof(bolt_visited));
        if(dfs(b)) ++bestmatched;
    }
}

int main()
{
    int cases, caseno;

    scanf("%d", &cases);
    for(caseno = 1; caseno <= cases; caseno++)
    {
        read_input_data();
        match_bolt();
        printf("Case %d: ", caseno);
        printf("a maximum of %d nuts and bolts ", bestmatched);
        printf("can be fitted together\n");
    }

    return 0;
}
