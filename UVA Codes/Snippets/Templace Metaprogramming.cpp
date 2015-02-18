#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

template<int n> 
struct fibonacci
{
    enum { val = fibonacci<n - 1>::val + fibonacci<n - 2>::val + 1LL };
};

template<> 
struct fibonacci<0>
{
    enum { val = 1LL };
};

template<> 
struct fibonacci<1>
{
    enum { val = 1LL };
};

int main()
{
    cout << "Fibonacci 10: ";
    cout << fibonacci<10>::val <<endl;
    
    cout << "Fibonacci 20: ";
    cout << fibonacci<20>::val <<endl;
    
    cout << "Fibonacci 30: ";
    cout << fibonacci<30>::val <<endl;
    
    cout << "Fibonacci 40: ";
    cout << fibonacci<40>::val <<endl;
    
    cout << "Fibonacci 40: ";
    cout << fibonacci<50>::val <<endl;
    
    getchar();
    return 0;
}