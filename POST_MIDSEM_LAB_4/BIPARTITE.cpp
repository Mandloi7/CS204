#include <bits/stdc++.h> 
using namespace std; 
int cnt=1;

void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 


bool isBipartite(vector<int> adj[], int v, 
				vector<bool>& visited, vector<int>& color) 
{ 

	for (int u : adj[v]) { 

		 
		if (visited[u] == false) { 

			
			visited[u] = true; 
            cnt++;
			 
			color[u] = !color[v]; 

			
			if (!isBipartite(adj, u, visited, color)) 
				return false; 
		} 

		
		else if (color[u] == color[v]) 
			return false; 
	} 
	return true; 
} 


int main() 
{ 
	
	int V,E;
	cin >>V>>E; 
	vector<int> adj[V + 1];
	vector<bool> visited(V + 1); 
	vector<int> color(V + 1); 
	int n1,n2;
	for(int i=0;i<E;i++){
		cin>>n1>>n2;
		addEdge(adj,n1,n2);
	}
	visited[1] = true; 
	color[1] = 0; 
	int	flag=0;
    if (isBipartite(adj, 1, visited, color)) { 
	
	} 
	else { 
		cout << "NO\n"; 
		return 0;
	} 
	
	//int flag=0;
//	cout << cnt <<" ";
	if(cnt!=V){
	for(int i=2;i<=V;i++){		// FOR DISCONNECTED GRAPH
	if(visited[i] && i!=1){
	        continue;
	    }
	if (isBipartite(adj, i, visited, color)) { 
		continue;
	} 
	else { 
		cout << "NO\n"; 
		flag=1;
		break;
	} 
	}
	if(flag==0){
		cout << "YES\n";	
	}
	}
	else{
	    cout << "YES\n";
	}
//	cout << cnt;
	return 0; 
} 
