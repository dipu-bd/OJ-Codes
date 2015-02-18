#include <stdio.h>
#include <string.h>

char array[25][25];
char pos[25][2];

int main()
{
    int n;
    scanf("%d",&n);
    set(n);

    char inp[100];
    char cmd[10], method[10];
    int task,call,block1,block2;
    while(scanf(" %[^\n]",inp)==1)
    {
        if(!strcmp(inp,"quit")) break;
        sscanf(inp,"%s %d %s %d",cmd,&block1,method,&block2);

        task=strcmp(cmd,"move")?1:0;
        call=strcmp(method,"onto")?1:0;

        if(!task && !call)
            move_onto(n,pos[block1][0],pos[block1][1],pos[block2][0],pos[block2][1]);
        else if(!task && call)
            move_over(n,pos[block1][0],pos[block1][1],pos[block2][0],pos[block2][1]);
        else if(task && !call)
            pile_onto(n,pos[block1][0],pos[block1][1],pos[block2][0],pos[block2][1]);
        else
            pile_over(pos[block1][0],pos[block1][1],pos[block2][0],pos[block2][1]);
    }
    print(n);
    return 0;
}

void set(int n)
{
    register int i;
    for(i=0; i<n; i++)
    {
        memset(array[i],-1,n);
        array[i][0]=i;
        pos[i][0]=i;
        pos[i][1]=0;
    }
    return;
}

void print(int n)
{
    register int i,j,k;
    for(i=0; i<n; i++)
    {
        printf("%d:", i);

        for(j=0; j<n && array[i][j]>=0; j++)
            printf(" %d",array[i][j]);

        puts("");
    }
    return;
}

void move_block(char px, char py, char qx, char qy)
{
    if(px==qx && py==qy) return;

    char pp = array[px][py];
    if(pp<0) return;

    pos[pp][0] = qx;
    pos[pp][1] = qy;
    array[qx][qy] = pp;
    array[px][py] = -1;
    return;
}

void move_onto(int n, char px, char py, char qx, char qy)
{
     if(px==qx) return;

    char pp = array[px][py+1];
    if(pp>=0) move_over(n,px,py+1,pp,0);

    char qq = array[qx][qy+1];
    if(qq>=0) move_over(n,qx,qy+1,qq,0);

    move_block(px,py,qx,qy+1);
    return;

}

void move_over(int n, char px, char py, char qx, char qy)
{
     if(px==qx) return;

    char pp = array[px][py+1];
    if(pp>=0) move_over(n,px,py+1,pp,0);

    while(array[qx][qy]>=0) qy++;
    move_block(px,py,qx,qy);
    return;
}

void pile_onto(int n, char px, char py, char qx, char qy)
{
    if(px==qx) return;

    char qq = array[qx][qy+1];
    if(qq>=0) move_over(n,qx,qy+1,qq,0);

    for(qy++; array[px][py]>=0; py++,qy++)
        move_block(px,py,qx,qy);
    return;

}

void pile_over(char px, char py, char qx, char qy)
{
    if(px==qx) return;

    while(array[qx][qy]>=0) qy++;
    for(; array[px][py]>=0; py++,qy++)
        move_block(px,py,qx,qy);

    return;
}
