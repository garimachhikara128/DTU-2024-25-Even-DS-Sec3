#include<iostream>

using namespace std ;

class Stack
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
        return head == NULL ;
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

    int top()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty" ;
            return INT_MIN ;
        }

        return head->data ;
    }

    void push(int item)
    {
        Node *nn = new Node(item) ;

        // 1. new node create
        if(isEmpty())
        {
            head = nn ;
        }
        else
        {
            // 2. linking
            nn->next = head ;

            // 3. update head
            head = nn ;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty." << endl ;
            return ;
        }

        // if ll has only one node, then your head will also get updated to NULL
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
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
    Stack s ;
    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.push(40) ;
    s.display() ;
    cout << s.top() << endl ;
    s.pop() ;
    cout << s.top() << endl ;
    s.display() ;
    return 0 ;
}