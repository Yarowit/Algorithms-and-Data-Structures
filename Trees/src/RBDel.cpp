#include "header.hpp"

void RBTree::deleteFix(Node* x, Node* xp) {
    Node* s;
    while (x != root && !isRed(x)) {
      if (x == xp->left) {
        s = xp->right;
		swp++;
        if (isRed(s)) {
          s->isRed = false;
          xp->isRed = true;
          leftRotate(xp);
          s = xp->right;
		  swp++;
        }

        if (!isRed(s->left) && !isRed(s->right)) {
          s->isRed = true;
          x = xp;
          if(x->parent) xp = x->parent;
        } else {
          if (!isRed(s->right)) {
            s->left->isRed = false;
            s->isRed = true;
            rightRotate(s);
            s = xp->right;
          }
          s->isRed = xp->isRed;
          xp->isRed = false;
          if(s->right) s->right->isRed = false;
          leftRotate(xp);
          x = root;
        }
      } else {
            // std::cout<<"Drugi"<<std::endl;
        s = xp->left;
        if (isRed(s)) {
          s->isRed = false;
          xp->isRed = true;
          rightRotate(xp);
          s = xp->left;
        }

        if (!isRed(s->right) && !isRed(s->left)) {
          s->isRed = true;
          x = xp;
          if(x->parent) xp = x->parent;
        } else {
          if (!isRed(s->left)) {
            s->right->isRed = false;
            s->isRed = true;
            leftRotate(s);
            s = xp->left;
          }

          s->isRed = xp->isRed;
          xp->isRed = false;
          s->left->isRed = false;
          rightRotate(xp);
          x = root;
        }
      }
    }
    x->isRed = false;
  }


  void RBTree::rbTransplant(Node* u, Node* v) {
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

void RBTree::remove(int value){
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
    bool original_color = isRed(del);
    y = del;
    if(!del->left){
        x = del->right;
        xp = del->parent;
        rbTransplant(del,del->right);
    }else if(!del->right){
        x = del->left;
        xp = del->parent;
        rbTransplant(del,del->left);
    }else{
        y = minimum(del->right);
        original_color = y->isRed;
        x = y->right;
        xp = y->parent;

        if(y->parent == del)
            // x->parent = y;
            xp = y;
        else{
            rbTransplant(y,y->right);
            y->right = del->right;
            y->right->parent = y;
			swp+=2;
        }

        rbTransplant(del,y);
        y->left = del->left;
        y->left->parent = y;
		swp+=2;
        y->isRed = del->isRed;
    }

    if(original_color == false)
        deleteFix(x,xp);
}