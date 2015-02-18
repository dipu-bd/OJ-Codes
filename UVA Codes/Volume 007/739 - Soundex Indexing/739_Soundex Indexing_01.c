#include <stdio.h>

char sounddex[] = "01230120022455012623010202";
char inp[25], res[5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif

    printf("%9c%-20s%5c%s\n",' ',"NAME",' ', "SOUNDEX CODE");
    while(scanf(" %[^\n]",inp)!=EOF)
    {
        encode();
        printf("%9c%-20s%5c%s\n",' ',inp,' ',res);
    }
    printf("%19c%s\n",' ',"END OF OUTPUT");

    return 0;
}

/* ENCODE INPUT */
void encode()
{
    char i,j,b,p;

    j = 0;
    b=res[j] = sounddex[inp[0]-'A'];
    for(i=1; inp[i]!='\0'; ++i)
    {
        p = sounddex[inp[i]-'A'];
        if(p != '0' && b!=p) res[++j] = p;
        b = p;
    }

    while(j<4) res[++j]='0';
    res[0] = inp[0];
    res[4]='\0';

    return;
}
