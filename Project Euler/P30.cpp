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

int penta(int n)
{
    return n * n * n * n * n;
}

int getsum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += penta(n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    int sum = 0;
    for(int n = 2; n < 1000000; ++n)
        if(n == getsum(n)) sum += n;

    printf("%d\n", sum);

    return 0;
}
