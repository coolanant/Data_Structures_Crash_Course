```c++
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void coin_change(vector<int> coins,int money){
    int count=0;
    while(money>0){
        vector<int>::iterator it;
        it=upper_bound(coins.begin(),coins.end(),money);
        it--;
        cout<<*it<<" ";
        money=money-*it;
        count++;
    }
    cout<<endl<<count;
}

int main() {
    vector<int> coins={1,2,5,10,20,50,100,500,1000,2000};
    int money=15;
    coin_change(coins,money);
}
```
