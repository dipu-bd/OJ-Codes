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
#include <assert.h>
#include <time.h>
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
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
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
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
/*--------------------------------------------------------------------------------*/

class BenfordsLaw
{
public:
    int questionableDigit(vector <int> transactions, int threshold)
    {
        double expected[10];
        int actual[10];

        REPE(i, 1, 9)
        expected[i] = log10((1.0 + i) / i) * (int)transactions.size();

        clr(actual);
        loop(i, transactions)
        {
            char out[20];
            sprintf(out, "%d", *i);
            ++actual[out[0] - '0'];
        }

        REPE(i, 1, 9)
        {
            if(expected[i] / actual[i] >= threshold ||
               actual[i] / expected[i] >= threshold)
                return i;
        }

        return -1;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << p1;
    cout << "]" << endl;
    BenfordsLaw *obj;
    int answer;
    obj = new BenfordsLaw();
    clock_t startTime = clock();
    answer = obj->questionableDigit(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p2;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    vector <int> p0;
    int p1;
    int p2;

    {
        // ----- test 0 -----
        int t0[] = {5236, 7290, 200, 1907, 3336, 9182, 17, 4209, 8746, 7932, 6375, 909, 2189, 3977, 2389, 2500, 1239, 3448, 6380, 4812};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        p2 = 1;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {1, 10, 100, 2, 20, 200, 2000, 3, 30, 300};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        p2 = 2;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {9, 87, 765, 6543, 54321, 43219, 321987, 21987, 1987, 345, 234, 123};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        p2 = -1;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 8;
        p2 = 9;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {987, 234, 1234, 234873487, 876, 234562, 17, 7575734, 5555, 4210, 678234, 3999, 8123};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        p2 = 8;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// PROBLEM STATEMENT
//
// Pick a random financial transaction from the ledger of a typical business
// and there is about a 30% chance that the first non-zero digit of the amount of
// money involved is a 1.  This counter-intuitive fact is a result of Benford's Law,
// discovered by astronomer Simon Newcomb in the late 1800's and rediscovered
// by physicist Frank Benford in the early 1900's.  They found that real world
// data are not evenly distributed.  Instead, given a random number related to
// some natural or social phenomenon satisfying certain conditions, the probability
// that the first non-zero digit of
// the number is D is log10(1 + 1/D).
//
//
//
// Increasingly, financial auditors are using Benford's Law to detect
// possible fraud.  Given a record of the financial transactions of a company,
// if some leading digit appears with a frequency that significantly differs
// from that predicted by Benford's Law, it is a signal that those transactions
// deserve a closer look.
//
//
//
// Create a class BenfordsLaw with a method questionableDigit
// that takes a vector <int> transactions and an int
// threshold and returns the smallest digit that appears as the
// first non-zero digit of numbers in transactions with a frequency
// that is at least threshold times more or less than its expected
// frequency (e.g., more than three times the expected frequency or less than
// one-third the expected frequency when threshold=3).
// If no such digit exists, return -1.
//
//
//
// For example, consider the data
//
//
//     5236    7290     200    1907    3336
//     9182      17    4209    8746    7932
//     6375     909    2189    3977    2389
//     2500    1239    3448    6380    4812
//
//     The following chart gives the actual frequency of each leading digit,
// and its expected frequency according to Benford's law.
//
//     digit    | 1    2    3    4    5    6    7    8    9
//     ---------|---------------------------------------------
//     actual   | 3    4    3    2    1    2    2    1    2
//     expected | 6.02 3.52 2.50 1.94 1.58 1.34 1.16 1.02 0.92
//
// Assuming a threshold of 2, there are two digits
// that are questionable: the leading digit 1 appears less
// than half as often as expected and the leading digit 9
// appears more than twice as often as expected.  Since 1
// is smaller than 9, the answer is 1.
//
//
// Note that, although the expected frequencies have been rounded to two decimal places
// in the above table for the purposes of presentation, you should perform all such calculations
// without rounding.  Errors of up to 0.000001 in the expected frequencies will not affect the
// final answer.
//
//
//
//
// DEFINITION
// Class:BenfordsLaw
// Method:questionableDigit
// Parameters:vector <int>, int
// Returns:int
// Method signature:int questionableDigit(vector <int> transactions, int threshold)
//
//
// NOTES
// -In the formula for Benford's Law, log10 means the base-10 logarithm.
//
//
// CONSTRAINTS
// -transactions contains between 1 and 50 elements, inclusive.
// -Each element of transactions is between 1 and 999999999, inclusive.
// -threshold is between 2 and 10, inclusive.
// -Errors of up to 0.000001 in calculating the expected frequencies will not affect the final answer.
//
//
// EXAMPLES
//
// 0)
// { 5236,7290,200,1907,3336,9182,17,4209,8746,7932,
//   6375,909,2189,3977,2389,2500,1239,3448,6380,4812 }
// 2
//
// Returns: 1
//
// The example above.
//
// 1)
// { 1,10,100,2,20,200,2000,3,30,300 }
// 2
//
// Returns: 2
//
// 2 and 3 appear more than twice as often as expected, and 4 through 9 appear
// less than half as often as expected.  2 is the smallest of these digits.
//
// 2)
// { 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 }
// 2
//
// Returns: -1
//
// 3)
// { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 }
// 8
//
// Returns: 9
//
// 4)
// { 987,234,1234,234873487,876,234562,17,
//   7575734,5555,4210,678234,3999,8123 }
// 3
//
// Returns: 8
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
