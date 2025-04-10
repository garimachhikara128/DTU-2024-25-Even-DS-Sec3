#include<iostream>
#include<queue>

using namespace std ;

class MinHeap
{
    vector<int> data ;

    public :

    void add(int item)
    {
        data.push_back(item) ;
        upheapify(data.size()-1) ;
    }

    void upheapify(int ci)
    {
        int pi = (ci-1)/2 ;

        if(data[ci] < data[pi])
        {
            swap(data[pi], data[ci]) ;
            upheapify(pi) ;
        }
    }

    void remove()
    {
        swap(data[0], data[data.size()-1]) ;
        data.pop_back() ;
        downheapify(0) ;
    }

    void downheapify(int pi)
    {
        int lci = 2*pi+1 ;
        int rci = 2*pi+2 ;

        int mini = pi ;

        if(lci < data.size() && data[lci] < data[mini])
            mini = lci ;
        
        if(rci < data.size() && data[rci] < data[mini])
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
        for(int i = 0 ; i < data.size() ; i++)
        {
            cout << data[i] << " " ;
        }
        cout << endl ;
    }

} ;

int main()
{
    // MinHeap h ;

    // h.add(100) ;
    // h.display() ;
    // h.add(20) ;
    // h.display() ;
    // h.add(300) ;
    // h.display() ;
    // h.add(50) ;
    // h.display() ;
    // h.add(10) ;
    // h.display() ;
    // h.add(7) ;
    // h.display() ;
    // h.remove() ;
    // h.display() ;
    // h.remove() ;
    // h.display() ;

    int arr[] = {100,5,15,7,40,30,80,50,205,9} ;
    int N = sizeof(arr)/ sizeof(int) ;
    int k = 3 ;

    MinHeap heap ;

    for(int i = 0 ; i <k ; i++)
        heap.add(arr[i]) ;

    for(int i = k ; i < N ; i++)
    {
        int curr = arr[i] ;
        int weaker = heap.get() ;

        if(curr > weaker)
        {
            heap.remove() ;
            heap.add(curr) ;
        }
    }

    for(int i = 0 ; i < k ; i++)
    {
        cout << heap.get() << " ";
        heap.remove() ;
    }

    cout << endl ;

    return 0 ;
}