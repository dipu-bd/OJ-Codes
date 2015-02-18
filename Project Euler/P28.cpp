#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int siz;
    printf("Grid size : ");
    scanf("%d", &siz);

    siz *= siz;
    long long sum = siz;
    for(int n = 1, d = 2; n < siz; n += 4 * d, d += 2)
    {
        sum += 2 * (2 * n + 3 * d);
        //cout << n << endl;
    }

    printf("Diagonal sum : %lld\n", sum);

    return 0;
}
