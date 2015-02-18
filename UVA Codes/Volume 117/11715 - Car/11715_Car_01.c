#include <stdio.h>
#include <math.h>

int i;
double u,v,a,s,t;

void set0();
void set1();
void set2();
void set3();

int main()
{
    int t;
    for(i=1; scanf("%d",&t)==1 && t>0; i++)
    {
        switch(t)
        {
            case 1: set0(); break;
            case 2: set1(); break;
            case 3: set2(); break;
            case 4: set3(); break;
        }
        puts("");
    }
    return 0;
}

void set0()
{
    scanf("%lf %lf %lf",&u, &v, &t);
    a = (v - u)/t;
    s = 0.5*(u+v)*t;
    printf("Case %d: %.3lf %.3lf", i, s, a);
}
void set1()
{
    scanf("%lf %lf %lf",&u, &v, &a);
    t = (v-u)/a;
    s = u*t + 0.5*a*t*t;
    printf("Case %d: %.3lf %.3lf", i, s, t);
}
void set2()
{
    scanf("%lf %lf %lf",&u, &a, &s);
    v = sqrt(u*u+2*a*s);
    t = (v-u)/a;
    printf("Case %d: %.3lf %.3lf", i, v, t);
}
void set3()
{
    scanf("%lf %lf %lf",&v, &a, &s);
    u = sqrt(v*v-2*a*s);
    t = (v-u)/a;
    printf("Case %d: %.3lf %.3lf", i, u, t);
}
