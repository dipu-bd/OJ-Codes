/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <stdio.h>
int test, cas = 1;

int main()
{
    double x1, y1, x2, y2; 
    double xc, yc, xd, yd;
    
    while(scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2)==4)
    {
        xc = (x1 + x2)/2;  yc = (y1 + y2)/2;     
        xd = (x1 - x2)/2;  yd = (y1 - y2)/2;   
        printf("%.10f %.10f %.10f %.10f\n", 
                xc - yd, xd + yc, xc+yd, yc-xd);
    } 
    
    return 0;
}
