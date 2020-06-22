```c++
#include <iostream>
#include<vector>
using namespace std;

//  1. Tabulated
// last row,col -> same
// 0->0
// min(right,down,diagonal_right_bottom)+1
void maxsize1(vector<vector<int> > mat){
    int mr=mat.size()-1;
    int mc=mat[0].size()-1;
    vector<vector<int> > dp(mr+1,vector<int>(mc+1));
    int maxsize=0,row,col;
    for(int r=mr;r>=0;r--){
        for(int c=mc;c>=0;c--){
            if(r==mr || c==mc){
                dp[r][c]=mat[r][c];
            }
            else{
                if(mat[r][c]==0){
                    dp[r][c]=0;
                }
                else{
                    dp[r][c]=1+min(min(dp[r+1][c],dp[r][c+1]),dp[r+1][c+1]);
                    if(dp[r][c]>=maxsize){
                        maxsize=dp[r][c];
                        row=r;
                        col=c;
                    }
                }
            }
        }
    }
    cout<<maxsize<<endl<<row<<endl<<col;
}

// 2. Memorization
int ans=0;
int maxSizeRecursion(vector<vector<int> > mat,int sr,int sc,int dp[][100]){
    if(sr==mat.size()-1 || sc==mat[0].size()-1){
        return mat[sr][sc];
    }
    if(dp[sr][sc]!=0){
        return dp[sr][sc];
    }
    if(mat[sr][sc]==0){
        return 0;
    }
    else{
        int op1=maxSizeRecursion(mat,sr+1,sc,dp);
        int op2=maxSizeRecursion(mat,sr,sc+1,dp);
        int op3=maxSizeRecursion(mat,sr+1,sc+1,dp);

        int res=min(op1,min(op2,op3))+1;
        if(ans<res){
            ans=res;
        }
        dp[sr][sc]=res;
        return res;
    }
}

int main() {
    vector<vector<int> > mat={
        {1,0,1,0,0,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,0,0},
        {1,1,1,1,1,1},
        {0,0,1,1,1,0},
    };

    maxsize1(mat);

    int dp2[100][100]={0};
    maxSizeRecursion(mat,0,0,dp2);
    cout<<endl<<ans;
}
```
