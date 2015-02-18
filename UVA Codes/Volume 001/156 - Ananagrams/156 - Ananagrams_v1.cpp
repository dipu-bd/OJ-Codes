#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
char input[100];


inline void lowercase(string& a)
{
    for(int i = 0, l = a.size(); i < l; ++i)
        a[i]  = tolower(a[i]);
    return;
}

void print(priority_queue<string>& pq)
{
    if(!pq.size()) return;
    string a = pq.top();
    pq.pop();
    print(pq);
    puts(a.c_str());
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("156.inp", "r", stdin);
#endif

    vector<string> words;
    string a, b;
    priority_queue<string> pq;
    bool found;

    while(scanf(" %s", input) != EOF && strcmp(input, "#"))
        words.push_back(input);

    for(int i = 0; i < words.size(); ++i)
    {
        a = words[i];
        lowercase(a);
        sort(a.begin(), a.end());

        found = false;
        for(int j = 0; j < words.size(); ++j)
        {
            if(i == j) continue;

            b = words[j];
            lowercase(b);
            sort(b.begin(), b.end());

            if(a == b) { found = true; break; }
        }

        if(!found) pq.push(words[i]);
    }

    print(pq);

    return 0;
}
