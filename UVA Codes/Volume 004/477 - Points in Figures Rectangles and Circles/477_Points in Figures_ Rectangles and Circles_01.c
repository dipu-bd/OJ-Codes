#include <stdio.h>
#include <math.h>

#define RECT 'r'
#define CIRC 'c'
#define _TYPE [0]
#define _X1 [1]
#define _Y1 [2]
#define _X2 [3]
#define _Y2 [4]
#define _C1 [1]
#define _C2 [2]
#define _RAD [3]


int indx = 0;
double figs[12][5]={};

void inputRectangle()
{
    figs[indx]_TYPE = RECT;
    scanf("%lf", &figs[indx]_X1);
    scanf("%lf", &figs[indx]_Y2);
    scanf("%lf", &figs[indx]_X2);
    scanf("%lf", &figs[indx]_Y1);
    indx++;
    return;
}
void inputCircle()
{
    figs[indx]_TYPE = CIRC;
    scanf("%lf", &figs[indx]_C1);
    scanf("%lf", &figs[indx]_C2);
    scanf("%lf", &figs[indx]_RAD);
    indx++;
    return;
}

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((y1-y2)*(y1-y2) + (x1-x2)*(x1-x2));
}
int checkCirle(int i, double x, double y)
{
    double d = distance(figs[i]_C1, figs[i]_C2, x,y);
    return (0<d && d < figs[i]_RAD);
}
int checkRectangle(int i, double x, double y)
{
    return ((figs[i]_X1 < x) && (x < figs[i]_X2) &&
            (figs[i]_Y1 < y) && (y < figs[i]_Y2));
}
void checkPoint(int i, double x, double y)
{
    int j,e=0;

    for(j=0; j<indx; ++j)
        if(figs[j]_TYPE == CIRC)
        {
            if(checkCirle(j, x,y))
               e = printf("Point %d is contained in figure %d\n",i,j+1);
        }
        else
        {
            if(checkRectangle(j, x,y))
                e = printf("Point %d is contained in figure %d\n",i,j+1);
        }

    if(!e) printf("Point %d is not contained in any figure\n",i);

    return;
}

int main()
{
    int i;
    char c;
    double x,y;

    indx=0;
    while((c=getchar())!='*')
    {
        if(c=='c') inputCircle();
        else if(c=='r') inputRectangle();
    }

    for(i=1; scanf("%lf %lf",&x,&y)==2
        && x<9999.9; i++) checkPoint(i,x,y);

    return 0;
}
