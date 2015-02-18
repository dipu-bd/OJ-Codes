// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <vector>
// default namespace
using namespace std;

int lower_bound(vector<int>& lady, int count, int& value)
{
    int step, first = 0, it;

    while (count > 0)
    {
        step = count >> 1;
        it = first + step;
        if (lady[it] < value)
        {
            first = it + 1;
            count -= step + 1;
        }
        else count = step;
    }
    return first;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10611.inp", "r", stdin);
#endif
    int n, h;
    vector<int> lady;
    int i, j, count;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &h);
        lady.push_back(h);
    }

    count = lady.size() - 1;

    // for(i = 0; i <= count; ++i) printf("%d ", lady[i]);
    // putchar('\n');

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &h);
        // printf("[%d]", h);

        i = j = lower_bound(lady, count, h);

        for(; lady[i] >= h && i >= 0; --i);
        if(i < 0) printf("X ");
        else printf("%d ", lady[i]);

        for(; lady[j] <= h && j <= count; ++j);
        if(j > count) printf("X\n");
        else printf("%d\n", lady[j]);
    }

    return 0;
}
