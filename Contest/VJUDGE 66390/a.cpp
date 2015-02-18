#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sf scanf
#define sz(a) (int) a.size()

int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
typedef vector<int>vi;
#define pb push_back
int n, arr[1001];

//#include <conio.h>

bool check(int &p, int i, int sum, vi &v)
{
//    if(sz(v) == 2 and v[0] == 4 and v[1] == 5 and v[2] == 6)
//    {
//        pf("i = %d\tsum = %d\n", i, sum); getch();
//    }
    if(sum > p)
        return 0;
    if(sum == p)
        return 1;
    if(i >= sz(v))
        return 0;
    if(check(p, i + 1, sum + num[v[i]], v) == true)
        return true;
    return check(p, i + 1, sum, v);
}

bool call(vi& v)
{
    for(int i = 0; i < n; i++)
    {
        if(check(arr[i], 0, 0, v) == 0)
            return 0;
    }
    return 1;
}

bool cmp(vi & save, vi& v)
{
    if(sz(v) == 3)
    {
//        pf("now\n");getch();
//        for(int i=0; i<sz(save); i++) pf("%d %d\n",save[i], v[i]); getch();
    }
    for(int i = 0; i < sz(save); i++)
    {
        if(save[i] < v[i])
            return 0;
    }
//    pf("returning 1\n");
    return 1;
}

void solve(void)
{
    int p, lim = pow(2, 10), mini = 10000;
    vi save;
    for(int i = 0; i < lim; i++)
    {
        vi v;
        for(int j = 0; j < 10; j++)
        {
            if((i & (1 << j)))
            {
                v.pb(j);
            }
        }

//        for(int i=0; i<sz(v); i++) pf("%d ", v[i]);
//        puts("");

//        {
//            sort(v.begin(), v.end());
//            bool flag = 0;
//        }

//        if(sz(v) == 3 and v[0] == 4 and v[1] == 5 and v[2] == 6)
//        {
//            pf("baby\n");
//            scanf("%d",&p);
//            pf("call = %d\n", call(v));
//            scanf("%d",&p);
//        }

        if(call(v) == true)
        {
            if(sz(v) < mini)
            {
                mini = sz(v);
                save = v;
            }
            else if(sz(v) == mini)
            {
                sort(v.rbegin(), v.rend());
                sort(save.rbegin(), save.rend());
                if(cmp(save, v) == true)
                    save = v;
            }
        }
    }
    for(int i = 0; i < sz(save); i++) pf("%d", save[i]);
    puts("");
    return ;
}

int main()
{
    int cases = 1;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) sf("%d", &arr[i]);
        pf("Case %d: ", cases++);
        solve();
    }
    return 0;
}
