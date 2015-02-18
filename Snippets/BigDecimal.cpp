/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
#include "BigInteger.cpp"

//{ BigDecimal Class

class BigDecimal
{
    friend istream& operator >> (istream& in, BigDecimal& d)
    {
        string str;
        in >> str;
        d = str.data();
        return in;
    }

    friend ostream& operator << (ostream& out, const BigDecimal& d)
    {
        out << d.toString();
        return out;
    }

private:
    /* --------------------
     * Member Variables
     * -------------------- */
    int mant;
    int maxsize;
    BigInteger num;

    void __format()
    {
        int n = 0;
        for(int i = 0; i < num.size(); ++i)
            if(num[i] == 0) n++;
        num >>= n;
    }

public:
    /* --------------------
     * Contructor, Destructor
     * -------------------- */
    BigDecimal(int maxsz = 100)
    {
        mant = 0;
        num = "0";
        maxsize = maxsz;
    }
    BigDecimal(const double& d)
    {
        *this = d;
    }
    BigDecimal(const char* ch)
    {
        *this = ch;
    }

    /* --------------------
     * Assignment operators
     * -------------------- */
    BigDecimal& operator = (const double& d)
    {

    }
    BigDecimal& operator = (const char* ch)
    {
        int dec = 0;
        while(ch[dec] != '.' && isdigit(ch[dec])) ++dec;

        num = ch;
        mant = dec - 1;
        if(ch[dec] != '.')
        {
            __format();
            return *this;
        }

        int adec = dec + 1;
        while(isdigit(ch[adec])) ++adec;
    }

    /* --------------------
     * Boolean operators
     * -------------------- */
    bool operator < (const BigDecimal& d) const
    {
        if(mant != d.mant)
            return mant < d.mant;
        else
            return num < d.num;
    }
    bool operator > (const BigDecimal& d) const
    {
        if(mant != d.mant)
            return mant > d.mant;
        else
            return num > d.num;
    }
    bool operator == (const BigDecimal& d) const
    {
        return (mant == d.mant && num == d.num);
    }
    bool operator <= (const BigDecimal& d) const
    {
        return !(*this > d);
    }
    bool operator >= (const BigDecimal& d) const
    {
        return !(*this < d);
    }

    /* --------------------
     * Arithmetic operators
     * -------------------- */
    BigDecimal operator + (const BigDecimal& d)
    {

    }

    /* --------------------
     * Other Functions
     * -------------------- */
     string toString() const
     {
         ostringstream out;

         string dn = num.toString();
         const char* str = dn.c_str();

         out << str[0];
         if(dn.size() > 1)
            out << '.' << (str + 1);

         out << 'E' << mant;
         return out.str();
     }

};

//}

//{ Main Function

int main()
{
    string op;
    BigDecimal bd;

    cout << bd << endl;

    return 0;
}

//}
