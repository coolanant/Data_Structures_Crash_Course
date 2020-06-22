### 01-Fibonnaci

```c++
#include <iostream>
#include <vector>
using namespace std;

// Fibonnaci

// 1.Top-Down (Memorization)
int fibonnaci(int x,int dp[]){
    if(x==0 || x==1){
        return x;
    }
    if(dp[x]!=0){
        return dp[x];
    }
    dp[x]=fibonnaci(x-1,dp)+fibonnaci(x-2,dp);
    return dp[x];
}

// 2. Bottom-Up (Tabulated)
int fibonnaci2(int n){
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// 3. Optimized
int fibonnaci3(int n){
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main() {
    int n=3;
    // int dp[100]={0};
    // vector<int> dp(n+1,0);
    int *dp = new int[n+1];
    cout<<fibonnaci(n,dp)<<endl;

    cout<<fibonnaci2(n)<<endl;

    cout<<fibonnaci3(n)<<endl;
}
```
