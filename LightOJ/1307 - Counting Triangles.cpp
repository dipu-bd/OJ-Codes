#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test, cas = 1;

    int n, x, cnt;
    vector<int>::iterator i, j, k;

    scanf("%d", &test);
    while(test--)
    {
        vector<int> nums;

        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &x);
            nums.push_back(x);
        }

        cnt = 0;
        sort(nums.begin(), nums.end());
        for(i = nums.begin(); i != nums.end(); ++i)
        {
            for(j = i + 1 ; j != nums.end(); ++j)
            {
                int s = *i + *j;
                k = lower_bound(j, nums.end(), s);
                cnt += (int)(k - j) - 1;
            }
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
