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

#define NUM 30000

vector<int> abun;
bool flag[NUM + 10];

bool isabun(int n)
{
    int sum = 0;
    for(int i = 1; i < n; ++i)
    {
        if(n % i == 0)
        {
            sum += i;
            if(sum > n) return true;
        }
    }

    return sum > n;
}

void find_abund()
{
    for(int i = 2; i <= NUM; ++i)
        if(isabun(i)) abun.push_back(i);
}

void setflags()
{
    vector<int>::iterator i, j;
    for(i = abun.begin(); i != abun.end(); ++i)
        for(j = i; j < abun.end(); ++j)
        {
            if(*i + *j > NUM) break;
            flag[(*i + *j)] = 1;
        }
}

int main()
{
    printf("finding abundand numbers...\n");
    find_abund();
    printf("%d abundand found.\n", abun.size());
    printf("Setting up flags...\n");
    setflags();

    printf("Calculating sum...\n");
    long long sum = 0;
    for(int  i = 1; i <= NUM; ++i)
        if(!flag[i])
        {
            sum += i;
        }

    printf("sum = %lld\n", sum);

    return 0;
}
