/*==================================
Author : Sudipto Chandra (Dipu)
Email  : dipu.sudipta@gmail.com
University : SUST
===================================*/
//#include <bits/stdc++.h>
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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define sz(v) ((int)(v).size())
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

struct Student
{
    int cid;
    int rank;
    char sid[15];
    char name[15];
    int score[4];
    int pass;
    
    int total()
    {
        return score[0] + score[1] + score[2] + score[3];
    }
    double average()
    {
        return 1e-5 + (total() / 4.0);
    }
    bool isPass(int i)
    {
        return score[i] >= 60;
    }
};
 
vector<Student> data;

bool rankComp(const pii& a, const pii& b)
{
    return (a.fr > b.fr) || (a.fr == b.fr && a.sc < b.sc);
}

void updateRank()
{
    vector<pii> ranks;
    REP(i, 0, sz(data))
    {
        ranks.pb(mp(data[i].total(), i));
    }
    
    stable_sort(all(ranks), rankComp);
    
    int cr = 0;
    REP(i, 0, sz(ranks))
    { 
        if(i == 0 || ranks[i].fr < ranks[i - 1].fr) cr = i + 1;
        data[ranks[i].sc].rank = cr;
    }
}

void mainMenu()
{
    puts("Welcome to Student Performance Management System (SPMS).");
    puts("");
    puts("1 - Add");
    puts("2 - Remove");
    puts("3 - Query");
    puts("4 - Show ranking");
    puts("5 - Show Statistics");
    puts("0 - Exit");
    puts("");
}

void addStudent()
{
    Student stu;
    while(true)
    {
        puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
        
        scanf(" %s", stu.sid);
        if(!strcmp(stu.sid, "0")) break;
        
        scanf("%d %s", &stu.cid, stu.name);
        stu.pass = 0;
        REP(i, 0, 4)
        {
            scanf("%d", &stu.score[i]);
            if(stu.score[i] >= 60) stu.pass++;
        }
        
        bool exist = false;
        REP(i, 0, sz(data))
        if(!strcmp(data[i].sid, stu.sid))
        {
            exist = true;
            break;
        }
        
        if(exist) puts("Duplicated SID.");
        else data.push_back(stu);
    }
}

void removeStudent()
{
    char inp[20];
    while(true)
    {
        puts("Please enter SID or name. Enter 0 to finish.");
        
        scanf(" %s", inp);
        if(!strcmp(inp, "0")) return;
        
        int xx = 0;
        bool name = isupper(inp[0]);
        while(true)
        {
            int p = -1;
            REP(i, 0, sz(data))
            {
                if(name && strcmp(inp, data[i].name)) continue;
                if(!name && strcmp(inp, data[i].sid)) continue;
                
                p = i;
                break;
            }
            
            if(p == -1) break;
            data.erase(data.begin() + p);
            ++xx;
        }
        
        printf("%d student(s) removed.\n", xx);
    }
}

void queryStudent()
{
    updateRank();
    
    char inp[20];
    while(true)
    {
        puts("Please enter SID or name. Enter 0 to finish.");
        
        scanf(" %s", inp);
        if(!strcmp(inp, "0")) break;
        
        bool name = isupper(inp[0]);
        REP(i, 0, sz(data))
        {
            if(name && strcmp(inp, data[i].name)) continue;
            if(!name && strcmp(inp, data[i].sid)) continue;
            
            printf("%d %s ", data[i].rank, data[i].sid);
            printf("%d %s ",  data[i].cid, data[i].name);
            REP(k, 0, 4) printf("%d ", data[i].score[k]);
            printf("%d %.2lf\n", data[i].total(), data[i].average()); 
        }
    }
}

void showRanking()
{
    puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
}

void showStats()
{
    int cid;
    int num;
    int lang[4][3];
    int overall[5];
    char sub[4][20] = { "Chinese", "Mathematics", "English", "Programming" };
    
    puts("Please enter class ID, 0 for the whole statistics.");
    scanf("%d", &cid);
    
    num = 0;
    clr(lang);
    clr(overall);
    
    REP(i, 0, sz(data))
    {
        if(cid && data[i].cid != cid) continue;
        
        ++num;
        REP(k, 0, 4)
        {
            lang[k][0] += data[i].score[k];
            lang[k][1] += data[i].isPass(k);
            lang[k][2] += !data[i].isPass(k);
        }
        if(data[i].pass == 4) overall[0]++;
        if(data[i].pass >= 3) overall[1]++;
        if(data[i].pass >= 2) overall[2]++;
        if(data[i].pass >= 1) overall[3]++;
        if(data[i].pass == 0) overall[4]++;
    }
    
    if(num == 0) num = 1;
    
    REP(k, 0, 4)
    {
        puts(sub[k]);
        printf("Average Score: %.2lf\n", 1e-5 + (double)lang[k][0] / num);
        printf("Number of passed students: %d\n", lang[k][1]);
        printf("Number of failed students: %d\n", lang[k][2]);
        puts("");
    }
    
    puts("Overall:");
    printf("Number of students who passed all subjects: %d\n", overall[0]);
    printf("Number of students who passed 3 or more subjects: %d\n", overall[1]);
    printf("Number of students who passed 2 or more subjects: %d\n", overall[2]);
    printf("Number of students who passed 1 or more subjects: %d\n", overall[3]);
    printf("Number of students who failed all subjects: %d\n", overall[4]);
    puts("");
}

int main()
{
    int n;
    while(true)
    {
        mainMenu();
        scanf("%d", &n);
        if(n == 1) addStudent();
        else if(n == 2) removeStudent();
        else if(n == 3) queryStudent();
        else if(n == 4) showRanking();
        else if(n == 5) showStats();
        else break;
    }
    
    return 0;
}
