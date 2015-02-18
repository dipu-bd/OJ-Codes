// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <algorithm>
#include <queue>
// default namespace
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11369.inp", "r", stdin);
#endif
    int t, n, p, sum;
    priority_queue<int> pq;

    scanf("%d", &t);
    while(t--)
    {
        //clear
        while(pq.size()) pq.pop();

        //input
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &p);
            pq.push(p);
        }

        //calculate
        sum = 0;
        while(pq.size() > 2)
        {
            pq.pop();
            pq.pop();
            sum += pq.top();
            pq.pop();
        }

        printf("%d\n", sum);
    }

    return 0;
}
