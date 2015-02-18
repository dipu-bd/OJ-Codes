#include <stdio.h>
#include <string.h>

typedef struct
{
    char state;
    int capacity;
} Device;

int main()
{
    Device device[25];
    char fused ;
    int sum, max;
    int n,m,capacity;
    int i,sequence=0;

    while(scanf("%d %d %d",&n,&m,&capacity)==3 && n>0)
    {
        /* clear previous data */
        memset(device,0,sizeof(Device)*n);
        sum = max = fused = 0;

        /* get device capacity */
        for(i=0;i<n;++i)
            scanf("%d", &device[i].capacity);

        /* get operations */
        while(m--)
        {
            scanf("%d",&i), --i;
            if(device[i].state) sum -= device[i].capacity;
            else sum += device[i].capacity;
            device[i].state = !(device[i].state);

            if(sum > capacity) fused = 1;
            if(sum > max) max = sum;
        }

        /* output */
        printf("Sequence %d\n", ++sequence);
        if(fused) printf("Fuse was blown.\n\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max);
    }
    return 0;
}
