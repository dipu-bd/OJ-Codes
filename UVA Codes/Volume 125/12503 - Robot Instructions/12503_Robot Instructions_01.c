#include <stdio.h>
#include <string.h>

char inp[50];
int move[110];
int getMove(register);

int main()
{
    register i,pos;
    int tc, rc;

    scanf(" %d ",&tc);
    for(; tc>0; tc--)
    {
        scanf(" %d ",&rc);

        for(i=0,pos=0; i<rc; i++)
        {
            gets(inp);
            pos+=getMove(i);
        }

        printf("%d\n",pos);
    }
}

int getMove(register i)
{
    if(inp[0]=='S')
    {
        int j;
        sscanf(strrchr(inp,' ')," %d",&j);
        move[i]=move[j-1];
    }
    else
        move[i]=(inp[0]=='L')?-1:1;
    return move[i];
}
