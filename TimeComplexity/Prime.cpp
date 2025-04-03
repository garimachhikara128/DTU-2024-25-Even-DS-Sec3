#include<iostream>

using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int factors = 0 ;
    for(int i = 2 ; i * i <= n ; i++)
    {
        if(n%i == 0)
        {
            factors ++ ;
        }
    }

    if(factors == 0) 
        cout << "Prime" << endl ;
    else
        cout << "Not Prime" << endl ;

    return 0 ;
}