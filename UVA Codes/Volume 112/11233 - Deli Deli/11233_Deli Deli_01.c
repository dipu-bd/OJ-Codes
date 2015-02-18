#include <stdio.h>
#include <string.h>

int main()
{
    int l,n,i,p;
    scanf("%d %d",&l,&n); getchar();
    char pre[l][2][1000], inp[n][1000];
    for(i=0;i<l;i++)
        scanf("%s %s",&pre[i][0],&pre[i][1]);

    for(i=0;i<n;i++)
        scanf("%s",&inp[i]);

    for(i=0;i<n;i++)
    {
        int j,exist=0;
        for(j=0;j<l;j++)
        {
            exist=!strcmp(pre[j][0],inp[i]);
            if(exist) {
                printf("%s\n",pre[j][1]);
                break;
            }
        }

        if(exist) continue;
        else
        {
            int li = strlen(inp[i]);
            char ck = inp[i][li-1];
            char cl = inp[i][li-2];

            if(!(cl=='a'||cl=='e'||cl=='i'||cl=='o'||cl=='u') && ck =='y')
            {
                inp[i][li-1] = 'i';
                inp[i][li]='e';
                inp[i][li+1]='s';
                inp[i][li+2]='\0';
                printf("%s\n",inp[i]);
            }
            else if(ck=='o'||ck=='s'||(cl=='c'&&ck=='h')||(cl=='s'&&ck=='h')||ck=='x')
            {
                inp[i][li] = 'e';
                inp[i][li+1]='s';
                inp[i][li+2]='\0';
                printf("%s\n",inp[i]);
            }
            else
            {
                inp[i][li] = 's';
                inp[i][li+1]='\0';
                printf("%s\n",inp[i]);
            }
        }
    }

    return 0;
}
