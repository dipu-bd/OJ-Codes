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

class CandyCollection {
public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	CandyCollection *obj;
	int answer;
	obj = new CandyCollection();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,0,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1,3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,2,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,5,10,13};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2,3,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {8,8,10,15};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 20;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 5101;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
// Alice likes eating candies.
// Her favorite type of candy are the Surprise Candies.
// Surprise Candies come in N different flavors and in N different shapes.
// You know the following facts about the shapes and flavors of Surprise Candies:
// 
// The shapes are numbered 0 through N-1.
// The flavors are numbered 0 through N-1.
// You can tell the shape of a candy before buying it. (Thus, you can do stuff like "buy exactly 47 candies of shape 3".)
// You can only tell the flavor of a candy when eating it. (Thus, you do not know the flavor when you are buying the candy.)
// For each shape of Surprise Candies, there are exactly two flavors that can have that shape.
// For each flavor of Surprise Candies, there are exactly two shapes that can have that flavor.
// 
// 
// 
// 
// In Alice's street there is a store that sells Surprise Candies.
// Alice knows the exact inventory of this store.
// You are given this information in vector <int>s Type1, Number1, Type2, and Number2.
// Each of these vector <int>s has exactly N elements.
// For each i, their elements at index i correspond to the shape number i, as follows:
// 
// The store contains exactly Number1[i] candies with shape i and flavor Type1[i].
// The store contains exactly Number2[i] candies with shape i and flavor Type2[i].
// 
// 
// 
// 
// Alice wants to eat candies of all N flavors today.
// However, she is lazy to go to the store, so she sent Kirito to do the shopping for her.
// Kirito must buy a set of candies that is guaranteed to contain all N flavors.
// Return the smallest number of candies Kirito may buy.
// 
// 
// DEFINITION
// Class:CandyCollection
// Method:solve
// Parameters:vector <int>, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2)
// 
// 
// CONSTRAINTS
// -N will between 1 and 1000, inclusive.
// -Type1, Number1, Type2, Number2 will each contain exactly N elements.
// -For each i, Type1[i] and Types2[i] will be different.
// -Each element of Type1 and Type2 will be between 0 and N-1, inclusive.
// -Each element of Number1 and Number2 will be between 1 and 1000, inclusive.
// -Each of the values 0 through N-1 will appear exactly twice in Type1 and Type2 together.
// 
// 
// EXAMPLES
// 
// 0)
// {0,0}
// {1,1}
// {1,1}
// {1,1}
// 
// Returns: 2
// 
// In this test case we have N=2.
// Thus, there are two shapes and two flavors.
// The store has exactly one candy for each combination (shape,flavor).
// Kirito can simply buy two candies with the same shape, their flavors must be different.
// 
// 1)
// {0,0}
// {2,5}
// {1,1}
// {2,5}
// 
// Returns: 3
// 
// In this test case we have N=2 again, but now the supply of candies in the store is larger.
// There are 2+2 = 4 candies of shape 0, and 5+5 = 10 candies of shape 1.
// The optimal strategy for Kirito is to buy 3 candies of shape 0.
// Both flavors have to be present in those three candies.
// 
// 2)
// {0,0,2,3}
// {1,1,2,2}
// {1,1,3,2}
// {1,1,2,2}
// 
// Returns: 5
// 
// One optimal solution is to buy two candies of shape 0 and three candies of shape 2.
// 
// 3)
// {0,1,2,3}
// {5,5,10,13}
// {1,2,3,0}
// {8,8,10,15}
// 
// Returns: 20
// 
// 
// 
// 4)
// {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13}
// {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530}
// {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16}
// {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394}
// 
// Returns: 5101
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
