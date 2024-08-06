#include "header.hpp"

bool SplayTree::search(int value){
    Node* node = root;
    if(!node) return false;
    bool result = true;
    while(node -> value != value){
        cmp++;
        if((value < node->value ? node->left : node->right) ==  NULL){
            result = false;
            break;
        }
        node = value < node->value ? node->left : node->right;
        swp++;
    }

    // splay
    Splay(node);
    // trafiony lub najbliższy
    // std::cout<<"Conn "<<checkConnections()<<std::endl;
    return result;

}

void SplayTree::Splay(Node* node){
    if(node == root) return;

    while(node != root){
        if(node->parent == root){
            if(node->isLeftChild())
                rightRotate(root);
            else
                leftRotate(root);
            break;
        }

        if(node->isLeftChild()){
            if(node->parent->isLeftChild()){
                rightRotate(node->parent);
                rightRotate(node->parent);
            }else{
                rightRotate(node->parent);
                leftRotate(node->parent);
            }
        }else{
            if(!node->parent->isLeftChild()){
                leftRotate(node->parent);
                leftRotate(node->parent);
            }else{
                leftRotate(node->parent);
                rightRotate(node->parent);
            }
        }
    }
}


void SplayTree::insert(int value){
    Node* newRoot = new Node(value, NULL);
    
    if(!root){
        root = newRoot;
        swp++;
        return;
    }

    search(value);
    // std::cout<<"found "<<root->value<<std::endl;

    cmp++;
    if(value < root->value){
        newRoot->right = root;
        root->parent = newRoot;
        if(root->left){
            newRoot->left = root->left;
            root->left->parent = newRoot;

            root->left = NULL;
            swp+=3;
        }

        root = newRoot;
        swp+=3;
    }else{
        newRoot->left = root;
        root->parent = newRoot;
        
        if(root->right){
            newRoot->right = root->right;
            root->right->parent = newRoot;

            root->right = NULL;
            swp+=3;
        }

        root = newRoot;
        swp+=3;
    }
}

void SplayTree::remove(int val){
    if(!search(val))
        return;
    
    // std::cout<<"======= ProtoTree =======\n";
    // std::cout<<draw();
    // std::cout<<"======= ========= ======="<<std::endl;
    // // val jest na szczycie
    Node* del = root;
    Node* right = root->right;
    Node* left = root->left;

    if(!left){
        if(!right){
            root = NULL;
        }else{
            root = right;
            right->parent = NULL;
            swp++;
        }
        swp++;
    }else{
        root = left;
        root->parent = NULL;
        search(val);
        root->right = right;
        swp+=3;
        if(right){ right->parent = root; swp++;}
    }
    free(del);
}



std::string SplayTree :: draw(){
    if(this -> root ==  NULL)
        return "--";
    return this -> root -> draw("");
}
int SplayTree::height(Node * node){
    if(node == NULL)
        return 1;
    return std::max(height(node->left), height(node->right)) + 1;
}