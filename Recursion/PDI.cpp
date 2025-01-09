#include<iostream>

using namespace std ;

void PDI(int) ;

int main()
{

    cout << "hii" << endl ;
    PDI(3) ;
    cout << "bye" << endl ;
    return 0 ; 
}

// n -> 1
void PDI(int n)
{
    if(n == 0)
        return ;
    
    cout << "hii" << n << endl ;
    PDI(--n) ;
    cout << "bye" << n << endl ;
}