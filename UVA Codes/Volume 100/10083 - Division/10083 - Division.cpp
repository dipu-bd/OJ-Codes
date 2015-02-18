/*============================
/\u7h0r : 5ud!p70 ch@ndr@ d@5
=============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct Bigint
{
    //
    // representations and structures
    //
    string digits; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise
    
    //
    // constructors
    //
    Bigint() {} // default constructor
    Bigint(string b )
    {
        (*this) = b;    // constructor for string
    }
    
    //
    // some helpful methods
    //
    int size()   // returns number of digits
    {
        return digits.size();
    }
    Bigint inverseSign()   // changes the sign
    {
        sign *= -1;
        return (*this);
    }
    Bigint normalize( int newSign )   // removes leading 0, fixes sign
    {
        for( int i = digits.size() - 1; i > 0 && digits[i] == '0'; i-- )
            digits.erase(digits.begin() + i);
        sign = ( digits.size() == 1 && digits[0] == '0' ) ? 1 : newSign;
        return (*this);
    }
    
    // assignment operator
    Bigint operator = ( string b )   // assigns a string to Bigint
    {
        digits = b[0] == '-' ? b.substr(1) : b;
        reverse( digits.begin(), digits.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
        return (*this);
    }
    
    //
    // conditional operators
    //
    bool operator < ( const Bigint &b ) const   // less than operator
    {
        if( sign != b.sign )
            return sign < b.sign;
        if( digits.size() != b.digits.size() )
            return sign == 1 ? digits.size() < b.digits.size() : digits.size() > b.digits.size();
        for( int i = digits.size() - 1; i >= 0; i-- )
            if( digits[i] != b.digits[i] )
            return sign == 1 ? digits[i] < b.digits[i] : digits[i] > b.digits[i];
        return false;
    }
    // conditional operators
    bool operator > ( const Bigint &b ) const   // less than operator
    {
        if( sign != b.sign ) return sign < b.sign;
        if( digits.size() != b.digits.size() )
            return sign == 1 ? digits.size() > b.digits.size() : digits.size() < b.digits.size();
        for( int i = digits.size() - 1; i >= 0; i-- )
            if( digits[i] != b.digits[i] )
            return sign == 1 ? digits[i] > b.digits[i] : digits[i] < b.digits[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const   // operator for equality
    {
        return digits == b.digits && sign == b.sign;
    }
    
    //
    // mathematical operators
    //
    Bigint operator + (Bigint b )   // addition operator overloading
    {
        if( sign != b.sign )
            return (*this) - b.inverseSign();
        
        Bigint c;
        
        for(int i = 0, carry = 0; i < (int)digits.size() || i < b.size() || carry; i++ )
        {
            carry += (i < (int)digits.size() ? digits[i] - '0' : 0)
            + (i < (int)b.digits.size() ? b.digits[i] - '0' : 0);
            c.digits += (carry % 10 + '0');
            carry /= 10;
        }
        
        return c.normalize(sign);
    }
    
    Bigint operator - ( Bigint b )   // subtraction operator overloading
    {
        if( sign != b.sign )
            return (*this) + b.inverseSign();
        
        int s = sign; 
        sign = b.sign = 1;
        
        Bigint c;
        
        if( (*this) < b )
        {
            c = (b - (*this)).inverseSign();
            return   c.normalize(-s);
        }
        
        
        for( int i = 0, borrow = 0, tmp; i < (int)digits.size(); i++ )
        {
            tmp = (i < b.size()) ? b.digits[i] : '0';
            borrow = digits[i] - borrow - tmp;
            
            c.digits += borrow >= 0 ? borrow + '0' : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    
    Bigint operator * ( Bigint b )   // multiplication operator overloading
    {
        Bigint c("0");
        for( int i = 0, k = digits[i] - '0'; i < (int)digits.size(); i++, k = digits[i] - '0' )
        {
            while(k--) c = c + b; // ith digit is k, so, we add k times
            b.digits.insert(b.digits.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }
    
    Bigint operator / ( Bigint b )   // division operator overloading
    {
        if( b.size() == 1 && b.digits[0] == '0' )
        {
            puts("Division by zero");
            abort();
        }
        
        Bigint c("0"), d;
        for( int j = 0; j < (int)digits.size(); j++ ) d.digits += "0";
        
        int dSign = sign * b.sign;
        b.sign = 1;
        for( int i = digits.size() - 1; i >= 0; i-- )
        {
            c.digits.insert( c.digits.begin(), '0');
            c = c + digits.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.digits[i]++;
        }
        return d.normalize(dSign);
    }
    
    Bigint operator % ( Bigint b )   // modulo operator overloading 
    {
        if( b.size() == 1 && b.digits[0] == '0' ) b.digits[0] /= ( b.digits[0] - '0' );
        Bigint c("0");
        b.sign = 1;
        for( int i = digits.size() - 1; i >= 0; i-- )
        {
            c.digits.insert( c.digits.begin(), '0');
            c = c + digits.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }
    
    //
    // output method
    //
    void print()
    {
        if( sign == -1 ) putchar('-');
        for( int i = digits.size() - 1; i >= 0; i-- )
            putchar(digits[i]);
    }
};

int t, a, b;

int li, lj, lk;
Bigint tb, tt, res;

void power(int p)
{
    if(p == 1) 
    {
        tb = tt;
    }
    else
    {
        power(p >> 1);
        tb = tb * tb;
        if(p & 1) tb = tb * tt;
    }
}

void findres(int n)
{
    char str[20];
    sprintf(str, "%d", t);
    
    tt = str;
    power(b);
    
    tt = "1";
    res = "0";
    REPE(i, 0, n)
    {
        res = res + tt;
        tt = tt * tb;
    }
}

bool process()
{
    if(t <= 1) return true;
    if(b == 0) return true;
    if(a % b != 0) return true;
    if(a == 0)
    {
        puts("0");
        return true;
    }
    
    int r = (int)((a - b) * log10(t) + 1);
    if(r > 100) return true;
    
    int n = a / b - 1;
    if(n == 0)
    {
        puts("1");
        return false;
    }
    
    findres(n);
    if(res.digits.size() > 100) return true;
    
    res.print();
    putchar('\n');
    return false;
}

int main()
{
    while(~sf3(t, a, b))
    {
        printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
        bool invalid = process();
        if(invalid) puts("is not an integer with less than 100 digits.");
    }
    
    return 0;
}