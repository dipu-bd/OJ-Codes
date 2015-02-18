// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <vector>
// default namespace
using namespace std;

struct BigInt
{
    string num;
    void normalize(void)
    {
        int i;
        for(i = num.size() - 1; num[i] == '0' && i; --i);
        num = num.substr(0, i + 1);
        return;
    }

    BigInt() { num = "0"; };
    BigInt(string s) { *this = s; };

    BigInt& operator = (BigInt& rval)
    {
        num = rval.num;
        return *this;
    }
    BigInt& operator = (string s)
    {
        for(string::iterator i = s.end() - 1; i >= s.begin(); --i)
            num.push_back(*i);
        normalize();
        return *this;
    }

    friend ostream& operator << (ostream& ostr, const BigInt& a)
    {
        const char* c_str = a.num.c_str();
        for(int i = a.num.size() - 1; i >= 0; --i) ostr << *(c_str + i);
        return ostr;
    }

    inline int size() { return num.size(); }

    BigInt& operator + (BigInt& rval)
    {
        const char* a = num.data();
        const char* b = rval.num.data();

        for(int carry = 0, i = 0, al = size(), bl = rval.size();
                carry || i < al || i < bl; ++i, carry /= 10)
        {
            carry += (i >= al ? 0 : * (a + i) - '0') + (i >= bl ? 0 : * (b + i) - '0');
            if(i < al) num[i] = carry % 10 + '0';
            else num.push_back(carry % 10 + '0');
        }

        return *this;
    }

    void print(void)
    {
        const char* a = num.data();
        for(int i = size() - 1; i >= 0; --i) putchar('0' + * (a + i));
        return;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("485.out", "w", stdout);
#endif

    const BigInt a = string("1");
    BigInt prev, tmp;
    vector<BigInt> row;
    row.push_back(a);
    int max_size = 1;

    cout << "1\\n";
    while(max_size <= 60)
    {
        cout << "1 ";
        max_size = 1;
        prev = row.front();
        for(vector<BigInt>::iterator it = row.begin() + 1; it < row.end(); ++it)
        {
            tmp = *it;
            *it = *it + prev;
            prev = tmp;

            cout << *it << " ";
            if(it->size() > max_size) max_size = it->size();
        }
        cout << "1\\n";

        row.push_back(a);
    }

    return 0;
}
