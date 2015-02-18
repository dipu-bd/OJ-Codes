#include <bits/stdc++.h>
using namespace std;

enum FACE
{
    _top = 0,
    _down = 1,
    _left = 2,
    _right = 3,
    _front = 4,
    _back = 5
};

enum ROTATION
{
    CW,
    CCW
};

//negihbors are in CCW order
const int neighbor[6][4] =
{
    { _front, _right, _back, _left },  //    _top
    { _front, _left, _back, _right },  // _down
    { _front, _top, _back, _down },  //   _left
    { _front, _down, _back, _top },  //  _right
    { _top, _left, _down, _right },  //  _front
    { _top, _right, _down, _left },  //   _back
};

const int DIM = 3;

struct Rect
{
    char color[DIM][DIM];

    Rect(char def = 'W')
    {
        memset(color, def, sizeof(color));
    }
    Rect(char mat[DIM][DIM])
    {
        memcpy(color, mat, sizeof(color));
    }

    char* operator [] (int i)
    {
        return color[i];
    }

    /**
    returns a character if whole color array is filled with it. Otherwise returns -1.
    @runtime O(DIM*DIM) [O(20)op]
    */
    char getColor(void)
    {
        char t = color[0][0];
        for(int i = 0; i < DIM; ++i)
            for(int j = 0; j < DIM; ++j)
                if(color[i][j] != t)
                    return -1;
        return t;
    }

    /**
    Rotate the rectange at the given direction
    @runtime O(2*DIM*DIM) [O(40)op]
    */
    char rotate(ROTATION dir = CW)
    {
        Rect tmp = *this;
        for(int i = 0; i < DIM; ++i)
        {
            for(int j = 0; j < DIM; ++j)
            {
                if(dir == CW)
                    color[i][j] = tmp[DIM - j - 1][i];
                else
                    color[i][j] = tmp[j][DIM - i - 1];
            }
        }
    }
};

struct Cube
{
    Rect side[6];

    Cube(void)
    {
    }

    Cube(char mat[][DIM][DIM])
    {
        side[_top] = Rect(mat[_top]);
        side[_down] = Rect(mat[_down]);
        side[_left] = Rect(mat[_left]);
        side[_right] = Rect(mat[_right]);
        side[_front] = Rect(mat[_front]);
        side[_back] = Rect(mat[_back]);
    }

    Rect& operator [] (int i)
    {
        return side[i];
    }

    /**
    returns if the rubiks cube is solved.
    @runtime O(4*DIM*DIM) [O(85)op]
    */
    bool isSolved()
    {
        for(int i = 0; i < 6; ++i)
            if(side[i].getColor() == -1)
                return false;
        return true;
    }

    /**
    Rotate a face of the cube at the given direction
    @runtime O(12*DIM*DIM) [O(115)op]
    */
    void rotate(FACE face = _top, ROTATION dir = CW, int times = 1)
    {
        int i, j, k, u, v;

        Cube tmp = *this;
        side[face].rotate(dir);

        if(dir == CW) j = times & 3;
        else j = 4 - (times & 3);
        for(i = 0; i < 4; ++i, ++j)
        {
            u = neighbor[face][i];
            v = neighbor[face][j];

            switch(face)
            {
            case _top: //move 0th row
                for(k = 0; k < DIM; ++k)
                    side[u][0][k] = tmp.side[v][0][k];
                break;
            case _down: //move nth row
                for(k = 0; k < DIM; ++k)
                    side[u][DIM - 1][k] = tmp.side[v][DIM - 1][k];
                break;
            case _left:
            case _back: //move 0th col
                for(k = 0; k < DIM; ++k)
                    side[u][k][0] = tmp.side[v][k][0];
                break;
            case _right:
            case _front: //move nth col
                for(k = 0; k < DIM; ++k)
                    side[u][k][DIM - 1] = tmp.side[v][k][DIM - 1];
                break;
            }
        }
    }
};
