//******************Tree_With_Variable_Arity***************

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
	struct node *next;
	struct node *prev;
	struct treenode *child;
};

struct treenode {
	ll key;
	struct node *sent;
	struct treenode *parent;
};

struct treenode* helpnode;
ll helpflag;

struct node *createNode(){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->next=temp;
	temp->prev=temp;
	temp->child=NULL;
	return temp;
}

struct treenode *createtreenode(){
	struct treenode *temp=(struct  treenode *)malloc(sizeof(treenode));
	temp->sent=createNode();
	temp->parent=NULL;
	return temp;
}


void insert(struct treenode *parent, ll k1){
	struct treenode *temp=createtreenode();
	temp->key=k1;
	struct node * temp2=createNode();
	temp2->child=temp;
	temp2->next=(parent->sent)->next;
	temp2->prev=parent->sent;
	(temp2->next)->prev=temp2;
	(parent->sent)->next=temp2;
	temp->parent=parent;
}
ll finde;
void findKeyAssist(struct treenode *root, ll k1){
	if(finde==1)return;
	if(root->key == k1){finde=1;return;}
	struct node *temp=(root->sent)->next;
	while(temp!=root->sent){
		if(temp->child==NULL)continue;
		return findKeyAssist(temp->child, k1);
		temp=temp->next;
	}
}

bool findKey(struct treenode *root, ll k1){
	findKeyAssist(root, k1);
	if(finde){
		finde=0;
		return true;
	}
	return false;
}


void getNodeWithKeyAssist(struct treenode * root, ll k1){
	if(helpflag)return;
	if(root->key == k1){
		helpnode=root;
		helpflag=1;
	}
	struct node *temp=(root->sent)->next;
	while(temp!=root->sent){
		if(temp->child==NULL){temp=temp->next;continue;}
		getNodeWithKeyAssist(temp->child, k1);
		temp=temp->next;
	}
}


struct treenode *getNodeWithKey(struct treenode * root, ll k1){
	getNodeWithKeyAssist(root, k1);
	if(helpflag){
		helpflag=0;
		return helpnode;
	}
	return NULL;
}

void deleteNode(struct treenode * root){
	if((root->sent)->next == root->sent){
		if(root->parent == NULL){
			free(root);
		} else{
			struct treenode *par=root->parent;
			struct node *temp2=(par->sent)->next;
			while(temp2!=par->sent){
				if(temp2->child==NULL){temp2=temp2->next;continue;}
				if((temp2->child) == root){
					free(temp2->child);
					(temp2->prev)->next=temp2->next;
					(temp2->next)->prev=temp2->prev;
					free(temp2);
				}
				temp2=temp2->next;
			}
		}
		return;
	}

	struct treenode * temp=((root->sent)->next)->child;
	struct node *temp2=(root->sent)->next;
	if((temp->sent)->next==temp->sent){
		root->key=temp->key;
		(root->sent)->next=temp2->next;
		(temp2->next)->prev=root->sent;
		free(temp2);
		free(temp);
	} else {
		root->key=temp->key;
		deleteNode(temp);
	}
}

void print(struct treenode *root){
	if(root == NULL){return;}
	cout<<root->key<<" ";
	struct node *temp=(root->sent)->next;
	while(temp!=root->sent){
		print(temp->child);
		temp=temp->next;
	}
}


int main(){
	struct treenode *root=createtreenode();
	root->key=3;
	insert(root, 5);
	insert(root, 10);
	insert(root, 15);
	insert(getNodeWithKey(root, 15), 100);
	insert(getNodeWithKey(root, 100), 20);
	insert(getNodeWithKey(root, 100), 90);
	insert(getNodeWithKey(root, 100), 110);
	print(root);
	cout <<endl;
	insert(getNodeWithKey(root, 100), 120);
	insert(getNodeWithKey(root, 100), 130);
	insert(getNodeWithKey(root, 100), 140);
	insert(getNodeWithKey(root, 100), 150);
	insert(getNodeWithKey(root, 100), 160);
	insert(getNodeWithKey(root, 160), 782);
	
	deleteNode(getNodeWithKey(root, 160));   //delete
	print(root);
	
    cout<<endl<<findKey(root, 160)<<" \n";    //search
    cout <<findKey(root, 100)<<endl;

}
/*

Output:

3 15 100 110 90 20 10 5 
3 15 100 782 150 140 130 120 110 90 20 10 5 
0 
1

*/

