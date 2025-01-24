#include<iostream>
#include<vector>

using namespace std ;
void intersection(int* arr1, int n1, int *arr2, int n2) ;

int main()
{
    int arr1[5] = {10,20,30,40,50} ;
    int arr2[5] = {20,30,50,60,70} ;

    intersection(arr1,5,arr2,5) ;

    return 0 ;
}

void intersection(int* arr1, int n1, int *arr2, int n2)
{

    int i = 0 , j=0  ;

    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
            i++ ;
        else if(arr1[i] > arr2[j])
            j++ ;
        else 
        {
            cout << arr1[i] << "\t" ;
            i++ ;
            j++ ;
        }
    }
}