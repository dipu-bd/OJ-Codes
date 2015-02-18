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

class StackingBoxes {
public:
	int highestStack(vector <string> weight, vector <string> canCarry) {
		
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	StackingBoxes *obj;
	int answer;
	obj = new StackingBoxes();
	clock_t startTime = clock();
	answer = obj->highestStack(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"10 20 30"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"11","100 10"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"11 20 30"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"11","100 10"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"10","20","91"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"11","100 10"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"100000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"1000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"100 100","1000 100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"90","91 92 93"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"200 200 600 700 400"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"1000 20 150 700 10"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// 
// Yesterday I was cleaning my house and I made a startling discovery. In the corner of the living room stood a nice decorated Christmas tree. The next Christmas is still too far away, thus I decided to remove all the decorations, put them into cardboard boxes and store them in the garage. However, the garage is almost full of other stuff. Therefore I'd like to arrange the boxes to form a tall stack, one atop another.
// 
// 
// 
// This may not be possible. Christmas tree decorations are fragile and the boxes that contain them aren't exactly made of steel. I weighed each of the boxes and for each of them I estimated the maximum weight that can be placed on the top of the box without it collapsing. In the following text we will use the term carrying capacity of a box when referring to this maximum weight.
// 
// 
// 
// You will be given this information in two vector <string>s: weight and canCarry.
// Each element of weight will contain the weights of some of the boxes.
// Similarly, each element of canCarry will contain the carrying capacities of some of the boxes.
// The carrying capacities of the boxes will be given in the same order as their weights.
// 
// 
// 
// Your task is to find and return the largest N such that N of the boxes can be selected and placed one atop another in some order such that none of the boxes collapse.
// 
// 
// DEFINITION
// Class:StackingBoxes
// Method:highestStack
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int highestStack(vector <string> weight, vector <string> canCarry)
// 
// 
// CONSTRAINTS
// -weight contains between 1 and 50 elements, inclusive.
// -canCarry contains between 1 and 50 elements, inclusive.
// -Each element of weight and canCarry contains between 1 and 50 characters, inclusive.
// -Each element of weight is of the form "NUMBER NUMBER ... NUMBER".
// -Each element of canCarry is of the form "NUMBER NUMBER ... NUMBER".
// -Each NUMBER in weight is an integer between 1 and 100,000, inclusive
// -Each NUMBER in canCarry is an integer between 1 and 1,000,000,000, inclusive.
// -All NUMBERs in weight and canCarry will contain no leading zeroes.
// -weight and canCarry contain the same total count of NUMBERs.
// 
// 
// EXAMPLES
// 
// 0)
// {"10 20 30"}
// {"11", "100 10"}
// 
// Returns: 3
// 
// Here we are given 3 boxes. The first one has weight 10 and can carry 11, the second one has weight 20 and can carry 100, the third one has weight 30 and can carry 10. It is possible to create a stack using all three of them: the first box goes on the top, the third one below and the second one on the bottom.
// 
// 1)
// {"11 20 30"}
// {"11", "100 10"}
// 
// Returns: 2
// 
// The first box is now too heavy, so the previous arrangement doesn't work anymore.
// 
// 2)
// {"10", "20", "91"}
// {"11", "100 10"}
// 
// Returns: 2
// 
// Again, the original arrangement doesn't work anymore. This time boxes 1 and 3 together are too heavy -- box 2 won't be able to carry both of them.
// 
// 3)
// {"100000"}
// {"1000000000"}
// 
// Returns: 1
// 
// You can always use at least one box, as it doesn't have to carry anything.
// 
// 4)
// {"100 100", "1000 100"}
// {"90", "91 92 93"}
// 
// Returns: 1
// 
// Each of the boxes is too heavy to be placed on any other box.
// 
// 5)
// {"200 200 600 700 400"}
// {"1000 20 150 700 10"}
// 
// Returns: 3
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
