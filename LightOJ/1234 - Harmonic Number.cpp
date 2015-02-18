#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    //Euler–Mascheroni constant
    double harm[110];
    harm[0] = 0;
    for(int i = 1; i <= 100; ++i)
        harm[i] = harm[i - 1] + 1.0 / i;
    const double gamma = 0.577215664901532860606512090082;

    int test, cas = 1;
    scanf("%d", &test);
    while(test--)
    {
        int n;
        double hn = 0;

        scanf("%d", &n);
        if(n < 100) hn = harm[n];
        else
        {
            //using assymtotic expansion : http://mathworld.wolfram.com/HarmonicNumber.html (13)
            double np2 = (double)n * n,
                   np4 = np2 * np2;
            hn = gamma + log(n) + 1.0 / (2.0 * n)
                 - 1.0 / (12 * np2)
                 + 1.0 / (120 * np4);
        }

        printf("Case %d: %.10lf\n", cas++, hn);
    }

    return 0;
}
