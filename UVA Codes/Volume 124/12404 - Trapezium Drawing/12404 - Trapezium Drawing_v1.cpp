/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;

int test, cas = 1;
const double PI = 2 * acos(0.0);

struct POINT
{
    double x;
    double y;
};

double a, b, c, d;
double angle1, angle2;
POINT A, B, C, D, P, Q;

/**
   gets distant between A and B points
*/
double getdis(POINT A, POINT B)
{
    return hypot(A.x - B.x, A.y - B.y);
}

/**
   gets the point that divide line AB inside of it.
   k1 = distance from A, k2 = distance from B
*/
POINT divide_in(POINT A, POINT B, double k1, double k2)
{
    POINT ans;
    ans.x = (k1 * B.x + k2 * A.x) / (k1 + k2);
    ans.y = (k1 * B.y + k2 * A.y) / (k1 + k2);
    return ans;
}

/**
   gets the point that divide line AB outside of it.
   k1 = distance from A, k2 = distance from B
*/
POINT divide_out(POINT A, POINT B, double k1, double k2)
{
    POINT ans;
    ans.x = (k2 * A.x - k1 * B.x) / (k2 - k1);
    ans.y = (k2 * A.y - k1 * B.y) / (k2 - k1);
    return ans;
}

/** gets angle between side a and b in a triangle with sides a, b, c. */
double getangle(double a, double b, double c)
{
    return acos((a * a + b * b - c * c) / (2 * a * b));
}


/** rotates P counter-clockwise around O in given angle */
POINT rotate(POINT O, POINT P, double angle)
{
    POINT ans;
    double s = sin(angle);
    double c = cos(angle);
    ans.x = O.x + (P.x - O.x) * c - (P.y - O.y) * s;
    ans.y = O.y + (P.x - O.x) * s + (P.y - O.y) * c;
    return ans;
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y);
        scanf("%lf %lf %lf", &b, &c, &d);

        a = getdis(A, B);
        
        C = divide_out(A, B, a + b, b);
        angle2 = getangle(a - c, b, d);
        C = rotate(B, C, PI - angle2);
        
        D = divide_in(A, B, d, a - d); 
        angle1 = getangle(a - c, d, b);
        D = rotate(A, D, angle1);

        printf("Case %d:\n", cas++);
        printf("%.8f %.8f %.8f %.8f\n", 
               C.x + 1e-10, C.y + 1e-10, D.x + 1e-10, D.y + 1e-10);
    }

    return 0;
}
