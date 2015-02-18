//c headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
//c++ headers
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
using namespace std;

/// STRUCTURE FOR FRACTION NUMBER
/// it will store number as fraction and
/// do operations as we do with fractions
struct Fraction
{
    typedef long long ll;

    ///variables
    ll num;
    ll den;

    ///initialize
    Fraction() : num(0), den(1) { }
    Fraction(const ll& n) : num(n), den(1) { }
    Fraction(const ll& n, const ll& d)
    {
        num = n;
        den = d;
        normalize();
    }

    ///input and output
    friend istream& operator >> (istream& in, Fraction& n)
    {
        n.den = 1;
        in >> n.num;
        if(in.get() == '/')
            in >> n.den;
        n.normalize();
        return in;
    }
    friend ostream& operator << (ostream& out, const Fraction& n)
    {
        out << n.num;
        if(n.num != 0 && n.den > 1)
            out << '/' << n.den;
        return out;
    }

    ///logical operators
    bool operator == (const ll& rhs) const
    {
        return den == 1 && num == rhs;
    }

    bool operator != (const ll& rhs) const
    {
        return !(*this == rhs);
    }

    ///arithmetic operators with same type
    Fraction operator + (const Fraction& b)
    {
        Fraction res;
        Fraction& a = *this;
        res.den = a.den * b.den;
        res.num =  a.num * b.den + b.num * a.den;
        res.normalize();
        return res;
    }
    Fraction operator - (const Fraction& b)
    {
        Fraction res;
        Fraction& a = *this;
        res.den = a.den * b.den;
        res.num =  a.num * b.den - b.num * a.den;
        res.normalize();
        return res;
    }
    Fraction operator * (const Fraction& b)
    {
        Fraction res;
        Fraction& a = *this;
        res.num = a.num * b.num;
        res. den = a.den * b.den;
        res.normalize();
        return res;
    }
    Fraction operator / (const Fraction& b)
    {
        Fraction res;
        Fraction& a = *this;
        res.num = a.num * b.den;
        res.den = a.den * b.num;
        res.normalize();
        return res;
    }

    ///necessary functions
    void normalize()
    {
        if(num == 0) den = 1;
        if(den == 0) den = 1;

        if(den < 0)
        {
            num = -num;
            den = -den;
        }

        ll g = __gcd(abs(num), den);
        if(g > 0)
        {
            num /= g;
            den /= g;
        }
    }
};


///
/// MATRIX OPERATIONS
///

typedef vector<Fraction> VFD;

//scan the matrix
void getmatrix(vector<VFD>& matrix, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        matrix.push_back(VFD());
        for(int j = 0; j < col; ++j)
        {
            matrix[i].push_back(Fraction());
            cin >> matrix[i][j];
        }
    }
}

/*-----------for debug purpose---------------*/
void show(vector<VFD>& mat)
{
    cout << "\nMATRIX of order " << mat.size()
         << " * " << mat[0].size() << endl;

    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << "   ";
        cout << endl;
    }
    cout << endl;

}
/*-------------------------------------------*/

//row reduced echelon form -> gaussian algorithm
void reduce(vector<VFD>& mat, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        //make sure that the pivot is not zero
        if(mat[i][i] == 0)
        {
            bool cont = true;

            //check upper rows
            for(int r = i - 1; cont && r >= 0; --r)
            {
                if(mat[r][r] == 0 && mat[r][i] != 0)
                {
                    cont = false;
                    swap(mat[i], mat[r]);
                    break;
                }
            }
            //check lower rows
            for(int r = i + 1; cont && r < row; ++r)
            {
                if(mat[r][i] != 0)
                {
                    cont = false;
                    swap(mat[i], mat[r]);
                    break;
                }
            }

            if(cont) continue;
        }

        //check if pivot is 1
        // if not divide the row by pivot
        Fraction pivot = mat[i][i];
        if(pivot != 1)
        {
            for(int j = 0; j < col; ++j)
                mat[i][j] = mat[i][j] / pivot;
        }

        //for all row do operatoins
        // to make the rest of pivot column zero
        for(int j = 0; j < row; ++j)
        {
            if(i != j) //if not the pivot row..
            {
                //make all pivot coloumn zero =
                //pivot row - pivot row elem * pivot column
                pivot = mat[j][i];
                for(int k = 0; k < col; ++k)
                    mat[j][k] = mat[j][k] - (mat[i][k] * pivot);
            }
        }
    }

}

///
///MAIN METHOD
///

int main()
{
#ifdef LOCAL
    freopen("10109.inp", "r", stdin);
#endif // LOCAL

    bool putline = false;

    int mat_num;
    int variable, equation;
    while(scanf("%d", &mat_num) != EOF && mat_num)
    {
        if(putline) putchar('\n');
        else putline = true;

        printf("Solution for Matrix System # %d\n", mat_num);

        cin >> variable >> equation;

        //get matrix
        int row = equation, col = variable + 1;
        vector<VFD> matrix;
        getmatrix(matrix, row, col);

        //get the reduced matrix form
        reduce(matrix, row, col);

        //determine the ranks of reduced form
        int rkA = 0, rkAc = 0;
        for(int i = 0, j; i < row; ++i)
        {
            bool rk = true;
            for(j = 0; rk && j < col - 1; ++j)
                if(matrix[i][j] != 0) rk = false;
            if(!rk) ++rkA;

            if(matrix[i][j] != 0) rk = false;
            if(!rk) ++rkAc;
        }

        //if rankof A is 0 or rank of A and AC doesn't match
        // system is inconsistent or there is no solution
        if(rkA != rkAc)
        {
            printf("No Solution.\n");
            continue;
        }

        //in consistent system if number of unknowns > rank of A
        // then there are infite soluton
        // in this case arbitrary constants = variable - rank
        if(variable > rkA)
        {
            printf("Infinitely many solutions containing %d arbitrary constants.\n", variable - rkAc);
            continue;
        }


        //there are finite solution
        // print them all one by one
        for(int i = 0; i < variable; ++i)
        {
            printf("x[%d] = ", i + 1);
            cout << matrix[i][variable] << endl;
        }

    }

    return 0;
}
