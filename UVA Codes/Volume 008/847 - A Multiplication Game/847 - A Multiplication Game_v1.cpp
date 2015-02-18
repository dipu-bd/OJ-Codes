// C header files
#include <stdio.h>

unsigned limits[] = {1, 9, 18, 162, 324, 2916, 5832, 52488, 104976, 944784, 1889568, 17006112, 34012224, 306110016, 612220032};
#define SIZE 15

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("", "r", stdin);
    #endif

    int p;
    unsigned n;

    while(scanf("%u", &n)!=EOF)
    {
        for(p=0; p<15 && limits[p]<n; ++p);
        if(p & 1) puts("Stan wins.");
        else puts("Ollie wins.");
    }

    return 0;
}
