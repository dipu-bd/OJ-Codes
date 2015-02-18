#include <stdio.h>
#include <iostream>
#include <map>
// default namespace
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10282.inp", "r", stdin);
    #endif

    char inp[50], word1[25], word2[25];
    map <string, string> dic;

    while(gets(inp) && *inp)
    {
        sscanf(inp, " %s %s", word1, word2);
        string w1(word1), w2(word2);
        dic[w2] = w1;
    }

    while(scanf(" %s", inp)!=EOF)
    {
        string word(inp);
        if(dic.end() == dic.find(word)) puts("eh");
        else cout << dic[word] << endl;
    }

    return 0;
}
