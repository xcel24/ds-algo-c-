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


void insertAtHead(node* &head, int data){

	if(head == NULL){
		head = new node(data);

		return;
	}

	node* n = new node(data);

	n->next = head;
	head = n;
}

void insertAtTail(node* &head, int data){

	if(head==NULL){
		head = new node(data);
		return;
	}

	node* tail = head;

	while(tail->next != NULL){
		tail = tail->next;
	}

	node* n = new node(data);

	tail->next = n;

	return;
}


void printList(node* head){
	while(head != NULL){
		cout<<head->data<<" ";

		head = head->next;
	}
}

// logic is basically to interchange the links


node* sortList(node* head){

	node* temp = head;

	while(temp->next){
		node* curr = temp->next;

		if(curr->data == 0){
			temp->next = curr->next;
			curr->next = head;

			head = curr;
		}else{
			temp = temp->next;
		}
	}

	return head;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif

	node* head = NULL;
	// insertAtHead(head,1);
	// insertAtHead(head,2);
	// insertAtHead(head,3);
	// insertAtHead(head,4);
	// insertAtHead(head,5);

	insertAtTail(head,1);
	insertAtTail(head,0);
	insertAtTail(head,0);
	insertAtTail(head,1);

	node* temp = sortList(head);

	printList(temp);


	return 0;
}