#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
typedef unsigned long long ull;
typedef map<char, int> cimap;
typedef map<char, ull> cllmap;

map<char, cimap> rule;
map<char, ull> freq1;
map<char, ull> freq2;

int main()
{
    int test;
    scanf("%d", &test);

    char ch;
    int loop, n;
    char inp[150];
    while(test--)
    {
        rule.clear();

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %c->%s", &ch, inp);
            cimap& cmp = rule[ch];
            for(int i = 0; inp[i]; ++i) ++cmp[inp[i]];
        }

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %s %c %d", inp, &ch, &loop);

            freq1.clear();
            for(int i = 0; inp[i]; ++i) ++freq1[inp[i]];

            for(int i = 0; i < loop; ++i)
            {
                freq2.clear();
                for(cllmap::iterator pt = freq1.begin(); pt != freq1.end(); ++pt)
                {
                    char j = pt->first;
                    if(rule.count(j))
                        for(cimap::iterator it = rule[j].begin();
                                it != rule[j].end(); ++it)
                            freq2[it->first] += pt->second * it->second;
                    else
                        freq2[j] += pt->second;
                }

                freq1 = freq2;
            }

            printf("%llu\n", freq1[ch]);
        }
    }

    return 0;
}
