#include <stdio.h>

int main()
{
    int s;
    char n[20];
    register i,j;
    while(scanf("%d %s",&s,n)==2 && s>0)
    {
        for(i=0; n[i]!=0; i++)
        {
            if(i>0) putchar(' ');
            printTop(n[i]-'0',s);
        }
        putchar('\n');

        for(j=0; j<s; j++)
        {
            for(i=0; n[i]!=0; i++)
            {
                if(i>0) putchar(' ');
                printPart1(n[i]-'0',s);
            }
            putchar('\n');
        }

        for(i=0; n[i]!=0; i++)
        {
            if(i>0) putchar(' ');
            printMiddle(n[i]-'0',s);
        }
        putchar('\n');

        for(j=0; j<s; j++)
        {
            for(i=0; n[i]!=0; i++)
            {
                if(i>0) putchar(' ');
                printPart2(n[i]-'0',s);
            }
            putchar('\n');
        }

        for(i=0; n[i]!=0; i++)
        {
            if(i>0) putchar(' ');
            printBottom(n[i]-'0',s);
        }
        printf("\n\n");
    }
    return 0;
}


#define BNK ' '
#define HOR '|'
#define VER '-'

void printTop(int n, int s)
{
    register i;

    putchar(BNK);
    if(n==1 || n==4)
        for(i=0; i<s; i++) putchar(BNK);
    else
        for(i=0; i<s; i++) putchar(VER);
    putchar(BNK);

    return;
}
void printPart1(int n, int s)
{
    register i;

    if(n==1||n==2||n==3||n==7)  putchar(BNK);
    else putchar(HOR);

    for(i=0; i<s; i++) putchar(BNK);

    if(n!=5 && n!=6)  putchar(HOR);
    else putchar(BNK);

    return;
}
void printMiddle(int n, int s)
{
    register i;

    putchar(BNK);
    if(n==1 || n==7 || n==0)
        for(i=0; i<s; i++) putchar(BNK);
    else
        for(i=0; i<s; i++) putchar(VER);
    putchar(BNK);

    return;
}
void printPart2(int n, int s)
{
    register i;

    if(n==0||n==2||n==6||n==8)  putchar(HOR);
    else putchar(BNK);

    for(i=0; i<s; i++) putchar(BNK);

    if(n!=2) putchar(HOR);
    else putchar(BNK);

    return;
}
void printBottom(int n, int s)
{
    register i;

    putchar(BNK);
    if(n==1 || n==7 || n==4)
        for(i=0; i<s; i++) putchar(BNK);
    else
        for(i=0; i<s; i++) putchar(VER);
    putchar(BNK);

    return;
}

