#include <stdio.h>

int main()
{
    int day;
    int h,u,d,f;
    float up,fatig,climb;
    while(scanf("%d %d %d %d",&h,&u,&d,&f)==4)
    {
        if(h==0) break;
        fatig = u*f/100.0;
        climb = u;
        for(up=0,day=1;up>=0 && up<=h;day++)
        {

            up += climb;
            if(up<0 || up>h) break;
            up -=d;
            if(up<0 || up>h) break;
            climb = (climb>fatig)?climb-fatig:0;
        }

        if(up>=h) printf("success on day %d\n",day);
        else printf("failure on day %d\n",day);
    }
    return 0;
}
