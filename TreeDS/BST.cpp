#include<iostream>
#include<queue>

using namespace std ;

class BST
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
    void add(int item)
    {
        root = add(root, item) ;
    }

    private :
    Node* add(Node *node, int item)
    {
        if(node == NULL)
        {
            Node *nn = new Node(item) ;
            return nn ;
        }

        if(item < node->data)
        {
            node->left = add(node->left, item) ;
        }
        else
        {
            node->right = add(node->right, item) ;
        }

        return node ;
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
    int maximum()
    {
        return maximum(root) ;
    }

    private:
    int maximum(Node *node)
    {
        if(node == NULL)
            return INT_MIN ;

        if(node->right == NULL)
            return node->data;
        else 
            return maximum(node->right) ;
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

        if(node->data > item)
            return find(node->left, item) ;
        else if (node->data < item)
            return find(node->right, item) ;
        else
            return true ;

    }

    public :
    void printInRange(int ll, int ul)
    {
        printInRange(root, ll, ul) ;
    }

    private :
    void printInRange(Node *node, int ll, int ul)
    {
        if(node == NULL)
            return ;
    
        if(node->data >= ll && node->data <= ul)
        {
            printInRange(node->left, ll, ul) ;
            cout << node->data << " ";
            printInRange(node->right, ll, ul) ;
        }

        else if(node->data < ll)
            printInRange(node->right, ll, ul) ;

        else if(node->data > ul)
            printInRange(node->left, ll, ul) ;
    }

    public :
    void remove(int item)
    {
        if(root == NULL)
            return ;

        if(item == root->data)
        {
            if(root->left == NULL && root->right == NULL)
                root = NULL ;
            else if (root->left != NULL && root->right == NULL)
                root = root->left ;
            else if (root->left == NULL && root->right != NULL)
                root = root->right ;
            else
            {
                int left_max = maximum(root->left) ;
                remove(root->left, root, left_max) ;
                root->data = left_max ;
            }
        }
        else
            remove(root, NULL, item) ;
    }

    private :
    void remove(Node *node, Node* parent, int item)
    {
        if(item < node->data)
            remove(node->left, node, item) ;

        else if(item > node->data)
            remove(node->right, node, item) ;

        else
        {
            // case 1 : node->left and node->right doesnot exist
            if(node->left == NULL && node->right == NULL)
            {
                if(node->data < parent->data)
                    parent->left = NULL ;
                else
                    parent->right = NULL ;
            }

            // case 2 : node->left exists and node->right doesnot exist
            if(node->left != NULL && node->right == NULL)
            {
                if(node->data < parent->data)
                    parent->left = node->left ;
                else
                    parent->right =  node->left ;
            }

            // case 3 : node->left doesnot exists and node->right exists
            if(node->left == NULL && node->right != NULL)
            {
                if(node->data < parent->data)
                    parent->left = node->right ;
                else
                    parent->right =  node->right ;
            }        
            
            // case 4 : node->left exists and node->right exists
            if(node->left == NULL && node->right != NULL)
            {
                int left_max = maximum(node->left) ;
                remove(node->left, node, left_max) ;
                node->data = left_max ;
            }
        }
    }


} ;

int main()
{
    BST bst ;

    bst.add(50) ;
    bst.add(30) ;
    bst.add(70) ;
    bst.add(20) ;
    bst.add(40) ;
    bst.add(60) ;
    bst.add(80) ;
    bst.add(10) ;
    bst.add(25) ;
    bst.add(35) ;
    bst.add(45) ;
    bst.add(75) ;
    bst.add(95) ;
    bst.add(5) ;

    // bst.display() ;

    // bst.printInRange(25,75) ;
    bst.remove(60) ;

    bst.display() ;
    return  0; 
}