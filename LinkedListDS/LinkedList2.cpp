#include<iostream>

using namespace std ;

class LinkedList
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

    int getFirst()
    {
        if(isEmpty())
        {
            cout << "LL is Empty" ;
            return INT_MIN ;
        }

        return head->data ;
    }

    int getLast()
    {
        if(isEmpty())
        {
            cout << "LL is Empty" ;
            return INT_MIN ;
        }

        return tail->data ;        
    }

    int getAt(int idx)
    {

        Node *temp = head ;
        for(int i = 1 ; i <= idx && temp != NULL ; i++) // run loop idx no of times
        {
            temp = temp->next ;
        }

        if(temp == NULL)
            return INT_MIN ;
        else 
            return temp->data ;
    }

    int getAt2(int idx)
    {
        if(idx >= size())
        {
            cout << idx << " index doesnot exist" << endl;
            return INT_MIN ;
        }

        Node *temp = head ;
        for(int i = 1 ; i <= idx; i++) // run loop idx no of times
        {
            temp = temp->next ;
        }
        return temp->data ;
    }

    void addLast(int item)
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

    void addFirst(int item)
    {
        Node *nn = new Node(item) ;

        // 1. new node create
        if(isEmpty())
        {
            head = nn ;
            tail = nn ;
        }
        else
        {
            // 2. linking
            nn->next = head ;

            // 3. update head
            head = nn ;
        }
    }

    void addAt(int item, int idx)
    {
        if(idx > size())
        {
            cout << "Invalid Index." << endl ;
            return ;
        }

        if(idx == 0)
            addFirst(item) ;
        else if(idx == size())
            addLast(item) ;
        else
        {
            // 1. create a new node
            Node *nn = new Node(item) ;

            // 2. idx-1 number of times move temp
            Node *temp = head ;
            for(int i = 1 ; i <= idx-1 ; i++)
                temp = temp->next ;
            
            // 3. linking
            nn->next = temp->next ;
            temp->next = nn ;

        }
    }

    void removeLast()
    {
        if(isEmpty())
        {
            cout << "LL is Empty." << endl ;
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
            // 1. reach till last 2nd node
            Node *temp = head ;
            while(temp->next->next != NULL)
                temp = temp->next ;
            
            // 2. store last node
            Node *lastNode = temp->next ;

            // 3. linking
            temp->next = NULL ;

            // 4. free memory
            delete lastNode ;

            // 5. tail update
            tail = temp ;
        }
    }

    void removeFirst()
    {
        if(isEmpty())
        {
            cout << "LL is Empty." << endl ;
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

    void removeAt(int idx)
    {
        if(isEmpty())
        {
            cout << "LL is Empty." << endl ;
            return ;
        }

        if(idx >= size())
        {
            cout << "Invalid Index." << endl ;
            return ;
        }

        if(idx == 0)
            removeFirst() ;
        else if(idx == size()-1)
            removeLast() ;
        else
        {
            // 1. reach to the node which is before the node to be deleted
            Node *temp = head ;
            for(int i = 1 ; i <= idx-1 ; i++)
                temp = temp->next ;

            // 2. get the access of the node to be deleted
            Node *temp1 = temp->next ;

            // 3. links set
            temp->next = temp1->next ;

            // 4. free memory
            delete temp1 ;
        }

    }

    void reverse()
    {
        Node *prev = NULL ;
        Node *curr = head ;

        while(curr != NULL)
        {
            Node *ahead = curr->next ;
            curr->next = prev ;

            prev = curr ;
            curr = ahead ;
        }

        head = prev ;
    }

    int mid()
    {
        Node *slow = head ;
        Node *fast = head ;

        // while(fast != NULL && fast->next != NULL)
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ;
        }

        return slow->data ;
    }

    int kthFromLast(int k)
    {
        Node *you = head ;
        Node *fr = head ;

        for(int i=1 ; i <= k ; i++)
            fr = fr->next ;

        while(fr != NULL)
        {
            you = you->next ;
            fr = fr->next ;
        }

        return you->data ;
    }
} ;

int main()
{
    LinkedList ll ;
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.display() ;
    ll.addFirst(60) ;
    ll.display() ;
    ll.addFirst(70) ;
    ll.display() ;
    // ll.removeLast() ;
    ll.display() ;
    // ll.removeFirst() ;
    ll.display() ;
    ll.removeAt(10) ;
    ll.display() ;
    ll.addFirst(80) ;
    ll.display() ;
    // ll.removeAt(0) ;
    ll.display() ;
    ll.addAt(90,2) ;
    ll.display() ;
    // cout << ll.getFirst() << endl ;
    // cout << ll.getLast()  << endl ;
    // cout << ll.getAt2(12)  << endl;
    // cout << ll.getAt2(2)  << endl;
    
    ll.reverse() ;
    ll.display() ;

    cout << ll.mid() << endl ;
    cout << ll.kthFromLast(3) << endl ;
    return 0 ;
}