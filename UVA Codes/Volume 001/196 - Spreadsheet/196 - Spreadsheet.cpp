#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 18300
vector<string> sheet[MAX];
typedef long long ll;

const char* getval(int r, int c)
{
    const char* cur = sheet[r][c].data();
    if(cur[0] != '=') return cur;

    ll t, res = 0;
    int l = strlen(cur);
    int p = 0, q = 0;
    for(int i = 0; i <= l; ++i)
    {
        if(cur[i] == '+' || cur[i] == 0)
        {
            sscanf(getval(p, q), "%lld", &t);
            res += t;
            p = 0, q = 0;
        }
        else if(isdigit(cur[i]))
        {
            p = p * 10 + cur[i] - '0';
        }
        else if(isalpha(cur[i]))
        {
            q = q * 26 + cur[i] - 'A' + 1;
        }
    }

    char num[30];
    sprintf(num, "%lld", res);
    sheet[r][c] = num;
    return sheet[r][c].data();
}

int main()
{
    int test;

    scanf("%d", &test);
    int row, col;
    while(test--)
    {
        scanf("%d %d", &col, &row);

        for(int i = 1; i <= row; ++i)
        {
            sheet[i].push_back("");
            for(int j = 1; j <= col; ++j)
            {
                if(j >= sheet[i].size())
                    sheet[i].push_back("");
                cin >> sheet[i][j];
            }
        }

        for(int i = 1; i <= row; ++i)
        {
            printf("%s", getval(i, 1));
            for(int j = 2; j <= col; ++j)
                printf(" %s", getval(i, j));
            putchar('\n');
        }
    }

    return 0;
}
