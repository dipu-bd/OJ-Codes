#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main()
{
    set<double> t;

    for (int a = 2; a <= 100; a++)
        for (int b = 2; b <= 100; b++)
            t.insert(pow(a, b));

    printf("%d\n", t.size());

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int up = 100;
    int cnt = 0; //(up - 1) * (up - 1);

    for(int a = 2; a <= up; ++a)
        for(int b = a * a, p = 2; b <= up; b *= a, ++p)
            for(int q = 2; q <= up; ++q)
                if(p * q <= up) ++cnt;
                else break;

    int tot = (up - 1) * (up - 1);
    printf("%d\n", tot - cnt);

    return 0;
}

*/
