#include <stdio.h>

void calculate(char *p,char *u, char *i, int ln);

int main()
{
    int tc;
    scanf("%d",&tc);

    char c,b='0',d='0';
    char p[50],u[50],i[50];
    int pi=1,ui=1,ii=1,ln=0,f=0;
    p[0]='0',u[0]='0',i[0]='0';
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
            ++ln;
            if(ln<=1) continue;
            if(p[pi-1]>='0' && p[pi-1]<='9') p[pi++]=' ';
            if(u[ui-1]>='0' && u[ui-1]<='9') u[ui++]=' ';
            if(i[ii-1]>='0' && i[ii-1]<='9') i[ii++]=' ';
            p[pi++]='\0';
            u[ui++]='\0';
            i[ii++]='\0';
            calculate(p,u,i,ln-1);
            p[0]='0';
            u[0]='0';
            i[0]='0';
            pi=1, ui=1, ii=1;
        }

        if(ln>tc) break;

        if(f && (c==' ' || b=='W' || b=='V' || b=='A')) f=0;

        if(f)
        {
            if(d=='P' && c!='W') p[pi++]=c;
            if(d=='U' && c!='V') u[ui++]=c;
            if(d=='I' && c!='A') i[ii++]=c;
        }

        if(c=='=') f=1, d=b;
        b=c;
    }

    return 0;
}

void calculate(char *p,char *u, char *i, int ln)
{
    double vp,vu,vi;
    char pp,pu,pi;
    sscanf(p,"%lf%c",&vp,&pp);
    sscanf(u,"%lf%c",&vu,&pu);
    sscanf(i,"%lf%c",&vi,&pi);

    if(pp=='M') vp*=1000000;
    if(pp=='k') vp*=1000;
    if(pp=='m') vp/=1000;

    if(pu=='M') vu*=1000000;
    if(pu=='k') vu*=1000;
    if(pu=='m') vu/=1000;

    if(pi=='M') vi*=1000000;
    if(pi=='k') vi*=1000;
    if(pi=='m') vi/=1000;

    if(vp==0) printf("Problem #%d\nP=%.2lfW\n\n",ln,vu*vi);
    if(vu==0) printf("Problem #%d\nU=%.2lfV\n\n",ln,vp/vi);
    if(vi==0) printf("Problem #%d\nI=%.2lfA\n\n",ln,vp/vu);

    return;
}
