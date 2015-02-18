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
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
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

class Jumping {
public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {

		ll dist = x * x + y * y;

		ssort(jumpLengths);

		//single jump
		ll first = jumpLengths[0];
		if(jumpLengths.size() == 1)
        {
            if(dist > sqr(first)) return "Not able";
            else if(dist == sqr(first)) return "Able";
		}

        //multiple jumps
		ll tot = 0;
		loop(i, jumpLengths) tot += *i;

        if(dist > sqr(tot)) return "Not able";

        ll last = *jumpLengths.rbegin();
        if(2 * last >= tot && dist < sqr(2 * last - tot)) return "Not able";

        return "Able";
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	Jumping *obj;
	string answer;
	obj = new Jumping();
	clock_t startTime = clock();
	answer = obj->ableToGet(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p2;
	string p3;

	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 4;
	int t2[] = {2,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 4;
	int t2[] = {4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 4;
	int t2[] = {6};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 0;
	p1 = 1;
	int t2[] = {100,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 300;
	p1 = 400;
	int t2[] = {500};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 11;
	p1 = 12;
	int t2[] = {1,2,3,4,5,6,7,8,9,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Able";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = 11;
	p1 = 12;
	int t2[] = {1,2,3,4,5,6,7,8,9,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "Not able";
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
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
// Frog Suwako lives on a two-dimensional plane.
// She likes to jump.
// Currently, she is located in the point (0, 0).
// She would like to reach the point (x, y).
// You are given the ints x and y.
//
//
//
// Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths.
// You are given these lengths in a vector <int> jumpLenghts.
// For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.
//
//
//
// Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
// Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths.
// Otherwise, return "Not able".
//
// DEFINITION
// Class:Jumping
// Method:ableToGet
// Parameters:int, int, vector <int>
// Returns:string
// Method signature:string ableToGet(int x, int y, vector <int> jumpLengths)
//
//
// CONSTRAINTS
// -x will be between -1,000 and 1,000, inclusive.
// -y will be between -1,000 and 1,000, inclusive.
// -len will contain between 1 and 50 elements, inclusive.
// -Each element in len will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 5
// 4
// {2, 5}
//
// Returns: "Able"
//
// One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).
//
// 1)
// 3
// 4
// {4}
//
// Returns: "Not able"
//
// The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.
//
// 2)
// 3
// 4
// {6}
//
// Returns: "Not able"
//
// The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.
//
// 3)
// 0
// 1
// {100, 100}
//
// Returns: "Able"
//
// Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).
//
// 4)
// 300
// 400
// {500}
//
// Returns: "Able"
//
//
//
// 5)
// 11
// 12
// {1,2,3,4,5,6,7,8,9,10}
//
// Returns: "Able"
//
//
//
// 6)
// 11
// 12
// {1,2,3,4,5,6,7,8,9,100}
//
// Returns: "Not able"
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!