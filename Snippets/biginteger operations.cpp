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

int test, cas = 1;

//a and b should not contain any leading zero or non-digit characters

int compare(const string& a, const string& b)
{
    if(a.size() < b.size()) return -1;
    if(a.size() > b.size()) return 1;
    return a.compare(b);
}

string add(const string& a, const string& b)
{
    string r = "";

    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i >= 0 || j >= 0 || carry)
    {
        carry += (i >= 0 ? a[i--] - '0' : 0) +
                 (j >= 0 ? b[j--] - '0' : 0);
        r.push_back(carry % 10 + '0');
        carry = carry / 10;
    }

    //remove leading spaces
    while(r.size() && *r.rbegin() == '0')
        r.erase(r.end() - 1);
    if(r.empty()) r.push_back('0');

    //main string
    reverse(r.begin(), r.end());
    return r;
}

string subtract(const string& a, const string& b)
{
    int comp = compare(a, b);
    if(comp == 0) return "0";
    if(comp < 0) return "-" + subtract(b, a);

    string r = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while(i >= 0)
    {
        carry = (a[i--] - '0') - carry -
                (j >= 0 ? b[j--] - '0' : 0);
        r.push_back((carry + 10) % 10 + '0');
        carry = 1 - (carry + 10) / 10;
    }

    //remove leading spaces
    while(r.size() && *r.rbegin() == '0')
        r.erase(r.end() - 1);
    if(r.empty()) r.push_back('0');

    //main string
    reverse(r.begin(), r.end());
    return r;
}

string multiply(const string& a, int b)
{
    string r = "";

    int carry = 0;
    int i = a.size() - 1;
    while(i >= 0 || carry)
    {
        carry += b * (i >= 0 ? a[i--] - '0' : 0);
        r.push_back(carry % 10 + '0');
        carry = carry / 10;
    }

    //remove leading spaces
    while(r.size() && *r.rbegin() == '0')
        r.erase(r.end() - 1);
    if(r.empty()) r.push_back('0');

    //main string
    reverse(r.begin(), r.end());
    return r;
}

string multiply(const string& a, const string& b)
{
    //for faster performance
    if(compare(a, b) < 0)
    {
        return multiply(b, a);
    }

    string p = "";
    string r = "0";
    int i = b.size() - 1;
    while(i >= 0)
    {
        int d = b[i--] - '0';
        string t = multiply(a, d);
        r = add(t + p, r);
        p.push_back('0');
    }

    return r;
}

struct strdiv_t
{
    string quot;
    string rem;
    strdiv_t() { quot.clear(); rem.clear(); }
};

strdiv_t divide(const string& a, const string& b)
{
    strdiv_t r;
    for(int i = 0; i < a.size(); ++i)
    {
        if(r.rem == "0") r.rem[0] = a[i];
        else r.rem.push_back(a[i]);
        if(compare(r.rem, b) < 0)
        {
            if(r.quot.size()) r.quot.push_back('0');
            continue;
        }

        int q = 0;
        while(compare(r.rem, b) >= 0)
        {
            ++q;
            r.rem = subtract(r.rem, b);
        }

        r.quot.push_back(q + '0');
    }

    if(r.quot.empty()) r.quot.push_back('0');
    if(r.rem.empty()) r.rem.push_back('0');
    return r;
}

void runtest()
{
    char a[20];
    char b[20];
    string r[10];
    long long z[10];
    for(int i = 0; i < 10000000; ++i)
    {
        long long x = rand();
        long long y = rand();
        sprintf(a, "%lld", x);
        sprintf(b, "%lld", y);


        r[0] = add(a, b);
        r[1] = subtract(a, b);
        r[2] = multiply(a, b);
        if(y != 0)
        {
            r[3] = divide(a, b).quot;
            r[4] = divide(a, b).rem;
        }

        for(int i = 0; i <= 4; ++i)
        {
            if(i > 2 && y == 0) break;
            sscanf(r[i].data(), "%lld", z + i);
        }

        if(z[0] != x + y) printf("       Addtion Failed : %lld + %lld : expected = %lld : given = %s\n", x, y, x + y, r[0].data());
        if(z[1] != x - y) printf("   Subtraction Failed : %lld - %lld : expected = %lld : given = %s\n", x, y, x - y, r[1].data());
        if(z[2] != x * y) printf("Multiplication Failed : %lld * %lld : expected = %lld : given = %s\n", x, y, x * y, r[2].data());
        if(y != 0)
        {
            if(z[3] != x / y) printf("      Division Failed : %lld / %lld : expected = %lld : given = %s\n", x, y, x / y, r[3].data());
            if(z[4] != x % y) printf("     Remainder Failed : %lld %% %lld : expected = %lld : given = %s\n", x, y, x % y, r[4].data());
        }
    }
}

int main()
{
    runtest();
    return 0;

    string a = "21201";
    string b = "4";
    strdiv_t r = divide(a, b);
    cout << r.quot << " " << r.rem << endl;
    return 0;
}
