#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;

struct point
{
    int x;
    int y;

    bool operator < (const point& b) const
    {
        return (x == b.x) ? y < b.y : x < b.x;
    }
    bool operator == (const point& b) const
    {
        return x == b.x && y == b.y;
    }
};

point arr[1010];
vector<point> pc;

int main()
{
    int test, cas = 1;

    int n;
    point p;
    long long cnt, num;

    scanf("%d", &test);
    while(test--)
    {
        pc.clear();
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d", &arr[i].x, &arr[i].y);

        int s, siz = 1;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
            {
                p.x = (arr[i].x + arr[j].x);
                p.y = (arr[i].y + arr[j].y);
                pc.push_back(p);
            }

        cnt = 0;
        sort(pc.begin(), pc.end());
        vector<point>::iterator it, jt;
        for(it = pc.begin(); it != pc.end();)
        {
            jt = upper_bound(it, pc.end(), *it);
            num = (jt - it);
            cnt += (num * (num - 1)) / 2;
            it = jt;
        }

        printf("Case %d: %lld\n", cas++, cnt);
    }

    return 0;
}
