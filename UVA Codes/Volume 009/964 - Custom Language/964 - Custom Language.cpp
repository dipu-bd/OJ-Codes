/*==================================
Author : Sudipto Chandra (Dipu)
Email  : dipu.sudipta@gmail.com
University : SUST
===================================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> 
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque> 
using namespace std;
//typedefs
typedef long long ll;
typedef unsigned long long ull; 
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io 
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b) 
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i) 
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

struct Line
{
    int com;
    char type[20];
    char part[200];

    bool get()
    {
        type[0] = 0;
        part[0] = 0;
        
        if(scanf(" %s ", type) != 1)
            return false;

        if(!strcmp(type, "#"))
            return false;

        if(!strcmp(type, "PUSH"))
        {
            com = 0;
            if(scanf(" %s ", part) != 1)
                return false;
        }
        else if(!strcmp(type, "POP"))
        {
            com = 1;
            if(scanf(" %s ", part) != 1)
                return false;
        }
        else if(!strcmp(type, "DUP"))
        {
            com = 2;
        }
        else if(!strcmp(type, "ADD"))
        {
            com = 3;
        }
        else if(!strcmp(type, "SUB"))
        {
            com = 4;
        }
        else if(!strcmp(type, "MUL"))
        {
            com = 5;
        }
        else if(!strcmp(type, "DIV"))
        {
            com = 6;
        }
        else if(!strcmp(type, "READ"))
        {
            com = 7;
        }
        else if(!strcmp(type, "WRITE"))
        {
            com = 8;
        }
        else if(!strcmp(type, "JUMP"))
        {
            com = 9;
            if(scanf(" %s ", part) != 1)
                return false;
        }
        else if(!strcmp(type, "JUMPPOS"))
        {
            com = 10;
            if(scanf(" %s ", part) != 1)
                return false;
        }
        else if(!strcmp(type, "JUMPZERO"))
        {
            com = 11;
            if(scanf(" %s ", part) != 1)
                return false;
        }
        else
        {
            com = -1;
        }

        return true;
    }

    bool isInt()
    {
        int i = 0;
        if(part[i] == '-') ++i;
        for( ; part[i]; ++i)
        {
            if(!isdigit(part[i])) return false;
        }
        return true;
    }

    bool isVar()
    { 
        int i = 0;
        if(!islower(part[0])) return false;
        for(i = 1; part[i]; ++i)
        { 
            if(part[i] == '0') return false;
            if(!(islower(part[i]) || isdigit(part[i]))) return false;
        }
        return true;
    }
};

char inp[10000];
stack<int> data;
queue<int> input;
queue<int> output;
vector<Line> code;
map<string, int> vars;

int extract(const char* str)
{
    int var;
    sscanf(str, "%d", &var);
    return var;
}

bool getvar(int pos, int& v)
{
    if(code[pos].isInt())
    {
        v = extract(code[pos].part);
        return true;
    }
    if(code[pos].isVar())
    {
        if(!vars.count(code[pos].part)) return false;
        v = vars[code[pos].part];
        return true;
    }
    return false;
}

bool execute()
{
    int pos = 0, a, b, v;
    while(pos >= 0 && pos < (int)code.size())
    {
        //printf("%d|%s|%s\n", code[pos].com, code[pos].type, code[pos].part);
        switch(code[pos].com)
        {
          case 0:
            if(!getvar(pos, v)) return false;
            data.push(v);
            pos++;
            break;
          case 1:
            if(data.empty()) return false;
            if(!code[pos].isVar()) return false; 
            vars[code[pos].part] = data.top();
            data.pop();
            pos++;
            break;
          case 2:
            if(data.empty()) return false;
            data.push(data.top());
            pos++;
            break;
          case 3:
            if(data.size() < 2) return false;
            a = data.top(); data.pop();
            b = data.top(); data.pop();
            data.push(a + b);
            pos++;
            break;
          case 4:
            if(data.size() < 2) return false;
            a = data.top(); data.pop();
            b = data.top(); data.pop();
            data.push(a - b);
            pos++;
            break;
          case 5:
            if(data.size() < 2) return false;
            a = data.top(); data.pop();
            b = data.top(); data.pop();
            data.push(a * b);
            pos++;
            break;
          case 6:
            if(data.size() < 2) return false;
            a = data.top(); data.pop();
            b = data.top(); data.pop();
            if(b == 0) return false;
            data.push(a / b);
            pos++;
            break;
          case 7:
            if(input.empty()) return false;
            data.push(input.front());
            input.pop();
            pos++;
            break;
          case 8:
            if(data.empty()) return false;
            output.push(data.top());
            data.pop();
            pos++;
            break;
          case 9:
            if(!getvar(pos, v)) return false;
            pos = v - 1;
            break;
          case 10:
            if(data.empty()) return false;
            if(data.top() > 0)
            {
                if(!getvar(pos, v)) return false;
                pos = v - 1;
            }
            else
            {
                pos++;
            }
            data.pop();
            break;
          case 11:
            if(data.empty()) return false;
            if(data.top() == 0)
            {
                if(!getvar(pos, v)) return false;
                pos = v - 1;
            }
            else
            {
                pos++;
            }
            data.pop();
            break;
          default:
            return false;
        }
    }

    return true;

}

int main()
{
    Line line;

    while(!feof(stdin))
    {
        vars.clear();
        code.clear();
        while(data.size()) data.pop();
        while(input.size()) input.pop();
        while(output.size()) output.pop();
        
        while(line.get())
        {
            code.push_back(line);  
        } 

        while(scanf(" %s ", inp) == 1)
        {
            if(!strcmp(inp, "#")) break;
            input.push(extract(inp));
        }

        if(execute())
        {
            while(output.size())
            {
                printf("%d\n", output.front());
                output.pop();
            }
        }
        else
        {
            puts("ABORTED");
        }
        puts("#");
    }

    return 0;
}
