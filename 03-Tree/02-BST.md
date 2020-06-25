### BST

```c++
#include<iostream>
#include<climits>
using namespace std;

// 0. TreeNode
class TreeNode{
  public:
  int data;
  TreeNode*left;
  TreeNode*right;
  TreeNode(int d){
      data=d;
      left=right=NULL;
  }
};

// 1. Create BST
TreeNode *CreateBst(TreeNode*root, int d){
    if(root==NULL){
        return new TreeNode(d);
    }
    if(root->data < d){
        root->right=CreateBst(root->right,d);
    }
    if(root->data > d){
        root->left=CreateBst(root->left,d);
    }
    return root;
}

TreeNode* buildBST(){
    int d;
    cin>>d;
    TreeNode *root=NULL;
    while(d!=-1){
        root=CreateBst(root, d);
        cin>>d;
    }
    return root;
}


// 2. print
void print(TreeNode*root){
    if(root!=NULL){
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
    }
}

// 3. Find
TreeNode* Find(TreeNode*root, int d){
    if(root!=NULL){
        if(d==root->data){
            return root;
        }
        if(root->data > d){
            return Find(root->left, d);
        }
        if(root->data < d){
            return Find(root->right, d);
        }
    }
    return NULL;
}

// 4. Find Min
TreeNode* FindMin(TreeNode*root){
    if(root!=NULL){
        if(root->left){
            return FindMin(root->left);
        }
        return root;
    }
    return NULL;
}

// 5. Is BST
bool isBST(TreeNode*root, int minV=INT_MIN,int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}

// 6. Delete
TreeNode* deleteNode(TreeNode*root,int d){
    if(root==NULL){
        return NULL;
    }
    if(d<root->data){
        root->left=deleteNode(root->left,d);
        return root;
    }
    if(d>root->data){
        root->right=deleteNode(root->right,d);
        return root;
    }
    if(d==root->data){
        // 1. 0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2. 1 children
        if(root->left!=NULL && root->right==NULL){
            TreeNode*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            TreeNode*temp=root->right;
            delete root;
            return temp;
        }
        // 3. 2 children
        TreeNode *minRight=root->right;
        while(minRight->left){
            minRight=minRight->left;
        }
        root->data=minRight->data;
        root->right=deleteNode(root->right,minRight->data);
        return root;
    }
    return root;
}

// 7. Flatten - BST->LL 
class linkedList{
    public:
    TreeNode*head;
    TreeNode*tail;
};
linkedList flatten(TreeNode*root){
    linkedList ll;
    if(root==NULL){
        ll.head=ll.tail=NULL;
        return ll;
    }
    // 0 children
    if(root->left==NULL && root->right==NULL){
        ll.head=ll.tail=root;
        return ll;
    }
    // 1 children
    if(root->left!=NULL && root->right==NULL){
        linkedList left=flatten(root->left);
        
        ll.head=left.head;
        ll.tail=root;
        return ll;
    }
    if(root->left==NULL && root->right!=NULL){
        linkedList right=flatten(root->right);
        
        ll.head=root;
        ll.tail=right.tail;
        return ll;
    }
    // 2children
    linkedList left=flatten(root->left);
    linkedList right=flatten(root->right);
    
    ll.head=left.head;
    ll.tail=right.tail;
    
    return ll;
}

int main() {
    // 1. Create BST
    int n;
    cin>>n;
    TreeNode*root=NULL;
    for(int i=1;i<=n;i++){//5 2 1 3 9 4 
        int d;
        cin>>d;
        root=CreateBst(root,d);
    }
    TreeNode* bst=buildBST();//1 2 3 4 5 -1
    
    // 2. Print
    cout<<"Print:";
    print(root);cout<<endl;
    print(bst);cout<<endl;
    
    // 3. Find
    cout<<"Find:";
    TreeNode *f=Find(root,2);//if NULL
    cout<<f->data<<endl;
    
    // 4. Find Min
    cout<<"FindMin:";
    TreeNode *fmini=FindMin(root);
    cout<<fmini->data<<endl;
    
    // 5. IS BST
    cout<<"IS BST:";
    cout<<isBST(root)<<endl;
    
    // 6. Delete
    deleteNode(root,1);
    print(root);cout<<endl;
     
    // 7. Flatten - BST->LL 
    linkedList ll=flatten(root);
    
}
```
