#include<iostream>

using namespace std ;

int validParenthesis(int, string, int, int) ;

int main()
{
    cout << validParenthesis(3, "", 0, 0) << endl ;
    return 0 ;
}

int validParenthesis(int n, string ans, int open, int close)
{
    if(open == n && close == n) 
    {
        cout << ans << endl ;
        return 1 ;
    }

    if(open > n || close > open) 
        return 0 ;

    int fc = validParenthesis(n, ans + "(" , open+1, close) ;
    int sc = validParenthesis(n, ans + ")" , open, close+1) ;

    return fc + sc ;
}