### Tries

```c++
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  bool terminal;
  unordered_map<char,Node*> children;
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
  
  // INSRET
  void insert(string w){
      Node*temp=root;
      for(int i=0;i<w.length();i++){
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
  
  // FIND
    bool find(string w){
        Node*temp=root;
        for(int i=0;i<w.length();i++){
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

int main() {
    vector<string> words={"dog","doggy","doggo"};
    Trie ob;
    for(int i=0;i<words.size();i++){
        ob.insert(words[i]);
    }
    cout<<ob.find("doggo");
}
```
