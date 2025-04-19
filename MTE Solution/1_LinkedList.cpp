#include<iostream>

using namespace std ;

class LinkedList
{
        class Node
        {
                public :
                float data ;
                Node *next ;   

                Node(float data)
                {
                    this->data = data ;
                    this->next = NULL ;
                }
        } ;

        Node *head = NULL;
        float sum = 0 ;
        int N = 0 ;

        public :

        void Display()
        {
                Node *temp = head ;
                while(temp != NULL)
                {
                    cout << temp->data << " " ;
                    temp = temp->next ;
                }
                cout << endl ;
        }

        void Insert(float item)
        {
                // create a new node
                Node *nn = new Node(item) ;

                // linked list is empty || new node to be inserted at beginning
                if(head == NULL || head->data > item)
                {
                        nn->next = head ;
                        head = nn ;
                }
                else
                {
                        // find the correct position for insertion
                        Node *temp = head ;
                        while(temp->next != NULL && temp->next->data < item) 
                            temp = temp->next ;
                        
                        // linking
                        nn->next = temp->next ;
                        temp->next = nn ;
                }

                // sum update
                sum += item ;
                N ++ ;
            
        }

        void Delete(float item)
        {
                // linked list is empty || new node to be inserted at beginning
                if(head == NULL || head->data == item)
                {
                        Node *temp1 = head ; // get the access of the node to be deleted   
                        head = head->next ; // links set
                        delete temp1 ; // free memory
                        sum -= item ; // sum update
                        N-- ;
                        return ;
                }

                Node *temp = head ;
                while(temp->next != NULL)
                {
                        if(temp->next->data == item)
                        {
                            // get the access of the node to be deleted
                            Node *temp1 = temp->next ;

                            // links set
                            temp->next = temp1->next ;

                            // free memory
                            delete temp1 ;

                            // sum update
                            sum -= item ;
                            N-- ;

                            break ;
                        }
                        temp = temp->next ;
                }

        }

        float getSum()
        {
                return sum ;
        }

        float getAvg()
        {
                return sum / N ;
        }
} ;

int main()
{
        LinkedList ll ;

        ll.Insert(10.1) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(5) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(30.5) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(35) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(50) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(7.2) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Insert(3.4) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Delete(5) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Delete(30.5) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Delete(50) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;
        ll.Delete(3) ;
        ll.Display() ;
        cout << ll.getSum() << " " << ll.getAvg() << endl ;

        return 0 ;
}