#include <stdio.h>
#include <stdlib.h>

#define EXIST(p,f) printf("Point %d is contained in figure %d\n",p,f)
#define NOT(p) printf("Point %d is not contained in any figure\n",p)

int rc;
double **rect;

void input();
void isIn(double x,double y, int p);

int main()
{
    rect = calloc(11, sizeof(double*));

    char c;
    double x,y;
    register p;

    for(rc=0; scanf(" %c", &c)!=EOF && c!='*'; rc++) input();

    for(p=1; scanf(" %lf %lf",&x,&y)!=EOF  &&
            (x<9999.9 || y<9999.9); p++) isIn(x,y,p);

    return 0;
}

void input()
{
    rect[rc]=calloc(4,sizeof(double));
    scanf("%lf %lf %lf %lf",
          &rect[rc][0],&rect[rc][1],
          &rect[rc][2],&rect[rc][3]);
    return;
}

void isIn(double x,double y, int p)
{
    register i,j,e;
    for(i=0,e=1; i<rc; i++)
        if(rect[i][0]<x && x<rect[i][2] &&
            rect[i][3]<y && y<rect[i][1])
                e=0, EXIST(p,i+1);

    if(e) NOT(p);
    return;
}
