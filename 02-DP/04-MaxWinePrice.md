```c++
#include <iostream>
#include<climits>
#include<vector>
using namespace std;

// In 1 year you can sell one bottle from one end
//Price inc every year

// 1. Memorization
int maxPrice(vector<int> wines,int i,int j,int year,int dp[100][100]){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    int op1=wines[i]*year + maxPrice(wines,i+1,j,year+1,dp);
    int op2=wines[j]*year + maxPrice(wines,i,j-1,year+1,dp);
    int ans=max(op1,op2);
    return dp[i][j]=ans;
}

// 2. Tabulated 2D Array

int main() {
    vector<int> wines={2,3,5,1,4};
    int dp[100][100]={0};
    int year=1;
    cout<<maxPrice(wines,0,wines.size()-1,year,dp);
}
```
