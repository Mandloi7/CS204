#include <bits/stdc++.h>
using namespace std;

struct Node {
int x;
int y;
struct Node *next;
};

struct Node* head=NULL;


void Addfirst(int x, int y){
    Node* TEMP = new Node;
    TEMP->x = x;
    TEMP->y = y;
    TEMP->next = head;
    head = TEMP;
}

void DelFirst(){
    if(head == NULL) {
        cout << -1 << endl;
        return;
    }
    Node* TEMP = head;
    head = head->next;
    delete TEMP;
    TEMP=NULL; 
}

void Del(int x, int y){
    Node* current = head;
    Node* prev = NULL;
    int FLAG=0;
    while(current != NULL){
        if((current->x == x)&& (current->y == y)){
            FLAG=1;
            if(prev == NULL){
                DelFirst();
                return;
            }

            prev->next = current->next;

            delete current;
            current = NULL;
            return;
        }

        prev = current;
        current = current->next;
    }
  if(FLAG==0){  cout << -1 <<endl;}
}

void Search(float d){
    Node* current = head;
    int x,y,FLAG=0,c=0;
    while(current != NULL){
        x = current->x;
        y = current->y;
        float dSquare = x * x + y * y;
        if(dSquare <= d * d){
           c++;
            FLAG =1;
        }
       
        current = current->next;
    }
    if(FLAG==0){ cout << -1<< endl;}
    if(FLAG==1){cout << c << endl;}
    
}

void Search(int x, int y){
    Node* current = head;
    int FLAG=0;
    while(current != NULL){
        if((current->x == x )&& (current->y == y)){
            cout << "True\n";
            FLAG=1;
            break;
        }
        current = current->next;
    }
    if(FLAG==0){ cout << "False\n";}
    
}
long long Length(){
    Node* current = head;
    long long size = 0;
    while(current != NULL){
        size++;
        current = current->next;
    }

    return size;
}





int main(){
int a,x,y;
float d;
long long s;
int t;
cin >> t;
while(t--){

cin >> a;
switch(a){

case 1:
  cin >> x >> y;
  Addfirst(x,y);
  break;

case 2:
  DelFirst();
  break;

case 3:
  cin >> x >> y;
  Del(x,y);
  break;
case 4:
  cin >> d;
  Search(d);
  break;

case 5:
  cin >> x >> y;
  Search(x,y);
  break;

case 6:
  s=Length();
  cout << s << endl;
  break;
  
  
default : 
  cout << "WRONG COMMAND" << endl;
  break;
}

}

return 0;
}
