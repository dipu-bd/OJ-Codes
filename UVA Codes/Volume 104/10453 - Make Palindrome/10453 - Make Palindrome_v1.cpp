#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
using namespace std;

#define SIZ 1005
char inp[SIZ];
int save[SIZ][SIZ];
char out[SIZ];

int recur(int i, int j)
{
    if(i >= j) return 0;

    int& s = save[i][j];
    if(s != -1) return s;

    if(inp[i] == inp[j])
    {
        s = recur(i + 1, j - 1);
    }
    else
    {
        s = 1 + min(recur(i + 1, j), recur(i, j - 1));
    }

    return s;
}

string printpath(int i, int j)
{
    char ch;
    string s;

    if(i > j) return "";
    if(i == j)
    {
        s.push_back(inp[i]);
        return s;
    }

    if(inp[i] == inp[j])
    {
        ch = inp[i];
        s = printpath(i + 1, j - 1);
    }
    else
    {
        if(recur(i, j) == recur(i + 1, j) + 1)
        {
            ch = inp[i];
            s = printpath(i + 1, j);
        }
        else
        {
            ch = inp[j];
            s = printpath(i, j - 1);
        }
    }

    s.insert(s.begin(), ch);
    s.push_back(ch);
    return s;
}

int main()
{
#ifdef LOCAL
    freopen("10453.inp", "r", stdin);
#endif // LOCAL

    int test, cas = 1;

    while(scanf(" %s", inp) == 1)
    {
        memset(save, -1, sizeof(save));
        int len = strlen(inp) - 1;
        int r = recur(0, len);
        printf("%d ", r);
        string s = printpath(0, len);
        cout << s << endl;
    }

    return 0;
}
