#include "Header.h"

struct Move
{
    Cube cur;
    string movement;
};

queue<Move> queue1;

struct Solver
{
    void showcube(Cube& rubik)
    {
        /*
             | back|
         left| top |right|bottom
             |front|
        */

        int i, j;

        //show back
        {
            for(j = -1; j <= DIM; ++j) putchar(' ');
            for(j = 0; j < DIM; ++j) putchar('_');
            printf("\n");
        }
        for(i = 0; i < DIM; ++i)
        {
            for(j = 0; j <= DIM; ++j) putchar(' ');
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_back][i][j]);
            printf("|\n");
        }

        //separator
        for(i = 4 * DIM + 5; i > 0; --i) putchar('-');
        putchar('\n');
        //show left top right bottom
        for(i = 0; i < DIM; ++i)
        {
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_left][i][j]);
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_top][i][j]);
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_right][i][j]);
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_down][i][j]);
            putchar('|');
            putchar('\n');
        }

        //separator
        for(i = 4 * DIM + 5; i > 0; --i) putchar('-');
        putchar('\n');
        //show front
        for(i = 0; i < DIM; ++i)
        {
            for(j = 0; j <= DIM; ++j) putchar(' ');
            putchar('|');
            for(j = 0; j < DIM; ++j) putchar(rubik[_front][i][j]);
            printf("|\n");
        }
        {
            for(j = -1; j <= DIM; ++j) putchar(' ');
            for(j = 0; j < DIM; ++j) putchar('-');
            printf("\n");
        }
    }

    /**
    Solve the rubik's cube.
    @limitation currently only available for 3 dimensional cube.
    */
    void Solve(Cube r)
    {
        /* ALGORITHM ->
            1> Put a color on top so that first row of each neighbors are of equal colors : use backtrack
            2> Make 2nd row of the neighbors of top the same color : fixed algo present
            4> solve the cube : fixed algo present
        */

        puts("Initial configuration: ");
        showcube(r);

        puts("Solving... ");
        Move m = backtrack(r);

        printf("\nMOVES : %s\n", m.movement.data());
        showcube(m.cur);
    }

    //
    // backtrack functions
    //
    Move backtrack(Cube r)
    {
        Move m;
        m.cur = r;
        m.movement.clear();

        if(m.cur.isSolved()) return m;

        queue1.push(m);
        while(queue1.size())
        {
            m = queue1.front();
            r = m.cur;
            string mov = m.movement;
            queue1.pop();

            if(mov.size() > 20)
                continue;

            for(int i = 0; i < 6; ++i)
                if(m.cur.side[i].getColor() != -1)
                    return m;

            //rotate top
            m.cur.rotate(_top, CW);
            m.movement.push_back('T+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_top, CCW);
            m.movement.push_back('T-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            //rotate front
            m.cur.rotate(_front, CW);
            m.movement.push_back('F+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_front, CCW);
            m.movement.push_back('F-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            //rotate left
            m.cur.rotate(_left, CW);
            m.movement.push_back('L+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_left, CCW);
            m.movement.push_back('L-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            //rotate right
            m.cur.rotate(_right, CW);
            m.movement.push_back('R+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_right, CCW);
            m.movement.push_back('R-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            //rotate bottom
            m.cur.rotate(_down, CW);
            m.movement.push_back('D+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_down, CCW);
            m.movement.push_back('D-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            //rotate back
            m.cur.rotate(_back, CW);
            m.movement.push_back('B+');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;

            m.cur.rotate(_back, CCW);
            m.movement.push_back('B-');
            if(m.cur.isSolved()) return m;
            queue1.push(m);
            m.movement = mov;
            m.cur = r;
        }

        return m;
    }
};
