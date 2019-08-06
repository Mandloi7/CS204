#include <bits/stdc++.h>

using namespace std;

int main(){


	long long int t;

	cin>>t;
	

while(t--){
	

		long long int n,i,g;

		g=0;
	
		cin>>n;
		

		for(i=2;i<=sqrt(n);i++){

					if(n % i==0){
	
							cout<<"Not a prime\n";

							g=1;
	
							break;
	
						    }
	
				       }

	
	if(g==1){

		continue;

		}
	
	if(n==1){

		    cout<<"Not a prime\n";

		}
		else
		{
		
		cout<<"Prime\n";
	
		}

	
	  }



return 0;

}
