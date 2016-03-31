#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int n, m;                      // length of input string
char T[MAX];                // input string up to 100K characters
char P[MAX];                // pattern to search
int SA[MAX], tempSA[MAX];   // suffix array and temporary suffix array
int RA[MAX], tempRA[MAX];   // rank array and temporary rank array
int c[MAX];                 // for counting or radix sort


void show()
{
    puts("");
    for(int i = 0; i < n; ++i) printf("%3d", i);
    puts("");
    for(int i = 0; i < n; ++i) printf("%3c", T[i]);
    puts("");
    for(int i = 0; i < n; ++i) printf("%3d", SA[i]);
    puts("");
    for(int i = 0; i < n; ++i) printf("%3d", RA[i]);
    puts("");
}

void print()
{
    puts("");
    for(int i = 0; i < n; ++i)
    {
        printf("%3d%3d ", i, SA[i]);
        puts(T + SA[i]);
    }
}

void countingSort(int k)    // sort suffix array in O(n)
{
    int i, sum;
    int maxi = max(256, n); // up to 255 ASCII chars or length of n

    memset(c, 0, sizeof c); // clear frequency table
    for(i = 0; i < n; ++i)  // count frequency of each integer rank
    {
        if(i + k < n)
            c[RA[i + k]]++;
        else
            c[0]++;
    }
    for(i = sum = 0; i < maxi; ++i)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for(i = 0; i < n; ++i)
    {
        if(SA[i] + k < n)
        {
            tempSA[c[RA[SA[i] + k]]] = SA[i];
            c[RA[SA[i] + k]]++;
        }
        else
        {
            tempSA[c[0]] = SA[i];
            c[0]++;
        }
    }
    for(i = 0; i < n; ++i)
    {
        SA[i] = tempSA[i];
    }
}

void buildSA()   // build suffix array in O(n.log(n))
{
    int i, k, r;
    for(i = 0; i < n; ++i) SA[i] = i;       // initialize SA
    for(i = 0; i < n; ++i) RA[i] = T[i];    // initialize RA
    for(k = 1; k < n; k <<= 1)
    {
        countingSort(k);    // sort by second item
        countingSort(0);    // then sort by first item

        // re-ranking starting from rank, r = 0
        r = 0;
        tempRA[SA[0]] = r;
        for(i = 1; i < n; ++i)
        {
            if(!(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k])) ++r;
            tempRA[SA[i]] = r;
        }
        for(i = 0; i < n; ++i) RA[i] = tempRA[i];

        // a nice optimization trick:
        // stop when no change detected.
        if(RA[SA[n - 1]] == n - 1) break;
    }
}

bool compLOW(const int& a, const char* p)
{
    return strncmp(T + SA[a], P, m);
}
bool compUP(const char* p, const int& a)
{
    return compLOW(a, p);
}

void stringMatching()
{
    int low = lower_bound(SA, SA + n, P, compLOW) - SA;
    int up = upper_bound(SA, SA + n, P, compUP) - SA;
    printf("%d to %d : %d\n", low, up, up - low);
}

int main()
{
    scanf("%s", T);
    n = (int)strlen(T);
    T[n++] = '$';

    buildSA();

    show();
    print();

    puts("\nInput strings:");
    while(scanf("%s", P)==1)
    {
        m = (int)strlen(P);
        stringMatching();
    }

    return 0;
}
