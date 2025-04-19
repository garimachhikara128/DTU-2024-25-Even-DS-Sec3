#include<iostream>

using namespace std ;

class Queue
{
        pair<int,bool> *arr ;
        int front ;
        int rear ;
        int size ;
        int cap ;

        public :

        Queue(int capacity)
        {
                cap = capacity ;
                arr = new pair<int,bool>[cap] ;
                front = -1 ;
                rear = -1 ;
                size = 0 ;
        }

        void push(int item)
        {
                push(item, true) ;
        }

        void push(int item, bool turn)
        {
                if(size == 0)
                {
                    front = 0 ;
                    rear = 0 ;
                }
                else
                    rear = (rear + 1) % cap ;

                arr[rear] = {item,turn} ;
                size ++ ;
        }

        void secondChanceDelete()
        {
                pair<int,bool> temp = arr[front] ;
                front = (front + 1) % cap ;

                if(temp.second == true)
                    push(temp.first, false) ;
                    
                size -- ;  
        }

        void display()
        {
                for(int i = 0 ; i < size ; i++)
                {
                    int idx = (i + front) % cap ;
                    cout << arr[idx].first << " " ; 
                }
                cout << endl ;
        }
} ;

int main()
{
        Queue q(10) ;

        q.push(10) ;
        q.push(20) ;
        q.push(30) ;
        q.push(40) ;
        q.push(50) ;
        q.display() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;
        q.display() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;
        q.display() ;
        q.secondChanceDelete() ;
        q.display() ;
        q.push(60) ;
        q.push(70) ;
        q.push(80) ;
        q.push(90) ;
        q.display() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;
        q.secondChanceDelete() ;  
        q.display() ;
        q.secondChanceDelete() ;
        q.display() ;
        return 0 ;
}