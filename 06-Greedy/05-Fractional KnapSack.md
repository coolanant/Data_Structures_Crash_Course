```c++
#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

// Fractional Knapsack
int fknapsack(vector<int> p,vector<int> w, int cap){
    vector<int> x(p.size(),0);
    for(int i=0;i<p.size();i++){
        x[i]=p[i]/w[i];
    }
    map<int,int> m;
    for(int i=0;i<x.size();i++){
        m[x[i]]=i;
    }
    sort(x.begin(),x.end(),cmp);
    int ans=0;
    int i=0;
    while(cap>0){
        int index=m[x[i]];
        if(w[index]<=cap){
            ans+=p[index];
        }else{
            ans+=(p[index] * cap/w[index] );
        }
        cap=cap-w[index];
        i++;
    }
    return ans;
}

int main() {
    vector<int> p={280,100,120,120};
    vector<int> w={40,10,20,24};
    int cap=60;
    
    cout<<fknapsack(p,w,cap);
}

// https://www.tutorialspoint.com/design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_fractional_knapsack.htm
```
