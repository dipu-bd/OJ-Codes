
#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 8105
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dp[101][MAX];
int dp2[101][1000];

int call(int indx, int sum)
{
    if(sum == 0)
        return true;
    if(indx >= 100 || sum < 0)
        return 0;
    int i, &ret = dp[indx][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(i = 1; i < 10; i++)
    {
        ret |= call(indx+1, sum - sqr(i));
        if(ret) return ret;
    }
    return ret;
}
int call2(int indx, int sum)
{
    if(sum == 0)
        return true;
    if(indx >= 100 || sum < 0)
        return 0;
    int i, &ret = dp2[indx][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(i = 1; i < 10; i++)
    {
        ret |= call(indx+1, sum - i);
        if(ret) return ret;
    }
    return ret;
}

vector <int> res;

bool path(int indx, int sum, int sq)
{
    if(sum == 0)
        return !sq;
    if(indx >= 100 || sum < 0 || sq < 0)
        return 0;
//    cout << "ic" << indx << ' ' << sum << ' ' << sq << endl;
    bool ret = 0;
    for(int i = 1; i < 10; i++)
    {
        if(call(indx+1,sq-sqr(i)) && call2(indx+1,sum-i))
            ret |= path(indx+1, sum-i, sq-sqr(i));
        if(ret)
        {
            res.pb(i);
            return ret;
        }
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j;
    clr(dp, -1);
    clr(dp2, -1);
    for(i = 0; i < MAX; i++)
        call(0, i);
    for(i = 0; i < 900; i++)
        call2(0, i);
    int test, sum, sq;
    cin >> test;
    while(test--)
    {
        res.clear();
        cin >> sum >> sq;
        if(!path(0, sum, sq))
        {
            cout << "No solution\n";
            continue;
        }
        sort(all(res));
        for(i = 0; i < SZ(res); i++)
            cout << res[i];
        cout << "\n";
    }
    return 0;
}
