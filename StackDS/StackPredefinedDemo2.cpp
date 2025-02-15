#include<iostream>
#include<stack>

using namespace std ;

void fun(stack<int> *st2)
{
    stack<int> st3 = *st2 ;

    st3.push(40) ;
    cout << st3.top() << endl ; // 40
}

int main()
{
    stack<int> *st = new stack<int>();
    st->push(10) ;
    st->push(20) ;
    cout << st->top() << endl ; // 20

    stack<int> *st1 ;
    st1 = st ;
    st1->push(30) ;

    cout << st->top() << endl ; // 30
    cout << st1->top() << endl ; // 30

    fun(st1) ;

    cout << st->top() << endl ; // 30
    cout << st1->top() << endl ; // 30

    return 0 ;
}