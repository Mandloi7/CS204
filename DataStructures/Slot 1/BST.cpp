//***********************BST*******************

#include<bits/stdc++.h> 
using namespace std;

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 

struct node* insert(struct node* node, int key) 
{ 
	
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
	struct node* current = node; 
	while (current && current->left != NULL) 
		current = current->left; 

	return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
	
	if (root == NULL) return root; 
	if (key < root->key) 
		root->left = deleteNode(root->left, key); 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 
	else
	{ 
		
		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 
		struct node* temp = minValueNode(root->right); 
		root->key = temp->key; 
		root->right = deleteNode(root->right, temp->key); 
	} 
	return root; 
} 

void search(node *root, int skey){
    if(root==NULL){
        cout <<endl<< "Key "<<skey<< ": NOT FOUND\n"<<endl;
        return;
    }
    if(root->key>skey){
        search(root->left,skey);
    }else if(root->key<skey){
        search(root->right,skey);
    }else{
        cout <<endl<<"Key "<< skey<< ": FOUND\n"<<endl;
        return; 
    }
}
int main() 
{ 
	
	struct node *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	
	inorder(root); 

	cout << endl;
	root = deleteNode(root, 20); 
	search(root,70);
	inorder(root); 
    cout << endl;

	root = deleteNode(root, 30); 
	
	inorder(root); 
    cout << endl;
	
	root = deleteNode(root, 50); 
	search(root,50);
	inorder(root); 
    cout << endl;
	return 0; 
} 
/*

Output:

20 30 40 50 60 70 80 

Key 70: FOUND

30 40 50 60 70 80 
40 50 60 70 80 

Key 50: NOT FOUND

40 60 70 80 

*/
