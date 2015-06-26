#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

const char*  file = "E:\\Dropbox\\Codes\\LightOJ\\1132.in";

int getnum(int b, int e)
{
    ++e;
    int r = rand() % e;
    while(r < b) r = (r + rand()) % e;
    return r;
}

void generate()
{
    int test = 200;

    printf("%d\n", test);
    while(test--)
    {
        long long n = getnum(1, 1000000005);
        if(test < 10) n = 1000000000000000LL - getnum(0, 100000005);
        int k = getnum(0, 50);
        printf("%lld %d\n", n, k);
    }
}

void init()
{
    freopen(file, "w", stdout);
    srand(clock());
}

int main()
{
    init();
    generate();
    return 0;
}
