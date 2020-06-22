```c++
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Tabulated
void palindrome(string str){
    vector<vector<bool> > pal(str.length()+1,vector<bool>(str.length()+1));
    int counter=0;
    //moving diagonally
    for(int d=0;d<str.length();d++){
        int s=0;
        int e=d;//end is going from 0 -> n
        while(e<str.length()){
            if(d==0){
                pal[s][e]=true;
                counter++;
            }
            else if(d==1){
                if(str[s]==str[e]){
                     pal[s][e]=true;
                     counter++;
                }
            }
            else{
                 if(str[s]==str[e] && pal[s+1][e-1]==true){
                     pal[s][e]=true;
                     counter++;
                }
            }
            s++;
            e++;
        }
    }
    cout<<counter;
}

int main() {
    string s="abccbc";
    palindrome(s);
}
```
