#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n > 0)
    {
        deque<int> deq;
        for(int i = 1; i <= n; ++i) deq.push_back(i);

        printf("Discarded cards:");
        if(deq.size() > 1)
        {
            printf(" %d", deq[0]);
            deq.pop_front();
            deq.push_back(deq[0]);
            deq.pop_front();

            while(deq.size() > 1)
            {
                printf(", %d", deq[0]);
                deq.pop_front();
                deq.push_back(deq[0]);
                deq.pop_front();
            }
        }

        printf("\nRemaining card: %d\n", deq[0]);
    }

    return 0;
}
