#include <stdio.h>
#include <string.h>

int main()
{
    int test, cas = 1;
    int len, res, d, i;
    char S[150], T[150];
    int s01, s10, sq1, sq0;
    
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s", S, T);
        s01 = s10 = sq1 = sq0 = 0; 
        len = strlen(S);
        for(i = 0; i < len; ++i)
        {
            if(S[i] == '0' && T[i] == '1') ++s01;
            if(S[i] == '1' && T[i] == '0') ++s10;
            if(S[i] == '?' && T[i] == '1') ++sq1;
            if(S[i] == '?' && T[i] == '0') ++sq0;
        }
         
        /* cost to convert all ? */
        res = sq1 + sq0; 
        
        /* cost to swap 01 and 10 */
        d = s10 < s01 ? s10 : s01;
        res += d;
        s10 -= d;
        s01 -= d; 
        
        /* cost to swap ?1 and 10 */
        d = s10 < sq1 ? s10 : sq1;
        res += d;
        sq1 -= d;
        s10 -= d;
         
        /* cost to convert 0 to 1 */
        res += s01;
             
        printf("Case %d: ", cas++);
        if(s10 > 0)
            printf("-1\n");
        else 
            printf("%d\n", res);
    }
    
    return 0;
}