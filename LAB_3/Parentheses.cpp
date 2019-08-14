#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	stack<char> stk;
	
	while(t--){
	    
	    string str;
	    int flag=0,b,i;
	    char x;
	    cin >> str;
	    b=str.size();
	    
	    for(i=0;i<b;i++){
	        
	        if((str[i]=='{')||(str[i]=='[')||(str[i]=='<')||(str[i]=='(')){
	            stk.push(str[i]);
	            continue;
	        }
	        if(str[i]=='}'){
	             if(stk.empty()){
	                 flag=1;
	                 break;
	             }else if(stk.top()!='{'){
	                flag=1;
	                break;
	            } else{
	            stk.pop();
	            continue;
	        }
	    }
	     if(str[i]==']'){
	             if(stk.empty()){
	                 flag=1;
	                 break;
	             }else if(stk.top()!='['){
	                flag=1;
	                break;
	            } else{
	            stk.pop();
	            continue;
	        }
	    }
	     if(str[i]==')'){
	             if(stk.empty()){
	                 flag=1;
	                 break;
	             }else if(stk.top()!='('){
	                flag=1;
	                break;
	            } else{
	            stk.pop();
	            continue;
	        }
	    }
	     if(str[i]=='>'){
	             if(stk.empty()){
	                 flag=1;
	                 break;
	             }else if(stk.top()!='<'){
	                flag=1;
	                break;
	            } else{
	            stk.pop();
	            continue;
	        }
	    }
	      
	 
	         if(str[i]=='|'){
	             if(stk.empty()){
	                 stk.push(str[i]);
	             }else{
	                 x=stk.top();
	                   if(x!='|'){
                stk.push(str[i]);
                continue;
            }
        else{
            stk.pop();
            continue;
            }
	             }
	         }
	       
	        }
 
	    
	 if((flag==1) ||(stk.empty()==0)){
	     cout << "NO\n";
	 }  else{
	     cout << "YES\n";
	 }
	    
	}
	return 0;
}
