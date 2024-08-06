#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <queue>

class Tree {
private:
    class Node{
    public:
        int value;
        Node *left = NULL, *right = NULL, *parent;
    
        Node(int value, Node* parent){
            this->value = value;
            this->parent = parent;
        }
        
        bool isLeftChild(){
            if(this->parent->left == this)
                return true;
            return false;
        }

        std::string draw(std::string spacing){
            std::string s = "";
            if(this->right !=  NULL)
                s += this -> right -> draw(spacing + "      ");
                
            s += spacing + std::to_string(this->value);
            
            if(this->left !=  NULL || this->right !=  NULL )
                s += " --{";
            
            s += "\n";

            if(this->left !=  NULL)
                s += this -> left -> draw( spacing + "      ");
                
            return s;
        }

        ~Node() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
    Node *root;
    int height(Node * node);
public:
    unsigned long long cmp = 0;
    unsigned long long swp = 0;
    
    
    Node* minimum(Node* node){
        while (node->left != NULL) {
        node = node->left;
        swp++;
        }
        return node;
    }
    void Transplant(Node* u, Node* v);
    
    
    void insert(int val);
    void remove(int val);
    bool search(int val);
    std::string draw();
    ~Tree(){ if(root) delete this -> root; }
    int height(){
        std::queue<Node*> nodesInLevel;
        int height = 0;
        int nodeCount = 0;
        Node* currentNode;
        
        if (root == NULL) 
            return 0;
        
        nodesInLevel.push(root);
        while (!nodesInLevel.empty()) {
            height++;
    
            nodeCount = nodesInLevel.size();
            while (nodeCount--) {
                currentNode = nodesInLevel.front();
    
                if (currentNode->left != NULL) 
                    nodesInLevel.push(currentNode->left);
                
                if (currentNode->right != NULL) 
                    nodesInLevel.push(currentNode->right);

                nodesInLevel.pop();
            }
        }
        return height;
    }
};

class RBTree {
private:
    class Node{
    public:
        bool isRed = true;
        int value;
        Node *left = NULL, *right = NULL, *parent;
    
        Node(int value, Node* parent){
            this->value = value;
            this->parent = parent;
        }
        
        bool isLeftChild(){
            if(this->parent->left == this)
                return true;
            return false;
        }

        std::string draw(std::string spacing){
            std::string s = "";
            if(this->right !=  NULL)
                s += this -> right -> draw(spacing + "      ");
            
            // std::string color = ;
            s += spacing + (this->isRed ? "R " : "B ") + std::to_string(this->value);
            
            if(this->left !=  NULL || this->right !=  NULL )
                s += " --{";
            
            s += "\n";

            if(this->left !=  NULL)
                s += this -> left -> draw( spacing + "      ");
                
            return s;
        }

        ~Node() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
    Node *root;
    int height(Node * node);

    void deleteNodeHelper(Node* node, int key);
    void rbTransplant(Node* u, Node* v);
    void deleteFix(Node* x, Node* xp);
    Node* minimum(Node* node){
        while (node->left != NULL) {
        node = node->left;
        swp++;
        }
        return node;
    }
    void leftRotate(Node* node){
        Node* x = node->right;
        Node* y = x->left;
        x->left = node;
        node->right = y;
        swp+=2;
        if(y){
            y->parent = node;
            swp++;
        }
        if(node->parent){
            if(node->isLeftChild())
                node->parent->left = x;
            else
                node->parent->right = x;
        }else
            root = x;
        x->parent = node->parent;
        node->parent = x;
        swp+=3;
    }

    void rightRotate(Node* node){
        Node* x = node->left;
        Node* y = x->right;
        x->right = node;
        node->left = y;
        swp+=2;
        if(y){
            y->parent = node;
            swp++;
        }
        if(node->parent){
            if(node->isLeftChild())
                node->parent->left = x;
            else
                node->parent->right = x;
        }else
            root = x;
        x->parent = node->parent;
        node->parent = x;
        swp+=3;
    }
public:
    void deleteNode(int data);
    
    unsigned long long cmp = 0;
    unsigned long long swp = 0;
    
    bool isRed(Node * node){return node ? node->isRed : false;}
    void insert(int val);
    void remove(int val);
    bool search(int val);
    std::string draw();
    ~RBTree(){ if(root) delete this -> root; }
    int height(){
        std::queue<Node*> nodesInLevel;
        int height = 0;
        int nodeCount = 0;
        Node* currentNode;
        
        if (root == NULL) 
            return 0;
        
        nodesInLevel.push(root);
        while (!nodesInLevel.empty()) {
            height++;
    
            nodeCount = nodesInLevel.size();
            while (nodeCount--) {
                currentNode = nodesInLevel.front();
    
                if (currentNode->left != NULL) 
                    nodesInLevel.push(currentNode->left);
                
                if (currentNode->right != NULL) 
                    nodesInLevel.push(currentNode->right);

                nodesInLevel.pop();
            }
        }
        return height;
    }
};

class SplayTree {
private:
    class Node{
    public:
        int value;
        Node *left = NULL, *right = NULL, *parent;
    

        Node(int value, Node* parent){
            this->value = value;
            this->parent = parent;
        }
        
        bool isLeftChild(){
            if(this->parent->left == this)
                return true;
            return false;
        }

        std::string draw(std::string spacing){
            std::string s = "";
            if(this->right !=  NULL)
                s += this -> right -> draw(spacing + "      ");
            
            // std::string color = ;
            s += spacing + std::to_string(this->value);
            
            if(this->left !=  NULL || this->right !=  NULL )
                s += " --{";
            
            s += "\n";

            if(this->left !=  NULL)
                s += this -> left -> draw( spacing + "      ");
                
            return s;
        }

        ~Node() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
    Node *root;
    int height(Node * node);

    void Transplant(Node* u, Node* v);
    
    Node* minimum(Node* node){
        while (node->left != NULL) {
        node = node->left;
        swp++;
        }
        return node;
    }

    void leftRotate(Node* node){
        Node* x = node->right;
        Node* y = x->left;
        x->left = node;
        node->right = y;
        swp+=2;
        if(y){
            y->parent = node;
            swp++;
        }
        if(node->parent){
            if(node->isLeftChild())
                node->parent->left = x;
            else
                node->parent->right = x;
        }else
            root = x;
        x->parent = node->parent;
        node->parent = x;
        swp+=3;
    }

    void rightRotate(Node* node){
        Node* x = node->left;
        Node* y = x->right;
        x->right = node;
        node->left = y;
        swp+=2;
        if(y){
            y->parent = node;
            swp++;
        }
        if(node->parent){
            if(node->isLeftChild())
                node->parent->left = x;
            else
                node->parent->right = x;
        }else
            root = x;
        x->parent = node->parent;
        node->parent = x;
        swp+=3;
    }
public:
    void deleteNode(int data);
    
    unsigned long long cmp = 0;
    unsigned long long swp = 0;
    
    void Splay(Node* node);
    void insert(int val);
    void remove(int val);
    bool search(int val);
    std::string draw();
    ~SplayTree(){ if(root) delete this -> root; }
    int height(){
        std::queue<Node*> nodesInLevel;
        int height = 0;
        int nodeCount = 0;
        Node* currentNode;
        
        if (root == NULL) 
            return 0;
        
        nodesInLevel.push(root);
        while (!nodesInLevel.empty()) {
            height++;
    
            nodeCount = nodesInLevel.size();
            while (nodeCount--) {
                currentNode = nodesInLevel.front();
    
                if (currentNode->left != NULL) 
                    nodesInLevel.push(currentNode->left);
                
                if (currentNode->right != NULL) 
                    nodesInLevel.push(currentNode->right);

                nodesInLevel.pop();
            }
        }
        return height;
    }
};
#endif
