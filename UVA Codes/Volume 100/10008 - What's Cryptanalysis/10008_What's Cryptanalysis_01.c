#include <stdio.h>
#include <string.h>

int main()
{
    const char set[]="abcdefghijklmnopqrstuvwxyz";
    int nc,i,l=strlen(set),dc[l],p,max=0;
    char inp,a[2]="a";
    scanf("%d",&nc);

    for(i=0; i<l; i++) dc[i]=0;
    for(i=0; i<=nc;)
    {
        inp=getchar();
        if(inp=='\n')
        {
            i++;
            continue;
        }
        else
        {
            if(inp>='A'&&inp<='Z') inp+='a'-'A';
            if(inp>='a'&&inp<='z')
            {
                a[0]=inp;
                p=strcspn(set,a);
                dc[p]+=1;
                if(dc[p]>max) max=p;
            }
        }
    }

    char sort[l],c=0;
    for(nc=max; nc>0; nc--)
        for(i=0; i<l; i++)
            if(dc[i]==nc)
                sort[c++]=set[i];

    for(i=0; i<c; i++)
    {
        a[0]=sort[i];
        p=strcspn(set,a);
        printf("%c %d\n",sort[i]-'a'+'A',dc[p]);
    }

    return 0;
}
