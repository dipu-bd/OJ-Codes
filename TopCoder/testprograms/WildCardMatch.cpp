/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
 //C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)


class WildCardMatch {
public:
	int minimalChanges(string file, string pattern) {
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	WildCardMatch *obj;
	int answer;
	obj = new WildCardMatch();
	clock_t startTime = clock();
	answer = obj->minimalChanges(p0, p1);
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
	
	string p0;
	string p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "abcd";
	p1 = "bcd";
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "abcd";
	p1 = "b?" "?";
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "aaaabbb";
	p1 = "aa?" "?" "?" "?b";
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "asdjkhajksdhajksdh";
	p1 = "asdjkhasdjk?";
	p2 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "niceone";
	p1 = "ieo?e";
	p2 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "abcaa";
	p1 = "abcba";
	p2 = 1;
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
// You have just hacked into your friend's computer, and you want to delete one of his personal files. But wait, why not let him delete it!
// As you keep watching him, he has a delete command typed in on the terminal which contains a pattern. You want to rename the file to match this pattern so that it gets deleted once he issues the command. You must accomplish this by renaming the given file to a similar name. Other than lowercase letters, a pattern might contain '?' which represents exactly one character (so "a?b" matches "aab", "abb", "acb" etc).
// 
// 
// A move is defined as adding a character, deleting a character, or modifying a character from the filename.  Given two Strings, file and pattern, return the minimal number of moves required to make the file match the pattern.
// 
// 
// DEFINITION
// Class:WildCardMatch
// Method:minimalChanges
// Parameters:string, string
// Returns:int
// Method signature:int minimalChanges(string file, string pattern)
// 
// 
// CONSTRAINTS
// -file contains between 1 and 50 characters, inclusive.
// -pattern contains between 1 and 50 characters, inclusive.
// -Each character in file will be a lowercase letter ('a'-'z').
// -Each character in pattern will be a lowercase letter ('a'-'z') or '?'
// 
// 
// EXAMPLES
// 
// 0)
// "abcd"
// "bcd"
// 
// Returns: 1
// 
// Just remove the first character.
// 
// 1)
// "abcd"
// "b??"
// 
// Returns: 1
// 
// Again the first character must be removed.
// 
// 2)
// "aaaabbb"
// "aa????b"
// 
// Returns: 0
// 
// The file already matches the wildcard.
// 
// 3)
// "asdjkhajksdhajksdh"
// "asdjkhasdjk?"
// 
// Returns: 6
// 
// 
// 
// 4)
// "niceone"
// "ieo?e"
// 
// Returns: 2
// 
// 
// 
// 5)
// "abcaa"
// "abcba"
// 
// Returns: 1
// 
// Modify just one character.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!