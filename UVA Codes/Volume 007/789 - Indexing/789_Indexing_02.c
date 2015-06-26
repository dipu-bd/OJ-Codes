#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define LINES 5000

typedef struct
{
    int pc;
    int pos[LINES];
    char word[100];
} WORD;

int lc;
char key;
char line[100];
char count = 0;
WORD words[SIZE];

int checkWord(register int i);
int printResult();
int compare(const WORD *w1, const WORD *w2);

int main()
{ 
    memset(words, 0, SIZE*sizeof(WORD));

    key = getchar();

    register int i;
    for(lc=1; scanf(" %[^\n]", line)!=EOF; ++lc)
        for(i=0; line[i]; i=checkWord(i));

    qsort(words, count, sizeof(WORD), compare);
    printResult();

    return 0;
}

int checkWord(register int i)
{
    register int j,k,l;

    j = i;
    while(isalpha(line[j])) ++j;                /* increment while letters */

    k = j;
    while(line[k] && !isalpha(line[k])) ++k;    /* increment while not letters */

    if(line[i]!=key) return k;          /* returns next word pos if not matched */

    for(l=0; l<count; ++l)
        if(!memcmp(line+i, words[l].word, j-i)) break;

    memcpy(words[l].word, line+i, j-i);
    words[l].pos[words[l].pc++] = lc;
    if(l==count) ++count;

    return k;
}

int printResult()
{
    register int i,j, last = 0;
    for(i=0; i<count; ++i)
    {
        printf(words[i].word);
        for(j=0; j<words[i].pc; ++j)
            if(last != words[i].pos[j])
            {
                last = words[i].pos[j];
                printf(" %d", last);
            }

        putchar('\n');
    }
}

int compare(const WORD *w1, const WORD *w2)
{
    return strcmp(w1->word, w2->word);
}
