#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 300

char *num1;
char *num2;
char *res;
int len;

void cross(long long n)
{
    int i;
    long long t,m;
    for(i=len, t=0; i>=0; --i)
    {
        m = (res[i]-'0')*n + t;
        t = m/10;
        res[i] = (m - t*10) + '0';
    }
    return;
}

void multiply()
{
    /* swap number if num2 > num1 */
    char *p;
    if(strcmp(num2, num1))
    {
        p = num1;
        num1 = num2;
        num2 = p;
    }

    int i,j;

    /* initialize res array */
    j = strlen(num1);
    i = len = j+strlen(num2)+10;
    while(j--) res[--i] = num1[j];
    while(i--) res[i]='0';
    res[len--] = 0;

    /* multiply */
    long long int n;
    for(i=strlen(num2)-10; i>=0; i-=10)
    {
        sscanf(res+i, "%lld", &n);
        cross(n);
        res[i] = 0;
    }
    if(strlen(res))
    {
        sscanf(res+i, "%lld", &n);
        cross(n);
    }

    /* display */
    for(i=0; res[i+1] && res[i]=='0'; ++i);
    puts(res+i);

    return;
}

int main()
{
    num1 = malloc(SIZE*sizeof(char));
    num2 = malloc(SIZE*sizeof(char));
    res = malloc(2*SIZE*sizeof(char));
    while(scanf(" %s\n%s", num1, num2)!=EOF) multiply();
    return 0;
}
