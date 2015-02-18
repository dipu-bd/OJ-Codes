#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    char **sites;
    int *rank;
    sites = calloc(10,sizeof(char*));
    rank = calloc(10,sizeof(int));

    register i,j,max;
    for(j=1; j<=tc; j++)
    {
        for(i=0,max=0; i<10; i++)
        {
            sites[i]=calloc(110,sizeof(char));
            scanf(" %s %d",sites[i],&rank[i]);
            if(max<rank[i]) max=rank[i];
        }

        printf("Case #%d:\n",j);
        for(i=0; i<10; i++)
        {
            if(rank[i]==max) puts(sites[i]);
            free(sites[i]);
        }
    }
    return 0;
}
