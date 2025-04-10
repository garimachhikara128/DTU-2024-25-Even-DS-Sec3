#include<iostream>
#include<queue>

using namespace std ;

class MinHeap
{
    int *data ;
    int N ;

    public :

    void add(int *arr, int N)
    {
        this->data = arr ;
        this->N = N ;

        // create a heap 
        for(int i = N/2-1 ; i >=0 ; i--)
            downheapify(i) ;
    }

    void remove()
    {
        swap(data[0], data[N-1]) ;
        N-- ;
        downheapify(0) ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < N && data[lci] < data[mini])
            mini = lci ;
        
        if(rci < N && data[rci] < data[mini])
            mini = rci ;

        if(pi != mini)
        {
            swap(data[pi], data[mini]) ;
            downheapify(mini) ;
        }
    }

    int get()
    {
        return data[0] ;
    }

    void display()
    {
        for(int i = 0 ; i < N ; i++)
        {
            cout << data[i] << " " ;
        }
        cout << endl ;
    }

} ;

int main()
{
    int arr[] = {10,100,50,5,7,20,60} ;
    int N = sizeof(arr)/ sizeof(int) ;

    MinHeap h ;
    h.add(arr, N) ;
    h.display() ;


    return 0 ;
}