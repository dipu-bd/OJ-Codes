#include <stdio.h>
#include <math.h>

typedef struct
{
    double x, y;
} point;
typedef struct
{
    double x1, y1, x2, y2;
} rectangle;
typedef struct
{
    double c1, c2, r;
} circle;
typedef struct
{
    char type;
    union
    {
        rectangle rect;
        circle circ;
    } fig;

} figure;

int indx;
figure figs[12];
void inputRectangle()
{
    figs[indx].type = 0;
    double x1,x2,y1,y2;
    scanf("%lf", &x1);
    scanf("%lf", &y2);
    scanf("%lf", &x2);
    scanf("%lf", &y1);
    figs[indx].fig.rect = (rectangle){x1,y1,x2,y2};
    indx++;
    return;
}
void inputCircle()
{
    figs[indx].type = 1;
    double c1,c2,r;
    scanf("%lf", &c1);
    scanf("%lf", &c2);
    scanf("%lf", &r);
    figs[indx].fig.circ=(circle){c1,c2,r};
    indx++;
    return;
}

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((y1-y2)*(y1-y2) + (x1-x2)*(x1-x2));
}
int checkCirle(circle *circ, point *pt)
{
    double d = distance(circ->c1, circ->c2, pt->x, pt->y);
    return (0<d && d < circ->r);
}
int checkRectangle(rectangle *rect, point *pt)
{
    return ((rect->x1 < pt->x) && (pt->x < rect->x2) &&
            (rect->y1 < pt->y) && (pt->y < rect->y2));
}
void checkPoint(int i, point *pt)
{
    int j,e=0;

    for(j=0; j<indx; j++)
        if(figs[j].type)
        {
            if(checkCirle(&figs[j].fig.circ, pt))
            {
                printf("Point %d is contained in figure %d\n",i,j+1);
                e = 1;
            }
        }
        else
        {
            if(checkRectangle(&figs[j].fig.rect, pt))
            {
                printf("Point %d is contained in figure %d\n",i,j+1);
                e = 1;
            }
        }

    if(!e) printf("Point %d is not contained in any figure\n",i);

    return;
}

int main()
{
    int i;
    char c;
    point pt;

    indx=0;
    while((c=getchar())!='*')
    {
        if(c=='c') inputCircle();
        else if(c=='r') inputRectangle();
    }

    for(i=1; scanf("%lf %lf",&pt.x,&pt.y)==2
            && pt.x<9999.9; i++) checkPoint(i,&pt);

    return 0;
}