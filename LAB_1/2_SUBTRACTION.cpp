#include <bits/stdc++.h>
using namespace std;

int main() {
	

	string a,b;
	
	int i,m;

	int ak=0,bk=0,j;

	int t;

	cin >> t;
	
while(t--){

	cin >> a >> b;

ak=0;
bk=0;
	if(a.size()>b.size())
	{
m=a.size();}
	else {
m=b.size();}

	reverse(a.begin(),a.end());

	reverse(b.begin(),b.end());


	int c[m];
	
	if(a.size()==b.size()){
	    
	    
	   for(i=m-1;i>=0;i--){
	       
	       
	       if(a[i]>b[i]){
	           ak++;
	           break;
	       } 
	       
	        
	       if(a[i]<b[i]){
	           bk++;
	           break;
	       } 
	       
	       
	       
	       
	       
	       
	   } 
	    
}

	if((a.size()>b.size())||(ak==1))
	{


	    
	  
	for(i=0;i<b.size();i++){


	    
					  if(a[i]>=b[i]){
								c[i]=a[i]-b[i];
								}


						  if(a[i]<b[i]){
	    
  
	  							    if(a[i+1]!='0'){
	   
  											 a[i+1]=a[i+1]-1;
	
   											   a[i]=a[i]+10;
	
    											  c[i]=a[i]-b[i];
	
   										   }

	      
 								    if(a[i+1]=='0'){

	    										  j=i;

	     										  while(a[j+1]=='0'){

										          			 a[j+1]='9';
	 
        											 		 j++;
	 
   													    }


	    										   a[j+1]=a[j+1]-1;
	  
     										           a[i]=a[i]+10;
	   
   										           c[i]=a[i]-b[i];
	  
        
	                                                                   }
	  
    
							       }
	
    
						}
	

				for(i=b.size();i<a.size();i++){
	  
				 				 c[i]=a[i]-48;

			    				      }
	




	
		for(i=a.size()-1;i>=0;i--){

				cout << c[i]; 
		
			  }
	
		
		cout << endl; 

				
	}
	    
	    
	

if((b.size()>a.size())||(bk==1))
	{


	    int c[m];
	  
	for(i=0;i<a.size();i++){


	    
					  if(b[i]>=a[i]){
								c[i]=b[i]-a[i];
								}


						  if(b[i]<a[i]){
	    
  
	  							    if(b[i+1]!='0'){
	   
  											 b[i+1]=b[i+1]-1;
	
   											   b[i]=b[i]+10;
	
    											  c[i]=b[i]-a[i];
	
   										   }

	      
 								    if(b[i+1]=='0'){

	    										  j=i;

	     										  while(b[j+1]=='0'){

										          			 b[j+1]='9';
	 
        											 		 j++;
	 
   													    }


	    										   b[j+1]=b[j+1]-1;
	  
     										           b[i]=b[i]+10;
	   
   										           c[i]=b[i]-a[i];
	  
        
	                                                                   }
	  
    
							       }
	
    
						}
	

				for(i=a.size();i<b.size();i++){
	  
				 				 c[i]=b[i]-48;

			    				      }

	
		for(i=b.size()-1;i>=0;i--){

				cout << c[i]; 
		
			  }
	
		
		cout << endl; 

				
				}
}
	
return 0;


}