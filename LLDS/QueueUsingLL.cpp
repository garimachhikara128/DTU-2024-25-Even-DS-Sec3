#include<iostream>

using namespace std ;

class Queue
{
    class Node
    {
        public :
        int data ;
        Node *next ;   

        Node(int data)
        {
            this->data = data ;
            this->next = NULL ;
        }
    } ;

    Node *head = NULL;
    Node *tail = NULL;

    public :

    void display()
    {
        Node *temp = head ;
        while(temp != NULL)
        {
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        cout << endl ;
    }

    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    int size()
    {
        int len = 0 ;
        Node *temp = head ;
        while(temp->next != NULL)
        {
            len ++ ;
            temp = temp->next ;
        }

        return len ; 
    }

    int get_front()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" ;
            return INT_MIN ;
        }

        return head->data ;
    }

    int get_back()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" ;
            return INT_MIN ;
        }

        return tail->data ;        
    }

    void push(int item)
    {
        // 1. new node create
        Node *nn = new Node(item) ;

        if(isEmpty()) // border case: ll is empty
        {
            head = nn ;
            tail = nn ;
        }
        else
        {
            tail->next = nn ;
            tail = nn ;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty." << endl ;
            return ;
        }

        // if ll has only one node, then your head will also get updated to NULL
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
            tail = NULL ;
        }
        else
        {
            Node *newHead = head->next ;
            delete head ;
            head = newHead ;
        }
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
    cout << q.get_back() << endl ;
    cout << q.get_front() << endl ;

    return 0 ;
}