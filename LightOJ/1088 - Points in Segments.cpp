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

    int n, q, x, y;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &q);

        vector<int> nums;
        while(n--)
        {
            scanf("%d", &x);
            nums.push_back(x);
        }

        printf("Case %d:\n", cas++);
        while(q--)
        {
            scanf("%d %d", &x, &y);
            int res = (int)(upper_bound(nums.begin(), nums.end(), y)
                            - lower_bound(nums.begin(), nums.end(), x));
            printf("%d\n", res);
        }
    }

    return 0;
}
