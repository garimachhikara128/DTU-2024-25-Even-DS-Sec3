#include<iostream>
#include<stack>

using namespace std ;

void reverse_display(stack<int> &st)
{
    if(st.empty())
        return ;

    int temp = st.top() ;
    st.pop() ;

    reverse_display(st) ;

    cout << temp << " " ;
    st.push(temp) ;
}

int main()
{
    stack<int> st ;
    st.push(10) ;
    st.push(20) ;
    st.push(30) ;
    st.push(40) ;
    st.push(50) ;
    
    reverse_display(st) ;
    cout << endl ;
    
    cout << st.top() << endl ;


    return 0 ;
}