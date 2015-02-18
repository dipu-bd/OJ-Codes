#include <stdio.h>
#include <ctype.h>
#include <string.h>

char inp[100];

void encode();
void decode();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("444_Encoder and Decoder_01.inp","r",stdin);
    //freopen("444_Encoder and Decoder_01.out","w",stdout);
#endif

    while(gets(inp))
        if(isdigit(inp[0])) decode();
        else encode();

    return 0;
}

void encode()
{
    char c,d;
    int ln = strlen(inp);
    while(ln--)
    {
        c = inp[ln];
        do
        {
            d = c/10;
            putchar(c-d*10+'0');
            c = d;
        } while(c>0);
    }
    putchar('\n');
    return;
}

void decode()
{
    char c;
    int ln = strlen(inp);
    while(ln--)
    {
        c = inp[ln]-'0';
        if(c-1) c = c*10 + (inp[--ln] - '0');
        else c = c*100 + inp[--ln]*10 + inp[--ln] - 11*'0';
        putchar(c);
    }
    putchar('\n');
    return;
}
