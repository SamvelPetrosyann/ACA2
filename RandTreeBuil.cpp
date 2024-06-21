#include <iostream>
#include <vector>
#include <queue>

class Node
{
public:
    std::vector<Node*> node_vec;
    int val;

    Node(int val) : val(val){}
    ~Node() {}
};

class Tree
{
    Node* root;
public: 
    Tree(Node* node) : root(node)
    {
        
    }
    
    ~Tree()
    {
        deleteTree(root);
    }
    
    void deleteTree(Node* node)
    {
        if (node == nullptr)
            return;
        
        for (Node* child : node->node_vec)
        {
            deleteTree(child);
            delete child;
        }
        
    }
    
    void buildtree(Node* node, int depth,const int numchilds)
    {
        if(depth <= 0)
        {
            return;
        }
        for(int i = 0; i < numchilds; ++i)
        {
            Node* child = new Node(rand() % 10);
            node->node_vec.push_back(child);
            buildtree(child,depth - 1, numchilds);
        }
    }
    
    void traverse() 
    {
        if (!root) 
        {
            return;
        }
        
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            std::cout << current->val << " ";

            for (Node* child : current->node_vec) 
            {
                q.push(child);
            }
        }
        std::cout << std::endl;
    }    
};

int main()
{
    Node* n = new Node(3);
    int depth = rand() % 5;
    Tree tree(n);
    tree.buildtree(n, depth, depth + 1);
    tree.traverse();
    return 0;
    
}