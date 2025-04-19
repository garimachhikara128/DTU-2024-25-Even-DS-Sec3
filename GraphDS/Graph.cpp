#include<iostream>
#include<queue>

using namespace std ;

class Graph
{
    int **matrix ;
    int V ;

    public :

    Graph(int V)
    {
        this->V = V ;

        matrix = new int*[V] ;
        for(int i = 0 ; i < V ; i++)
        {
            matrix[i] = new int[V] ;
            for(int j = 0 ; j < V ; j++)
                matrix[i][j] = 0;
        }
    }

    void addEdge(int u, int v, int cost)
    {
        matrix[u][v] = cost ;
        matrix[v][u] = cost ;
    }

    void display()
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << i << " -> " ;
            for(int j = 0 ; j < V ; j++)
            {
                if(matrix[i][j] != 0)
                {
                    cout << j << " " ;
                }
            }
            cout << endl ;
        }
    }

    bool BFS(int src, int dst)
    {
        queue<int> q ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> src node q ds insert
        q.push(src) ;

        while(!q.empty())
        {
            // remove
            int rv = q.front() ;
            q.pop() ;

            // if removed node is already visited then ignore it
            if(visited[rv])
                continue ;

            // visited
            visited[rv] = true ;

            // check dst ?
            if(rv == dst)
                return true ;

            // unvisted nbrs work
            for(int j = 0 ; j < V ; j++)
            {
                if(matrix[rv][j] != 0 && !visited[j])
                {
                    q.push(j) ;
                }
            }
        }

        return false ;
    }

    bool DFS(int src, int dst)
    {
        stack<int> s ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> src node stack ds insert
        s.push(src) ;

        while(!s.empty())
        {
            // remove
            int rv = s.top() ;
            s.pop() ;

            // if removed node is already visited then ignore it
            if(visited[rv])
                continue ;

            // visited
            visited[rv] = true ;

            // check dst ?
            if(rv == dst)
                return true ;

            // unvisted nbrs work
            for(int j = 0 ; j < V ; j++)
            {
                if(matrix[rv][j] != 0 && !visited[j])
                {
                    s.push(j) ;
                }
            }
        }

        return false ;
    }

    void BFT()
    {
        queue<int> q ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> 0 node q ds insert
        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            q.push(src) ;

            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                // if removed node is already visited then ignore it
                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // printing
                cout << rv << " " ;

                // unvisted nbrs work
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }
            }
        }
        cout << endl ;
    }

    void DFT()
    {
        stack<int> s ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> 0 node stack ds insert
        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            s.push(src) ;

            while(!s.empty())
            {
                // remove
                int rv = s.top() ;
                s.pop() ;

                // if removed node is already visited then ignore it
                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // printing
                cout << rv << " " ;

                // unvisted nbrs work
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        s.push(j) ;
                    }
                }
            }
        }
        cout << endl ;
    }

    bool isConnected()
    {
        int num_components = 0 ;
        queue<int> q ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> 0 node q ds insert
        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            q.push(src) ;
            num_components ++ ;

            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                // if removed node is already visited then ignore it
                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // unvisted nbrs work
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }
            }
        }
        
        return num_components == 1 ;
    }

    bool isCyclic()
    {
        queue<int> q ;
        
        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> 0 node q ds insert
        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            q.push(src) ;

            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                // if removed node is already visited then cycle is present
                if(visited[rv])
                    return true ;

                // visited
                visited[rv] = true ;

                // unvisted nbrs work
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }
            }
        }

        return false ;
    }

    bool isTree()
    {
        return isConnected() && !isCyclic() ;
    }

    vector<vector<int> > getConnectedComponents()
    {
        vector<vector<int> > bv ;

        queue<int> q ;

        // visited array
        bool *visited = new bool[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;

        // work start -> 0 node q ds insert
        for(int src=0 ; src < V ; src++)
        {
            if(visited[src])
                continue ;

            vector<int> sv ;
            q.push(src) ;

            while(!q.empty())
            {
                // remove
                int rv = q.front() ;
                q.pop() ;

                // if removed node is already visited then ignore it
                if(visited[rv])
                    continue ;

                // visited
                visited[rv] = true ;

                // printing
                sv.push_back(rv) ;

                // unvisted nbrs work
                for(int j = 0 ; j < V ; j++)
                {
                    if(matrix[rv][j] != 0 && !visited[j])
                    {
                        q.push(j) ;
                    }
                }
            }

            bv.push_back(sv) ;
        }
        
        return bv ;
    }

    
} ;

int main()
{

    Graph g(10) ;

    g.addEdge(0,1,2) ;
    g.addEdge(0,3,3) ;
    g.addEdge(1,2,4) ;
    g.addEdge(2,3,5) ;
    g.addEdge(3,4,6) ;
    g.addEdge(4,5,1) ;
    g.addEdge(5,6,10) ;
    g.addEdge(4,6,58) ;

    g.addEdge(7,8,1) ;
    g.addEdge(8,9,2) ;
    g.addEdge(7,9,3) ;

    g.display() ;

    cout << g.DFS(0,9) << endl ;

    g.BFT() ;
    g.DFT() ;

    cout << g.isTree() << endl ;

    vector<vector<int> > res = g.getConnectedComponents() ;

    for(int i = 0 ; i < res.size() ; i++)
    {
        vector<int> sv = res[i] ;
        for(int j =0 ; j < sv.size() ; j++)
        {
            cout << sv[j] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}