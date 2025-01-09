#include<iostream>

using namespace std ;

void PI(int) ;

int main()
{

    cout << "hii" << endl ;
    PI(3) ;
    cout << "bye" << endl ;
    return 0 ; 
}

// n -> 1
void PI(int n)
{
    if(n == 0)
        return ;
        
    PI(n-1) ;
    cout << n << endl ;
}