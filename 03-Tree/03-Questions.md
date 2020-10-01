## 1. Symmetric Tree/ Mirror

https://leetcode.com/problems/symmetric-tree/

```c++
bool isSymmetric(TreeNode* root) {
    return isMirror(root,root);
}
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val)
        && isMirror(t1->right, t2->left)
        && isMirror(t1->left, t2->right);
}
```

## 2. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/

```c++
class HBPair{
    public:
    int height;bool balance;
};
HBPair isBal(TreeNode*root){
    HBPair ob;
    if(root==NULL){
        ob.height=0;
        ob.balance=true;
        return ob;
    }

    HBPair left=isBal(root->left);
    HBPair right=isBal(root->right);

    ob.height = max(left.height,right.height)+1;

    if(left.balance && right.balance && abs(left.height-right.height)<=1){
        ob.balance=true;
    }else{
        ob.balance=false;
    }
    return ob;
}

bool isBalanced(TreeNode* root) {
    HBPair ob=isBal(root);
    return ob.balance;
}
```

## 3. Root to Leaf Sum

https://leetcode.com/problems/path-sum/

```c++
 bool find(TreeNode*root,int sum,int cs){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL && cs + root->val == sum)
        return true;

    return
        find(root->left, sum, cs+root->val) ||
        find(root->right,sum,cs+root->val);
}

bool hasPathSum(TreeNode* root, int sum) {
    return find(root,sum,0);
}
```

## 4. Binary Tree Right Side View

```c++
void rightView(TreeNode* root, vector<int>& view, int level) {
    if (!root) {
        return;
    }
    if (view.size() == level) {
        view.push_back(root -> val);
    }
    rightView(root -> right, view, level + 1);
    rightView(root -> left, view, level + 1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rightView(root,ans,0);
    return ans;
}
```

## 5. Count Nodes

```c++
int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int x=countNodes(root->left);
    int y=countNodes(root->right);
    return 1+x+y;
}
```

## 6. Invert Binary Tree

```c++
if(root!=NULL){
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
}
return root;
```

## 7. All Root to leaf paths

https://leetcode.com/problems/binary-tree-paths/

```c++
vector<string> ans;
void traverse(TreeNode*root, string x){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        x+=to_string(root->val);
        ans.push_back(x);
    }
    else{
        x+=(to_string(root->val)+"->");
        traverse(root->left,x);
        traverse(root->right,x);
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    traverse(root,"");
    return ans;
}
```

## 8. 404. Sum of Left Leaves

```c++
int ans=0;
int sumOfLeftLeaves(TreeNode* root) {
    if(root==NULL) return 0;
    if(root->left){
        if(root->left->left==NULL && root->left->right==NULL){
            ans+=root->left->val;
        }
    }
    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);
    return ans;
}
```

## 9. Find Bottom Left Tree Value

```c++
int maxlevel=-1;
int ans;
int solve(TreeNode *root, int level){
    if(root!=NULL){
        if(level>maxlevel){
            maxlevel=max(level,maxlevel);
            ans=root->val;
        }
        solve(root->left,level+1);
        solve(root->right,level+1);
        return ans;
    }
    return ans;
}
```

BFS APPROACH

```c++
 int findBottomLeftValue(TreeNode* root) {
    // return solve(root, 0);
    queue<TreeNode*> q;
    q.push(root);
    int result;
    while(!q.empty()){
        TreeNode* current = q.front();
        result = current->val;
        q.pop();
        if(current->right)
            q.push(current->right);
        if(current->left)
            q.push(current->left);
    }
    return result;
}
```

## 10. Merge 2 Binary Tree

```c++
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
```

## 11. Increasing Order Search Tree

```c++
TreeNode*ans=NULL;
TreeNode* InsertRight(TreeNode*ans,int val){
    if(ans==NULL) return ans=new TreeNode(val);
    // insert in right
    ans->right=Insert(ans->right,val);
    return ans;
}
TreeNode* increasingBST(TreeNode* root) {
    if(root==NULL)return NULL;
    //left
    increasingBST(root->left);
    //val  - insert
    int val=root->val;
    ans=InsertRight(ans,val);
    //right
    increasingBST(root->right);

    return ans;
}
```

## 12. Vertical Order Search Tree

```c++
map<int, vector<pair<int,int>> > m;
void solve(TreeNode*root, int d, int level){
    if(root==NULL) return;
    m[d].push_back(make_pair(level,root->val));
    solve(root->left, d-1, level+1);
    solve(root->right, d+1, level+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    solve(root,0,0);
    vector<vector<int> > ans;
    for(auto it:m){
        vector<int> path;
        sort(it.second.begin(),it.second.end());
        for(auto x:it.second){
            path.push_back(x.second);
        }
        ans.push_back(path);
    }
    return ans;
}
```

## 13. Deepest Leaves Sum

```c++
 int maxHeightFunc(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int l=maxHeightFunc(root->left);
    int r=maxHeightFunc(root->right);
    return max(l,r)+1;
}
int deepestLeavesSum(TreeNode* root) {
    int ans=0;
    map<TreeNode*, int> height;
    queue<TreeNode*> q;
    q.push(root);
    height[root]=0;

    int maxHeight=maxHeightFunc(root);
    while(!q.empty()){
        TreeNode *front=q.front();
        q.pop();
        if(front->left){
            q.push(front->left);
            //
            height[front->left]=height[front]+1;
            if(height[front->left]==maxHeight-1){
                ans+=front->left->val;
            }
        }
        if(front->right){
            q.push(front->right);
            //
            height[front->right]=height[front]+1;
            if(height[front->right]==maxHeight-1){
                ans+=front->right->val;
            }
        }
    }
    return ans;
}

```
