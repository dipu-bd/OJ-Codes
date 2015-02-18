/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/

#include <stdio.h> 
 
int main()
{
    int a, b, c, d, e, ans;
    while(scanf("%d%d%d%d%d", &a,&b,&c,&d,&e)==5 && (a | b | c | d | e))
    {
        ans = a * b * c * (d * d) * (e * e);
        printf("%d\n", ans);
    }
    
    return 0;
}