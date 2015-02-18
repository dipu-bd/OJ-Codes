#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int fact[15];
    fact[0] = 1;
    for(int i = 1; i < 15; ++i)
        fact[i] = i * fact[i - 1];

    string v = "0123456789";
    string res = "";

    int indx = 1000000-1;
    while(v.size())
    {
        int i = v.size() - 1;
        int p = indx / fact[i];
        indx %= fact[i];
        res.push_back(v[p]);
        v.erase(v.begin() + p);

        //cout << indx << " " << fact[i] << endl;
    }

    cout << res << endl;

    return 0;
}
