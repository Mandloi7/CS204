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
    if(head == NULL) return;
    Node* TEMP = head;
    head = head->next;
    delete TEMP;
    TEMP=NULL; 
}

void Del(int x, int y){
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL){
        if((current->x == x)&& (current->y == y)){
            
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
    cout << "NO SUCH POINT\n";
}

void Search(float d){
    Node* current = head;
    int x,y,FLAG=0;
    while(current != NULL){
        x = current->x;
        y = current->y;
        float dSquare = x * x + y * y;
        if(dSquare <= d * d){
            cout << "(" << x << "," << y << ") ";
            FLAG =1;
        }
       
        current = current->next;
    }
    if(FLAG==0){ cout << "THERE ARE NO SUCH POINTS";}
    cout << endl;
    
}

bool Search(int x, int y){
    Node* current = head;

    while(current != NULL){
        if((current->x == x )&& (current->y == y))
          
  return true;
       
        current = current->next;
    }

    return false;
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
