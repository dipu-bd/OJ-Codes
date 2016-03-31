#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, a, p;
    int m = 1 << 25;
    long long total = 0;

    cin >> n;
    while(n--)
    {
        scanf("%d %d", &a, &p);
        if(p < m) m = p;
        total += a * m;
    }

    cout << total;

    return 0;
}
