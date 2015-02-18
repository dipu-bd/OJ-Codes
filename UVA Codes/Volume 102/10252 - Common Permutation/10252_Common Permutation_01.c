#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10252_Common Permutation_02.inp","r",stdin);
    #endif

    char *alp;
    char c,pos,mov,i;
    alp=calloc(26,sizeof(char));

    pos=1, mov=0;
    while(!feof(stdin))
    {
        c = getchar();

        if(c=='\n')
        {
            if(pos && mov>0) pos=0;

            else if(mov<0)
            {
                for(i=0; i<26; i++)
                    if(alp[i]<0) mov=1, putchar(i+'a');
                if(mov>0) putchar(c);
                free(alp);
                alp=calloc(26,sizeof(char));
                mov=0, pos=1;
            }
        }

        else if(c>='a' && c<='z')
        {
            if(pos)
                alp[c-'a']=mov=1;
            else if(alp[c-'a'])
                alp[c-'a']=mov=-1;
        }
    }
    return 0;
}
