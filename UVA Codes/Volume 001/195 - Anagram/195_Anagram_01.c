#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;
char word[10];

void printAnagram()
{
    int i, j, k;
    for(i=0; i<size; ++i)
    {
        for(j=0; j<size; ++j)
        {
            if(j==i) continue;

            putchar(word[i]);

            for(k=j; k<size; ++k)
                if(k!=i) putchar(word[k]);

            for(k=0; k<j; ++k)
                if(k!=i) putchar(word[k]);

            putchar('\n');
        }
    }

}

int compare(const char *a, const char *b)
{
    int c =(toupper(*a) - toupper(*b));
    if(!c) return ((*a) - (*b));
    else return c;
}

int main()
{
    int n;
    scanf("%d\n",&n);

    while(n--)
    {
        scanf(" %[^\n]", word);
        size = strlen(word);
        qsort(word, size, sizeof(char), compare);
        printAnagram();
    }

    return 0;
}
