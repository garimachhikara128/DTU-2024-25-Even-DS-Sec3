#include<iostream>
#include<stack>

using namespace std ;

void fun(stack<int> st2)
{
    st2.push(40) ;
    cout << st2.top() << endl ; // 40
}

void fun1(stack<int> &st2)
{
    st2.push(40) ;
    cout << st2.top() << endl ; // 40
}

int main()
{
    stack<int> st ;
    st.push(10) ;
    st.push(20) ;
    cout << st.top() << endl ; // 20

    stack<int> st1 ;
    st1 = st ;
    st1.push(30) ;

    cout << st.top() << endl ; // 20
    cout << st1.top() << endl ; // 30

    fun1(st1) ;

    cout << st1.top() << endl ; // 40

    return 0 ;
}