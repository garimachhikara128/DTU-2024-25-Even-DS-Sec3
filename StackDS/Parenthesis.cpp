#include<iostream>
#include<stack>

using namespace std ;

bool check_parenthesis(string str)
{
    stack<char> st ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch) ;
        }
        else
        {   
            if(st.empty()) // close > open
                return false ;

            else if(ch == ')' && st.top() == '(')
                st.pop() ;

            else if(ch == '}' && st.top() == '{')
                st.pop() ;

            else if(ch == ']' && st.top() == '[')
                st.pop() ;

            else // corresponding pair was not present
                return false ;
        }
    }

    return st.empty() ; // open > close

}

int main()
{
    string str = "[()(){}]" ;

    cout << (check_parenthesis(str) == 1 ? "true" : "false") << endl ;
}
