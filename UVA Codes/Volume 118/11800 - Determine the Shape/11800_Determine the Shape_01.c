#include <stdio.h>
#include <stdlib.h>

#define line(a,b) ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))

typedef struct
{
    int x, y;
} Point;

int compare(const int *a, const int *b)
{
    return (*a) - (*b);
}

int main()
{
    Point a,b,c,d;
    int t, i, lines[6];

    scanf("%d", &t);
    for(i=1; i<=t; ++i)
    {
        scanf("%d %d\n%d %d\n%d %d\n%d %d", &a.x,&a.y, &b.x,&b.y, &c.x,&c.y, &d.x,&d.y);
        lines[0] = line(a,b), lines[1] = line(a,c), lines[2] = line(a,d);
        lines[3] = line(b,c), lines[4] = line(b,d), lines[5] = line(c,d);

        qsort(lines,6,sizeof(int),compare);

        printf("%d %d %d %d %d %d", lines[0], lines[1], lines[2], lines[3], lines[4], lines[5], lines[6]);

        if(lines[0]==lines[1]==lines[2]==lines[3])
            if(lines[4]==lines[5]) printf("Case %d: Square\n", i);
            else printf("Case %d: Rhombus\n", i);
    }

    return 0;
}
