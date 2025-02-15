#include<iostream>
#include<stack>

using namespace std ;

int evaluate(string str)
{
    stack<int> st ;

    for(int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i] ;

        if(ch >= '0' && ch <= '9') // operand
            st.push(ch-'0') ;
        else // operator
        {
            int t1 = st.top() ;
            st.pop() ;
            int t2 = st.top() ;
            st.pop() ;

            if(ch == '+')
                st.push(t2+t1) ;
            else if(ch == '-')
                st.push(t2-t1) ;
            else if(ch == '*')
                st.push(t2*t1) ;
            else if(ch == '/')
                st.push(t2/t1) ;
        }
    }

    return st.top() ;
}

int main()
{
    string str = "231*+9-" ;

    cout << evaluate(str) << endl ;
    
    return 0 ;
}
