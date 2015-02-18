#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,l,count;

    char inp[80];
    char name[80];

    gets(inp);
    for(i=0,n=0; inp[i]!='\0'; i++)
        if(inp[i]>='0'&&inp[i]<='9') n=n*10+inp[i]-'0';

    char res[n][80];
    for(i=0; i<n; i++) res[i][1]='\0';

    for(i=0,l=0; i<n; i++)
    {
        gets(inp);
        for(j=0; inp[j]!=' ' && inp[j]!='\0'; j++)
            name[j]=inp[j];
        name[j]='\0';
        for(k=0; k<l; k++)
            if(!strncmp(name,res[k],j)) break;

        if(k>=l)
            sprintf(res[l++],"%s %d",name,1);
        else
        {
            for(count=0,j++; res[k][j]!='\0'; j++)
                count=count*10+res[k][j]-'0';
            sprintf(res[k],"%s %d",name, ++count);
        }
    }

    qsort(res,l,80,strcmp);

    for(i=0; i<l; i++) puts(res[i]);

    return 0;
}
