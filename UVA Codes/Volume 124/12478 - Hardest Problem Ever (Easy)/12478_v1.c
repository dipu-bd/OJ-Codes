#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

const char grid[][12] = {"OBIDAIBKR", "RKAULHISP", "SADIYANNO", "HEISAWHIA",
                         "IRAKIBULS", "MFBINTRNO", "UTOYZIFAH", "LEBSYNUNE", "EMOTIONAL"
                        };

const char names[][12] = { "RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
char tmp[15], hor[15], ver[15];

int comp(const void* a, const void* b)
{
    return (*(char*)a - * (char*)b);
}

int main()
{
    int i, count, j, k, l, len;
    for(i = 0; i < 8; ++i)
    {
        count = 0;
        len = strlen(names[i]);
        strcpy(tmp, names[i]);
        qsort(tmp, len, sizeof(char), comp);

        for(j = 0; j < 10; ++j)
            for (k = 0; k < 10; ++k)
            {
                for(l = 0; l < len; ++l)
                {
                    hor[l] = grid[j][l + k];
                    ver[l] = grid[l + j][k];
                }
                hor[l] = ver[l] = 0;

                qsort(hor, len, sizeof(char), comp);
                qsort(ver, len, sizeof(char), comp);
                count += !strcmp(hor, tmp) + !strcmp(ver, tmp);
            }


        if(count == 2)
        {
            puts(names[i]);
            break;
        }
    }

    return 0;
}
