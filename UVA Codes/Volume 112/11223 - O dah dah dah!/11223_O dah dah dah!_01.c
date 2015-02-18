#include <stdio.h>
#include <string.h>

char code[10];

void putcode();

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11223_O dah dah dah!_01.inp","r",stdin);
    #endif

    int t, i;
    char c, l;
    scanf(" %d ",&t);

    for(i=1; i<=t; ++i)
    {
        if(i>1) putchar('\n');
        printf("Message #%d\n", i);

        l = 0;
        while((c=getchar())!='\n')
            if(c=='.' || c=='-') code[l++] = c;
            else if(l>0) l=code[l]=0, putcode();
            else putchar(' ');

        l=code[l]=0, putcode();

        putchar('\n');
    }

    return 0;
}

void putcode()
{
    if(!strcmp(code, ".-")) putchar('A');
    else if(!strcmp(code, "-...")) putchar('B');
    else if(!strcmp(code, "-.-.")) putchar('C');
    else if(!strcmp(code, "-..")) putchar('D');
    else if(!strcmp(code, ".")) putchar('E');
    else if(!strcmp(code, "..-.")) putchar('F');
    else if(!strcmp(code, "--.")) putchar('G');
    else if(!strcmp(code, "....")) putchar('H');
    else if(!strcmp(code, "..")) putchar('I');
    else if(!strcmp(code, ".---")) putchar('J');
    else if(!strcmp(code, "-.-")) putchar('K');
    else if(!strcmp(code, ".-..")) putchar('L');
    else if(!strcmp(code, "--")) putchar('M');
    else if(!strcmp(code, "-.")) putchar('N');
    else if(!strcmp(code, "---")) putchar('O');
    else if(!strcmp(code, ".--.")) putchar('P');
    else if(!strcmp(code, "--.-")) putchar('Q');
    else if(!strcmp(code, ".-.")) putchar('R');
    else if(!strcmp(code, "...")) putchar('S');
    else if(!strcmp(code, "-")) putchar('T');
    else if(!strcmp(code, "..-")) putchar('U');
    else if(!strcmp(code, "...-")) putchar('V');
    else if(!strcmp(code, ".--")) putchar('W');
    else if(!strcmp(code, "-..-")) putchar('X');
    else if(!strcmp(code, "-.--")) putchar('Y');
    else if(!strcmp(code, "--..")) putchar('Z');

    else if(!strcmp(code, "-----")) putchar('0');
    else if(!strcmp(code, ".----")) putchar('1');
    else if(!strcmp(code, "..---")) putchar('2');
    else if(!strcmp(code, "...--")) putchar('3');
    else if(!strcmp(code, "....-")) putchar('4');
    else if(!strcmp(code, ".....")) putchar('5');
    else if(!strcmp(code, "-....")) putchar('6');
    else if(!strcmp(code, "--...")) putchar('7');
    else if(!strcmp(code, "---..")) putchar('8');
    else if(!strcmp(code, "----.")) putchar('9');

    else if(!strcmp(code, ".-.-.-")) putchar('.');
    else if(!strcmp(code, "--..--")) putchar(',');
    else if(!strcmp(code, "..--..")) putchar('\?');
    else if(!strcmp(code, ".----.")) putchar('\'');
    else if(!strcmp(code, "-.-.--")) putchar('!');
    else if(!strcmp(code, "-..-.")) putchar('/');
    else if(!strcmp(code, "-.--.")) putchar('(');
    else if(!strcmp(code, "-.--.-")) putchar(')');
    else if(!strcmp(code, ".-...")) putchar('&');
    else if(!strcmp(code, "---...")) putchar(':');
    else if(!strcmp(code, "-.-.-.")) putchar(';');
    else if(!strcmp(code, "-...-")) putchar('=');
    else if(!strcmp(code, ".-.-.")) putchar('+');
    else if(!strcmp(code, "-....-")) putchar('-');
    else if(!strcmp(code, "..--.-")) putchar('_');
    else if(!strcmp(code, ".-..-.")) putchar('\"');
    else if(!strcmp(code, ".--.-.")) putchar('@');

    return;
}

