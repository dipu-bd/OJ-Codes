// C header files
#include <stdio.h>
// C++ header files
#include <algorithm>
#include <vector>
// default namespace
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("441.inp", "r", stdin);
#endif

    int t, x;
    bool first = false, sorted;
    vector<int> vc;

    while(scanf("%d", &t) != EOF && t > 0)
    {
        if(first) { putchar('\n'); vc.clear();}

        // input
        while(t--)
        {
            scanf("%d", &x);
            vc.push_back(x);
        }

        do  //check permutations and print
        {
            sorted = true;
            for(vector<int>::iterator it = vc.begin() + 1;
                    it < vc.begin() + 6 && sorted; ++it) sorted = (*it > *(it - 1));

            if(sorted)
            {
                for(vector<int>::iterator it = vc.begin();
                    it < vc.begin() + 6; ++it) printf("%d ", *it);
                putchar('\n');
            }
        }
        while(next_permutation(vc.begin(), vc.end()));
        first = true;
    }

    return 0;
}
