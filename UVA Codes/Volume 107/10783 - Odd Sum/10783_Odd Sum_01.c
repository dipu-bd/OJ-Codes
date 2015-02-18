#include <stdio.h>

int main()
{
    int tcase, i;
    scanf("%d",&tcase);
    int pairs[tcase][2];
    for(i=0;i<tcase;i++)
        scanf("%d %d", &pairs[i][0], &pairs[i][1]);

    for(i=0;i<tcase;i++)
    {
        int low, high;
        low = pairs[i][0];
        high = pairs[i][1];
        while(low%2==0) low++;

        int sum=0;
        while(low<=high)
        {
            sum += low;
            low +=2;
        }

        printf("Case %d: %d\n",i+1,sum);
    }

    return 0;
}
