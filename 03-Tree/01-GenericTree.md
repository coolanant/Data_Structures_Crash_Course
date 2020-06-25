```c++
#include <iostream>
#include<queue>
using namespace std;

// 0. TreeNode
class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int d){
        val=d;
        left=right=NULL;
    }
};

// 1. Build Tree
TreeNode* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    TreeNode*root=new TreeNode(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

// 2. Print Tree (Traversal)
void printTree(TreeNode*root){
    if(root!=NULL){
        cout<<root->val;
        printTree(root->left);
        printTree(root->right);
    }
}

// 3. Sum
int sum(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+root->val+sum(root->right);
}

// 4. Count
int count(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return count(root->left)+1+count(root->right);
}

// 5. Height
int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

// 6. Level Order Print
void printKthLevel(TreeNode*root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->val<<" ";
    }
    printKthLevel(root->left, level-1);
    printKthLevel(root->right, level-1);
    return;
}
void printAllLevel(TreeNode*root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
}

// 7. BFS //Level Order Print
void BFS(TreeNode*root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode*front=q.front();
        cout<<front->val<<" ";
        q.pop();

        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}

// 8. Diametere (Max dist b/w 2 nodes)
class Pair{
    public:
    int height,diametere;
};
int diametere1(TreeNode*root){   //O(n2)
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int d=h1+h2;

    int d1=diametere1(root->left);
    int d2=diametere1(root->right);

    return max(d,max(d1,d2));
}

Pair diametere2(TreeNode*root){//O(n)
    Pair p;
    if(root==NULL){
        p.height=p.diametere=0;
        return p;
    }
    Pair left=diametere2(root->left);
    Pair right=diametere2(root->right);

    p.height=max(left.height,right.height)+1;

    p.diametere=max(left.diametere,max(right.diametere,left.height+right.height));

    return p;
}

// 9. Is Height balanced
class HBPair{
  public:
  int height;
  bool balance;
};

HBPair isHBT(TreeNode*root){
    HBPair ob;
    if(root==NULL){
        ob.height=0;
        ob.balance=true;
        return ob;
    }
    HBPair left=isHBT(root->left);
    HBPair right=isHBT(root->right);

    ob.height=left.height+right.height+1;

    if(left.balance && right.balance && abs(left.height-right.height)<=1){
        ob.balance=true;
    }else{
        ob.balance=false;
    }
    return ob;
}


int main() {
    // 1. Build Tree
    TreeNode*root=buildTree(); //3 4 -1 6 -1 -1 5 1 -1 -1 -1

    // 2. Print Tree (Traversal)
    printTree(root);cout<<endl;

    // 3. Sum
    cout<<sum(root)<<endl;

    // 4. Count
    cout<<count(root)<<endl;

    // 5. Height
    cout<<height(root)<<endl;

    // 6. Level Order Print
    cout<<"Level wise Print:"<<endl;printAllLevel(root);cout<<endl;

    // 7. BFS
    cout<<"BFS:";BFS(root);cout<<endl;

    // 8. Diametere
    cout<<"Diametere:"<<diametere1(root)<<endl;
    Pair hd=diametere2(root);
    cout<<hd.height<<" "<<hd.diametere<<endl;

    // 9. is Height Balanced
    HBPair ob=isHBT(root);
    cout<<ob.balance<<endl;


}
```
