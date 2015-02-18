#include <stdio.h>

#define SIZE 100

int matrix[SIZE][SIZE];


int main()
{
    int n,i,j,k,l,m, s,t;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
                scanf("%d",matrix[i]+j);


        for(k=s=0; k<n; ++k)
            for(l=0; l<n; ++l)
            {
                for(i=t=0; i<k; ++i)
                    for(j=0; j<l; ++j)
                        t+= matrix[i][j];
                if(t>s) s=t;
            }

        printf("%d\n",s);
    }

    return 0;
}
