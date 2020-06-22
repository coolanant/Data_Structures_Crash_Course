```c++

#include <iostream>
#include<climits>
#include<vector>
using namespace std;

// 1. Tabulated
int maxGoldMine2(vector<vector<int> >mine){
    int dp[100][100]={0};
    int op1,op2,op3;
    for(int col=mine[0].size()-1;col>=0;col--){
        for(int row=0;row<mine.size();row++){
            op1=op2=op3=INT_MIN;
            if(row>0){
                op1=dp[row-1][col+1];
            }
            op2=dp[row][col+1];
            if(row<mine.size()-1){
                op3=dp[row+1][col+1];
            }
            dp[row][col]=mine[row][col]+max(op1,max(op2,op3));
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<mine.size();i++){
        if(dp[i][0] > ans){
            ans=dp[i][0];
        }
    }
    return ans;
}

// 2. Memorization
int maxGoldMine(vector<vector<int> >mine,int r, int c,int dp[][100]){
    if(c==mine[0].size()-1){
        return mine[r][c];
    }
    if(dp[r][c]!=0){
        return dp[r][c];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MIN;
    if(r>0){
        op1=maxGoldMine(mine,r-1,c+1,dp);
    }
    op2=maxGoldMine(mine,r,c+1,dp);
    if(r<mine.size()-1){
        op3=maxGoldMine(mine,r+1,c+1,dp);
    }
    return dp[r][c]=mine[r][c]+max(op1,max(op2,op3));
}

int main() {
    vector<vector<int> > mine={
        {2,6,0,5},
        {0,7,5,2},
        {3,0,3,7},
        {8,0,2,3},
    };
    int maxAns=0;
    for(int i=0;i<mine.size();i++){
        int dp[100][100]={0};
        int ans=maxGoldMine(mine,i,0,dp);
        if(ans>maxAns){
            maxAns=ans;
        }
    }
    cout<<maxAns;

    cout<<maxGoldMine2(mine)<<endl;
}


```
