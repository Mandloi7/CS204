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
    if(head == nullptr) return;
    Node* TEMP = head;
    head = head->next;
    delete TEMP;
            TEMP->next=NULL; 
}

void Del(int x, int y){
    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr){
        if((current->x == x)&& (current->y == y)){
            
            if(prev == nullptr){
                DelFirst();
                return;
            }

            prev->next = current->next;

            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

void Search(float d){
    Node* current = head;
    int x,y;
    while(current != nullptr){
        x = current->x;
        y = current->y;
        float dSquare = x * x + y * y;
        if(dSquare <= d * d){
            cout << "(" << x << "," << y << ") ";
        }
       
        current = current->next;
    }
    cout << endl;
}

bool Search(int x, int y){
    Node* current = head;

    while(current != nullptr){
        if((current->x == x )&& (current->y == y))
          
  return true;
       
        current = current->next;
    }

    return false;
}
long long Length(){
    Node* current = head;
    long long size = 0;
    while(current != nullptr){
        current = current->next;
        size++;
    }

    return size;
}





int main(){

struct Node* head=NULL;
int t;
cin >> t;
while(t--){
int a,x,y;
float d;
long long s;
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
  if(Search(x,y)){
   cout << "True\n";   
  }else{cout << "False\n";}
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