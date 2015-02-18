#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NULL -1
#define CORRECT -100

typedef struct
{
    int length;
    char word[30];
} Dictionary;

int DICT_SIZE = 0;
Dictionary *dict;

char query[50];

/* MAIN FUNCTION */
int main()
{
    int i,n,q;
    /* get dictionary */
    scanf("%d",&DICT_SIZE);
    dict = calloc(DICT_SIZE+10,sizeof(Dictionary));
    for(n=0; n<DICT_SIZE; ++n)
    {
        scanf(" %[^\n]", dict[n].word);
        dict[n].length = strlen(dict[n].word);
    }

    /* process query */
    scanf("%d",&q);
    for(i=0; i<q; ++i)
    {
        scanf(" %[^\n]",query);
        if(isCorrect(query))
            printf("%s is correct\n",query);
        else
        {
            n = search(query);
            if(n==NULL) printf("%s is unknown\n",query);
            else printf("%s is a misspelling of %s\n",query,dict[n].word);
        }
    }

    return 0;
}

/* SEARCH FOR WORD */
int isCorrect()
{
    int n;
    for(n=0; n<DICT_SIZE; ++n)
        if(!strcmp(dict[n].word,query)) return 1;
    return 0;
}

int search()
{
    int n, que_siz;
    que_siz = strlen(query);
    for(n=0; n<DICT_SIZE; ++n)
    {
        if(dict[n].length == que_siz)
        {
            if(isWrong(dict[n].word, query)) return n;
            else if(isAdjacent(dict[n].word, query)) return n;
        }
        else if(dict[n].length == que_siz+1)
        {
            if(isExcess(dict[n].word, query)) return n;
        }
        else if(dict[n].length == que_siz-1)
        {
            if(isExcess(query,dict[n].word)) return n;
        }
    }
    return NULL;
}

/* CHECK WORD PROPERTIES */

int isWrong(const char *word)
{
    int i,m;
    for(i=m=0; m<2 && query[i]; ++i)
        if(word[i]!=query[i]) ++m;
    return (m==1);
}

int isAdjacent(const char *word)
{
    int i,m;
    for(i=m=0; m<2 && query[i]; ++i)
    {
        if(query[i]!=word[i])
        {
            if(query[i]==word[i+1] &&
                    query[i+1]==word[i]) ++m, ++i;
            else return 0;
        }
    }
    return (m==1);

}

int isExcess(const char *bigger, const char *smaller)
{
    int i,j,m;
    for(i=j=m=0; smaller[i] && bigger[j]; ++i,++j)
        if(bigger[j]!=smaller[i]) --i, ++m;
    return (m<2);
}

