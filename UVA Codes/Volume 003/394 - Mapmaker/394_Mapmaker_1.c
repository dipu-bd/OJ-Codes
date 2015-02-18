#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[12];
    int base;
    short size;
    short d;
    struct
    {
        short lower;
        short upper;
    } bounds[10];
    short bsiz[10];
} arraydef;

typedef struct
{
    int index;
    int loc[10];
    int location;
} itemdef;


int n,r;
arraydef *ary;
itemdef *itm;
int main()
{
    scanf("%d %d",&n,&r);

    ary = calloc(n, sizeof(arraydef));
    itm = calloc(r, sizeof(itemdef));

    register i;
    for(i=0; i<n; i++) getArray(&ary[i]);
    for(i=0; i<r; i++) getItem(&itm[i]);
    print();
    return 0;
}

void getArray(arraydef *list)
{
    register j;
    scanf("%s %d %d %d", &(*list).name, &(*list).base, &(*list).size, &(*list).d);
    for(j=0; j<(*list).d; j++)
    {
        scanf("%d %d", &(*list).bounds[j].lower, &(*list).bounds[j].upper);
        (*list).bsiz[j] = (*list).bounds[j].upper - (*list).bounds[j].lower + 1;
    }
    return;
}
void getItem(itemdef *item)
{
    char nam[12];
    register j,d;
    scanf("%s", &nam);

    for(j=0; j<n; j++)
        if(!strcmp(nam,ary[j].name)) break;

    (*item).index = j;
    d = ary[j].d;
    for(j=0; j<d; j++)
        scanf("%d", &(*item).loc[j]);

    calculate(item);
    return;
}
void print()
{
    register i,j,k,d;
    for(j=0; j<r; j++)
    {
        i = itm[j].index;
        printf("%s[",ary[i].name);

        d = ary[i].d-1;
        for(k=0; k<d; k++)
            printf("%d, ",itm[j].loc[k]);

        printf("%d] = %d\n", itm[j].loc[d], itm[j].location);
    }
    return;
}

void calculate(itemdef *item)
{
    register i,j,x,t,r;
    i = (*item).index;
    j=ary[i].d-1;
    for(r=0, t=1; j>=0; j--)
    {
        x = (*item).loc[j] - ary[i].bounds[j].lower;
        r += x*t;
        t *= ary[i].bsiz[j];
    }
    (*item).location = ary[i].base + r*ary[i].size;
    return;
}

