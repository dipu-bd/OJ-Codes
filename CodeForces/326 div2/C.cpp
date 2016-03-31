#include <bits/stdc++.h>
using namespace std;

map<int, int> freq;

int main()
{
    int n, w;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &w);
        freq[w]++;
    }

    int res = 0;
    for(auto& p : freq)
    {
        if(p.second > 1)
        {
            int t = p.second;
            p.second = 0;
            for(int i = 0; t > 0; ++i, t >>= 1)
            {
                if(t & 1)
                {
                    freq[p.first + i]++;
                }
            }
        }
        if(p.second)
        {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}

