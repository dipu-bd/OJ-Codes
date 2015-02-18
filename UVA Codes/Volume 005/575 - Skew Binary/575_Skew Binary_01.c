#include <stdio.h>
#include <math.h>
#include <string.h>

void todecimal(char *num)
{
    register i,l,dec;
    l=strlen(num);
    for(i=l,dec=0;i>0;i--)
        dec+=(num[l-i]-'0')*(pow(2,i)-1);
    printf("%d\n",dec);
    return;
}

int main()
{
    char *num = calloc(50,sizeof(char));
    while(scanf(" %s",num)==1 && (num[0]!='0' || num[1]!='\0'))
        todecimal(num);
    return 0;
}
