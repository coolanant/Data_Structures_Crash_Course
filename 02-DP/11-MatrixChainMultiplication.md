```c++
#include <iostream>
#include<vector>
#include<climits>
using namespace std;


// 1. Memorization
int mcm(vector<int> dims,int s,int e,int dp[][100]){
    if(e-s==1){
        return 0;
    }
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int i=s+1;i<=e-1;i++){
        int x=mcm(dims,s,i,dp);
        int y=mcm(dims,i,e,dp);
        int z=dims[s]*dims[e]*dims[i];

        int total=x+y+z;
        if(ans>total){
            ans=total;
        }
    }
    return dp[s][e]=ans;
}

//2. tabulated
int mcm2(vector<int> dims){
    vector<vector<int> > dp(dims.size(),vector<int>(dims.size()));
    //diagonally
    for(int gap=1;gap<dims.size();gap++){
        int i=0,j=gap;
        while(j<dims.size()){
            if(gap==1){
                dp[i][j]=0;
            }
            else{
                int min= INT_MAX;
                for(int cp=i+1;cp<=j-1;cp++){
                    int x=dp[i][cp];
                    int y=dp[cp][j];
                    int z=dims[i]*dims[cp]*dims[j];
                    int total=x+y+z;
                    if(total<min){
                        min=total;
                    }
                    dp[i][j]=min;
                }
            }
            i++;
            j++;

        }
    }
    return dp[0][dims.size()-1];
}

int main() {
    vector<int> dims={10,20,30,40,50,60};

    int dp[100][100]={0};
    cout<<mcm(dims,0,dims.size()-1,dp)<<endl;
    cout<<mcm2(dims);
}
```
