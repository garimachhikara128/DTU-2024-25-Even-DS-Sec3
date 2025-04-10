#include<iostream>
#include<queue>

using namespace std ;

void downheapify(int *arr, int N, int pi)
{
    int lci = 2*pi+1 ;
    int rci = 2*pi+2 ;

    int mini = pi ;

    if(lci < N && arr[lci] < arr[mini])
        mini = lci ;
    
    if(rci < N && arr[rci] < arr[mini])
        mini = rci ;

    if(pi != mini)
    {
        swap(arr[pi], arr[mini]) ;
        downheapify(arr, N, mini) ;
    }
}

void heapSort(int *arr, int N)
{
    // make a heap from arr array using strategy 2 (s2 : where all elements are given to you at once)
    for(int i = N/2-1 ; i >=0 ; i--)
        downheapify(arr, N, i) ;

    // sort
    for(int i = N-1 ; i >= 1 ; i--)
    {
        swap(arr[0], arr[i]) ;
        downheapify(arr, i, 0) ;
    }
}

void display(int *arr, int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int main()
{
    int arr[] = {10,100,50,5,7,20,60} ;
    int N = sizeof(arr)/ sizeof(int) ;
    
    heapSort(arr, N) ;
    display(arr, N) ;

    return 0 ; 
}
