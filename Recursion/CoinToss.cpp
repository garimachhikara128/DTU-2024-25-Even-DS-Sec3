#include<iostream>

using namespace std ;

void coinToss(int, string) ;

int main()
{
    coinToss(5, "") ;
    return 0 ;
}

void coinToss(int n, string ans)
{
    if(n == 0)
    {
        cout << ans << endl ;
        return ;
    }
    coinToss(n-1, ans + "H") ;
    coinToss(n-1, ans + "T") ;
}