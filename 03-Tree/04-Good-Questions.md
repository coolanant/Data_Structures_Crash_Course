## 1. All Path Sum

```c++
vector<vector<int>> ans;
vector<int> path;
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    dfs(root, sum);
    return ans;
}

void dfs(TreeNode* root, int sum) {
    if(root==NULL) return;
    path.push_back(root->val);
    if(root->left==NULL && root->right==NULL) {
        if(sum == root->val) {
            ans.push_back(path);
        }
        path.pop_back();
        return;
    }
    dfs(root->left, sum - root->val);
    dfs(root->right, sum - root->val);
    path.pop_back();
}
```

## 2. Vertical Order Search Tree

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
