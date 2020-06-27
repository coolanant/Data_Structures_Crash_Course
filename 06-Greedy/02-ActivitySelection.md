```c++
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

// select max n. of activities-
// 1. Sort activity acc to finish time
// 2. Select first activity
// 3. For remaining, if `start time` >= `finish time` of prev activity -> then select it.

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second < p2.second;
}

void activitySelection(vector<pair<int,int> > v){
    int counter=1;
    sort(v.begin(),v.end(),compare);
    cout<<v[0].first<<"->"<<v[0].second<<endl;
    for(int i=1;i<v.size();i++){
        if(v[i].first>=v[i-1].second){
            counter++;
            cout<<v[i].first<<"->"<<v[i].second<<endl;
        }
    }
    cout<<counter;
}

int main() {
    vector<pair<int,int> > v;
    v.push_back(make_pair(7,9));//start,end
    v.push_back(make_pair(0,10));
    v.push_back(make_pair(4,5));
    v.push_back(make_pair(8,9));
    v.push_back(make_pair(4,10));
    v.push_back(make_pair(5,7));
    
    activitySelection(v);
}
```
