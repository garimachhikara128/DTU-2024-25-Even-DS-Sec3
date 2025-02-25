#include<iostream>

using namespace std ;

class Queue
{
    int *arr ;
    int front ;
    int rear ;
    int size ;
    int cap ;

    public :

    Queue()
    {
        cap = 5 ;
        arr = new int[cap] ;
        front = -1 ;
        rear = -1 ;
        size = 0 ;
    }

    Queue(int capacity)
    {
        cap = capacity ;
        arr = new int[cap] ;
        front = -1 ;
        rear = -1 ;
        size = 0 ;
    }

    void push(int item)
    {
        if(isFull())
        {
            cout << "Queue is Full." << endl ;
            return ;
        }

        if(isEmpty())
        {
            front = 0 ;
            rear = 0 ;
        }
        else
            rear = (rear + 1) % cap ;

        arr[rear] = item ;
        size ++ ;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty." << endl ;
            return ;
        }

        arr[front] = 0;
        front = (front + 1) % cap ;
        size -- ;
    }

    int get_front()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty." << endl ;
            return INT_MIN;
        }

        return arr[front] ;
    }

    int get_back()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty." << endl ;
            return INT_MIN;
        }

        return arr[rear] ;
    }

    bool isEmpty()
    {
        return size == 0 ;
    }

    bool isFull()
    {
        return size == cap;
    }

    void display()
    {
        for(int i = 0 ; i < size ; i++)
        {
            int idx = (i + front) % cap ;
            cout << arr[idx] << " " ; 
        }
        cout << endl ;
    }

} ;

int main()
{
    Queue q ;

    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    q.display() ;
    q.pop() ;
    q.pop() ;
    q.pop() ;
    q.pop() ;
    q.display() ;
    q.push(60) ;
    q.push(70) ;
    q.push(80) ;
    q.push(90) ;
    q.display() ;

    return 0 ;
}