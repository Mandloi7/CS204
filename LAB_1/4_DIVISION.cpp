#include <bits/stdc++.h>

using namespace std;

int comparison(string a,string b){
    int x = a.size();
    int y= b.size();
    if(y>x){
        return 1;
    }
    else{
        int i=0;
        if(x==y){
            while(a[i]==b[i]){
                i++;
            }
            if(i>x){return 0;}
            if(b[i]>a[i]){
                return 1;
            }
        }
    }
    return 0;
}

string subtract(string a,string b){
 string c;
    int e=0;
    if(comparison(a,b)){
        swap(a,b);
        e=1;
    }

    int m=a.length(),n=b.length();
    int subt=m-n,carry=0;

    for(int i=n-1;i>=0;i--){
        int temp=(a[subt+i]-'0')-(b[i]-'0')-carry;
        if(temp<0){
            temp+=10;
            carry=1;
            c+= to_string(temp);
        }
        else{
            c += to_string(temp);
            carry=0;
        }
    }
    for(int i=subt-1;i>=0;i--){
        if(a[i]=='0'&& carry){
            c += to_string(9);
            continue;
        }
        int temp=(a[i]-'0')-carry;
        if( i>0 || temp>0){
            c += to_string(temp);
        }
    }
    if(e){c.append("-");}

    reverse(c.begin(),c.end());

    return c;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
      string a;
      string b;
      cin>>a;
      cin>>b;
      if(comparison(a,b)){
          cout<<0<<endl<<a;
          
      }
      int x=a.length()-b.length()+1;
      char arr[x];
      for(int i=0;i<x;i++){
          arr[i]='0';
      }
      while(!comparison(a,b)){
          int n=a.length()-b.length();
          string temp=b;
          if(a[0]<b[0]){
              for(int i=1;i<n;i++)temp.push_back('0');
              int u=0;
              while(!comparison(a,temp)){
                   a = subtract(a,temp);
                  u++;
              }
              arr[x-n]=u+'0';
          }
          else{
              for(int i=0;i<n;i++)temp.push_back('0');
              int u=0;
              while(!comparison(a,temp)){
                   a = subtract(a,temp);
                  u++;
              }
              arr[x-1-n]=u+'0';
          }

      }
      int j = 0;
      while(arr[j]=='0'){
          j++;
      }
      for(int i = j;i<x;i++){
              if(arr[i]<49 || arr[i]>58){cout<<'0';}
          else{cout<<arr[i];}
      }
      cout<<endl<<a<<endl;
      
    }
    return 0;
}
