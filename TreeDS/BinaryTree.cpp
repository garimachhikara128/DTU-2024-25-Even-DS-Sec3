#include<iostream>
#include<queue>

using namespace std ;

class BinaryTree
{
    class Node
    {
        public :
        int data ;
        Node *left ;  
        Node *right ;

        Node(int data)
        {
            this->data = data ;
            this->left = NULL ;
            this->right = NULL ;
        }
    } ;

    Node *root = NULL ;

    public :
    BinaryTree()
    {
        root = construct(NULL, true) ;
    }

    private :
    Node* construct(Node *parent, bool ilc)
    {
        if(parent == NULL)
            cout << "Enter the data for root node ?" << endl ;
        else
        {
            if(ilc)
                cout << "Enter the data for left child of " << parent->data << "?" << endl ;
            else
                cout << "Enter the data for right child of " << parent->data << "?" << endl ;
        }

        int item ;
        cin >> item ;
        Node *nn = new Node(item) ;

        cout << nn->data << " has left child ?" << endl;
        bool hlc ;
        cin >> hlc ;
        if(hlc)
            nn->left = construct(nn, true) ;

        cout << nn->data << " has right child ?" << endl;
        bool hrc ;
        cin >> hrc ;
        if(hrc)
            nn->right = construct(nn, false) ;
        
        
        return nn ;
    }

    public :
    void display()
    {
        display(root) ;
    }

    private :
    void display(Node *node)
    {
        if(node == NULL)
            return ;

        if(node->left == NULL)
            cout << "." ;
        else
            cout << node->left->data ;

        cout << " -> " << node->data << " <- " ;

        if(node->right == NULL)
            cout << "." ;
        else
            cout << node->right->data ;

        cout << endl ;

        display(node->left) ;
        display(node->right) ;
        
    }

    public :
    int size()
    {
        return size(root) ;
    }

    private:
    int size(Node *node)
    {
        if(node == NULL)
            return 0;

        int ls = size(node->left) ;
        int rs = size(node->right) ;

        return ls + rs + 1 ;
    }

    public :
    int maximum()
    {
        return maximum(root) ;
    }

    private:
    int maximum(Node *node)
    {
        if(node == NULL)
            return INT_MIN;
            
        int lm = maximum(node->left) ;
        int rm = maximum(node->right) ;

        return max(node->data, max(lm,rm)) ;
    }

    public :
    int height()
    {
        return height(root) ;
    }

    private:
    int height(Node *node)
    {
        if(node == NULL)
            return -1;
            
        int lh = height(node->left) ;
        int rh = height(node->right) ;

        return max(lh,rh) + 1 ;
    }

    public :
    bool find(int item)
    {
        return find(root, item) ;
    }

    private:
    bool find(Node *node, int item)
    {
        if(node == NULL)
            return false;
        
        if(node->data == item)
            return true ;

        bool lf = find(node->left, item) ;
        bool rf = find(node->right, item) ;

        return lf || rf ;
    }

    public :
    void display2()
    {
        display2(root) ;
    }

    private :
    void display2(Node *node)
    {
        if(node == NULL)
            return ;

        cout << "Hii" << node->data << endl ;

        display2(node->right) ;
        cout << "Coming back from right child of " << node->data << " and going towards left child" << endl ;
        display2(node->left) ;

        cout << "Bye" << node->data << endl ;

    }

    public :
    void preorder()
    {
        preorder(root) ;
    }

    private :
    void preorder(Node *node)
    {
        if(node == NULL)
            return ;

        cout << node->data << " " ;
        preorder(node->left) ;
        preorder(node->right) ;
    }

    public :
    void inorder()
    {
        inorder(root) ;
    }

    private :
    void inorder(Node *node)
    {
        if(node == NULL)
            return ;

        inorder(node->left) ;
        cout << node->data << " " ;
        inorder(node->right) ;
    }

    public :
    void postorder()
    {
        postorder(root) ;
    }

    private :
    void postorder(Node *node)
    {
        if(node == NULL)
            return ;

        postorder(node->left) ;
        postorder(node->right) ;
        cout << node->data << " " ;
    }

    public:
    void levelorder()
    {
        queue<Node*> q ;
        q.push(root) ;

        while(!q.empty())
        {
            // 1. remove
            Node* rn = q.front() ;
            q.pop() ;

            // 2. print
            cout << rn->data << " " ;

            // 3. child push
            if(rn->left != NULL)
                q.push(rn->left) ;

            if(rn->right != NULL)
                q.push(rn->right) ;

            cout << endl ;
        }

        cout << endl ;

    }

    public:
    void levelorderlinewise()
    {
        queue<Node*> q ;
        q.push(root) ;
        q.push(NULL) ;

        while(!q.empty())
        {
            // 1. remove
            Node* rn = q.front() ;
            q.pop() ;

            if(rn == NULL)
            {
                if(q.empty())
                    break ;

                cout << "\n" ;
                q.push(NULL) ;
                continue ;
            }

            // 2. print
            cout << rn->data << " " ;

            // 3. child push
            if(rn->left != NULL)
                q.push(rn->left) ;

            if(rn->right != NULL)
                q.push(rn->right) ;  

        }

        cout << "\n" ;
    }

    int dia_ans = 0 ;

    public :
    int diameter()
    {
        diameter(root) ;
        return dia_ans ;
    }

    private :
    void diameter(Node *node)
    {
        if(node == NULL)
            return ;
        
        int self_diameter_root = height(node->left) + height(node->right) + 2 ;
        dia_ans = max(dia_ans, self_diameter_root) ;

        diameter(node->left) ;
        diameter(node->right) ;
    }

} ;

int main()
{
    // 10 1 20 1 40 0 0 1 50 0 0 1 30 1 60 0 0 0 
    BinaryTree bt ;
    bt.display() ;
    
    cout << bt.size() << endl ;
    cout << bt.maximum() << endl ;
    cout << bt.height() << endl ;
    cout << bt.find(60) << endl ;

    bt.preorder() ;
    cout << endl ;

    bt.inorder() ;
    cout << endl ;

    bt.postorder() ;
    cout << endl ;

    bt.levelorderlinewise() ;
    // bt.display2() ;

    cout << bt.diameter() << endl ;
    return 0 ;
}
