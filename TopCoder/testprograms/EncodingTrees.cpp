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

class EncodingTrees {
public:
	string getCode(int N, int index) {
		
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	EncodingTrees *obj;
	string answer;
	obj = new EncodingTrees();
	clock_t startTime = clock();
	answer = obj->getCode(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 1;
	p2 = "ab";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	p2 = "ba";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 3;
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	p1 = 9;
	p2 = "cbad";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 15;
	p1 = 14023;
	p2 = "abcdeohgfniljkm";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
// A binary tree is either empty or it consists of a root node and two binary trees, called the left subtree and the right subtree of the root node. Each node of our binary trees will contain one lowercase letter. We say that a binary tree is a binary search tree (BST) if and only if for each node the following conditions hold:
// 
// 
// 
//  All letters in the left subtree of the node occur earlier in the alphabet than the letter in the node. 
//  All letters in the right subtree of the node occur later in the alphabet than the letter in the node. 
// 
// 
// 
// Note that if a tree is a BST, then each subtree of this tree is also a BST. As a consequence, if the tree is non-empty, then both subtrees of the root node are BSTs again.
// 
// 
// 
// Examples of BSTs with 4 nodes:
// 
// 
// 
//     c        b        a
//    / \      / \        \
//   b   d    a   d        c
//  /            /        / \
// a            c        b   d
// 
// 
// 
// A pre-order code of a BST is a string obtained in the following way: 
// 
// 
// 
//  The pre-order code of an empty BST is an empty string. 
//  The pre-order code of a non-empty BST is obtained in the following way: Let L and R be the pre-order codes of the left and right subtree, respectively. Then the pre-order code of the whole BST is the concatenation of the letter in its root node, L and R (in this order). 
// 
// 
// 
// The pre-order codes for the trees above are "cbad", "badc" and "acbd", respectively.
// 
// 
// 
// Consider all BSTs with exactly N nodes containing the first N lowercase letters. Order these trees alphabetically by their pre-order codes.
// Our sequence of BSTs is one-based, i.e., the index of the first tree in this sequence is 1.
// Return the pre-order code of the BST at the specified index in this sequence.
// If index is larger than the number of BSTs with exactly N nodes, return an empty string.
// 
// 
// 
// DEFINITION
// Class:EncodingTrees
// Method:getCode
// Parameters:int, int
// Returns:string
// Method signature:string getCode(int N, int index)
// 
// 
// NOTES
// -You may assume that the number of our BSTs with 19 nodes doesn't exceed 2,000,000,000.
// 
// 
// CONSTRAINTS
// -N is between 1 and 19, inclusive.
// -index is between 1 and 2,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 1
// 
// Returns: "ab"
// 
// There are 2 BSTs with 2 nodes. The first of them is
// 
// a
//  \
//   b
// 
// 
// 1)
// 2
// 2
// 
// Returns: "ba"
// 
// The second one is
// 
//   b
//  /
// a
// 
// 
// 2)
// 2
// 3
// 
// Returns: ""
// 
// There are only 2 BSTs with 2 nodes, so the empty string is returned for an index of 3.
// 
// 3)
// 4
// 9
// 
// Returns: "cbad"
// 
// The 14 valid pre-order codes of BSTs with 4 nodes: abcd, abdc, acbd, adbc, adcb, bacd, badc, cabd, cbad, dabc, dacb, dbac, dcab, dcba. The 9th tree:
// 
//     c
//    / \
//   b   d
//  /
// a
// 
// 
// 
// 4)
// 15
// 14023
// 
// Returns: "abcdeohgfniljkm"
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
