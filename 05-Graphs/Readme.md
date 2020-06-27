### Graphs

```c++
#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<map>
#include<climits>
using namespace std;

// template<typename T>

class Graph{
    map<int,list<int> > l;//unweighted graph
    public:
    
    // 1. Add Edge
    void addEdge(int x,int y, bool bidir=true){
        l[x].push_back(y);
        if(bidir){
            l[y].push_back(x);
        }
    }
    
    // 2. Print AdjList
    void printAdjList(){
        for(auto it:l){
            cout<<it.first<<"-->";
            for(auto nbr:l[it.first]){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
    
    // 3. BFS
    void bfs(int src){
        queue<int> q;
        map<int, bool> visited;
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            int val=q.front();
            q.pop();
            cout<<val<<" ";
            for(auto nbr:l[val]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
            
        }
    }
    
    // 4. BFS - Shortest Path
    void bfs_shortest_path(int src,int dest){
        queue<int> q;
        map<int, int> dist;
        map<int, int> parent;
        
        for(auto it:l){
            dist[it.first]=INT_MAX;
        }
        
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto nbr:l[val]){
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    dist[nbr]=dist[val]+1;
                    parent[nbr]=val;
                }
            }
        }
        int temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src<<'\n';
        
        cout<<dist[dest];
    }
    
    // 5. DFS
    void dfsHelper(int val, map<int,bool> &dfs_visited){
        dfs_visited[val]=true;
        cout<<val<<"->";
        
        for(auto nbr:l[val]){
            if(!dfs_visited[nbr]){
                dfsHelper(nbr,dfs_visited);
            }
        }
    }
    void dfs(int src){
        map<int,bool> dfs_visited;
        dfsHelper(src,dfs_visited);
    }
    
    // 6. DFS - more than 2 components
    
    // 7. Tropological Sort
    
    // 8. Cycle Detection
    
    // 9. Dijkstra's
    
    // 10. Bellman
    
    // 11. MST- Prim's & Kruskal
    
    // 12. Floyd Warshall
};

int main() {
    //Snakes and Ladder
    int board[50]={0};
    
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[25]=10;
    
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[32]=-2;
    board[34]=-22;
    
    Graph g;
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j+=board[j];
            if(j<=36){
                g.addEdge(i,j,false);
            }
        }
    }
    g.addEdge(36,36);
    
    // g.bfs(0);
    // g.bfs_shortest_path(0,36);
    // g.printAdjList();
    g.dfs(0);
}
```
