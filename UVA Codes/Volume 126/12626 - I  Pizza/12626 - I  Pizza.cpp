#include <stdio.h>

char inp[610];
int iratio[] = {1,3,2,1,1,1};
int ratio[6] = {};

int lowest();
void AddToRatio(char a);

int main()
{
    char c;
    int tc, i;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf(" %[^\n]",inp);

        for(i=0; inp[i]; ++i)
            AddToRatio(inp[i]);

        printf("%d\n", lowest());
    }

    return 0;
}

void AddToRatio(char a)
{
    switch(a)
    {
    case 'M' :
        ++ratio[0];
        return;
    case 'A' :
        ++ratio[1];
        return;
    case 'R' :
        ++ratio[2];
        return;
    case 'G' :
        ++ratio[3];
        return;
    case 'I' :
        ++ratio[4];
        return;
    case 'T' :
        ++ratio[5];
        return;
    default :
        return;
    }
}

int lowest()
{
    int min, i, a;
    min = ratio[1];

    for(i=0; i<6; ++i)
    {
        a = ratio[i]/iratio[i];
        if(a<min) min = a;
        ratio[i] = 0;
    }

    return min;
}

/* INPUT
--------------
5
MARGARITA

AAAAAAMMRRTITIGGRRRRRRRR
AMARGITA
BOLOGNESACAPRICHOSATOMATERA
ABCDEFGHIJKLMNOPQRSTUVWXYZ

*/
