#include <stdio.h>
#include <stdlib.h>

char *angles;
void loadAngles();

int main()
{
    loadAngles();
    int a;
    for(;scanf("%d",&a)!=EOF; putchar('\n'))
        if(angles[a]) putchar('Y');
        else putchar('N');
    return 0;
}

void loadAngles()
{
    register h,m,a;
    angles = calloc(181,sizeof(char));
    for(h=0;h <12;h++)
    {
        for(m=0;m<60;m++)
        {
            a = 30*h - 6*m;
            if(a<0) a=-a;
            if(a>180) a=360-a;
            angles[a]=1;
        }
    }
    return;
}
