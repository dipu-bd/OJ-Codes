#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000
#define mem(a,b) memset(a, b, sizeof(a))

inline int max(int a, int b)
{
    return a > b ? a : b;
}

struct node
{
    int cnt;
    int nums[4];

    int& operator [](const int& i)
    {
        return nums[i];
    }
};

inline int ind(const char& c)
{
    if(c == 'A') return 0;
    else if(c == 'T') return 1;
    else if(c == 'C') return 2;
    else return 3;
}

int siz, mval;
node trie[MAX];
char seq[100];

void trie_ins(int p = 0, int i = 0)
{
    if(!seq[i]) return;

    int t = ind(seq[i]);
    if(trie[p][t] == 0)
        trie[p][t] = siz++;

    p = trie[p][t];
    trie[p].cnt++;

    mval = max(mval, (i + 1) * trie[p].cnt);

    trie_ins(p, i + 1);
}

int main()
{
    int test, cas = 1;
    int n;

    scanf("%d", &test);
    while(test--)
    {
        siz = 1;
        mval = 0;

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %s", seq);
            trie_ins();
        }

        printf("Case %d: %d\n", cas++, mval);
        memset(trie, 0, (siz + 10) * sizeof(trie[0]));
    }

    return 0;
}
