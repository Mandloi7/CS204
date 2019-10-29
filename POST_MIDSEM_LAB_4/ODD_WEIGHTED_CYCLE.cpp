#include <bits/stdc++.h> 
using namespace std; 


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
	int k=V,j=V;
	vector<int> adj[2*k+1];
	
	int n1,n2,w;
	for(int i=0;i<E;i++){
		cin>>n1>>n2>>w;
		if(w%2){
		addEdge(adj,n1,n2);
		}else{
		    addEdge(adj,n1,j+1 );
		    addEdge(adj,j+1 ,n2);
		    V++;
		    j++;
		}
	}
	vector<bool> visited(V + 1); 
	vector<int> color(V + 1); 
	visited[1] = true; 
	color[1] = 0; 

	int flag=0;
	for(int i=1;i<=V;i++){		// FOR DISCONNECTED GRAPH
	if(visited[i] && i!=1){
	        continue;
	    }
	if (isBipartite(adj, i, visited, color)) { 
		continue;
	} 
	else { 
		cout << "YES\n"; 
		flag=1;
		break;
	} 
	}
	if(flag==0){
		cout << "NO\n";	
	}
	return 0; 
} 
