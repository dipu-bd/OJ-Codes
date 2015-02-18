#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

#define SIZE 5001
int array[SIZE];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10954.inp", "r", stdin);
#endif
    int N, tmp;
    priority_queue<int> pque;

    while(scanf("%d", &N) != EOF && N > 0)
    {
        while(N--)
        {
            scanf("%d", &tmp);
            pque.push(tmp);
        }

        for(N = 0; pque.size(); ++N)
        {
            array[N] = pque.top();
            pque.pop();
        }

        while(N--)
            printf("%d ", array[N]);
        putchar('\n');

    }

    return 0;
}
