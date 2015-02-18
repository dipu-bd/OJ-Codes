// C header files
#include <stdio.h>
#include <ctype.h>
#include <vector>
using namespace std;

#define MAX 36

#define IGNORE_SPACE \
        do {\
            ch = getchar(); \
            if(ch == EOF) return 0;  \
        } while(isspace(ch)); \
        ungetc(ch, stdin);

#define INPUT_NUMBER(i, base1, num1) \
        for(i = base1 = 0; !isspace(ch = getchar()); ++i) \
        {\
            if(ch == EOF) break; \
            ch = isdigit(ch) ? ch - '0' : ch - 'A' + 10;\
            num1[i] = ch;\
            if(base1 < ch) base1 = ch;\
        }\
        num1[i] = 0; if(base1 < 1) base1 = 1;

#define PRINT_NUMBER(len1, num1) \
        for(int i = 0; i < len1; ++i) \
        {\
            ch = *(num1 + i); \
            putchar(ch < 10 ? ch + '0' : ch + 'A' - 10); \
        }


long long power(long long a, long long n)
{
    if(n == 0) return 1;
    if(n & 1)
    {
        long long res = power(a, (n - 1) >> 1);
        return a * res * res;
    }
    else
    {
        long long res = power(a, n >> 1);
        return (res * res);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("343.inp", "r", stdin);
#endif

    char num1[500], num2[500], ch;
    int base1, base2, len1, len2 ;
    vector<long long> na, nb;
    long long num;

    do
    {
        // input number 1
        IGNORE_SPACE;
        INPUT_NUMBER(len1, base1, num1);

        // input number 2
        IGNORE_SPACE;
        INPUT_NUMBER(len2, base2, num2);

        // now convert each base to decimal and check equality
        na.clear(), nb.clear();
        for(int base = ++base1; base <= MAX; ++base)
        {
            for(int i = num = 0, j = len1, ch; j--; ++i)
                num += (long long)num1[i] * power(base, j);
            na.push_back(num);
        }

        for(int base = ++base2; base <= MAX; ++base)
        {
            for(int i = num = 0, j = len2, ch; j--; ++i)
                num += (long long)num2[i] * power(base, j);


            vector<long long>::iterator it = na.begin();
            for(int i = base1; it < na.end(); ++it, ++i)
                if(num == *it)
                {
                    base1 = i;
                    base2  = base;
                    goto found;
                }
        }

        // if not found
        PRINT_NUMBER(len1, num1);
        printf(" is not equal to ");
        PRINT_NUMBER(len2, num2);
        printf(" in any base 2..36\n");
        continue;

        //if found
found:
        {
            PRINT_NUMBER(len1, num1);
            printf(" (base %d) = ", base1);
            PRINT_NUMBER(len2, num2);
            printf(" (base %d)\n", base2);
        } ;
    }
    while(!feof(stdin));

    return 0;
}
