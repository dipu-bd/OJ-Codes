/*============================
 UVA 450 - Little Black Book
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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define sf scanf
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)

struct Employee
{
    string title;
    string firstName;
    string lastName;
    string homeAddress;
    string department;
    string homePhone;
    string workPhone;
    string campusBox;

    Employee() { }
    Employee(const string& dept) : department(dept) { }

    bool operator < (const Employee& b) const
    {
        return lastName < b.lastName;
    }

    void takeInput(char* ch)
    {
        int idx;
        string inp = ch;

        idx = inp.find(',');
        title = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        idx = inp.find(',');
        firstName = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        idx = inp.find(',');
        lastName = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        idx = inp.find(',');
        homeAddress = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        idx = inp.find(',');
        homePhone = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        idx = inp.find(',');
        workPhone = inp.substr(0, idx);
        inp = inp.substr(idx + 1);

        campusBox = inp;
    }

};

char inp[100000];

int main()
{
    #ifdef LOCAL
    freopen("450.txt", "r", stdin);
    #endif

    int test;
    sscanf(gets(inp), "%d", &test);

    vector<Employee> ve;
    while(test--)
    {
        string dept = gets(inp);

        Employee em(dept);
        while(gets(inp) && strlen(inp))
        {
            em.takeInput(inp);
            ve.pb(em);
        }
    }

    ssort(ve);
    loop(vector<Employee>, it, ve)
    {
        Employee& em = *it;
        cout << "----------------------------------------" << endl
             << em.title << " " << em.firstName << " " << em.lastName << endl
             << em.homeAddress << endl
             << "Department: " << em.department << endl
             << "Home Phone: " << em.homePhone << endl
             << "Work Phone: " << em.workPhone << endl
             << "Campus Box: " << em.campusBox << endl;
    }

    return 0;
}

