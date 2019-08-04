#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    
    cin >> t;
    
    
    while(t--){
        
	string A,B;
	
	cin >> A >>B;
	
	int i,j,m=0,carry=0;
	
vector<int> a,b;

vector<int> ans ;

for(i=A.size()-1;i>=0;i--){
    
    a.push_back(A[i]-48);
    
}



for(i=B.size()-1;i>=0;i--){
    
    b.push_back(B[i]-48);
    
}


for(i=0;i<=(A.size()+B.size());i++){
    
   ans.push_back(0) ;
   
}

for(i=0;i<A.size();i++){
    
   for(j=0;j<B.size();j++){
    
         ans[i+j]+=a[i]*b[j];
         
        ans[i+j+1]+=ans[i+j]/10;
        
        ans[i+j]%=10;
        
   } 
   


}

for(i=((A.size()+B.size())-1);i>=0;i--){
    
    cout << ans[i] ;
    
}


cout << endl ;

}

return 0;



}
