### Tries

```c++
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char d){
        data=d;
        terminal=false;
    }
};

class Trie{
    Node*root;
    public:
    Trie(){
        root=new Node('\0');
    }
    // 1. INSERT
    void insert(string w){
        Node*temp=root;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                Node *n=new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }

    // 2. Find
    bool find(string w){
        Node*temp=root;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp=temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main(){
    vector<string> words={"no","apple","nose"};
    Trie ob;
    for(int i=0;i<words.size();i++){
        ob.insert(words[i]);
    }
    string w;
    cin>>w;
    cout<<ob.find(w);
    return 0;
}
```
