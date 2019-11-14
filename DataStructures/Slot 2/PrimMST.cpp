//**************PrimMST******************

#include <bits/stdc++.h> 
using namespace std; 
const int V= 5  ;
long long int sum=0;
int minKey(int key[], bool mstSet[])  
{  
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  

void printMST(int parent[], int graph[V][V])  
{  
    for (int i = 1; i < V; i++)  
    {
        cout<<"Edge "<<i<<" : "<< parent[i]<<" "<<i<<" | Weight : "<<graph[i][parent[i]]<<" \n"; 
        sum+=graph[i][parent[i]];
    }
}  
  
void primMST(int graph[V][V])  
{  
   
    int parent[V];  
    int key[V];  
    bool mstSet[V];  
   
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;   
    key[0] = 0;  
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++) 
    {  
    
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  
        for (int v = 0; v < V; v++)  
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
        }
    }  
    printMST(parent, graph);  
}  
int main()  
{  
    int graph[V][V] = { { 0, 21, 0, 63, 0 },  
                        { 82, 0, 13, 48, 51 },  
                        { 0, 38, 0, 0, 67 },  
                        { 65, 88, 0, 0, 91 },  
                        { 0, 45, 57, 99, 0 } };  
    primMST(graph);  
    cout<<endl<<"Minimum Sum of Weights : "<<sum<<endl;
  
}  

/*
Output:

Edge 1 : 0 1 | Weight : 82 
Edge 2 : 1 2 | Weight : 38 
Edge 3 : 1 3 | Weight : 88 
Edge 4 : 1 4 | Weight : 45 

Minimum Sum of Weights : 253
*/
