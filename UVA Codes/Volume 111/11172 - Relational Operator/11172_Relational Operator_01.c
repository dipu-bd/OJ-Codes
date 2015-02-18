#include <stdio.h>

int main()
{
    int i,tcase;
    scanf("%d", &tcase);

    char res[10000];

    for(i=0;i<tcase;i++)
    {
        long int a,b;
        scanf("%ld %ld",&a,&b);

        if(a>b)
            res[i]='>';
        else if(a<b)
            res[i]='<';
        else
            res[i]='=';
    }

    for(i=0;i<tcase;i++)
        printf("%c\n",res[i]);

    return 0;
}
