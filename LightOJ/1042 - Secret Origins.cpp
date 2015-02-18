#include <stdio.h>
#include <bitset>
using namespace std;

int main()
{
    int test, cas = 1;

    int n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        bitset<31> bit(n);

        for(int i = 0, lo = 0; i < bit.size(); ++i)
        {
            if(bit[i])
            {
                if(!bit[i + 1])
                {
                    bit.set(i, 0);
                    bit.set(i + 1, 1);
                    break;
                }
                else if(lo < i)
                {
                    bit.set(lo++, 1);
                    bit.set(i, 0);
                }
                else lo++;
            }
        }

        printf("Case %d: %d\n", cas++, (int)bit.to_ulong());
    }

    return 0;
}
