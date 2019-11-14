/*
************QUEUE**************


sample input : 8

Output:
1 2 3 4 5 6 7 8 
4 5 6 7 8 
EMPTY !!
EMPTY !!
EMPTY !!
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct node {
  lli x;
  struct node* ptr;
};
struct node* head=NULL;

node* create(lli t){
    node* temp= new node;
    temp->x=t;
    temp->ptr=NULL;
    return temp;
}

void insertlast(lli t){
    node* temp=create(t);
    temp->ptr=NULL;
    node* temp1=head;
    node* prev;
    if(head==NULL){
        head=temp;
        return;
    }
    while(temp1!=NULL){
        prev=temp1;
        temp1=temp1->ptr;
    }
    prev->ptr=temp;
}

void print(){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->x << " ";
        temp=temp->ptr;
    }
    cout << "\n";
}

void DeleteFirst(){
    node* temp=head;
    if(head==NULL){
        return;
    }else{
        head=head->ptr;
        free(temp);
    }
}

bool isempty(){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}



void enqueue(lli t){
    insertlast(t);
}
void dequeue(){
    if(isempty()){
        cout << "EMPTY !!\n";
    }
    DeleteFirst();
}
int main(){
    lli n;
    cin >> n;
    for(lli i=1;i<=n;i++){
        enqueue(i);
    }
    print();
    dequeue();
    dequeue();
    dequeue();
    print();
    for(lli i=1;i<=n;i++){
        dequeue();
    }
    print();
}
