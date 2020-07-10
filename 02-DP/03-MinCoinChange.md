```c++
#include <iostream>
#include<vector>
#include<climits>
using namespace std;

// 1. Tabulated
int minCoinChange(vector<int> coins,int n){
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

int counter=0;
// 2. Memorization
int minCoinChange2(vector<int> coins, int n, int dp[]){
    if(n==0){
        counter++;//this will count permuation too which we dont want
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(n-coins[i]>=0){
            int subprob=minCoinChange2(coins,n-coins[i],dp);
            ans=min(ans,subprob+1);
        }
    }
    return ans;
}

// 3. TOTAL WAYS
int totalWays(vector<int>& coins, int amount) {
     vector<int> table(amount+1,0);
    table[0] = 1;
    for(int i=0; i<coins.size(); i++) 
        for(int j=coins[i]; j<=amount; j++) 
            table[j] += table[j-coins[i]]; 
    return table[amount]; 
}

int main() {
    vector<int> coins={1,7,10};
    int n=15;
    
    // 1. Tabulated
    cout<<minCoinChange(coins,n)<<endl;
    
    // 2. Memorization
    int dp[100]={0};
    cout<<minCoinChange2(coins,n,dp)<<endl;
    
    // 3. Total Ways
    cout<<totalWays(coins,n);
}
```
