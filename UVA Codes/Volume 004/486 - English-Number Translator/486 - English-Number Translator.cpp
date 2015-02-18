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
#define ssort(v) sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)

int getval(const string& val)
{
    if (val == "negative") return -1;
    else if(val == "zero") return 0;
    else if(val == "one") return 1;
    else if(val == "two") return 2;
    else if(val == "three") return 3;
    else if(val == "four") return 4;
    else if(val == "five") return 5;
    else if(val == "six") return 6;
    else if(val == "seven") return 7;
    else if(val == "eight") return 8;
    else if(val == "nine") return 9;
    else if(val == "ten") return 10;
    else if(val == "eleven") return 11;
    else if(val == "twelve") return 12;
    else if(val == "thirteen") return 13;
    else if(val == "fourteen") return 14;
    else if(val == "fifteen") return 15;
    else if(val == "sixteen") return 16;
    else if(val == "seventeen") return 17;
    else if(val == "eighteen") return 18;
    else if(val == "nineteen") return 19;
    else if(val == "twenty") return 20;
    else if(val == "thirty") return 30;
    else if(val == "forty") return 40;
    else if(val == "fifty") return 50;
    else if(val == "sixty") return 60;
    else if(val == "seventy") return 70;
    else if(val == "eighty") return 80;
    else if(val == "ninety") return 90;
    else if(val == "hundred") return 100;
    else if(val == "thousand") return 1000;
    else if(val == "million") return 1000000;
    else return 0;
}

int main()
{
    char inp[500], sub[80];
    while(gets(inp))
    {
        int res;
        int neg = 1;
        int num = 0;
        int tmp = 0;
        do
        {
            res = sscanf(inp, "%s %[^\n]", sub, inp);
            //if(res == 1) strcpy(sub, inp);

            int v = getval(string(sub));
            if(v == -1) neg = -1;
            else if(v < 100) tmp += v;
            else if(v == 100) tmp = tmp ? tmp * v : v;
            else num += tmp * v, tmp = 0;
        }
        while(res == 2);

        num = neg * (num + tmp);
        printf("%d\n", num);
    }

    return 0;
}

/*
nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine
negative one hundred fifty thousand
one thousand fifty
negative twelve million twelve thousand
eight hundred eighty eight million
two million two thousand twelve
eight hundred eighty eight million eight hundred eighty eight thousand eight hundred eighty eight
nine hundred million one hundred two thousand one hundred eleven
one hundred eleven million eleven
seven hundred nine million nine hundred
nine hundred nine thousand nine
eight hundred eighty eight
eighty eight million eighty eight thousand eighty eight
nine hundred nine thousand nine hundred
*/
