#include <stdio.h>
#include <math.h>

char quirk2[] = "00\n01\n81\n";
char quirk4[] = "0000\n0001\n2025\n3025\n9801\n";
char quirk6[] = "000000\n000001\n088209\n494209\n998001\n";
char quirk8[] = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";

int main()
{
    char inp[2];
    while(gets(inp))
        if(inp[0]=='2') printf(quirk2);
        else if(inp[0]=='4') printf(quirk4);
        else if(inp[0]=='6') printf(quirk6);
        else printf(quirk8);


    return 0;
}
