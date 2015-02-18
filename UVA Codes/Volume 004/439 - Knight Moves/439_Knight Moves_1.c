#include <stdio.h>
#include <string.h>

int search(char y1, char y2, char from);
void setmove(char x1,char x2,char from);
int isValid(char x1, char x2);
char board[8][8];

int main()
{
    char i,j,from;
    char xx[3],yy[3];
    while(scanf(" %s %s",xx,yy)==2)
    {
        for(i=0; i<8; i++)
            for(j=0; j<8; j++)
                board[i][j]=-1;

        board[xx[1]-'1'][xx[0]-'a'] = 0;
        i = yy[1]-'1', j = yy[0]-'a';

        for(from=0; search(i,j,from); from++);

        printf("To get from %s to %s takes %d knight moves.\n",xx,yy,from);
    }
    return 0;
}

int search(char y1, char y2, char from)
{
    if(board[y1][y2]>=0) return 0;

    char i,j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            if(board[i][j]==from)
                setmove(i,j,from+1);

    return 1;
}

char move[8][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
void setmove(char x1, char x2, char val)
{
    char i,a,b;
    for(i=0; i<8; i++)
    {
        a = x1 + move[i][0];
        b = x2 + move[i][1];
        if(isValid(a,b))
            board[a][b] = val;
    }
    return;
}

int isValid(char a, char b)
{
    if(a<0 || a>7) return 0;
    if(b<0 || b>7) return 0;
    return (board[a][b]<0);
}
