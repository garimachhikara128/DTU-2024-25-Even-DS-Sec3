#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int> v ;
    v.push_back(10) ;
    v[1] = 200 ;

    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << endl ;
    } 

    return 0 ;
}