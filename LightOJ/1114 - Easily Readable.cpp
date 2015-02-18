#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

char tmp[110];
char inp[100010];

inline void format(string& word)
{
    if(word.size() > 2)
    {
        swap(*(word.begin() + 1), *(word.end() - 1));
        if(word.size() > 3) sort(word.begin() + 2, word.end());
    }
}

inline void trim(char * p)
{
    char *big = p;
    while(*p == ' ') ++p;
    strcpy(big, p);
}

int main()
{
    int test, cas = 1;

    sscanf(gets(tmp), "%d", &test);
    while(test--)
    {
        int n;
        string word;
        map<string, int> dic;

        sscanf(gets(tmp), "%d", &n);
        while(n--)
        {
            gets(inp);
            word = inp;
            format(word);
            dic[word]++;
        }

        printf("Case %d:\n", cas++);

        sscanf(gets(tmp), "%d", &n);
        while(n--)
        {
            int res = 1;

            gets(inp);
            trim(inp);
            tmp[0] = 0;
            while(strlen(inp) && res)
            {
                sscanf(inp, " %s", tmp);

                if(strlen(tmp))
                {
                    word = tmp;
                    format(word);
                    res *= dic[word];
                }

                if(strlen(inp) <= strlen(tmp)) break;

                strcpy(inp, inp + strlen(tmp));
                trim(inp);
            }

            printf("%d\n", res);
        }
    }

    return 0;
}
