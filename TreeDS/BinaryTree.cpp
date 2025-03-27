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

    // https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    // public:
    // BinaryTree(int *pre, int *in, int n)
    // {
    //     root = construct(pre, 0, n-1, in, 0, n-1) ;
    // }

    // private:
    // Node* construct(int *pre, int plo, int phi, int *in, int ilo, int ihi)
    // {
    //     if(plo > phi || ilo > ihi)
    //         return NULL ;

    //     Node *nn = new Node(pre[plo]) ;

    //     int si = -1 ;
    //     for(int i = ilo; i <= ihi ; i++)
    //     {
    //         if (in[i] == pre[plo])
    //         {
    //            si = i ;
    //            break ;
    //         }
    //     }

    //     int nel = si - ilo ;

    //     nn->left = construct(pre, plo+1, plo+nel, in, ilo, si-1) ;
    //     nn->right = construct(pre, plo+nel+1, phi, in, si+1, ihi) ;

    //     return nn ;

    // }

    public:
    BinaryTree(int *post, int *in, int n)
    {
        root = construct(post, 0, n-1, in, 0, n-1) ;
    }

    private:
    Node* construct(int *post, int plo, int phi, int *in, int ilo, int ihi)
    {
        if(plo > phi || ilo > ihi)
            return NULL ;

        Node *nn = new Node(post[phi]) ;

        int si = -1 ;
        for(int i = ilo; i <= ihi ; i++)
        {
            if (in[i] == post[phi])
            {
               si = i ;
               break ;
            }
        }

        int nel = si - ilo ;

        nn->left = construct(post, plo, plo+nel-1, in, ilo, si-1) ;
        nn->right = construct(post, plo+nel, phi-1, in, si+1, ihi) ;

        return nn ;

    }

    public:
    BinaryTree(int *level, int n)
    {
        construct(level, n) ;
    }

    private:
    void construct(int* level, int n)
    {
        queue<Node*> q ;
        root = new Node(level[0]) ;
        q.push(root) ;

        int i = 1;
        while(!q.empty())
        {
            // remove
            Node *rn = q.front() ;
            q.pop() ;

            // left child
            if(level[i] != -1)
            {
                Node *leftnode = new Node(level[i]) ;
                rn->left = leftnode ;
                q.push(leftnode) ;
            }
            i++ ;

            // right child
            if(level[i] != -1)
            {
                Node *rightnode = new Node(level[i]) ;
                rn->right = rightnode ;
                q.push(rightnode) ;
            }        
            i++ ;
        }

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

    // https://www.geeksforgeeks.org/problems/size-of-binary-tree/0
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

    // https://www.geeksforgeeks.org/problems/size-of-binary-tree/0
    public :
    int sum()
    {
        return sum(root) ;
    }

    private:
    int sum(Node *node)
    {
        if(node == NULL)
            return 0;

        int ls = sum(node->left) ;
        int rs = sum(node->right) ;

        return ls + rs + node->data ;
    }

    // https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/
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

    // https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
    // https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

    // https://www.geeksforgeeks.org/search-a-node-in-binary-tree/
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

    // https://leetcode.com/problems/binary-tree-preorder-traversal/
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

    // https://leetcode.com/problems/binary-tree-inorder-traversal/
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

    // https://leetcode.com/problems/binary-tree-postorder-traversal/
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

    // https://leetcode.com/problems/binary-tree-level-order-traversal/
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

    // https://leetcode.com/problems/diameter-of-binary-tree/
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

    public :
    int diameter2()
    {
        return diameter2(root) ;
    }

    private :
    int diameter2(Node *node)
    {
        if(node == NULL)
            return 0 ;

        int ld = diameter2(node->left) ;
        int rd = diameter2(node->right) ;       
        int self_diameter_root = height(node->left) + height(node->right) + 2 ;
        
        return max(self_diameter_root, max(ld,rd)) ;
    }

    // https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
    int subtree_sum_ans = 0 ;

    public :
    int maxSubtreeSum()
    {
        maxSubtreeSum(root) ;
        return subtree_sum_ans ;
    }

    private :
    void maxSubtreeSum(Node *node)
    {
        if(node == NULL)
            return ;
        
        subtree_sum_ans = max(subtree_sum_ans, sum(node)) ;

        maxSubtreeSum(node->left) ;
        maxSubtreeSum(node->right) ;
    }

    public :
    int maxSubtreeSum2()
    {
        return maxSubtreeSum2(root) ;
    }

    private :
    int maxSubtreeSum2(Node *node)
    {
        if(node == NULL)
            return 0 ;
        
        int lmss = maxSubtreeSum2(node->left) ;
        int rmss = maxSubtreeSum2(node->right) ;
        int smss = sum(node) ;

        return max(smss, max(lmss, rmss)) ;
    }

    // https://leetcode.com/problems/same-tree/
    bool isSameTree(Node* p, Node* q) {
        
        if(p == NULL && q == NULL)
            return true ;
        
        if(p == NULL || q == NULL)
            return false ;

        bool li = isSameTree(p->left, q->left) ;
        bool ri = isSameTree(p->right, q->right) ;

        return (p->data == q->data) && li && ri ;
    }

    // https://leetcode.com/problems/balanced-binary-tree/
    bool is_bal_ans = true ;
    
    public :
    int isBalanced()
    {
        isBalanced(root) ;
        return is_bal_ans ;
    }

    private :
    void isBalanced(Node *node)
    {
        if(node == NULL)
            return ;
        
        int bf = height(node->left) - height(node->right) ;

        if(!(bf == -1 || bf == 0 || bf == 1))
            is_bal_ans = false ;

        isBalanced(node->left) ;
        isBalanced(node->right) ;
    }
    
} ;

int main()
{
    // 10 1 -20 1 -40 0 0 1 50 0 0 1 -30 1 -60 0 0 0 
    // int pre[] = {10,20,40,50,90,30,60,70,80} ;
    // int in[] = {40,20,90,50,10,30,70,60,80} ;
    // int post[] = {40,80,50,20,60,100,90,70,30,10} ;
    // int in[] =   {40,20,50,80,10,60,30,90,100,70} ;
    // BinaryTree bt(post,in,10) ;
    int level[] = {10,20,30,40,-1,-1,50,-1,-1,60,70,-1,-1,-1,-1} ;
    BinaryTree bt(level, 15) ;
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
    cout << bt.diameter2() << endl ;

    cout << bt.maxSubtreeSum() << endl ;
    cout << bt.maxSubtreeSum2() << endl ;

    return 0 ;
}
