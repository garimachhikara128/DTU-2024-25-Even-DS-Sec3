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

    private :
    bool DFS(int src, int dst, bool *visited)
    {
        // visited mark
        visited[src] = true ;

        // dst ?
        if(src == dst)
            return true ;

        // unvisited nbrs
        for(int j = 0 ; j < V ; j++)
        {
            if(matrix[src][j] != 0 && !visited[j])
            {
                if(DFS(j, dst, visited) == true)
                    return true ;
            }
        }

        return false ;   

    }   

    bool DFS(int src, int dst)
    {
        bool visited[V] ;
        for(int i = 0 ; i < V ; i++)
            visited[i] = false ;
        
        return DFS(src, dst, visited) ;
    }

    public :

    vector<vector<int> > getSCC()
    {
        vector<vector<int> > bv ;

        bool part_scc[V] ;
        for(int i = 0 ; i < V ; i++)
            part_scc[i] = false ;

        for(int src = 0 ; src < V ; src++)
        {
            if(part_scc[src])
                continue ;

            vector<int> sv ;
            sv.push_back(src) ;

            for(int j = src+1 ; j < V ; j++)
            {
                if(DFS(src,j) && DFS(j,src) && !part_scc[j])
                {
                    part_scc[j] = true ;
                    sv.push_back(j) ;
                }
            }

            bv.push_back(sv) ;
        }

        return bv ;
    }
} ;

int main()
{
    Graph g(7) ;

    g.addEdge(0,1,2) ;
    g.addEdge(1,2,3) ;
    g.addEdge(2,3,4) ;
    g.addEdge(3,0,5) ;
    g.addEdge(1,3,6) ;
    g.addEdge(3,4,1) ;
    g.addEdge(2,5,10) ;
    g.addEdge(4,5,58) ;
    g.addEdge(5,6,1) ;
    g.addEdge(6,4,2) ;

    vector<vector<int> > res = g.getSCC() ;

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

