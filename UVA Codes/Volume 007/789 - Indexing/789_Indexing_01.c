#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

char res[1000][MAX];
int resLen=0;
void saveToRes(char *tmp,int indx);
int compare(char *str1, char *str2);

int main()
{
    char key=getchar();
    char c,p;
    int t=0,indx=0,tc=0;
    char tmp[100];
    while((c=getchar())!=EOF)
    {
        if(t)
        {
            if(c<'A' || c>'Z')
            {
                tmp[tc]='\0';
                t=0, tc=0;
                saveToRes(tmp,indx);
            }
            else tmp[tc++]=c;
        }
        else if(c==key && (p<'A' || p>'Z'))
        {
            t=1;
            tmp[tc++]=c;
        }

        if(c=='\n') ++indx;
        p=c;
    }

    qsort(res,resLen,MAX,strcmp);
    for(t=0; t<resLen; t++) puts(res[t]);

    return 0;

}

void saveToRes(char *tmp,int indx)
{
    register int i,j,l,m;
    l=strlen(tmp);
    for(j=0; j<resLen; j++)
        if(!strncmp(res[j],tmp,l)) break;

    if(j<resLen)
    {
        char in[10];
        sprintf(in,"%d",indx);
        if(compare(in,res[j])) return;
        sprintf(res[j],"%s %d",res[j],indx);
    }
    else
        sprintf(res[j],"%s %d",tmp,indx), ++resLen;
    return;
}

int compare(char *str1, char *str2)
{
    int i,j,k,l;
    k=strlen(str1);
    l=strlen(str2);
    for(i=k-1,j=l-1; i>=0 && j>=0; i--,j--)
        if(str1[i]!=str2[j]) return 0;
    return 1;
}
