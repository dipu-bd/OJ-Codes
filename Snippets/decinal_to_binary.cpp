/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//useful definitions
#define gcd(a,b) __gcd(a,b)
#define mem(a,b) memset(a, b, sizeof(a))
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
template<typename T> inline T sqr(T n) { return n * n; }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, long long p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod(T n,  long long p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/
//typedefs
typedef long long ll;
typedef pair<ll, ll> pii;

int test, cas = 1;


struct Binary
{
    int len;
    char arr[10000];

    Binary()
    {
        clear();
    }

    void clear()
    {
        len = 0;
        memset(arr, 0, sizeof(arr));
    }

    int get(int i)
    {
        return (arr[i >> 3] & (1 << (i & 7)));
    }

    void set(int i, bool v)
    {
        if(v) arr[i >> 3] |=  ~(1U << (i & 7));
        else arr[i >> 3] &=  ~(1U << (i & 7));
    }

    static Binary toBinary(long long n)
    {
        Binary res;
        for(int i = 0; n; ++i)
        {
            ++res.len;
            res.set(i, n & 1);
            n >>= 1;
        }
        return res;
    }

    string toNumber()
    {
        string num = "";
        for(int i = len - 1; i > 0; ++i)
        {
            num.push_back(get(i) + '0');
            for(int j = num.size() - 1; j > 0; --j)
            {

            }
        }
    }

    Binary shiftLeft(int n)
    {
        Binary res;
        res.len = len + n;
        int base = n >> 3;
        int off = (1 << (n & 7));
        for(int i = 0; i <= (len << 3); ++i)
        {
            res.arr[i + base] |= arr[i] << off;
            res.arr[i + base + 1] |= arr[i] >> (7 - off);
        }
        return res;
    }

    Binary add(Binary val)
    {
        Binary eight = val.shiftLeft(3);
        Binary two = val.shiftLeft(1);
        int rem = 0;

    }

};


string inp;
Binary bin, tmp;

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    string inp;
    cin >> inp;


    return 0;
}

