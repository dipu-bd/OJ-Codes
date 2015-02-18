// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
// default namespace
using namespace std;

string getpost()
{
    string first, mid, last;
    cin >> mid;
    printf("[%s]", mid.c_str());
    if(mid.size()==0 || mid == ")") return "";

    first = (mid=="(") ? getpost() : mid;
    cin >> mid;
    if(mid == "*" || mid == "/")
    {
        cin >> last;
        return first + last + mid;
    }
    else
    {
        last = getpost();
        return first + last + mid;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("727.inp", "r", stdin);
#endif

    int t;
    scanf("%d", &t);

    while(t--)
    {
        cout << getpost() << endl;
        if(t) putchar('\n');
    }



    return 0;
}
