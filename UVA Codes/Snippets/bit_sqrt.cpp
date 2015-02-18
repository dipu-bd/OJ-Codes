#include <bits/stdc++.h>
using namespace std;

string getbin(int n)
{
    string res = "";
    if(n == 0) res = "0";
    while(n > 0)
    {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    return  res;
}

int findsqrt(int num)
{
    int res = 0;
    int bit = 1 << 30; // The second-to-top bit is set: 1 << 30 for 32 bits

    // "bit" starts at the highest power of four <= the argument.
    while (bit > num)
        bit >>= 2;

    cerr << "Main : num = " << num << " = " << getbin(num) << endl;

    int step = 1;
    while (bit != 0)
    {
        cerr << "Step " << step << " : " << endl
             << "    num = " << getbin(num) << endl
             << "    res = " << getbin(res) << endl
             << "    bit = " << getbin(bit) << endl;

        if (num >= res + bit)
        {
            cerr << " As num >= res + bit : " << getbin(num) << " >= " << getbin(res + bit) << endl;

            num -= res + bit;
            res = (res >> 1) + bit;

            cerr << "    num -= res + bit  : num = " << getbin(num) << endl
                 << "    res = (res >> 1) + bit : res = " << getbin(res) << endl;
        }
        else
        {
            cerr << " As num < res + bit : " << getbin(num) << " >= " << getbin(res + bit) << endl;

            res >>= 1;

            cerr << "    res >>= 1 : res = " << getbin(res) << endl;
        }

        bit >>= 2;

        cerr << "    bit >>= 2 : bit = " << getbin(bit) << endl << endl;
        ++step;
    }

    cerr << "Final Result : res = " << res << " = " << getbin(res) << endl << endl;

    return res;
}


int main()
{
    findsqrt(0b10000000000000);
    return 0;
}
