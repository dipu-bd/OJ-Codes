#include <stdio.h>
#include <string.h>

int isJolly(const int n);

int main()
{
    int n;
    register int i,j;
    while(scanf("%d",&n)==1)
    {
        if(n<=0 || n>3000)  continue;
        if(isJolly(n)) printf("Jolly\n");
        else  printf("Not jolly\n");
    }
    return 0;
}

int isJolly(int n)
{

    register int i,f,r;
    int p,q;

    char arr[n];
    memset(arr,'0',n-1);

    for(r=0, i=0; i<n; i++,q=p)
    {
        scanf("%d",&p);
        if(i>0 & !r) {
            f = q-p;
            f=(f<0)?-f:f;
            if(f>=n || f<1) r = 1;
            else arr[f-1] = '1';
        }
    }
    if(r) return 0;

    for(i=0; i<n-1; i++)
        if(arr[i] != '1') return 0;

    return 1;
}
