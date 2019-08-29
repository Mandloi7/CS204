#include <bits/stdc++.h>
using namespace std;
vector <string> var;
vector <string> value;
struct tr{
    string value;
    tr *left,*right ;
};

 struct tr* newNode(string a){
    tr* tp=new tr;
    tp->left=NULL;
    tp->right=NULL;
    tp->value=a;
    return tp;
}

bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*'|| c =='/' || 
            c == '^') 
        return true; 
    return false; 
} 
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

string PF(string s)
{
	stack<char> a;
	string post = "";

	for(long long int i=0; i<s.length(); i++)
	{
	    long long int flag=0;
		if(s[i] >= '0' && s[i] <= '9')
			{
				while(s[i] >= '0' && s[i] <= '9')
				{
					post += s[i];
				i++;
				}

				post += " ";
				i--;
			}

		else if(s[i] == '('){
			a.push(s[i]);
			if(s[(i+1)]=='-'){
			    post+="0";
			    post+=" ";
			}
		}

		else if(s[i] == ')')
		{
			while(a.empty() == 0 && a.top() != '(')
			{
				post += a.top();
				a.pop();
			}

			if(a.top() == '(')
			{
			
				a.pop();
			}
		}

		else
		{
		    if(prec(s[i])==3&&(a.empty()==0)&&(prec(a.top())==3)){
                    a.push(s[i]);
                    
                    continue;
            }
             
			while((a.empty() == 0) && (prec(s[i]) <= prec(a.top()))) 
            { 
                //cout << "ljvk" ;
                char c = a.top(); 
                a.pop(); 
                post += c;
                post += " ";
            } 
         
             
            a.push(s[i]); 
		}
		
	}

		while(a.empty() == 0) 
    { 
        char c = a.top(); 
        a.pop(); 
        post += c; 
        post += " ";
    } 
	
	return post;
}

tr* CreateTree(string postfix) 
{ 
    stack<tr *> st; 
    tr *t, *t1, *t2; 
  
    
    for (long long int i=0; i<postfix.length(); i++) 
    { 
        if(postfix[i]==' '){continue;}
        
        if (!isOperator(postfix[i]) )
        { 
             
           long long  int z=0;
            for(long long int j=i;j<postfix.length();j++){
                if(postfix[j]>=48 && postfix[j]<=57){
                    i=j;
                    z=10*z+postfix[j]-48;
                }
                else{
                    break;
                }
            }
            //cout << z << "\n";
            string g=to_string(z);
            t=newNode(g);
            st.push(t);
            continue;
        } 
        else
        { 
            string st2(1,postfix[i]);
            t = newNode(st2); 
  
             
            t1 = st.top();  
            st.pop();      
            t2 = st.top(); 
            st.pop(); 
  
             
            t->right = t1; 
            t->left = t2; 
  
             
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 


long long int evaluate (struct tr *root)
{
    if(root->left == NULL && root->right == NULL)
		return stoll(root->value);
/*else if(root == NULL)
	{
		cout << "EMPTY, CANNOT BE EVALUATED\n";
		return 0;
	}*/

	
	else
	{
	long long	int r = evaluate(root->right);
	long long	int l = evaluate(root->left);

		    if(root->value=="+"){return l+r;}
		  if(root->value=="-"){return l-r;}
		  if(root->value=="*"){return l*r;}
		  if(root->value=="/"){return l/r;}
		  if(root->value=="^"){return (long long int)pow(l,r);}
		
	}
}



bool assign(string s){
    for(long long int i=0;i<s.size();i++){
        if(s[i]=='='){
            return true;
        }
    }
    return false;
}
long long int findequal(string s){
    for(long long int i=0;i<s.size();i++){
        if(s[i]=='='){
            return i;
        }
    }
}
string leftt(string s){
    long long int i=findequal(s);
    long long int sz=s.size();
    string l = s.substr(0,i);
    return l;
}
string rightt(string s){
    long long int i=findequal(s);
    long long int sz=s.size();
    string r = s.substr(i+1,sz-i-1);
    return r;
}
void vecstore(string s,long long int rvalue){
    int flag=0;
    long long int vs=var.size();
    for(long long int i=0;i<vs;i++){
        if(s==var[i]){
            value[i]="("+to_string(rvalue)+")";
            flag=1;
            break;
        }
    }
    if(flag==0){
        var.push_back(s);
        value.push_back("("+to_string(rvalue)+")");
    }
}
bool ifallnumbers(string s){
    long long int i=s.size();
    for(long long int j=0;j<i;j++){
        if(isalpha(s[j])){
            return false;
        }
    }
    return true;
}

void repvar(string *s,string tosearch,string rep){
 
    long long int pos;
    pos=(*s).find(tosearch);
    while(pos!=string::npos){
        (*s).replace(pos,tosearch.size(),rep);
        pos=(*s).find(tosearch,pos+rep.size());
    }
    
}
long long int findrvalue(string s){
    string p= PF(s);
    tr* tree=CreateTree(p);
    long long int v=evaluate(tree);
    return v;
}



int main() {
 long long  int t;
    cin >> t;
    while(t--){
    
long long int n;
cin >> n;
long long int i;
for(i=0;i<n;i++){
string a;
cin >> a;
if(assign(a)){
    string ll=leftt(a);
    string rr= rightt(a);
    long long int  rv;
    
        if(ifallnumbers(rr)){
    rv=findrvalue(rr);
        }else{
        
        for(long long int i=0;i<var.size();i++){
            repvar(&rr,var[i],value[i]);
        }
        
        rv=findrvalue(rr);
        }

    vecstore(ll,rv);
    
}

else{
    for(long long int i=0;i<var.size();i++){
        repvar(&a,var[i],value[i]);
    }
    if(ifallnumbers(a)){
    long long int ans=findrvalue(a);
 
    cout << ans<< endl;}
    else{
        cout <<"CANNOT BE EVALUATED!\n";
    }
}
}


       var.clear();
       value.clear();
    }


return 0;
}
