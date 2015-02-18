// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <algorithm>
#include <vector>
// default namespace
using namespace std;

inline bool comp(const string& a, const string& b)
{
    return (a + b) < (b + a);
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("10905.inp", "r", stdin);
#endif

    int n;
    string tmp;
    vector<string> nums;

    while(scanf("%d", &n) != EOF && n > 0)
    {
        //input numbers
        while(n--)
        {
            cin >> tmp;
            nums.push_back(tmp);
        }

        //sort
        sort(nums.begin(), nums.end(), comp);

        //print
        for(int i = nums.size() - 1; i >= 0; --i)
            printf(nums[i].c_str());
        putchar('\n');
        nums.clear();
    }

    return 0;
}
