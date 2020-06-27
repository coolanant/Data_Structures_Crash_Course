```c++
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Minimum length of wire requires 
int connectDotsWithWires(vector<int> whites, vector<int> blacks){
    int sum=0;
    sort(whites.begin(),whites.end());
    sort(blacks.begin(),blacks.end());
    for(int i=0;i<whites.size();i++){
        sum+=abs(whites[i]-blacks[i]);
    }
    return sum;
}

int main() {
    vector<int> whiteDotPos={3,4,1};
    vector<int> blackDotPos={2,5,6};
    cout<<connectDotsWithWires(whiteDotPos,blackDotPos);
}
```
