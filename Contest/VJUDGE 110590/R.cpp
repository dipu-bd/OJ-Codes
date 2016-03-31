/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
//typedefs
typedef long long ll;
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct node
{
    int pos[2];
    node() { pos[0] = pos[1] = 0; }
    int& operator [] (int i) { return pos[i]; }
};

const int siz = 32;

int n;
ll arr[50010];
vector<node> trie;


void insert_trie(ll val)
{
    int pos = 0;
    for(ll m = siz; m >= 0; --m)
    {
        bool d = (val & (1LL << m));
        if(trie[pos][d] == 0)
        {
            trie[pos][d] = trie.size();
            trie.push_back(node());
        }
        pos = trie[pos][d];
    }
}

ll findMax(ll val)
{
    ll ans = 0;
    //try to find a number as close as possible to reverse of val in the trie
    int pos = 0;
    for(int m = siz; m >= 0; --m)
    {
        int d = (val & (1LL << m)) ? 0 : 1;

        if(trie[pos][d] == 0)
        {
            pos = trie[pos][1 ^ d];
        }
        else
        {
            ans |= (1LL << m);
            pos = trie[pos][d];
        }
    }

    return ans;
}

ll findMin(ll val)
{
    ll ans = 0;
    //try to find a number as close as possible to val in the trie
    int pos = 0;
    for(ll m = siz; m >= 0; --m)
    {
        int d = (val & (1LL << m)) ? 1 : 0;
        if(trie[pos][d] == 0)
        {
            ans |= (1LL << m);
            pos = trie[pos][1 ^ d];
        }
        else
        {
            pos = trie[pos][d];
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    ll maxi, mini;

    scanf("%d", &test);
    while(test--)
    {
        trie.clear();
        trie.push_back(node());

        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld", &arr[i]);
            arr[i] = arr[i - 1] ^ arr[i];

            if(i)
            {
                maxi = max(maxi, arr[i]);
                mini = min(mini, arr[i]);
                maxi = max(maxi, findMax(arr[i]));
                mini = min(mini, findMin(arr[i]));
            }
            else
            {
                maxi = arr[0];
                mini = arr[0];
            }
            insert_trie(arr[i]);
        }

        printf("Case %d: %lld %lld\n", cas++, maxi, mini);
    }

    return 0;
}

