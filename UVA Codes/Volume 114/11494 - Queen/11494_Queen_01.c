#include <stdio.h>

int main()
{
    char *move;
    int i, j, x, y, m;
    while(scanf("%d %d %d %d", &i, &j, &x, &y) != EOF && i > 0 && x > 0)
    {
        if(i == x && j == y) move = "0";
        else if(i == x || j == y) move = "1";
        else if((x - i) == (j - y)) move = "1";
        else if((i - x) == (j - y)) move = "1";
        else move = "2";

        puts(move);
    }

    return 0;
}
