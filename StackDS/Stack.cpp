#include<iostream>

using namespace std ;

class Stack
{
    int *arr ;
    int tos ;
    int N ;

    public :

    Stack()
    {
        int cap = 20 ;
        arr = new int[cap] ;
        tos = -1 ;
        N = cap ;
    }

    Stack(int cap)
    {
        arr = new int[cap] ;
        tos = -1 ;
        N = cap ;
    }

    void push(int item)
    {
        if(isFull())
        {
            cout << "Stack is Full." << endl ;
            return ;
        }

        tos ++ ;
        arr[tos] = item ;
    }

    int top()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty." << endl ;
            return INT_MIN;
        }

        return arr[tos] ;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty." << endl ;
            return ;
        }

        arr[tos] = 0 ;
        tos -- ;
    }

    bool isEmpty()
    {
        return tos == -1 ;
    }

    bool isFull()
    {
        return tos == N-1 ;
    }

    int size()
    {
        return tos + 1 ;
    }

    void display()
    {
        for(int i = tos ; i >=0 ; i--)
            cout << arr[i] << " " ;
        cout << endl ;
    }
} ;

int main()
{
    Stack s(5) ;

    s.push(10) ;
    s.display() ;
    s.push(20) ;
    s.display() ;
        s.push(30) ;
    s.display() ;
        s.push(40) ;
    s.display() ;
        s.push(50) ;
    s.display() ;

    s.push(60) ;
    s.pop() ;
    s.display() ;
        s.pop() ;
    s.display() ;
        s.pop() ;
    s.display() ;
        s.pop() ;
    s.display() ;
        s.pop() ;
    s.display() ;

    s.pop() ;

    return 0 ;
}