#include <iostream> 
#include "header.hpp"

void Tree :: insert(int value){
    if(this -> root ==  NULL){
        this -> root = new Node(value, NULL);
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
                swp++;
                return;
            }
        }else{
            if(node -> right !=  NULL){
                node = node -> right;
                swp++;
            }else{
                node -> right = new Node(value, node);
                swp++;
                return;
            }
        }
    }
}

bool Tree :: search(int value){
    if(this -> root ==  NULL)
        return false;

    Node *node = this -> root;
    
    while(node !=  NULL){
        if(node -> value == value)
            return true;
            
        if(value < node -> value)
            node = node -> left;
        else
            node = node -> right;
        cmp++; swp++;
    }
    return false;
}

std::string Tree :: draw(){
    if(this -> root ==  NULL)
        return "--";
    return this -> root -> draw("");
}


// void Tree :: remove(int value){
//     // wrzuć najbardziej prawego syna lewego drzewa
//     Node* del = this -> root;

//     // Search
//     while(del -> value != value){
//         del = value < del->value ? del->left : del->right;
//         cmp++;swp++;
//         if(del ==  NULL)
//             return;
//     }

//     Node * replacement = NULL; // root
//     bool isReplacementALeftChild;
//     if((!del->left + !del->right) == 1){
//         if(del->left){
//             isReplacementALeftChild = true;
//             replacement = del->left;
//         }else{
//             isReplacementALeftChild = false;
//             replacement = del->right;
//         }
//     }else if(del->left && del->right){
//         Node * node = del->left;
//         while(node->right != NULL){ node = node->right; swp++;}
//         replacement = node;
//     }
//     if(replacement != NULL){
//         if(replacement != del->left){
//             // odpięcie replacementa
//             if(isReplacementALeftChild)
//                 replacement->parent->left = NULL;
//             else
//                 replacement->parent->right = NULL;
//             swp++;
        
//             //dzieci replacementa
//             Node * node = replacement;
//             while(node->left){ node = node->left; swp++;}
//             node->left = del->left;
//             swp++;
//         }
//         replacement->right = del->right;
//         swp++;
//     }
//         // rodzic replacementa
//     if(del->parent != NULL)
//         if(del->isLeftChild())
//             del->parent->left = replacement;
//         else
//             del->parent->right = replacement;
//     else
//         root = replacement;
//     swp++;
//     std::cout<<"s"<<std::endl;
        
//     // free(del);
//     delete del;
// }

int Tree::height(Node * node){
    if(node == NULL)
        return 1;
    return std::max(height(node->left), height(node->right)) + 1;
}

void Tree::remove(int value){
    // wrzuć najbardziej prawego syna lewego drzewa
    Node* del = this -> root;
    Node* x = NULL, *xp;
    Node* y;

    if(!root) return;

    if(root->value == value && !root->left && !root->right){
        root = NULL;
        return;
    }

    // Search
    while(del -> value != value){
        del = value < del->value ? del->left : del->right;
		cmp++;swp++;
        if(del ==  NULL)
            return;
    }
    y = del;
    if(!del->left){
        x = del->right;
        xp = del->parent;
        Transplant(del,del->right);
    }else if(!del->right){
        x = del->left;
        xp = del->parent;
        Transplant(del,del->left);
    }else{
        y = minimum(del->right);
        x = y->right;
        xp = y->parent;

        if(y->parent == del)
            // x->parent = y;
            xp = y;
        else{
            Transplant(y,y->right);
            y->right = del->right;
            y->right->parent = y;
			swp+=2;
        }

        Transplant(del,y);
        y->left = del->left;
        y->left->parent = y;
		swp+=2;
    }
    
}
void Tree::Transplant(Node* u, Node* v) {
    // u <-> v.parent
    if (u->parent == NULL) {
      root = v;
	  swp++;
    } else if (u->isLeftChild()) {
      u->parent->left = v;
	  swp++;
    } else {
      u->parent->right = v;
	  swp++;
    }
    if(v){
        v->parent = u->parent;
		swp++;
	}
  }