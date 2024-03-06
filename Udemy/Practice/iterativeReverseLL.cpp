#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node* &head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}

	node* n = new node(data);
	n->next = head;
	head = n;

	return;
}

void printLL(node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<endl;
}

node* reverseLL(node* head){

	node* prev = NULL;
	node* curr = head;
	node* temp = NULL;

	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	return prev;

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);

	printLL(head);

	node* reversedHead = reverseLL(head);

	printLL(reversedHead);


	return 0;
}