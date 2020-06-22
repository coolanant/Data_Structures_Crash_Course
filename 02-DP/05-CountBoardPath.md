```c++
#include <iostream>
#include <vector>

using namespace std;

//1. COUNT BOARD PATH
int cbp(int src,int dest,int dp[]){
    if(src==dest){
        return 1;
    }
    if(src>dest){
        return 0;
    }
    int ans=0;
    for(int dice=1;dice<=6;dice++){
        int interm=src+dice;
        int midans=cbp(interm,dest,dp);
        ans+=midans;
    }
    dp[src]=ans;
    return ans;
}

//2. COUNT MAZE PATH
int cmp(int sx,int sy, int dx, int dy,int dp2[][100]){
    if(sx>dx || sy>dy){
        return 0;
    }
    if(sx==dx && sy==dy){
        return 1;
    }
    if(dp2[sx][sy]!=0){
        return dp2[sx][sy];
    }
    return dp2[sx][sy]=cmp(sx,sy+1,dx,dy,dp2)+cmp(sx+1,sy,dx,dy,dp2);
}


int main() {
    int n;
    n=20;
    //1.
    int *dp=new int[n+1];
    cout<<cbp(0,n,dp)<<endl;

    //2.
    int dp2[100][100];
    cout<<cmp(0,0,n,n,dp2)<<endl;
}
```
