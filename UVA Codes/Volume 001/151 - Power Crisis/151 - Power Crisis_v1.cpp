// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <queue>
// default namespace
using namespace std;

int getlast(queue<int> q, int m)
{
    while(q.size() > 1)
    {
        q.pop();
        for(int i = 0; i < m; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front();
}

int main()
{
    freopen("151.out", "w", stdout);

    int n, m;
    for( n = 0; n <= 100; ++n)
    {
        if(n < 13) printf("0, ");
        else if(n == 13) printf("1, ");
        else
        {
            queue<int> q;
            for(int i = 1; i <= n; ++i) q.push(i);
            for(m = 1; getlast(q, m) != 13; ++m);
            printf("%d, ", ++m);
        }
    }

    return 0;
}
