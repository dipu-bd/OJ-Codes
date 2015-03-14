#include <stdio.h>
#include <iostream>
using namespace std;

bool get5(string& r)
{
    char ch;
    r.clear();
    for(int i = 0; i < 5; ++i)
    {
        if(scanf(" %c", &ch) != 1) 
            return false;
        r.push_back(ch);
    }
    return true;
}

int main()
{
    string a, b;
    while(get5(a), get5(b))
    {
        bool ok = true;
        for(int i = 0; i < 5; ++i)
        {
            if(a[i] == b[i])
            {
                ok = false;
                break;
            }
        }
        if(ok) puts("Y");
        else puts("N");
    }
    
    return 0;
}