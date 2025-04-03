#include<iostream>
int power(int , int) ;

using namespace std ;

int main()
{
    cout << power(2,10) << endl;

    return 0 ;
}

int power(int x, int n)
{
    if(n == 0)
        return 1 ;

    int sp = power(x,n-1) ;
    int bp = sp * x ;
    return bp ;
}