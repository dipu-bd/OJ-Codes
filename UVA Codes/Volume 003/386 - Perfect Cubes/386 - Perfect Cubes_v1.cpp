// C header files
#include <stdio.h>
// C++ header files
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
// default namespace
using namespace std;

#define LIM 201

class cubes
{
    friend void print(const cubes& val)
    {
        printf("Cube = %d, Triple = (%d,%d,%d)\\n", val.a, val.b, val.c, val.d);
    }

private :
    int a;
    int b;
    int c;
    int d;

public :
    cubes(int p, int q, int r, int s)
    { a = p; b = q; c = r; d = s; }

    bool operator < (const cubes& rval) const
    {
        if(a != rval.a) return (a < rval.a);
        if(b != rval.b) return (b < rval.b);
        if(c != rval.c) return (c < rval.c);
        return (d < rval.d);
    }

};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("386.out", "w", stdout);
#endif

    double tmp;
    vector<cubes> vc;

    for(int b = 2, a = 0; b < LIM; ++b)
        for(int c = b + 1; c < LIM; ++c)
            for(int d = c + 1, a = 0; d < LIM; ++d)
            {
                tmp = cbrt(b * b * b + c * c * c + d * d * d);
                if(tmp < LIM && tmp == (int)tmp)
                    vc.push_back(*new cubes((int)tmp, b, c, d));
            }

    sort(vc.begin(), vc.end());
    for(vector<cubes>::iterator i = vc.begin(); i < vc.end(); ++i) print(*i);

    //printf("\nCount = %d\n", vc.size());

    return 0;
}
