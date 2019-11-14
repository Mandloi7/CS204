//***************STACK*************************
//**********using linked-list******************




#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* link; 
}; 
struct Node* top; 

void push(int data) 
{ 
	struct Node* temp; 
	temp = new Node(); 
	temp->data = data; 
	temp->link = top; 
	top = temp; 
} 

 
int isEmpty() 
{ 
	return top == NULL; 
} 


int peek() 
{ 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 


void pop() 
{ 
	struct Node* temp;
	if (top == NULL) { 
		cout << "Stack Underflow" << endl; 
	} 
	else {
		temp = top; 
		top = top->link; 
		temp->link = NULL; 
		free(temp); 
	} 
} 


void print() 
{ 
	struct Node* temp; 
	if (top == NULL) { 
		cout << "Stack Underflow"; 
	} 
	else { 
		temp = top; 
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->link; 
		} 
	} 
	cout << endl;
} 


int main() 
{ 
	push(11); 
	push(22); 
	push(33); 
	push(44); 
	print(); 
	cout << peek()<<endl; 
	pop(); 
	pop(); 
    pop();
    print();
    pop();
    pop();
	print(); 
	cout << peek()<<endl; 
	return 0; 
}

/*

Output:
44 33 22 11 
44
11 
Stack Underflow
Stack Underflow

*/
