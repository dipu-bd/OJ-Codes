#include "Solver.h"

Solver solver;

void scanface(FACE f, Cube& rubik)
{
    printf("   ");
    for(int j = 0; j <= DIM; ++j)
        if(j == DIM) putchar('\n');
        else putchar('-');

    for(int i = 0; i < DIM; ++i)
    {
        printf(" %d|", i);
        char line[20];
        scanf(" %[^\n]", line);

        for(int j = 0; line[j]; ++j)
        {
            char ch = line[j];
            rubik[f][i][j] = ch;

            if(!(ch == 'W' || ch == 'R' || ch == 'G' ||
                    ch == 'B' || ch == 'Y' || ch == 'O'))
            {
                puts("!@<invalid input>");
                --i;
                break;
            }
        }
    }

    printf("   ");
    for(int j = 0; j <= DIM; ++j)
        if(j == DIM) putchar('\n');
        else putchar('-');
}

Cube getcube()
{
    Cube rubik;

    puts("Top Face : ");
    scanface(_top, rubik);
    puts("");

    puts("Front Face : ");
    scanface(_front, rubik);
    puts("");

    puts("Left Face : ");
    scanface(_left, rubik);
    puts("");

    puts("Right Face : ");
    scanface(_right, rubik);
    puts("");

    puts("Down Face : ");
    scanface(_down, rubik);
    puts("");

    puts("Back Face : ");
    scanface(_back, rubik);
    puts("");

    return rubik;
}


int main()
{
    puts("   Rubik's Cube Solver   ");
    puts("=========================");
    puts("");

    puts("------------------------ Instructions ------------------------ \n");
    puts("Represents color with one character. eg:- ");
    puts("WHITE = W, RED = R, GREEN = G, BLUE = B, YELLOW = Y, ORANGE = O");
    puts("Default cube is 3x3x3. But the program can be modified for other dimensions.");
    printf("Current Dimension is [%dx%dx%d]\n", DIM, DIM, DIM);
    puts("");

    Cube r = getcube();
    puts("");

    solver.Solve(r);

    return 0;
}

/* INPUT : top front left right bottom back
GRG
WBR
ROY
YWB
RRY
BBW
YGG
GWW
BRO
RYW
BYY
ROB
WWG
BGG
ROY
OGO
OOY
OBW
*/
