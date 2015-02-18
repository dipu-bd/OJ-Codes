#include <stdio.h>

int main()
{
    int tc;
    scanf("%d",&tc);
    printf("Lumberjacks:\n");

    register i,flag;
    int x,y;
    for(; tc>0; tc--)
    {
        scanf("%d %d",&x,&y);
        flag = (x>y)?1:-1;
        for(i=0; i<8; i++)
        {
            x=y, scanf("%d",&y);
            if(flag) flag = compare(x,y,flag);
        }
        if(flag) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}

int compare(register x, register y, register flag)
{
    if(x<y && flag<0) return -1;
    else if(x>y && flag>0) return 1;
    else return 0;
}
