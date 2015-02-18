#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int test;
    char str[120];
    int n;
    int b, w, d, a;
    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas++)
    {
        printf("Case %d: ", cas);
        b = w = a = d = 0;
        scanf("%d", &n);
        scanf("%s", str);
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] == 'B') b++;
            else if(str[i] == 'W') w++;
            else if(str[i] == 'A') a++;
            else d++;
        }
        
        if(b && w == 0 && d == 0) printf("BANGLAWASH\n");
        else if(b == 0 && w && d == 0) puts("WHITEWASH");
        else if(b > w) printf("BANGLADESH %d - %d\n", b, w);
        else if(w > b) printf("WWW %d - %d\n", w, b);
        else if(b == 0 && d == 0 && w == 0 && a) printf("ABANDONED\n");
        else if(b == w) printf("DRAW %d %d\n", w, d);

    }
    return 0;
}