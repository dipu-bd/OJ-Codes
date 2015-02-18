#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

// default namespace
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("119.inp", "r", stdin);
#endif

    int n, m, p, r;
    string name;
    vector<string> group;
    map<string, int> rest;

    while(scanf("%d", &n) != EOF)
    {
        if(rest.size())
        {
            putchar('\n');
            rest.clear();
            group.clear();
        }

        for(int i = 0; i < n; ++i)
        {
            cin >> name;
            rest[name] = 0;
            group.push_back(name);
        }

        for(int i = 0; i < n; ++i)
        {
            cin >> name >> m >> p;
            if(p == 0) continue;

            r = m / p;
            rest[name] -= r * p;
            while(p--)
            {
                cin >> name;
                rest[name] += r;
            }
        }

        for(int i=0; i<group.size(); ++i)
            cout << group[i] << " " << rest[group[i]] << endl;
    }

    return 0;
}
