#include <bits/stdc++.h>
using namespace std;

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

string inpost (string s)
{
	stack<char> a;
	string post = "";

	for(int i=0; i<s.length(); i++)
	{
	    int flag=0;
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

		else if(s[i] == '(')
			a.push(s[i]);

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
            /*if(prec(s[i])==3){
                if()
            }*/
             
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
  
    
    for (int i=0; i<postfix.length(); i++) 
    { 
        if(postfix[i]==' '){continue;}
        
        if (!isOperator(postfix[i]) )
        { 
             
            int z=0;
            for(int j=i;j<postfix.length();j++){
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


int evaluate (struct tr *root)
{
    if(root->left == NULL && root->right == NULL)
		return stoi(root->value);
/*else if(root == NULL)
	{
		cout << "EMPTY, CANNOT BE EVALUATED\n";
		return 0;
	}*/

	
	else
	{
		int r = evaluate(root->right);
		int l = evaluate(root->left);

		    if(root->value=="+"){return l+r;}
		  if(root->value=="-"){return l-r;}
		  if(root->value=="*"){return l*r;}
		  if(root->value=="/"){return l/r;}
		  if(root->value=="^"){return (int)pow(l,r);}
		
	}
}

int main() {
  int t;
    cin >> t;
    while(t){
    
int n;
cin >> n;
while(n){
int i;
for(i=0;i<n;i++){
string a;
string b;
cin >> a;
b=inpost(a);




//cout << b<<"\n";
//CreateTree(b);
struct tr* root=CreateTree(b);
//cout << root->value ;
int ans=evaluate(root);
cout << ans << endl;
n--;
}
}

        t--;
    }


return 0;
}
