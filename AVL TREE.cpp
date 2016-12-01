#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int ht;
    node *left;
    node *right;
};

node *root;

int height(node *ptr)
{
    //cout<<"aaaaaaaaaaaaaa";
    if(ptr==NULL)
        return 0;
    return ptr->ht;
}

node* createnode(int val)
{
    node *np;
    np=(node *)malloc(sizeof(node));
    np->right=NULL;
    np->left=NULL;
    np->data=val;
    np->ht=1;
    return np;
}

node* rightrot(node *y)
{
    node *x=y->left,*T2=x->right;
    x->right=y;
    y->left=T2;
    y->ht=1+max(height(y->left),height(y->right));
    x->ht=1+max(height(x->left),height(x->right));
    return x;
}

node* leftrot(node *x)
{
    node *y=x->right,*T2=y->left;
    y->left=x;
    x->right=T2;
    y->ht=1+max(height(y->left),height(y->right));
    x->ht=1+max(height(x->left),height(x->right));
    return y;
}

int getbal(node *ptr)
{
    if(ptr==NULL)
        return 0;
    return (height(ptr->left)-height(ptr->right));
}

node* insertavl(node *nd,int val)
{
    if(nd==NULL)
        return createnode(val);
    if (val<nd->data)
        nd->left=insertavl(nd->left,val);
    else
        nd->right=insertavl(nd->right,val);

    nd->ht=max(height(nd->left),height(nd->right))+1;

    int balance=getbal(nd);
    // left left
    if(balance>1 && val<nd->left->data)
    {
        return rightrot(nd);
        //cout<<"bbbbbbbbbbbbbb";
    }
    // right right
    if(balance<-1 && val>nd->right->data)
    {
        return leftrot(nd);
        //cout<<"ccccccccccccccccccc";
    }
    // left right
    if(balance>1 && val>nd->left->data)
    {
        nd->left=leftrot(nd->left);
        return rightrot(nd);
    }
    // right left
    if(balance<-1 && val<nd->right->data)
    {
        nd->right=rightrot(nd->right);
        return leftrot(nd);
    }
    return nd;
}

void preOrder(node *rooot)
{
    if(rooot != NULL)
    {
        printf("%d ", rooot->data);
        preOrder(rooot->left);
        preOrder(rooot->right);
    }
}

int main()
{
  root=NULL;
  root = insertavl(root, 10);
  //cout<<"10 ";
  root = insertavl(root, 20);
 // cout<<"20 ";
  root = insertavl(root, 30);
 // cout<<"30 ";
  root = insertavl(root, 40);
 // cout<<"40 ";
  root = insertavl(root, 50);
 // cout<<"50 ";
  root = insertavl(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  cout<<"Pre order traversal of the constructed AVL tree is \n";
  preOrder(root);
}
