int mod = 1000000;
const int dim = 5;

ll mat[dim][dim];
ll ans[dim][dim];
ll tmp[dim][dim];

void UNIT()
{
    clr(ans);
    REP(i, 0, dim)
    ans[i][i] = 1;
}

void COPY(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    ans[i][j] = A[i][j];
}

void CROSS(ll A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        {
            tmp[i][j] += ans[i][k] * A[k][j];
            tmp[i][j] %= mod;
        }
    }
    COPY(tmp);
}

void POWER(ll p)
{
    if(p == 0) UNIT();
    else if(p == 1) COPY(mat);
    else
    {
        POWER(p >> 1);
        CROSS(ans);
        if(p & 1) CROSS(mat);
    }
}

void init()
{
    clr(mat);
}
