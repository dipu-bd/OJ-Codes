#include <stdio.h>
#include <string.h>

int move[110];
int getMove(char inp[], int);

int main()
{
    int t, n;
    char inp[50];
    
    scanf(" %d ",&t);
    while(t--)
    {
        scanf(" %d ",&n);
        
        int i, pos = 0;
        for(i = 0; i < n; i++)
        {
            gets(inp);
            pos += getMove(inp, i);
        }
        
        printf("%d\n",pos);
    }
    
    return 0;
}

int getMove(char inp[], int i)
{
    if(inp[0]=='S')
    {
        int j;
        sscanf(strrchr(inp,' ')," %d",&j);
        move[i] = move[j - 1];
    }
    else
    {
        move[i] = (inp[0] == 'L') ? -1 : 1;
    }
    return move[i];
}
