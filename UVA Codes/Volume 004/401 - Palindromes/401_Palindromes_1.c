#include <stdio.h>
#include <string.h>

int isPalin(char *inp);
int isMirror(char *inp);
int compare(char a, char b);

int main()
{
    char inp[10000];
    register int p,m;
    while(scanf(" %[^\n]",inp)!=EOF)
    {
        p=isPalin(inp);
        m=isMirror(inp);
        if(p && m)
            printf("%s -- is a mirrored palindrome.",inp);
        else if(!p && m)
            printf("%s -- is a mirrored string.",inp);
        else if(p && !m)
            printf("%s -- is a regular palindrome.",inp);
        else
            printf("%s -- is not a palindrome.",inp);
        printf("\n\n");
    }
    return 0;
}

int isPalin(char *inp)
{
    register int i,j,l;
    l=strlen(inp);
    for(i=0,j=l-1; i<=l/2; i++,j--)
    {
        if(inp[i]=='0') inp[i]='O';
        if(inp[j]=='0') inp[j]='O';
        if(inp[i]!=inp[j]) return 0;
    }
    return 1;
}
int isMirror(char *inp)
{
    register int i,j,l,p;
    l=strlen(inp);
    for(i=0,j=l-1; i<=l/2; i++,j--)
        if(!compare(inp[i],inp[j])) return 0;
    return 1;
}
int compare(char a, char b)
{
    if(a=='0') a='O';
    if(b=='0') b='O';
    char num[]="1SE Z  8 ";
    char let[]="A   3  HIL JM O   2TUVWXY5";
    if(a>='1' && a<='9')
        return (b==num[a-'1']);
    if(a>='A' && a<='Z')
        return (b==let[a-'A']);
    return 0;
}
