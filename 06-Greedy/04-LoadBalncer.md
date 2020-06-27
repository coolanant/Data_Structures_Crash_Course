 ```c++
 #include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

// min ways to give avg allocation to all
// can transfer one at a time, to the adjacent blocks, i.e 2 for non-corner ones
int loadBalancer(vector<int> processor){
    int sum1,sum2,max=-1,avg=0;
    for(int j=0;j<processor.size();j++){
            avg+=processor[j];
    }
    avg=avg/processor.size();
    for(int i=1;i<processor.size();i++){
        int shouldbe=avg*i;
        sum1=sum2=0;
        for(int j=0;j<i;j++){
            sum1+=processor[j];
        }
        if(abs(shouldbe-sum1)>max){
            max=abs(shouldbe-sum1);
        }
    }
    return max;
}
int main() {
    vector<int> processor={6,0,0,10};
    cout<<loadBalancer(processor);
}
 ```
