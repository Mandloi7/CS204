#include <bits/stdc++.h>
using namespace std;

struct tr{
    char value;
    tr *left,*right ;
};

 struct tr* newNode(char a){
    tr* tp=new tr;
    tp->left=NULL;
    tp->right=NULL;
    tp->value=a;
    return tp;
}

bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
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

string ToPostfix(string s) 
{ 
    stack<char> st; 
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(isdigit(s[i]) )
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.top() != 'N' && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != 'N' && prec(s[i]) >= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    } 
      
 return ns;
  
} 


tr* CreateTree(string postfix) 
{ 
    stack<tr *> st; 
    tr *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.length(); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int evaluate(tr* node){
    if(!isOperator){
        return node->value;
    }else{
        int val;
        int l=evaluate(node->left);
        int r=evaluate(node->right);
        switch (node->value){
            case '+' : 
            val=l+r ;
            break;
            case '-' : 
            val=l-r ;
            break;
            case '*' : 
            val=l*r ;
            break;
            case '/' : 
            val=l/r ;
            break;
            case '^' : 
            val=l^r ;
            break;
            
        }
    }
} 
int main() {
    int t;
    cin >> t;
    while(t--){
    
int n;
cin >> n;
string a[n];
string b[n];
int i;
for(i=0;i<n;i++){
cin >> a[i];
b[i]=ToPostfix(a[i]);

tr* root=CreateTree(b[i]);
int ans=evaluate(root);
cout << ans << endl;


}
}
	return 0;
}
