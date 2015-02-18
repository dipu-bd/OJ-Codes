#include<stdio.h>

int main()
{
    int w,h,n,res[100000],m=0,i;

    while(1)
    {
        scanf("%d %d %d",&w,&h,&n);
        if(w==0 && h==0 && n==0) break;

        int count=0,set[w][h],p,q;
        for(p=0;p<w;p++)
                for(q=0;q<h;q++)
                    set[p][q]=0;

        for(i=0;i<n;i++)
        {
            int x1,x2,y1,y2,c;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1>x2) {c=x1; x1=x2; x2=c;}
            if(y1>y2) {c=y1; y1=y2; y2=c;}
            for(p=x1-1;p<x2;p++)
                for(q=y1-1;q<y2;q++)
                    set[p][q]=1;
        }
        for(p=0;p<w;p++)
                for(q=0;q<h;q++)
                    count += set[p][q];

        res[m++]=(w*h)-count;
    }

    for(i=0;i<m;i++)
    {
        if(res[i]==0) printf("There is no empty spots.\n");
        else if(res[i]==1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n",res[i]);
    }

    return 0;
}
