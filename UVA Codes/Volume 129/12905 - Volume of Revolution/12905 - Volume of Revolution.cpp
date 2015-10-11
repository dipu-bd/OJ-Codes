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
//typedefs
typedef long long ll;
//always useful
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define REPNE(i, a, n) for(int i = a;  i >= n; --i)
//input-output
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)

//const int oo = 1 << 30;
//const int mod = 1000000007;

int test, cas = 1;
const double PI = 2 * acos(0.0);

int n;
int arr[10];
int a, b, l, s;

double getY(double x)
{
    double res = 0;
    REPE(i, 0, n)
    {
        res += arr[i] * pow(x, n - i);
    }
    return (res);
}

double cube(double x)
{
    return x * x * x;
}

double sqr(double x)
{
    return x * x;
}

double integrate(double x1, double x2)
{
    double y1 = getY(x1);
    double y2 = getY(x2);
    double m = (y1 - y2) / (x1 - x2);
    double c = y1 - m * x1;
    double res1 = sqr(m) * cube(x1) / 3.0 + (m * c) * sqr(x1) + sqr(c) * x1;
    double res2 = sqr(m) * cube(x2) / 3.0 + (m * c) * sqr(x2) + sqr(c) * x2;
    double res = res2 - res1;
    return res;
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf1(n);
        REPE(i, 0, n)
        {
            sf1(arr[i]);
        }
        sf2(a, b);
        sf2(l, s);

        double c = (double)(b - a) / (double)s;
        double Vapprox = 0, Vreal = 0;

        //integration of f(x)^2
        REPE(i, 1, s)
        {
            double p = a + i * c;
            Vapprox += fabs(integrate(p - c, p));
        }
        Vapprox *= l * sin(2 * PI / l) / 2.0;

        //real volume
        REPE(i, 0, n)
        {
            double p = 2 * (n - i) + 1;
            Vreal += sqr(arr[i]) * (pow(b, p) - pow(a, p)) / p;

            REPE(j, i + 1, n)
            {
                p = (n - i) + (n - j) + 1;
                Vreal += 2 * arr[i] * arr[j] * (pow(b, p) - pow(a, p)) / p;
            }
        }
        Vreal = PI * Vreal;

        //result
        double result = 100.0 * fabs((Vreal - Vapprox) / Vreal);
        printf("Case %d: %.4f\n", cas++, result);
    }

    return 0;
}

/*
2
2 1 -4 5 1 4 4 3
1 1 0 1 4 4 3
*/
