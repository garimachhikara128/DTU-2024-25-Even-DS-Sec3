#include<iostream>

using namespace std ;

int main()
{

    int n ; 
    cin >> n ;

    bool arr[n+1] ;
    for(int i = 0 ; i <= n ; i++)
        arr[i] = true ;
        
    arr[0] = false ;
    arr[1] = false ;

    for(int table = 2 ; table * table <= n ; table ++)
    {
        if(arr[table] == false) 
            continue ;

        for(int multiplier = 2 ; table * multiplier <= n; multiplier++)
        {
            arr[table * multiplier] = false ;
        }
    }

    for(int i = 0 ; i <= n ; i++)
    {
        if(arr[i] == true) 
            cout << i << endl ;
    }

    return 0 ;
}