#include<iostream>
#include<stack>

using namespace std ;

int main()
{
    int arr[] = {50,30,20,40,10,45,5,60,8,15} ;
    int N = sizeof(arr) / sizeof(int) ;
    int ans[N] ;

    stack<int> st ;

    for(int i = 0 ; i < N ; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i] ;
            st.pop() ;
        }

        st.push(i) ;
    }

    while(!st.empty())
    {
        ans[st.top()] = -1 ;
        st.pop() ;
    }

    for(int i = 0 ; i < N ; i++)
        cout << ans[i] << " " ;
    cout << endl ;
    
    return 0 ;
}