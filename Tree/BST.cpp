#include <iostream>
#include <climits>

using namespace std;

class BSTnode
{
public:
    int data;
    BSTnode* lc,*rc;
    BSTnode()
    {
        lc = rc = NULL;
        data = INT_MIN;
    }
};

void insert(BSTnode*&BST,int k)
{
    if (BST == NULL)
    {
        BST = new BSTnode();
        BST->data = k;
        return ;
    }

    if (BST->data > k)
        insert(BST->lc,k);

    else if (BST->data < k)
        insert(BST->rc,k);
}

void inorder(BSTnode* BST)
{
    if(BST==NULL) return;

    inorder(BST->lc);
    cout<<BST->data<<" ";
    inorder(BST->rc);
}

BSTnode* min(BSTnode* BST)
{
    while(BST->lc!=NULL)
        BST=BST->lc;

    return BST;
}

BSTnode* max(BSTnode* BST)
{
    while(BST->rc!=NULL)
        BST=BST->rc;

    return BST;
}

BSTnode* find(BSTnode* BST,int key)
{
    if (BST->data == key) return BST;
    if(BST==NULL) return NULL;

    if (BST->data > key) find(BST->lc,key);
    else if (BST->data <key) find(BST->rc,key);
}

BSTnode* parent(BSTnode* BST,int key)
{
    if (key<BST->data)
    {
        if (BST->lc->data == key) return BST;
        else return parent(BST->lc,key);
    }
    else if (key>BST->data)
    {
        if (BST->rc->data == key) return BST;
        else return parent(BST->rc,key);
    }
    else return NULL;
}

void predsucc(BSTnode* &root,BSTnode*&pre,BSTnode*&succ,int key)
{
    if (root==NULL) return ;
    if (root->data == key)
    {
        if (root->lc !=NULL)
            pre = max(root->lc);
        if (root->rc!=NULL)
            succ = min(root->rc);
        return;
    }

    if (root->data<key)
    {
        pre=root;
        predsucc(root->rc,pre,succ,key);
    }
    else
    {
        succ = root;
        predsucc(root->lc,pre,succ,key);
    }
}

int main()
{
    BSTnode* BST = NULL;

    int k;
    while(true)
    {
        cin>>k;
        if (k==-1) break;
        insert(BST,k);
    }
    
    cout<<"INORDER : ";inorder(BST);cout<<"\n";
    BSTnode* prec,*succ;
    prec = succ =NULL;
    while(true)
    {
        cin>>k;
        if (k==-1) break;
        //cout<<parent(BST,k)->data<<"\n";
        predsucc(BST,prec,succ,k);
        cout<<prec->data<<" "<<succ->data<<'\n';
        prec = succ =NULL;
    }

    return 0;
}

//5 7 1 9 3 2 4 8 -1