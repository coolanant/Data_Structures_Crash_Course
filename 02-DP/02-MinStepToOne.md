```c++
#include <iostream>
#include<climits>
using namespace std;

//if n%3==0 n/3
//if n%2==0 n/2
//else n-1

// 1. Memorization
int minStepToOne(int n,int dp[]){
    if(n==1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0){
        op1=minStepToOne(n/3,dp);
    }
    if(n%2==0){
        op2=minStepToOne(n/2,dp);
    }
    op3=minStepToOne(n-1,dp);
    int ans=min(op1,min(op2,op3))+1;

    return dp[n]=ans;
}

// 2. Tabulated
int minStepToOne2(int n){
    int dp[100]={0};
    for(int i=2;i<=n;i++){
        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        if(n%3==0){
            op1=dp[i/3];
        }
        if(n%2==0){
            op2=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(op1,min(op2,op3))+1;
    }
    return dp[n];
}

int main() {
    int n=10;
    int *dp=new int[n+1];
    cout<<minStepToOne(n,dp)<<endl;

    cout<<minStepToOne2(n)<<endl;
}
```
