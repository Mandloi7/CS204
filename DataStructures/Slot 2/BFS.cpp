//*****************BFS****************
/*
Sample Input :
8 11
1 2 
2 3 
4 2 
3 4 
1 4 
1 3 
7 8 
1 7 
6 5 
3 4 
5 1 

Output:
1 2 4 3 7 5 8 6 
*/



#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n,m, s; 
vector<vector<lli>> adj;  
queue<lli> q;
vector<bool> visited;
vector<lli> d, p;
//dn for distance from s and pn for storing parent 

void bfs(lli s){
    q.push(s-1);
    visited[s-1] = true;
    p[s-1] = -1;
    while (!q.empty()) {
        lli v = q.front();
        q.pop();
        cout << v+1 <<" ";
        for (lli u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    for(lli i=0;i<n;i++){
        vector<lli> ele;
        adj.push_back(ele);
    };
    visited.resize(n);
    p.resize(n);
    d.resize(n);
    lli a,b;
    for(lli i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bfs(1);
	return 0;
}

