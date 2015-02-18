#include <stdio.h>

int GCD(int i, int j)
{
    if(j==0) return i;
    else return GCD(j, i%j);
}

int GSUM(int N)
{
    int   i,j, G=0;
    for(i=1; i<N; i++)
        for(j=i+1; j<=N; j++)
            G+=GCD(i,j);

    return G;
}

int main()
{
    FILE *fpt = fopen("11417_GCD_02.out","w");

    int N;

    for(N=1; N<501; ++N)
        fprintf(fpt, "\"%d\\n\", ", GSUM(N));
    fclose(fpt);

//    while(scanf("%d", &N)!=EOF && N>0)
//        printf("%d\n",GSUM(N));

    return 0;
}
