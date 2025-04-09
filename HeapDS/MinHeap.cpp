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
    MinHeap h ;

    h.add(100) ;
    h.display() ;
    h.add(20) ;
    h.display() ;
    h.add(300) ;
    h.display() ;
    h.add(50) ;
    h.display() ;
    h.add(10) ;
    h.display() ;
    h.add(7) ;



    return 0 ;
}