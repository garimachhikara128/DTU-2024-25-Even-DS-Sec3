#include<iostream>

using namespace std ;

int fib(int) ;

int main()
{

    cout << "hii" << endl ;
    cout << fib(50) << endl ;
    cout << "bye" << endl ;
    return 0 ; 
}

// nth fib no ?
int fib(int n)
{
    if(n == 0 || n == 1)
        return n ;

    int fnm1 = fib(n-1) ;
    int fnm2 = fib(n-2) ;
    int fn = fnm1 + fnm2 ;
    return fn ;

}