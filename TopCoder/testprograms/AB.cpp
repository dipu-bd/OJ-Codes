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

bool save[55][2555][55];
bool _save[55][2555][55];

bool recur(int n, int k, int b)
{
	if(n == 0) return (k == 0);
	
	bool& dp = save[n][k][b];
	bool& dpc = _save[n][k][b];
	if(dpc) return dp;
	
	dpc = true;
	dp = recur(n - 1, k - b, b) ||  //put A
		 recur(n - 1, k, b + 1);    //put B
	
	return dp;
}

string getpath(int n, int k, int b)
{
	if(n == 0) return "";	
	 
    string res;
    if(recur(n - 1, k - b, b)) 
    {
    	res = getpath(n - 1, k - b, b);
    	res.pb('A');
    	return res;
    }
    else if(recur(n - 1, k, b + 1))
    {
      	res = getpath(n - 1, k, b + 1);
    	res.pb('B');
    	return res;    
    }    
    
    return res;    
}

class AB {
public:
	string createString(int N, int K) {
		return getpath(N, K, 0);
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
	AB *obj;
	string answer;
	obj = new AB();
	clock_t startTime = clock();
	answer = obj->createString(p0, p1);
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
	p0 = 3;
	p1 = 2;
	p2 = "ABB";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 0;
	p2 = "BA";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 8;
	p2 = "";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 12;
	p2 = "BAABBABAAB";
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
// You are given two ints: N and K. Lun the dog is interested in strings that satisfy the following conditions:
// 
// The string has exactly N characters, each of which is either 'A' or 'B'.
// The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
// 
// If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
// 
// DEFINITION
// Class:AB
// Method:createString
// Parameters:int, int
// Returns:string
// Method signature:string createString(int N, int K)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -K will be between 0 and N(N-1)/2, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 2
// 
// Returns: "ABB"
// 
// This string has exactly two pairs (i, j) mentioned in the statement: (0, 1) and (0, 2).
// 
// 1)
// 2
// 0
// 
// Returns: "BA"
// 
// Please note that there are valid test cases with K = 0.
// 
// 2)
// 5
// 8
// 
// Returns: ""
// 
// Five characters is too short for this value of K.
// 
// 3)
// 10
// 12
// 
// Returns: "BAABBABAAB"
// 
// Please note that this is an example of a solution; other valid solutions will also be accepted.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!