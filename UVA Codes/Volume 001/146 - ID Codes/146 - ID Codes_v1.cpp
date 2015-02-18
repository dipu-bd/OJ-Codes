// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <algorithm>
// default namespace
using namespace std;

int main()
{
    string s;
    while(!cin.eof())
    {
        cin >> s;
        if(s == "#") return 0;
        if(next_permutation(s.begin(), s.end()))
            cout << s << endl;
        else puts("No Successor");
    }
    return 0;
}
