#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <string.h>

#define SIZ 10000
int sz;
char inp[SIZ];
char bin[SIZ];
char gray[SIZ];
char tmp[SIZ];

bool copyto(char* dest)
{
    int i;
    sz = 0;
    for(i = 1; inp[i]; ++i)
    {
        if(inp[i] < '0' || inp[i] > '1') return false;
        if(sz == 0 && inp[i] == '0') continue;
        dest[sz++] = inp[i];
    }
    dest[sz] = 0;
    strcpy(inp, dest);

    return true;
}

bool decimalToBinary()
{
    int i;
    long long dec = 0;
    for(i = 0; inp[i]; ++i)
    {
        if(inp[i] < '0' || inp[i] > '9') return false;
        if(dec > (LONG_LONG_MAX - inp[i] + '0') / 10) return false;
        dec = dec * 10 + inp[i] - '0';
    }

    for(i = 0; dec; ++i)
    {
        tmp[i] = (dec & 1) + '0';
        dec >>= 1;
    }
    if(i == 0) tmp[i++] = '0';

    sz = 0;
    for(--i; i >= 0; --i)
    {
        bin[sz++] = tmp[i];
    }
    bin[sz] = 0;

    return true;
}

void convertToGray()
{
    int i;
    gray[0] = bin[0];
    for(i = 1; i < sz; ++i)
    {
        gray[i] = '0' + ((bin[i - 1] - '0') ^ (bin[i] - '0'));
    }
    gray[sz] = 0;
}

void convertToBinary()
{
    int i;
    bin[0] = gray[0];
    for(i = 1; i < sz; ++i)
    {
        bin[i] = '0' + ((bin[i - 1] - '0') ^ (gray[i] - '0'));
    }
    bin[sz] = 0;
}

void showres()
{
    printf("      Input : %s\n", inp);
    printf("     Binary : %s\n", bin);
    printf("  Gray Code : %s\n", gray);
}

void showhelp()
{
    puts("Help: ");
    puts("  Decimal number should appear normally.");
    puts("  Put 'b' before Binary Input.");
    puts("  Put 'g' before Graycode Input.");
    puts("  Type 'q' or 'Q' to stop taking input.");
    puts("Example input: ");
    puts("  Decimal  : 24328, 0122, 1010");
    puts("  Binary   : b11011, b1, b0, B001101010");
    puts("  Graycode : g11011, g1, g0, G001101010");
    puts("");
}

void showheader()
{
    puts("--------------------------------------");
    puts("      BINARY AND GRAY CONVERSION      ");
    puts("--------------------------------------");
    puts("");
    puts("<< Type 'H' for help. 'Q' to quit. >>");
    puts("");
}

bool suretoexit()
{
    printf("Are you sure to quit? : ");
    printf("(y = yes, n = no)\n");
    printf("Your choice : ");
    char ch = getch();
    return (ch == 'y' || ch == 'Y');
}

void takeInput()
{
    while(true)
    {
        printf(":input:>>> ");
        scanf(" %s", inp);

        if(inp[0] == 'Q' || inp[0] == 'q') return;

        bool help = false;
        if(inp[0] == 'H' || inp[0] == 'h')
        {
            help = true;
        }
        else if(inp[0] == 'b' || inp[0] == 'B')
        {
            help = help || !copyto(bin);
            if(!help) convertToGray();
        }
        else if(inp[0] == 'g' || inp[0] == 'G')
        {
            help = help || !copyto(gray);
            if(!help) convertToBinary();
        }
        else
        {
            help = help || !decimalToBinary();
            if(!help) convertToGray();
        }

        if(help) showhelp();
        else showres();
        puts("");
    }
}

int main()
{
    while(true)
    {
        showheader();

        takeInput();
        puts("");

        if(suretoexit()) break;
        system("cls");
    }

    return 0;
}
