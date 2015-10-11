/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;

/*
  a == c | a == c | a != c | a != c
  b == c | b != c | b == c | b != c
---------------------------------------------
  a == b | a != b | a != b | a == b (l)
    (p)  |   (q)  |   (r)  | a != b (m)
---------------------------------------------
   r + l + m = q + l + m = t <=> r = q
---------------------------------------------
  [1] p + 2 * q + l + m = n
  [2]         q + l + m = t
  [3]             p + l = e (number of a==b)
---------------------------------------------
 Minimizing this,   | if p is fixed,
     p + q = n - t <=>   q = n - t - p
     p + l = e     <=>   l = e - p
                   <=>   m = t - l - q
---------------------------------------------
All are positive and consistant with equ-[1]
*/

char getone(char a, char b)
{
    for(char c = 'a'; c <= 'z'; ++c)
    {
        if(c != a && c != b) return c;
    }
}

int main()
{
    int n, t;
    string a, b;
    cin >> n >> t >> a >> b;

    int e = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == b[i]) ++e;
    }

    int p, q, l, m;
    bool consistant = 0;
    for(int i = 0; i <= n; ++i)
    {
        p = i;
        q = n - t - p;
        l = e - p;
        m = t - l - q;

        //printf("%d %d %d %d\n", p, q, l, m);

        if(q >= 0 && l >= 0 && m >= 0
           && p + 2 * q + l + m == n
           && q + l + m == t)
        {
            consistant = 1;
            break;
        }
    }

    //printf("%d %d %d %d\n", p, q, l, m);

    if(!consistant)
    {
        puts("-1");
        return 0;
    }

    for(int i = 0; i < n; ++i)
    {
        if(a[i] == b[i])
        {
            if(l > 0)
            {
                --l;
                a[i] = getone(a[i], b[i]);
            }
        }
        else
        {
            if(m > 0)
            {
                --m;
                a[i] = getone(a[i], b[i]);
            }
            else if(q > 0)
            {
                --q;
                a[i] = b[i];
            }
        }
    }

    cout << a << endl;

    return 0;
}


