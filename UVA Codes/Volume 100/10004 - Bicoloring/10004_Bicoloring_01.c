#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

char vertex[SIZE];
char adjlist[SIZE][15];

int main()
{
    int n,l, p,q,r, i;
    char flag ;

    while(scanf("%d",&n)!=EOF && n>0)
    {
        scanf("%d",&l);
        for(i=0;i<l;++i)
        {
            scanf(" %d %d",&p,&q);
            sprintf(adjlist[i], "%d %d %d", (p+q), p, q);
        }

        qsort(adjlist, l, 15, strcmp);

        flag = 1;
        memset(vertex, -1, n);
        for(i=l-1;i>=0 && flag; --i)
        {
            sscanf(adjlist[i], "%d %d %d", &r, &p, &q);

            if(vertex[p]<0 && vertex[q]<0)
                vertex[p]=0, vertex[q]=1;

            else if(vertex[p]<0 && vertex[q]>=0)
                vertex[p] = !vertex[q];

            else if(vertex[p]>=0 && vertex[q]<0)
                vertex[q] = !vertex[p];

            else
                flag = (vertex[p]!=vertex[q]);
        }

        if(flag) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
