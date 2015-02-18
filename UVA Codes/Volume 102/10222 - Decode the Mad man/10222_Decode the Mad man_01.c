#include <stdio.h>
#include <ctype.h>

const char *set1 = "ertyuiop[]dfghjkl;'cvbnm,./";
const char *set2 = "qwertyuiopasdfghjklzxcvbnm,";

char decode(register c, register i);

int main()
{
    char c;
    register i;

    while((c=tolower(getchar()))!=EOF)
        putchar(decode(c,i));
    return 0;
}

char decode(register c, register i)
{
    for(i=0; i<26; i++)
        if(c==set1[i]) return set2[i];
    return c;
}
