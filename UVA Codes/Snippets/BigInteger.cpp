/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
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
using namespace std;

class BigInteger
{
    /* --------------------
     * IO Operators
     * -------------------- */
    friend istream& operator >> (istream& in, BigInteger& bi)
    {
        string str;
        in >> str;
        bi = str.data();
        return in;
    }
    friend ostream& operator << (ostream& out, const BigInteger& bi)
    {
        out << bi.toString();
        return out;
    }

private :

    /* --------------------
     * Member variables
     * -------------------- */

    typedef char NUM_TYPE;
    typedef vector<char> NUM_ARRAY;
    typedef vector<char>::iterator NUM_ARRAY_IT;
    typedef vector<char>::reverse_iterator NUM_ARRAY_RIT;

    char sign;
    int npos;
    int buf_siz;        //default = 100
    NUM_ARRAY num;      //numbers are in reverse order and in integer format

    template <class T>
    struct div_res
    {
        T quot;
        T rem;

        div_res(const T& _quot, const T& _rem)
        {
            quot = _quot;
            rem = _rem;
        }
    };

    void __init(int nsize = 0)
    {
        if(nsize < 0) nsize = 0;
        if(num.size() > nsize + 10) return;

        buf_siz = (nsize + 50);
        while(num.size() < buf_siz)
            num.push_back(0);
    }

    void __format()
    {
        while(npos > 0 && num[npos - 1] == 0) --npos;
        if(npos == 0) sign = 1, num[npos++] = 0;
    }

public :

    /* --------------------
     * Contructor, Destructor
     * -------------------- */
    BigInteger()
    {
        sign = 1;
        npos = 0;
        buf_siz = 0;
    }
    template <typename T>
    BigInteger(T n)
    {
        BigInteger();
        *this = n;
    }
    BigInteger(const char* str)
    {
        BigInteger();
        *this = str;
    }

    ~BigInteger()
    {
        num.clear();
    }


    /* -------------------- */
//{  Comparasion
    /* -------------------- */
    bool operator < (const BigInteger& b) const
    {
        if(sign != b.sign)
            return sign < b.sign;

        if(npos != b.npos)
            return npos < b.npos;

        for(int i = npos - 1; i >= 0; --i)
        {
            if(num[i] != b.num[i])
                return num[i] < b.num[i];
        }

        return false;
    }
    bool operator == (const BigInteger& b) const
    {
        if(sign != b.sign) return false;
        if(npos != b.npos) return false;

        for(int i = npos - 1; i >= 0; --i)
        {
            if(num[i] != b.num[i]) return false;
        }

        return true;
    }
    bool operator > (const BigInteger& b) const
    {
        if(sign != b.sign)
            return sign > b.sign;

        if(npos != b.npos)
            return npos > b.npos;

        for(int i = npos - 1; i >= 0; --i)
        {
            if(num[i] != b.num[i])
                return num[i] > b.num[i];
        }

        return false;
    }
    bool operator <= (const BigInteger& b) const
    {
        return !(*this > b);
    }
    bool operator >= (const BigInteger& b) const
    {
        return !(*this < b);
    }

    template <typename T>
    bool operator < (T n) const
    {
        if(n == 0) return sign < 0;
        return *this < BigInteger(n);
    }
    template <typename T>
    bool operator == (T n) const
    {
        if(n == 0) return isZero();
        return *this == BigInteger(n);
    }
    template <typename T>
    bool operator > (T n) const
    {
        if(n == 0) return sign > 0;
        return *this > BigInteger(n);
    }
    template <typename T>
    bool operator <=(T n) const
    {
        return !(*this > n);
    }
    template <typename T>
    bool operator >=(T n) const
    {
        return !(*this < n);
    }
//}

    /* -------------------- */
//{      Assignment Operators
    /* -------------------- */
    BigInteger& operator = (long long n)
    {
        __init();

        //determine the sign
        if(n < 0) sign = -1, n = -n;
        else sign = 1;

        //save value from left
        npos = 0;
        while(n > 0)
        {
            num[npos++] = n % 10;
            n /= 10;
        }

        __format();
        return *this;
    }

    BigInteger& operator = (const string& str)
    {
        *this = str.data();
    }

    BigInteger& operator = (const char* str)
    {
        int left = 0, right;

        //determine the sign
        if(str[left] == '-') sign = -1, ++left;
        else sign = 1;

        //take only digits
        right = left;
        while(isdigit(str[right])) ++right;

        //ignore leading zeros
        while(str[left] == '0' && left < right) ++left;

        //take memory for num array
        __init(right - left);

        //save the number in reverse order
        npos = 0;
        for(int i = right - 1; i >= left; --i)
            num[npos++] = str[i] - '0';

        __format();
        return *this;
    }
//}

    /* --------------------
     * Addition
     * -------------------- */

    template <typename T>
    BigInteger operator + (T n)
    {
        return *this + BigInteger(n);
    }

    BigInteger operator + (BigInteger b)
    {
        if(sign != b.sign)
        {
            if(b.sign < 0) return (*this) - (-b);
            else return (b) - (-*this);
        }

        /* at this point [ (a >= 0 <=> b >= 0) and (a < 0 <=> b < 0) ] */

        BigInteger res;

        res.sign = sign;
        int sz = max(npos, b.npos);
        res.__init(sz);

        int t = 0;
        for(int i = 0; i < sz; ++i)
        {
            if(i < npos) t += num[i];
            if(i < b.npos) t += b.num[i];
            res.num[res.npos++] = (t % 10);
            t /= 10;
        }
        while(t > 0)
        {
            res.num[res.npos++] = (t % 10);
            t /= 10;
        }

        res.__format();
        return res;
    }

    /* --------------------
     * Substruction
     * -------------------- */
    BigInteger operator -() const
    {
        BigInteger bi(*this);
        bi.sign = -bi.sign;
        return bi;
    }

    template <typename T>
    BigInteger operator - (T n)
    {
        return (*this) - BigInteger(n);
    }

    BigInteger operator - (BigInteger b)
    {
        if(sign != b.sign)
        {
            if(b.sign < 0) return (*this + (-b));
            else return -((-*this) + b);
        }
        if(b.sign < 0) return (-b) - (-*this);
        if(*this < b) return -(b - *this);

        /* at this point [ a > b >= 0 ] */

        BigInteger res;

        res.npos = 0;
        res.sign = 1;
        res.__init(npos);

        int t = 0, s;
        for(int i = 0; i < npos; ++i)
        {
            s = num[i] - t;
            if(i < b.npos) s -= b.num[i];

            t = (s < 0);
            res.num[res.npos++] = 10 * t + s;
        }

        if(res.npos == 0) res.num[res.npos++] = 0;
        res.num[res.npos] = 0;

        res.__format();
        return res;
    }

    /* --------------------
     * Multiplication
     * -------------------- */

    template <typename T>
    BigInteger operator * (T n)
    {
        BigInteger res("0");
        if(n == 0 || isZero()) return res;

        res.__init(npos);
        res.sign = sign;
        res.npos = 0;
        if(n < 0) res.sign *= -1, n = -n;

        T tmp = 0;
        for(int i = 0; i < npos; ++i)
        {
            tmp += n * num[i];
            res.num[res.npos++] = tmp % 10;
            tmp /= 10;
        }
        while(tmp > 0)
        {
            res.num[res.npos++] = tmp % 10;
            tmp /= 10;
        }

        res.__format();
        return res;
    }

    BigInteger operator * (BigInteger b)
    {
        if(npos > b.npos) return b * (*this);

        BigInteger res("0");
        if(isZero() || b.isZero()) return res;

        for(int i = npos - 1; i >= 0; --i)
            res = (res << 1) + (b * num[i]);

        res.sign = sign * b.sign;
        return res;
    }

    /* --------------------
     * Division and Modulus
     * -------------------- */

    template <typename T>
    BigInteger operator / (T n)
    {
        return *this / BigInteger(n);
    }
    BigInteger operator / (BigInteger b)
    {
        return divideBy(b).quot;
    }

    template <typename T>
    T operator % (T n)
    {
        T r = 1;
        for(int i = npos - 1; i >= 0; --i)
            r = ((r << 1) + num[i]) % n;
        return r;
    }
    BigInteger operator % (BigInteger b)
    {
        return divideBy(b).rem;
    }

    div_res<BigInteger> divideBy(BigInteger b)
    {
        assert(!b.isZero());

        BigInteger quot("0"), rem("0");
        int qsign = sign * b.sign;
        b.sign = 1;

        if(abs(*this) < b)
            return div_res<BigInteger>(quot, *this);
        else if(num == b.num)
            return div_res<BigInteger>(BigInteger(qsign), rem);

        for(int i = npos - 1; i >= 0; --i)
        {
            quot = (quot << 1);
            rem = (rem << 1) + num[i];
            if(rem < b) continue;

            int n = 0;
            do
            {
                rem = rem - b;
                ++n;
            }
            while(rem >= b);

            quot = quot + n;
        }

        quot.sign = qsign;
        rem.sign = sign;
        return div_res<BigInteger>(quot, rem);
    }

    /* --------------------
      * bitshift operators
      * -------------------- */
    BigInteger& operator >>= (int n) //divide by power of 10
    {
        if(n < 1) return *this;

        int p = 0;
        for(int i = n; i < npos; ++i)
            num[p++] = num[i];

        npos = p;
        __format();
        return *this;
    }

    BigInteger& operator <<= (int n) //multiply by power of 10
    {
        if(n < 1) return *this;

        __init(npos + n);

        int p = p = npos + n;
        for(int i = npos; i >= 0; --i)
            num[p--] = num[i];
        while(p >= 0) num[p--] = 0;

        npos += n;
        __format();
        return *this;
    }

    BigInteger operator >> (int n) //divide by power of 10
    {
        BigInteger res = *this;
        res >>= n;
        return res;
    }

    BigInteger operator << (int n) //multiply by power of 10
    {
        BigInteger res = *this;
        res <<= n;
        return res;
    }


    /* --------------------
      * power functions
      * -------------------- */
    BigInteger operator ^ (int b)   //power operator
    {
        if(b < 0) BigInteger(0);
        if(b == 0) return BigInteger(1);
        if(b == 1) return (*this);
        BigInteger res = (*this) ^ (b >> 1);
        res = res * res;
        if(b & 1) res = (*this) * res;
        return res;
    }

    /* --------------------
      * friend functions
      * -------------------- */

    friend BigInteger abs(BigInteger b)
    {
        return (b < 0) ? -b : b;
    }

    /* --------------------
     * Iterator Options
     * -------------------- */
    int size()
    {
        return npos;
    }

    NUM_TYPE& operator [] (int i)
    {
        if(i >= npos) return num[npos];
        return num[npos - 1 - i];
    }

    void push_back(int n)
    {
        num[npos++] = n;
    }
    void pop_back()
    {
        num[npos--] = 0;
    }

    void push_front(int n)
    {
        *this <<= 1;
        num[0] = n;
    }
    void pop_front()
    {
        *this >>= 1;
    }

    NUM_ARRAY_IT begin()
    {
        return num.begin();
    }
    NUM_ARRAY_IT end()
    {
        return num.end();
    }
    NUM_ARRAY_RIT rbegin()
    {
        return num.rbegin();
    }
    NUM_ARRAY_RIT rend()
    {
        return num.rend();
    }


    /* --------------------
     * Useful Functions
     * -------------------- */
    bool isZero() const
    {
        return num[0] == 0 && npos == 1;
    }
    bool isOdd() const
    {
        return (num[0] & 1);
    }

    string toString() const
    {
        string out;
        if(sign < 0) out.push_back('-');
        for(int i = npos - 1; i >= 0; --i)
            out.push_back(num[i] + '0');
        return out;
    }

    long long toLongInt() const
    {
        long long out = 0;
        for(int i = npos - 1; i >= 0; --i)
            out = out * 10 + num[i];
        if(sign < 0) out = -out;
        return out;
    }

};


int main()
{
    string op;
    BigInteger a, b;

    cout << "Available operator: + - * / % ^(power) < > <= >= == << >>\n";
    cout << "Insert Simple Equation [(big1) (op) (big2)]: \n\n";

    while(!cin.eof())
    {
        cout << ">>> ";
        cin >> a >> op >> b;
        cout << a << " " << op << " " << b << " = ";
        if(op == "+") cout << (a + b) << endl;
        else if(op == "-") cout << (a - b) << endl;
        else if(op == "*") cout << (a * b) << endl;
        else if(op == "/") cout << (a / b) << endl;
        else if(op == "%") cout << (a % b) << endl;
        else if(op == "^") cout << (a ^ ((int)b.toLongInt())) << endl;
        else if(op == "<") cout << (a < b) << endl;
        else if(op == ">") cout << (a > b) << endl;
        else if(op == "<=") cout << (a <= b) << endl;
        else if(op == ">=") cout << (a >= b) << endl;
        else if(op == "==") cout << (a == b) << endl;
        else if(op == "<<") cout << (a << ((int)b.toLongInt())) << endl;
        else if(op == ">>") cout << (a >> ((int)b.toLongInt())) << endl;
        else cout << "unrecognized operator" << endl;
    }

    return 0;
}
