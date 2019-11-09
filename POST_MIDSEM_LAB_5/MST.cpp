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
   sort(edges.begin(),edges.end(), greater<>());
   make();
   lli p=1;
   for(lli i=0;i<e;i++){
       lli a=edges[i].second.first;
       lli b=edges[i].second.second;
       lli w=edges[i].first;
       if(find(a)!=find(b)){
           Union(a,b);
           p*=(w%mod);
           p%=mod;
       }
   }
  cout << p<<endl;
	return 0;
}
