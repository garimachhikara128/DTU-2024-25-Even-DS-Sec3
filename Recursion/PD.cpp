#include<iostream>

using namespace std ;

void PD(int) ;

int main()
{

    cout << "hii" << endl ;
    PD(5) ;
    cout << "bye" << endl ;
    return 0 ; 
}

// n -> 1
void PD(int n)
{
    if(n == 0)
        return ;
        
    cout << n << endl ;
    PD(n-1) ;
}