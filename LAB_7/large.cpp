#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

    
int main() {
lli t;
cin >> t;
while(t--){
    lli i,n,j;
    cin >> n;
    string s[n],a[n];
    lli max=0;
    
    for(i=0;i<n;i++){
                     cin >> s[i];
                     a[i]=s[i];
                     if(s[i].size()>max){
                                         max=s[i].size();
                                      }
                    }
                    
    for(j=0;j<n;j++){
    for(i=0;((a[j].size())*pow(2,i))<=max+1;i++){
                                                s[j]+=s[j];
                                               }
                                               s[j]=s[j].substr(0,max+1);
                    }
                   
     vector <pair <string,string>> vect;
      for (i=0; i<n; i++) {
                             vect.push_back( make_pair(s[i],a[i]));
                          }
                          
                          
      sort(vect.begin(),vect.end());
      
      for (i=n-1; i>=0; i--) {
                             cout << vect[i].second ;
                          }
      cout << endl;
      
                        
}
	return 0;
}
