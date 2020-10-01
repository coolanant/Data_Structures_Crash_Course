```c++
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
```

## 1. Pre-Order Traversal

```c++
void solve(Node *root,vector<int> &ans) {
    if(root==NULL) return;
    ans.push_back(root->val);
    for(auto child: root->children) {
        solve(child,ans);
    }
}
vector<int> preorder(Node* root) {
    vector<int> ans;
    solve(root,ans);
    return ans;
}
```

## 2. Post-Order Traversal

```c++
void solve(Node *root,vector<int> &ans) {
if(root==NULL) return;
    for(auto child: root->children) {
        solve(child,ans);
    }
    ans.push_back(root->val);
}
vector<int> postorder(Node* root) {
    vector<int> ans;
    solve(root,ans);
    return ans;
}
```

## 3. Height of N-ary Tree

```c++
 int findHeight(Node*root){
    if(root==NULL){
        return 0;
    }
    // for all leaves node
    if(root->children.size()==0){
        return 1;
    }
    int x=INT_MIN;
    for(auto child:root->children){
        x=max(x,findHeight(child));
    }
    return x+1;
}

int maxDepth(Node* root) {
    int n=findHeight(root);
    return n;
}
```

## 4. Level Order Traversal

```c++
vector<vector<int> > levelOrder(Node* root) {
    queue<Node*> q;
    vector<int> arr;
    vector<vector<int> > ans;
    q.push(root);
    arr.push_back(root->val);
    ans.push_back(arr);

    while(!q.empty()){
        // int size=q.size();
        vector<int> temp;
        Node *front=q.front();
        q.pop();
        // while(size-- >0){
            for(auto child:front->children){
                q.push(child);
                temp.push_back(child->val);
            }
        // }
        if(temp.size()!=0){
            ans.push_back(temp);
        }
    }
    return ans;
}
```

```c++
void printKthLevel(Node*root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        arr.push_back(root->val);
    }
    for(auto child:root->children){
            printKthLevel(child, level-1);
    }
    return;
}
```
