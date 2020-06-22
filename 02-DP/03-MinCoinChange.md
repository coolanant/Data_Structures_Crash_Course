```c++
#include <iostream>
#include<climits>
#include<vector>
using namespace std;

// 1. Memorization
int minCoins(int n,vector<int> coins,int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(n-coins[i]>=0){
            int subprob=minCoins(n-coins[i],coins,dp);
            ans=min(ans,subprob+1);
        }
    }
    return dp[n]=ans;
}

// 2. Tabulated
int minCoins2(int n,vector<int> coins){
    int dp[100]={0};
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j]<=i){
                if(dp[i-coins[j]]+1<dp[i]){
                    dp[i]=dp[i-coins[j]]+1;
                }
            }
        }
    }
    return dp[n];
}


int main() {
    int n=15;
    vector<int> coins={1,7,10};
    int *dp=new int[n+1];
    cout<<minCoins(n, coins,dp)<<endl;

    cout<<minCoins2(n, coins);
}
```
