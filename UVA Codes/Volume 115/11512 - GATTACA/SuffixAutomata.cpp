//#pragma warning (disable: 4786)

#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define REP(i,n)    for(i=0;i<n;i++)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define csprnt printf("Case %d: ", ++cas);

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
//Link = Longest Proper suffix in suffix automata(already exist). (next clear can be needed)
//Depth means the highest substring attainable towards these node. Some strings are already attained by the link of the node(the total depth of the link)
//Preprocess complexity nlogk (k=number of child)

struct state {
    int depth, link ;
    map < char , int > next ;  //by sacrificing memory we can make it linear
    void initialize(){
        next.clear();
        link=-1;
        depth=0;
    }
};

const int MAXLEN = 100010; //stringsize
state st [ MAXLEN * 2 ] ;
int sz, last ;
/* when topological sort is needed (insert frequeny)
int height[MAXLEN],top[2*MAXLEN]; //for topological sort
int maxhei;
for(i=0;i<sz;i++) height[st[i].depth]++;
for(i=1;i<=maxhei;i++) height[i]+=height[i-1];
for(i=0;i<sz;i++) top[--height[st[i].depth]] = i;
for(i=sz-1;i>=1;i--)
{
    int now=top[i];
    st[st[now].link].freq+=st[now].freq;
}
*/

void sam_init ( ) {
    //topological sort
    //mem(height,0);
    //maxhei=0;
    st[0].initialize();
    sz = last = 0 ;
    ++ sz ;
    
}

//intially clone frequency is 0 and regular node frequency 1
void sam_extend ( char c ) {
    //it is needed for more than 1 string
    if(st[last].next[c])
    {
        int q = st [ last ] . next [ c ] ;
        int p = last;
        if ( st [ p ] . depth + 1 == st [ q ] . depth )
            last = q ;
        else
        {
            int clone = sz ++ ; //clone of q
            st[clone].initialize();
            st [ clone ] . depth = st [ p ] . depth + 1 ;
            st [ clone ] . next = st [ q ] . next ;
            st [ clone ] . link = st [ q ] . link ;
            for ( ; p!= -1 && st [ p ] . next [ c ] == q ; p = st [ p ] . link )
                st [ p ] . next [ c ] = clone ;
            st [ q ] . link = clone ;
            last = clone;
        }
        return;
    }
    
    int cur = sz ++ ;
    st[cur].initialize();
    st [ cur ] . depth = st [ last ] . depth + 1 ;
    int p;
    
    for ( p = last; p!= -1 && !st [ p ] . next[c]  ; p = st [ p ] . link )
        st [ p ] . next [ c ] = cur ;
    if ( p == - 1 )
        st [ cur ] . link = 0 ;
    else {
        int q = st [ p ] . next [ c ] ;
        if ( st [ p ] . depth + 1 == st [ q ] . depth )
            st [ cur ] . link = q ;
        else
        {
            int clone = sz ++ ; //clone of q
            st[clone].initialize();
            st [ clone ] . depth = st [ p ] . depth + 1 ;
            st [ clone ] . next = st [ q ] . next ;
            st [ clone ] . link = st [ q ] . link ;
            for ( ; p!= -1 && st [ p ] . next [ c ] == q ; p = st [ p ] . link )
                st [ p ] . next [ c ] = clone ;
            st [ q ] . link = st [ cur ] . link = clone ;
        }
    }
    last = cur ;
}

string lcs (string s, string t) { //longest common substring with length
    sam_init();
    for (int i=0; i<(int)s.length(); ++i)
        sam_extend (s[i]);
    
    int v = 0,  l = 0,
    best = 0,  bestpos = 0;
    for (int i=0; i<(int)t.length(); ++i) {
        while (v && ! st[v].next.count(t[i])) {
            v = st[v].link;
            l = st[v].depth;
        }
        if (st[v].next.count(t[i])) {
            v = st[v].next[t[i]];
            ++l;
        }
        if (l > best)
            best = l,  bestpos = i;
    }
    return t.substr (bestpos-best+1, best);
}

void all_occurences ( int v, int p_length ) {
    
    while(true) {
        if ( ! st [ v ] . isclone )
            noverlap.pb(st [ v ] . in - p_length );
        for ( int i = 0 ; i < st [ v ] . inv_link . size ( ) ; ++ i )
            all_occurences ( st [ v ] . inv_link [ i ] , p_length ) ;
    }
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    return 0;
}

/*
abcbc
*/