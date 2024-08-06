#include "header.hpp"

void RBTree::insert(int value){
    if(this -> root ==  NULL){
        this -> root = new Node(value, NULL);
        this->root->isRed = false;
        swp++;
        return;
    }

    Node* node = this -> root;

    while(true){
        cmp++;
        if(value < node -> value){
            if(node -> left !=  NULL){
                node = node -> left;
                swp++;
            }else{
                node -> left = new Node(value, node);
                node = node->left;
                swp+=3;
                break;
            }
        }else{
            if(node -> right !=  NULL){
                node = node -> right;
                swp++;
            }else{
                node -> right = new Node(value, node);
                node = node->right;
                swp+=3;
                break;
            }
        }
    }
    //std::cout<<"f\n";
    //std::cout<<node->parent->value<<std::endl;
    // fixup
    while(isRed(node->parent)){
        //std::cout<<"r\n";
        
        if(node->parent->isLeftChild()){
            Node * uncle = node->parent->parent->right;
            //std::cout<<"u\n";
            if(isRed(uncle)){
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
                swp++;
            }else{ 
                //std::cout<<"inr\n";
                if(!node->isLeftChild()){
                    //std::cout<<"nlc\n";
                    node = node->parent;
                swp++;
                    leftRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
        //std::cout<<"col\n";
        //std::cout<<node->value<<node->parent->value<<node->parent->parent->value<<"\n";
        //std::cout<<draw()<<std::endl;
                rightRotate(node->parent->parent);
            }
        }else{
            Node * uncle = node->parent->parent->left;
            //std::cout<<"u\n";
            if(isRed(uncle)){
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
                swp++;
                // std::cout<<"val: "<<node->value<<std::endl;
            }else{ 
                if(node->isLeftChild()){
                    node = node->parent;
                swp++;
                    rightRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                leftRotate(node->parent->parent);
            }
        }
        if(!node->parent){
            node->isRed = false;
            break;
        }
        // std::cout<<"parent: "<<node->value<<" its parent: "<<node->parent->value<<std::endl;
        // Node* n = root;
        // std::cout<<( isRed(n) ? "R" : "B" )<<std::endl;
    }
        //std::cout<<"d\n";

}

std::string RBTree :: draw(){
    if(this -> root ==  NULL)
        return "--";
    return this -> root -> draw("");
}
int RBTree::height(Node * node){
    if(node == NULL)
        return 1;
    return std::max(height(node->left), height(node->right)) + 1;
}