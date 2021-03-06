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

class Stitch {
public:
	vector <string> stitch(vector <string> A, vector <string> B, int overlap) {
		
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, int p2, bool hasAnswer, vector <string> p3) {
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
	cout << "}" << "," << p2;
	cout << "]" << endl;
	Stitch *obj;
	vector <string> answer;
	obj = new Stitch();
	clock_t startTime = clock();
	answer = obj->stitch(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p3[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
	vector <string> p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"AAAAAA"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"JJJJJ"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	string t3[] = {"AACEFHJ"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"14ABCD","25EFGH","36IJKL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ABCD14","EFGH25","IJKL36"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	string t3[] = {"14ABCD14","25EFGH25","36IJKL36"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {" 32ygfd","3uh53G:",")O83gh3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"hsd$*(PH","3G:$)(*P","gh86$PBB"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	string t3[] = {" 32ygmd$*(PH","3uh53G:$)(*P",")O83gh76$PBB"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"A"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"A"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	string t3[] = {"AA"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
// Many image editing programs have the ability to stitch two images
// together to form one larger image.  In this problem, you will be given
// two images, represented by vector <string>'s.  Each
// vector <string> represents a bitmap, where the ASCII value of
// character j of element i represents the color of the pixel in row i,
// column j of the image.  Your task is to stitch the two images
// together.  Specifically, image A goes to the left of image
// B and overlap pixels from the right of A and the
// left of B overlap.  To prevent any obvious artifacts from the
// stitching, you want to gradually blend the stitched region from
// image A to image B.  The ith pixel (indexed from 1) from the left in the
// overlapping region should have a value of
// 
// ((overlap+1-i)*a+(i*b))/(overlap+1) where a and b are
// the values of the pixels from A and B, respectively.  Hence, the leftmost pixels in the overlapping
// region should have values of
// 
// (overlap*a+b)/(overlap+1).
// 
// In all cases, you should round the pixel values to the nearest
// integer, rounding 0.5 up.
// 
// 
// 
// DEFINITION
// Class:Stitch
// Method:stitch
// Parameters:vector <string>, vector <string>, int
// Returns:vector <string>
// Method signature:vector <string> stitch(vector <string> A, vector <string> B, int overlap)
// 
// 
// CONSTRAINTS
// -A will contain between 1 and 50 elements, inclusive.
// -B will contain the same number of elements as A.
// -Each element of A will contain the same number of characters.
// -Each element of B will contain the same number of characters.
// -Each element of A and B will contain between overlap+1 and 50 characters, inclusive.
// -overlap will be between 0 and 49, inclusive.
// -Each character in A and B will have ASCII value between 32 and 126, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"AAAAAA"}
// {"JJJJJ"}
// 4
// 
// Returns: { "AACEFHJ" }
// 
// First, line up the two images:
// 
//  AAAAAA
//    JJJJJ
// 
// Then, blend the overlapping region:
// 
//  AACEFHJ
// 
// 
// 1)
// {"14ABCD",
//  "25EFGH",
//  "36IJKL"}
// {"ABCD14",
//  "EFGH25",
//  "IJKL36"}
// 4
// 
// Returns: { "14ABCD14",  "25EFGH25",  "36IJKL36" }
// 
// 2)
// {" 32ygfd",
//  "3uh53G:",
//  ")O83gh3"}
// {"hsd$*(PH",
//  "3G:$)(*P",
//  "gh86$PBB"}
// 3
// 
// Returns: { " 32ygmd$*(PH",  "3uh53G:$)(*P",  ")O83gh76$PBB" }
// 
// 3)
// {"A"}
// {"A"}
// 0
// 
// Returns: { "AA" }
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
