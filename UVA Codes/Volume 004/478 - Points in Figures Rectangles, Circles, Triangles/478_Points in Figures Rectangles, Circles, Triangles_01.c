#include <stdio.h>
#include <string.h>
#include <math.h>

#define PRINT(i,j) printf("Point %d is contained in figure %d\n", i,j)
#define PRINTN(i) printf("Point %d is not contained in any figure\n",i)

/* STRUCTURES AND ENUMERATIONS */
typedef enum
{
    rect,
    circ,
    tri
} FIG_TYPE;

typedef struct
{
    double x, y;
} POINT;

typedef struct
{
    double xl, xr, yu, yd;
} RECT;

typedef struct
{
    double cx, cy, r;
} CIRC;

typedef struct
{
    double ax, ay, bx, by, cx, cy;
} TRI;


typedef struct
{
    FIG_TYPE type;
    union
    {
        RECT rect;
        CIRC circ;
        TRI tri;
    };
} Figure;


/* ARRAY OF FIGURES */
Figure figs[15];


/* FUNCTIONS TO CHECK POINT */

char IsInRect(POINT *pt, RECT *rect)
{
    return
        (pt->x > rect->xl && pt->x < rect->xr) &&
        (pt->y > rect->yd && pt->y < rect->yu);
}

char IsInCirc(POINT *pt, CIRC *circ)
{
    double d = sqrt((pt->x - circ->cx)*(pt->x - circ->cx)
                    + (pt->y - circ->cy)*(pt->y - circ->cy));

    return (circ->r > d);
}

#define SIGN(x1,y1,x2,y2,x3,y3) ((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3))
char IsInTriangle(POINT *pt, TRI *tri)
{
    char b1, b2, b3;

    b1 = SIGN(pt->x,pt->y, tri->ax,tri->ay, tri->bx,tri->by) < 0.0;
    b2 = SIGN(pt->x,pt->y, tri->bx,tri->by, tri->cx,tri->cy) < 0.0;
    b3 = SIGN(pt->x,pt->y, tri->cx,tri->cy, tri->ax,tri->ay) < 0.0;

    return (b1==b2) && (b2==b3);
}


/* MAIN FUNCTION */
int main()
{

#ifndef ONLINE_JUDGE
    freopen("478.inp", "r", stdin);
#endif

    char isnt, tp;
    int i,j, count;
    RECT r;
    CIRC c;
    TRI t;
    POINT pt;

    /* GET FIGURES */
    for(count=0; ; ++count)
    {
        scanf(" %c", &tp);
        if(tp == 'r')
        {
            figs[count].type = rect;
            scanf(" %lf %lf %lf %lf", &r.xl, &r.yu, &r.xr, &r.yd);
            figs[count].rect = r;
        }
        else if(tp == 'c')
        {
            figs[count].type = circ;
            scanf(" %lf %lf %lf", &c.cx, &c.cy, &c.r);
            figs[count].circ = c;
        }
        else if(tp == 't')
        {
            figs[count].type = tri;
            scanf(" %lf %lf %lf %lf %lf %lf", &t.ax, &t.ay, &t.bx, &t.by, &t.cx, &t.cy);
            figs[count].tri = t;
        }
        else break;
    }

    /* GET INPUT AND PROCESS */
    for(i=1; scanf(" %lf %lf", &pt.x, &pt.y)!=EOF && pt.x<9999.9; ++i)
    {
        isnt = 1;

        for(j=0; j<count; ++j)
        {
            switch(figs[j].type)
            {
            case rect :
                if(IsInRect(&pt, &figs[j].rect))
                    isnt =  0, PRINT(i, j+1);
                break;
            case circ :
                if(IsInCirc(&pt, &figs[j].circ))
                    isnt =  0, PRINT(i, j+1);
                break;
            case tri:
                if(IsInTriangle(&pt, &figs[j].tri))
                    isnt =  0, PRINT(i, j+1);
                break;
            }
        }

        if(isnt) PRINTN(i);
    }

    return 0;
}
