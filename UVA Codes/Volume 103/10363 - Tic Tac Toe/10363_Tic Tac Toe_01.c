#include <stdio.h>
#include <ctype.h>

#define NO printf("no\n")
#define YES printf("yes\n")
#define XW win(3)
#define OW win(30)

int game[3][3];
int win(int sum);

int main()
{
    int n,i,j;
    int xc,oc,p,q;
    char inp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0,xc=0,oc=0; j<9; j++)
        {
            inp=toupper(getchar());
            p=j/3;
            q = j-p*3;
            if(inp=='X') xc++, game[p][q]=1;
            else if(inp=='O') oc++, game[p][q]=10;
            else if(inp=='.') game[p][q]=0;
            else j--;
        }

        if(XW && OW) NO;
        else if(XW) (xc==oc+1) ? YES : NO;
        else if(OW) (xc==oc) ? YES : NO;
        else if(xc==oc || xc==oc+1) YES;
        else NO;
    }
    return 0;
}

int win(int sum)
{
    register int i,j,t1,t2,t3,t4;
    for(i=0,t3=0,t4=0; i<3; i++)
    {
        for(j=0,t1=0,t2=0; j<3; j++)
        {
            t1 += game[i][j];
            t2 += game[j][i];
        }
        if(t1==sum) return 1;
        if(t2==sum) return 1;

        t3 += game[i][i];
        t4 += game[i][2-i];
    }
    if(t3==sum) return 1;
    if(t4==sum) return 1;

    return 0;
}
