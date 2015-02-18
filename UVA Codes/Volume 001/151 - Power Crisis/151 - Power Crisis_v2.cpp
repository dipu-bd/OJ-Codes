// C header files
#include <stdio.h>
// C++ header files
#include <queue>
// default namespace
using namespace std;

int getLast(queue<int> vc, int dif)
{
    while(vc.size() > 1)
    {
        vc.pop();
        for(int i = 0; i < dif; ++i)
        {
            vc.push(vc.front());
            vc.pop();
        }
    }

    return vc.front();
}

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF && n)
    {
        if(n == 13) puts("1");
        else
        {
            queue<int> vc;
            for(int i = 1; i <= n; ++i) vc.push(i);
            for(m = 1; getLast(vc, m) != 13; ++m);
            printf("%d\n", ++m);
        }
    }

    return 0;
}
