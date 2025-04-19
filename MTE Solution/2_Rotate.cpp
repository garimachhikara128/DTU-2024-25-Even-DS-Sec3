#include<iostream>

using namespace std ;

int main()
{
        int arr[] = {2,3,4,5,6,7,8,9} ;
        int N = sizeof(arr) / sizeof(int) ;
        int k = 3 ;

        // One Loop, Time Complexity: O(n), Space Complexity: O(n)
        int na[N] ;
        for(int i = 0 ; i < N ; i++)
        {
                na[i] = arr[(i + N - k) % N] ;
                cout << na[i] << " " ;
        }
        cout << endl ;

        return 0 ;
}