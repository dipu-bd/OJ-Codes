#include <stdio.h>
#include <string.h>

char inp[10000];

typedef struct
{
    char *div;
    long long rem;
} div_res;

div_res divide(long long a)
{
    int i;
    long long d, t;
    for(i = d = 0; inp[i]; ++i)
    {
        d = d * 10 + inp[i] - '0' ;
        if(d < a) inp[i] = '0';
        else
        {
            t = d / a;
            inp[i] = t + '0';
            d -= t * a;
        }
    }

    for(i = 0; inp[i] == '0' && inp[i + 1]; ++i);
    return (div_res){inp + i, d};
}


int main()
{
    char c;
    long long a;
    while(scanf("%s %c %lld", inp, &c, &a) != EOF)
    {
        div_res r = divide(a);

        if(c == '/') puts(r.div);
        else printf("%lld\n", r.rem);
    }

    return 0;
}
