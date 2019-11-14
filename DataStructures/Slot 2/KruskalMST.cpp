//**************KRUSKAL******************
/*
Sample Input:
8 11
1 2 6
2 3 6
4 2 7
3 4 9
1 4 8
1 3 2
7 8 9
1 7 6
6 5 9
3 4 6
5 1 6

Output:
Edges in our MST are :
Edge 1 : 1 3
Edge 2 : 1 2
Edge 3 : 1 7
Edge 4 : 3 4
Edge 5 : 5 1
Edge 6 : 6 5
Edge 7 : 7 8
Minimum Sum Of Weights : 44
*/






#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
unordered_map <lli,lli> parent;
unordered_map <lli,lli> Rank;
lli v,e;
void make(){
    for(lli i=1;i<=v;i++){
        parent[i]=i;
        Rank[i]=0;
    }
}
lli find(lli a){
    if(parent[a]!=a){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}
void Union(lli a,lli b){
    if(find(a)==find(b)) return;
    lli irep=find(a);
    lli jrep=find(b);
    if(Rank[irep]>Rank[jrep]){
        parent[jrep]=irep;
    }else{
        parent[irep]=jrep;
    }
    if(Rank[irep]==Rank[jrep]){
        Rank[jrep]++;
    }
}
int main() {
   cin >>v>>e;
   vector<pair<lli,pair<lli,lli>>>edges;
   for(lli i=0;i<e;i++){
       lli a,b,c;
       cin >> a>>b>>c;
       pair <lli,lli> ed;
       ed = make_pair(a,b);
       edges.push_back(make_pair(c,ed));
   }
   sort(edges.begin(),edges.end());
   make();
   lli p=0,k=1;
   cout << "Edges in our MST are :\n";
   for(lli i=0;i<e;i++){
       lli a=edges[i].second.first;
       lli b=edges[i].second.second;
       lli w=edges[i].first;
       if(find(a)!=find(b)){
           Union(a,b);
           cout <<"Edge "<<k<<" : "<< a <<" "<< b <<endl;
           k++;
           p+=w;
       }
   }
  cout << "Minimum Sum Of Weights : "<<p<<endl;
	return 0;
}
