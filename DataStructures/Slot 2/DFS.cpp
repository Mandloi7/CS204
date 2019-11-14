//****************DFS*******************
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
2 1 4 3 7 8 5 6

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,m, s; 
vector<vector<lli>> adj; 
vector<bool> visited;

void dfs(lli s){
    if(visited[s]){
        return ;
    }
    visited[s]= true;
    cout << s <<" ";
    for(lli u : adj[s-1]){
        dfs(u);
    };
    
}


int main(){
    cin>>n>>m;
    for(lli i=0;i<n;i++){
        vector<lli> ele;
        adj.push_back(ele);
    };
    visited.resize(n);
    lli a,b;
    for(lli i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
    }
    
    dfs(2);  //Starting vertex is 2
	return 0;
}
