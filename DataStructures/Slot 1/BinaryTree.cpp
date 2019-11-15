//**************************Binary-Tree*******************************

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node *newNode(int key){
        Node *a = ( Node*)malloc(sizeof( Node));
        a->key=key;
        a->left=NULL;
        a->right=NULL;
        return a;
    }

Node *InsertR( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->right =  InsertR(root->right, key);
    	return root;
    }

Node *InsertL( Node *root, int key){
    	if(root == NULL) return newNode(key);
    	root->left =  InsertL(root->left, key);
    	return root;
    }

void inorder( Node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    
void preorder( Node* root) {
        if(root == NULL) return;
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

void postorder( Node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }

bool Search( Node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->key == key)
            return true;

        bool l = Search(root->left, key);

        bool r = Search(root->right, key);

        return l || r;
    }


int main(){
  Node *root = NULL;
	root = InsertL(root, 880);
	root = InsertR(root, 584);
	root = InsertL(root, 283);
	root = InsertL(root, 483);
	root = InsertR(root, 885);
	root = InsertL(root, 48);
	root = InsertR(root, 85);
	root = InsertL(root, 83);
	root = InsertR(root, 857);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
    postorder(root);
	cout<<endl;
	cout<<Search(root, 584)<<"\n";
	cout<<Search(root,70)<<"\n";
}

/*
******Output:

83 48 483 283 880 584 885 85 857 
880 283 483 48 83 584 885 85 857 
83 48 483 283 857 85 885 584 880 
1
0
*/
