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

class BirthdayOdds {
public:
	int minPeople(int minOdds, int daysInYear) {
		int n = 1;
		double prob = 1.0;
		double expected = 1.0 - minOdds / 100.0;
		while(prob > expected)
		{
			prob *= (double)(daysInYear - n) / daysInYear;
			++n;
		}
		return n;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	BirthdayOdds *obj;
	int answer;
	obj = new BirthdayOdds();
	clock_t startTime = clock();
	answer = obj->minPeople(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 75;
	p1 = 5;
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 50;
	p1 = 365;
	p2 = 23;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 365;
	p2 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 84;
	p1 = 9227;
	p2 = 184;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Here is an interesting factoid:  "On the planet Earth, if there are at least 23 people in a room, the chance that two of them have the same birthday is greater than 50%."  You would like to come up with more factoids of this form.  Given two integers (minOdds and daysInYear), your method should return the fewest number of people (from a planet where there are daysInYear days in each year) needed such that you can be at least minOdds% sure that two of the people have the same birthday. See example 0 for further information.
//
// DEFINITION
// Class:BirthdayOdds
// Method:minPeople
// Parameters:int, int
// Returns:int
// Method signature:int minPeople(int minOdds, int daysInYear)
//
//
// NOTES
// -Two people can have the same birthday without being born in the same year.
// -You may assume that the odds of being born on a particular day are (1 / daysInYear).
// -You may assume that there are no leap years.
//
//
// CONSTRAINTS
// -minOdds will be between 1 and 99, inclusive.
// -daysInYear will be between 1 and 10000, inclusive.
// -For any number of people N, the odds that two people will have the same birthday (in a room with N people, on a planet with daysInYear days in each year) will not be within 1e-9 of minOdds. (In other words, you don't need to worry about floating-point precision for this problem.)
//
//
// EXAMPLES
//
// 0)
// 75
// 5
//
// Returns: 4
//
// We must be 75% sure that at least two of the people in the room have the same birthday. This is equivalent to saying that the odds of everyone having different birthdays is 25% or less.
//
// If there is only one person in the room, the odds are 5/5 or 100% that nobody shares a birthday.
// If there are two people in the room, the odds are 5/5 * 4/5 = 80% that nobody shares a birthday. This is because the second person has 4 "safe" days on which his birthday could fall, out of 5 possible days in the year.
// If there are three people in the room, the odds of no overlap are 5/5 * 4/5 * 3/5 = 48%.
// If there are four people in the room, the odds are 5/5 * 4/5 * 3/5 * 2/5 = 19.2%. This means that you can be (100% - 19.2%) = 80.8% sure that two or more of them do, in fact, have the same birthday.
//
// We only need to be 75% sure of this, which was untrue for three people but true for four.  Therefore, your method should return 4.
//
// 1)
// 50
// 365
//
// Returns: 23
//
// The factoid from the problem statement. If there are 22 people in a room, the odds of a shared birthday are roughly 47.57%. With 23 people, these odds jump to 50.73%, which is greater than or equal to the 50% needed.
//
// 2)
// 1
// 365
//
// Returns: 4
//
// Another example from planet Earth. The odds of a repeat birthday among only four people are roughly 1.64%.
//
// 3)
// 84
// 9227
//
// Returns: 184
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
