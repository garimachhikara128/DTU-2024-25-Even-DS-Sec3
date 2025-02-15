#include<iostream>
#include<stack>

using namespace std ;

void step2(stack<int> &org, stack<int> &extra)
{
    if(extra.empty())
        return ;

    int temp = extra.top() ;
    extra.pop() ;

    step2(org, extra) ;

    org.push(temp) ;
}

void actual_reverse(stack<int> &org, stack<int> &extra)
{
    if(org.empty())
    {
        step2(org, extra) ;
        return ;
    }

    extra.push(org.top()) ;
    org.pop() ;

    actual_reverse(org, extra) ;
}

void display(stack<int> &st)
{
    if(st.empty())
    {   
        cout << endl ;
        return ;
    }

    int temp = st.top() ;
    st.pop() ;
    cout << temp << " " ;

    display(st) ;

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
    
    stack<int> st1 ;

    actual_reverse(st, st1) ;
    
    display(st) ;

    return 0 ;
}
