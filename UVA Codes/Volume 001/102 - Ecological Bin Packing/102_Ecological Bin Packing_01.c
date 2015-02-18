#include <stdio.h>

int inp[3][3];
char *permu[] = {"BCG","BGC","CBG","CGB","GBC","GCB"};

void checklower();
int getsum(char*);
int index(char);

int main()
{
    register i,j;
    while(scanf("%d %d %d %d %d %d %d %d %d",
                &inp[0][0], &inp[0][1], &inp[0][2],
                &inp[1][0], &inp[1][1], &inp[1][2],
                &inp[2][0], &inp[2][1], &inp[2][2]) == 9)
        checklower();

    return 0;
}

void checklower()
{
    char *min;
    register i,s,mval=0;
    for(i=0; i<6; i++)
    {
        s=getsum(permu[i]);
        if(s<mval) min=permu[i], mval=s;
        else if(i==0) min=permu[i], mval=s;
    }

    printf("%s %d\n",min,mval);
    return;
}

int getsum(char *state)
{
    register int i,j,k,s=0;
    for(i=0; i<3; i++)
    {
        k=index(state[i]);
        for(j=0; j<3; j++)
            if(j!=i) s += inp[j][k];
    }
    return s;
}

int index(char c)
{
    switch(c)
    {
    case 'B' :
        return 0;
    case 'C' :
        return 2;
    case 'G' :
        return 1;
    }
}
