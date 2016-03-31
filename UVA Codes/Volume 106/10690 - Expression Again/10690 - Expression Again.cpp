#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int cas = 1;
int n, m, tot;
int arr[110];
pii save[105][52][2600];
int _save[105][52][2600];

pii recur(int p, int t, int s)
{
    if(t == n)
    {
        int r = s * (tot - s);
        return make_pair(r, r);
    }
    if(p > n + m)
    {
        return make_pair(0, tot);
    }
    
    pii& dp = save[p][t][s];
    int& dpc = _save[p][t][s];
    if(dpc == cas) return dp;
    dpc = cas;
    
    pii a = recur(p + 1, t, s);
    pii b = recur(p + 1, t + 1, s + arr[p]);
     
    dp.first = max(a.first, b.first);
    dp.second = min(a.second, b.second);
    
    return dp;
}

int main()
{
    while(scanf("%d %d", &n, &m) == 2)
    {
        tot = 0;
        for(int i = n + m; i >= 1; --i)
        {
            scanf("%d", &arr[i]);
            tot += arr[i];
        }
        
        ++cas;
        pii t = recur(1, 0, 0);
        printf("%d %d\n", t.first, t.second);
    }
}